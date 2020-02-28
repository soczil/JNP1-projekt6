#ifndef __PRINTER_H__
#define __PRINTER_H__

#include <iostream>

class Printer {
public:
    static void printSong(const std::string& artist,
                          const std::string& title, const std::string& content);

    static void printMovie(const std::string& title,
                           const std::string& year, const std::string& content);

    static void printPlaylist(const std::string& name);
};

#endif /* __PRINTER_H__ */
