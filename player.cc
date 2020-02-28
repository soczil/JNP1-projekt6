#include "player.h"
#include "player_exception.h"

#include <iostream>

std::shared_ptr<Playable> Player::openFile(File file) {
    if (file.getFileType() == "audio") {
        Song song (file);
        return std::make_shared<Song> (song);
    } else if (file.getFileType() == "video") {
        Movie movie (file);
        return std::make_shared<Movie> (movie);
    } else {
        throw UnsupportedTypeException();
    }
}

std::shared_ptr<Playlist> Player::createPlaylist(std::string name) {
    Playlist playlist (name);
    return std::make_shared<Playlist> (playlist);
}
