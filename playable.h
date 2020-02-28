#ifndef __PLAYABLE_H__
#define __PLAYABLE_H__

#include <memory>

class Playable {
public:
    virtual void play() = 0;

    // Sprawdza, czy nowy element może zostać dodany bez tworzenia cykli.
    virtual bool canBeAdded(const std::shared_ptr<Playable> &element) = 0;
};

#endif /* __PLAYABLE_H__ */
