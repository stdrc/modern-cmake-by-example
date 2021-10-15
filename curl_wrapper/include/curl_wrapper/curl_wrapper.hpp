#pragma once

#include <string>

namespace curl_wrapper {
    std::string http_get_string(const std::string &url);
    std::string url_encode(const std::string &s);
} // namespace curl_wrapper
