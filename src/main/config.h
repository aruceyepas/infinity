//
// Created by JinHai on 2022/7/31.
//

#pragma once

#include "common/singleton.h"
#include "common/types/internal_types.h"
#include "spdlog/spdlog.h"

#include <cstdint>

namespace infinity {

enum class LogLevel {
    kTrace,
    kInfo,
    kWarning,
    kError,
    kFatal
};

struct Options {
    // General
    String version{};
    String time_zone{};
    i32    time_zone_bias{};

    String listen_address{};
    u16 pg_port{};
    u32 http_port{};
    u32 sdk_port{};

    // Log
    String log_filename{"infinity.log"};
    String log_dir{};
    String log_file_path{};
    bool log_to_stdout{};
    SizeT log_max_size{};
    SizeT log_file_rotate_count{};
    spdlog::level::level_enum log_level{spdlog::level::info};

    // Storage
    String data_dir{};
    String wal_dir{};
    u64 default_row_size{};

    // Buffer
    u64 buffer_pool_size{};
    String temp_dir{};
};

struct Config {
public:
    SharedPtr<String>
    Init(const SharedPtr<String>& config_path);

    void
    PrintAll() const;

    // General
    [[nodiscard]] inline String
    version() const {
        return option_.version;
    }

    [[nodiscard]] inline String
    time_zone() const {
        return option_.time_zone;
    }

    [[nodiscard]] inline i32
    time_zone_bias() const {
        return option_.time_zone_bias;
    }

    [[nodiscard]] inline String
    listen_address() const {
        return option_.listen_address;
    }

    [[nodiscard]] inline u16
    pg_port() const {
        return option_.pg_port;
    }

    [[nodiscard]] inline u32
    http_port() const {
        return option_.http_port;
    }

    [[nodiscard]] inline u32
    sdk_port() const {
        return option_.sdk_port;
    }

    // Log
    [[nodiscard]] inline String
    log_filename() const {
        return option_.log_filename;
    }

    [[nodiscard]] inline String
    log_dir() const {
        return option_.log_dir;
    }

    [[nodiscard]] inline String
    log_file_path() const {
        return option_.log_file_path;
    }

    [[nodiscard]] inline bool
    log_to_stdout() const {
        return option_.log_to_stdout;
    }

    [[nodiscard]] inline SizeT
    log_max_size() const {
        return option_.log_max_size;
    }

    [[nodiscard]] inline SizeT
    log_file_rotate_count() const {
        return option_.log_file_rotate_count;
    }

    [[nodiscard]] inline spdlog::level::level_enum
    log_level() const {
        return option_.log_level;
    }

    // Storage
    [[nodiscard]] inline String
    data_dir() const {
        return option_.data_dir;
    }

    [[nodiscard]] inline String
    wal_dir() const {
        return option_.wal_dir;
    }

    [[nodiscard]] inline u64
    default_row_size() const {
        return option_.default_row_size;
    }

    [[nodiscard]] inline u64
    buffer_pool_size() const {
        return option_.buffer_pool_size;
    }

    [[nodiscard]] inline String
    temp_dir() const {
        return option_.temp_dir;
    }
private:
    static void
    ParseTimeZoneStr(const String& time_zone_str, String& parsed_time_zone, i32& parsed_time_zone_bias);

    static SharedPtr<String>
    ParseByteSize(const String& byte_size_str, u64& byte_size);

    Options option_;
};

}
