#include <regex>
#include "file.h"
#include "player_exception.h"

const std::regex correctnessRegex ("(?:[^|:]+)[|](?:[^|:]+:[^|]*[|]){2,}(?:[^|]*)");
const std::regex typeRegex("[a-zA-Z]+");
const std::regex metadataRegex("([^|:]+):([^|]*)[|]");
const std::regex contentRegex("[a-zA-Z0-9\\s,.!?':;-]*");
const std::regex yearRegex("[0-9]*");

File::File(std::string info) {
    std::smatch result;
    if (!std::regex_match(info, correctnessRegex)) {
        throw CorruptedException();
    } else {
        if (!std::regex_search(info, result, typeRegex)) {
            throw UnsupportedTypeException();
        } else {
            this->fileType = result[0];
        }

        while (std::regex_search(info, result, metadataRegex)) {
            if (result[1] == "year") {
                if (!std::regex_match((std::string) result[2], yearRegex)) {
                    // rok nie jest liczbą
                    throw MetadataException();
                }
            }
            auto ret = this->metadata.emplace(result[1], result[2]);
            if (!ret.second) {
                auto it = ret.first;
                it->second = result[2];
            }
            info = result.suffix().str();
        }

        if (!std::regex_match(info, contentRegex)) {
            throw CorruptedContentException();
        } else {
            this->content = info;
        }
    }
}

std::string& File::getFileType() {
    return this->fileType;
}

std::unordered_map<std::string, std::string> &File::getMetadata() {
    return this->metadata;
}

std::string File::getContent() {
    return this->content;
}