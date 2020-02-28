#include "printer.h"

const int rotConstant = 13;
const int alphabetSize = 26;

void Printer::printSong(const std::string& artist,
                        const std::string& title, const std::string& content) {
    std::string result = "Song [" + artist + ", " + title +"]: " + content;
    std::cout << result << std::endl;
}

// Odkodowuje tekst utworu z kodu ROT13.
static std::string decode(const std::string& content) {
    char sign;
    std::string result;

    for (char c : content) {
        if ((c >= 'a') && (c <= 'z')) {
            sign = (char) (c - rotConstant);
            if (sign < 'a') {
                sign += alphabetSize;
            }
            result.push_back(sign);
        } else if ((c >= 'A') && (c <= 'Z')) {
            sign = (char) (c - rotConstant);
            if (sign < 'A') {
                sign += alphabetSize;
            }
            result.push_back(sign);
        } else {
            result.push_back(c);
        }
    }

    return result;
}

void Printer::printMovie(const std::string& title,
                         const std::string& year, const std::string& content) {
    std::string result = "Movie [" + title + ", " + year + "]: " + decode(content);
    std::cout << result << std::endl;
}

void Printer::printPlaylist(const std::string& name) {
    std::string result = "Playlist [" + name + "]";
    std::cout << result << std::endl;
}
