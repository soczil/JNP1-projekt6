#include <deque>
#include <vector>
#include <algorithm>
#include "play_mode.h"

void SequenceMode::play(std::deque<std::shared_ptr<Playable>> &playlist) {
    for (auto &element : playlist) {
        element->play();
    }
}

ShuffleMode::ShuffleMode(unsigned seed) {
    std::default_random_engine newEngine(seed);
    this->engine = newEngine;
}

void ShuffleMode::play(std::deque<std::shared_ptr<Playable>> &playlist) {
    std::vector<size_t> positions (playlist.size());
    // generuję liczby od 0 do positions.size - 1
    std::iota(positions.begin(), positions.end(), 0);
    // przestawiam losowo elementy positions używając std::default_random_engine
    std::shuffle(positions.begin(), positions.end(), this->engine);

    for (auto &position : positions) {
        playlist.at(position)->play();
    }
}

void OddEvenMode::play(std::deque<std::shared_ptr<Playable>> &playlist) {
    for (size_t i = 1; i < playlist.size(); i += 2) {
        playlist.at(i)->play();
    }

    for (size_t i = 0; i < playlist.size(); i += 2) {
        playlist.at(i)->play();
    }
}

std::shared_ptr<PlayMode> createSequenceMode() {
    SequenceMode sequenceMode;
    return std::make_shared<SequenceMode>(sequenceMode);
}

std::shared_ptr<PlayMode> createShuffleMode(unsigned seed) {
    ShuffleMode shuffleMode(seed);
    return std::make_shared<ShuffleMode>(shuffleMode);
}

std::shared_ptr<PlayMode> createOddEvenMode() {
    OddEvenMode oddEvenMode;
    return std::make_shared<OddEvenMode>(oddEvenMode);
}
