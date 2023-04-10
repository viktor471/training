#include "rapidjson/internal/itoa.h"
#include <memory>
#include <mutex>
#include <iostream>
#include <cstdint>

std::mutex freeChunksMutex_;

class LoggerException : public std::runtime_error {
public:
    explicit LoggerException(const std::string& what) : std::runtime_error(what){};
    explicit LoggerException(const char* what) : std::runtime_error(what){};
};

struct Chunk {
    char*                  begin;
    char*                  last;
    char*                  end;
    int                    type;
    std::shared_ptr<Chunk> next;

    Chunk(int size) : type(0), next(nullptr) {
        begin = (char*)malloc(size);
        if (!begin) {
            throw LoggerException("can't malloc");
        }
        last = begin;
        end  = begin + size;
    }

    ~Chunk() {
        if (begin) {
            free(begin);
        }
    }

    void clear() {
        last = begin;
        type = 0;
    }
};

std::shared_ptr<Chunk> freeChunks_;

std::shared_ptr<Chunk> newChunk() {
    std::unique_lock<std::mutex> guard(freeChunksMutex_);
    if (freeChunks_) {
        auto c      = freeChunks_;
        freeChunks_ = c->next;
        c->next     = nullptr;
        return c;
    } else {
        guard.unlock();
        auto c = std::make_shared<Chunk>(1024);
        return c;
    }
}

std::shared_ptr<Chunk> append(std::shared_ptr<Chunk> c, int32_t n) {
    if (c->end - c->last < 10) {
        c->next = newChunk();
        c       = c->next;
    }
    c->last = rapidjson::internal::i32toa(n, c->last);
    return c;
}

int main() {
    char *buf = (char*)malloc(100);

    memset(buf, 0, 100);

    char *new_ptr = rapidjson::internal::i32toa(142, buf);

    std::cout << &buf << std::endl;
    std::cout << *(char*)(new_ptr - 2) << std::endl;
    std::cout << UINT32_MAX << std::endl;

    memset(buf, 0, 100);

    rapidjson::internal::u32toa(UINT32_MAX, buf);

    std::cout << strlen(buf) << std::endl;
    std::cout << UINT32_WIDTH << std::endl;
    free(buf);
}