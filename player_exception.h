#ifndef __PLAYER_EXCEPTION_H__
#define __PLAYER_EXCEPTION_H__

#include <exception>

class PlayerException : std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override {
        return "player exception";
    }
};

class UnsupportedTypeException : public PlayerException {
public:
    [[nodiscard]] const char* what() const noexcept override {
        return "unsupported type";
    }
};

class CorruptedException : public PlayerException {
public:
    [[nodiscard]] const char* what() const noexcept override {
        return "corrupt";
    }
};

class CorruptedContentException : public PlayerException {
public:
    [[nodiscard]] const char* what() const noexcept override {
        return "corrupt content";
    }
};

class WrongPositionException : public PlayerException {
public:
    [[nodiscard]] const char* what() const noexcept override {
        return "wrong position";
    }
};

class LoopException : public PlayerException {
public:
    [[nodiscard]] const char* what() const noexcept override {
        return "loop exception";
    }
};

class MetadataException : public PlayerException {
public:
    [[nodiscard]] const char* what() const noexcept override {
        return "wrong metadata";
    }
};

#endif /* __PLAYER_EXCEPTION_H__ */
