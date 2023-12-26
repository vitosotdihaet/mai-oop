#pragma once

#include <memory>
#include <chrono>
#include <optional>

#include "npc.hpp"

using namespace std::chrono_literals;


struct FightEvent {
    std::shared_ptr<NPC> attacker;
    std::shared_ptr<NPC> defender;
};

class FightManager final {
private:
    std::queue<FightEvent> events;
    std::shared_mutex mutex;

    FightManager() {}

public:
    static FightManager& get() {
        static FightManager instance;
        return instance;
    }

    void add_event(FightEvent&& event) {
        std::lock_guard<std::shared_mutex> lock(mutex);
        events.push(event);
    }

    void operator()(void* args) {
        auto start = std::chrono::steady_clock::now();
        auto max_time = (std::chrono::seconds*) args;

        while (true) {
            std::optional<FightEvent> event;

            {
                std::lock_guard<std::shared_mutex> lock(mutex);
                if (!events.empty()) {
                    event = events.back();
                    events.pop();
                }
            }

            if (event) {
                if (
                    event->attacker->is_alive() && event->defender->is_alive() &&
                    event->attacker->throw_dice() > event->defender->throw_dice() &&
                    event->defender->accept(event->attacker)
                ) {
                    event->defender->must_die();
                }
            } else {
                std::this_thread::sleep_for(10ms);
            }

            auto end = std::chrono::steady_clock::now();
            if (std::chrono::duration_cast<std::chrono::seconds>(end - start) >= *max_time) break;
        }
    }
};