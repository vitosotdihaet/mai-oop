#include <sstream>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <chrono>
#include <queue>
#include <array>
#include <algorithm>

#ifdef _WIN32
#include <windows.h>
#endif

#include "fight.hpp"
#include "npc.hpp"
#include "factory.hpp"
#include "elf.hpp"
#include "knight.hpp"
#include "druid.hpp"


using namespace std::chrono_literals;


const int NPC_COUNT = 50;
const std::vector<std::string> npc_names = {
    "Oliver", "Emma", "William", "Ava", "James",
    "Isabella", "Benjamin", "Sophia", "Lucas", "Mia",
    "Henry", "Charlotte", "Alexander", "Amelia", "Michael",
    "Harper", "Elijah", "Evelyn", "Daniel", "Abigail",
    "Matthew", "Emily", "Jackson", "Elizabeth", "David",
    "Sofia", "Joseph", "Ella", "Samuel", "Grace",
    "John", "Chloe", "Andrew", "Victoria", "Jack",
    "Lily", "Ryan", "Hannah", "Noah", "Zoe",
    "Anthony", "Penelope", "Jonathan", "Nora", "Joshua",
    "Scarlett", "Christian", "Addison", "David", "Charles"
};

const int MAX_X = 25;
const int MAX_Y = 25;

set_t npcs;

const std::chrono::seconds max_time = 30s;
auto start = std::chrono::steady_clock::now();

std::shared_mutex npc_mutex;

#define REPRINT
void reprint(int H) {
#ifdef __linux__
    std::cout << "\033[" << H << "A";
    std::cout << "\r";
#elif _WIN32
    HANDLE StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(StdOut, &csbi);
    COORD c = csbi.dwCursorPosition;
    SetConsoleCursorPosition(StdOut, (COORD) {c.X, c.Y - H});
#endif
}


void npc_move() {
    while (true) {
        {
            std::lock_guard<std::shared_mutex> lock(npc_mutex);

            // move randomly
            for (std::shared_ptr<NPC> npc : npcs) {
                if (npc->is_alive()) {
                    int shift_x = std::rand() % (npc->get_move_distance() * 2 + 1) - npc->get_move_distance();
                    int shift_y = std::rand() % (npc->get_move_distance() * 2 + 1) - npc->get_move_distance();

                    npc->move(shift_x, shift_y, MAX_X, MAX_Y);
                }
            }

            // fight
            for (std::shared_ptr<NPC> npc : npcs) {
                for (std::shared_ptr<NPC> other : npcs) {
                    if (other != npc && npc->is_alive() && other->is_alive() && npc->is_close(other)) {
                        FightManager::get().add_event({ npc, other });
                    }
                }
            }
        }

        auto end = std::chrono::steady_clock::now();
        if (std::chrono::duration_cast<std::chrono::seconds>(end - start) >= max_time) break;
        std::this_thread::sleep_for(100ms);
    }
}


void npc_print() {
    const int scale_inverted = MAX_X, step_x = MAX_X / scale_inverted, step_y = MAX_Y / scale_inverted;

    while (true) {
        std::array<std::array<char, scale_inverted>, scale_inverted> fields = {};

        {
            std::lock_guard<std::shared_mutex> lock(npc_mutex);

            for (std::shared_ptr<NPC> npc : npcs) {
                auto [x, y] = npc->get_position();

                int i = x / step_x;
                int j = y / step_y;

                if (i >= scale_inverted) i = scale_inverted - 1;
                if (j >= scale_inverted) j = scale_inverted - 1;

                if (npc->is_alive()) {
                    switch (npc->get_type()) {
                        case ElfType:
                            fields[i][j] = 'E';
                            break;
                        case KnightType:
                            fields[i][j] = 'K';
                            break;
                        case DruidType:
                            fields[i][j] = 'D';
                            break;
                        default:
                            break;
                    }
                // } else {
                //     fields[i][j] = 'x';
                }
            }
        }

        for (int j = 0; j < scale_inverted; ++j) {
            for (int i = 0; i < scale_inverted; ++i) {
                if (fields[i][j]) std::cout << ' ' << fields[i][j] << ' ';
                else std::cout << " . ";
            }
            std::cout << '\n';
        }

        auto end = std::chrono::steady_clock::now();
        if (std::chrono::duration_cast<std::chrono::seconds>(end - start) >= max_time) break;

#ifdef REPRINT
        std::this_thread::sleep_for(100ms);
        reprint(MAX_Y);
#else 
        std::this_thread::sleep_for(1s);
        std::cout << '\n';
#endif
    }
    for (int i = 0; i < MAX_Y; ++i) {
        std::cout << '\n';
    }
}


int main() {
    for (size_t i = 0; i < NPC_COUNT; ++i) {
        npcs.insert(
            Factory::CreateNPC(
                NPCType(std::rand() % 3 + 1),
                npc_names[i],
                std::rand() % MAX_X,
                std::rand() % MAX_Y
            )
        );
    }

    std::cout << "Starting list:\n";
    for (auto& n : npcs) std::cout << *n << '\n';

    std::thread fight_thread(std::ref(FightManager::get()), (void*) &max_time);
    std::thread move_thread(npc_move);
    std::thread print_thread(npc_print);

    fight_thread.join();
    move_thread.join();
    print_thread.join();

#ifdef REPRINT
    reprint(MAX_Y);
#endif
    std::cout << "Survivors:\n";
    for (auto& n : npcs) {
        if (n->is_alive()) std::cout << *n << '\n';
    }

    return 0;
}
