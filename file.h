#ifndef __FILE_H__
#define __FILE_H__

#include <string>
#include <unordered_map>

class File {
private:
    std::string fileType;
    std::string content;
    std::unordered_map<std::string, std::string> metadata;

public:
    explicit File(std::string info);

    std::string& getFileType();

    std::unordered_map<std::string, std::string>& getMetadata();

    std::string getContent();
};

#endif /* __FILE_H__ */
