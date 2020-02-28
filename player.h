#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "playables.h"
#include "file.h"

class Player {
public:
    static std::shared_ptr<Playable> openFile(File file);

    static std::shared_ptr<Playlist> createPlaylist(std::string name);
};

#endif /* __PLAYER_H__ */
