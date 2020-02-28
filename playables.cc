#include "playables.h"
#include "player_exception.h"
#include "printer.h"

Song::Song(File &file) {
    try {
        this->artist = file.getMetadata().at("artist");
        this->title = file.getMetadata().at("title");
        this->content = file.getContent();
    } catch (const std::out_of_range &oor) {
        throw MetadataException();
    }
}

void Song::play() {
    Printer::printSong(this->artist, this->title, this->content);
}

bool Song::canBeAdded(const std::shared_ptr<Playable> &element) {
    (void) element;
    return true;
}

Movie::Movie(File &file) {
    try {
        this->title = file.getMetadata().at("title");
        this->year = file.getMetadata().at("year");
        this->content = file.getContent();
    } catch (const std::out_of_range &oor) {
        throw MetadataException();
    }
}

void Movie::play() {
    Printer::printMovie(this->title, this->year, this->content);
}

bool Movie::canBeAdded(const std::shared_ptr<Playable> &element) {
    (void) element;
    return true;
}

Playlist::Playlist(std::string name) {
    this->name = std::move(name);
    this->mode = createSequenceMode();
}

void Playlist::add(const std::shared_ptr<Playable>& element) {
    if (!element->canBeAdded(shared_from_this())) {
        throw LoopException();
    } else {
        playlist.push_back(element);
    }
}

void Playlist::add(const std::shared_ptr<Playable>& element, size_t position) {
    if (position >= this->playlist.size()) {
        throw WrongPositionException();
    } else if (!element->canBeAdded(shared_from_this())) {
        throw LoopException();
    } else {
        auto it = playlist.begin() + position;
        playlist.insert(it, element);
    }
}

void Playlist::remove() {
    auto it = playlist.end() - 1;
    playlist.erase(it);
}

void Playlist::remove(size_t position) {
    if (position >= this->playlist.size()) {
        throw WrongPositionException();
    } else {
        auto it = playlist.begin() + position;
        playlist.erase(it);
    }
}

void Playlist::setMode(std::shared_ptr<PlayMode> playMode) {
    this->mode = std::move(playMode);
}

void Playlist::play() {
    Printer::printPlaylist(this->name);
    this->mode->play(this->playlist);
}

bool Playlist::canBeAdded(const std::shared_ptr<Playable> &element) {
    if (element.get() == this) {
        // spotkaliśmy tę samą playlistę
        return false;
    } else {
        for (const auto& x : this->playlist) {
            if (!x->canBeAdded(element)) {
                return false;
            }
        }
        return true;
    }
}
