#ifndef __PLAY_MODE_H__
#define __PLAY_MODE_H__

#include <random>
#include "playable.h"

class PlayMode {
public:
    virtual void play(std::deque<std::shared_ptr<Playable>> &playlist) = 0;
};

class SequenceMode : public PlayMode {
public:
    SequenceMode() = default;

    void play(std::deque<std::shared_ptr<Playable>> &playlist) override;
};

class ShuffleMode : public PlayMode {
private:
    std::default_random_engine engine;

public:
    explicit ShuffleMode(unsigned seed);

    void play(std::deque<std::shared_ptr<Playable>> &playlist) override;
};

class OddEvenMode : public PlayMode {
public:
    OddEvenMode() = default;

    void play(std::deque<std::shared_ptr<Playable>> &playlist) override;
};

std::shared_ptr<PlayMode> createSequenceMode();

std::shared_ptr<PlayMode> createShuffleMode(unsigned seed);

std::shared_ptr<PlayMode> createOddEvenMode();

#endif /* __PLAY_MODE_H__ */
