// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

// NOTE: This is a modified exerpt of
//  https://github.com/PENGUINLIONG/graphi-t/blob/da31ec530df07c9899e056eeced08a64062dcfce/include/util.hpp;
// MIT-licensed by Rendong Liang.

// HAL independent utilities.
// @PENGUINLIONG
#pragma once
#include <cstdint>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <android/log.h>
#define  LOG_TAG    "opencl"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)


namespace archprobe {

namespace util {

namespace {

template<typename ... TArgs>
struct format_impl_t;
template<>
struct format_impl_t<> {
  static inline void format_impl(std::stringstream& ss) {}
};
template<typename T>
struct format_impl_t<T> {
  static inline void format_impl(std::stringstream& ss, const T& x) {
    ss << x;
  }
};
template<typename T, typename ... TArgs>
struct format_impl_t<T, TArgs ...> {
  static inline void format_impl(std::stringstream& ss, const T& x, const TArgs& ... others) {
    format_impl_t<T>::format_impl(ss, x);
    format_impl_t<TArgs...>::format_impl(ss, others...);
  }
};

} // namespace

template<typename ... TArgs>
inline std::string format(const TArgs& ... args) {
  std::stringstream ss {};
  format_impl_t<TArgs...>::format_impl(ss, args...);
  return ss.str();
}



extern const char* path_prefix;
extern std::vector<uint8_t> load_file(const char* path);
extern std::string load_text(const char* path);
extern void save_file(const char* path, const void* data, size_t size);
extern void save_text(const char* path, const std::string& txt);

} // namespace util

} // namespace archprobe
