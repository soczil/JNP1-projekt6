#ifndef __PLAYABLES_H__
#define __PLAYABLES_H__

#include <string>
#include <deque>
#include "playable.h"
#include "play_mode.h"
#include "file.h"

class Song : public Playable {
private:
    std::string artist;
    std::string title;
    std::string content;

public:
    explicit Song(File &file);

    void play() override;

    bool canBeAdded(const std::shared_ptr<Playable> &element) override;
};

class Movie : public Playable {
private:
    std::string title;
    std::string year;
    std::string content;

public:
    explicit Movie(File &file);

    void play() override;

    bool canBeAdded(const std::shared_ptr<Playable> &element) override;
};

class Playlist : public Playable, public std::enable_shared_from_this<Playable> {
private:
    std::string name;
    std::deque<std::shared_ptr<Playable>> playlist;
    std::shared_ptr<PlayMode> mode;

public:
    explicit Playlist(std::string name);

    void add(const std::shared_ptr<Playable>& element);

    void add(const std::shared_ptr<Playable>& element, size_t position);

    void remove();

    void remove(size_t position);

    void setMode(std::shared_ptr<PlayMode> playMode);

    void play() override;

    bool canBeAdded(const std::shared_ptr<Playable> &element) override;
};

#endif /* __PLAYABLES_H__ */
