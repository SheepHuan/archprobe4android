// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

// NOTE: This is a modified excerpt of
//  https://github.com/PENGUINLIONG/graphi-t/blob/da31ec530df07c9899e056eeced08a64062dcfce/src/util.cpp;
// MIT-licensed by Rendong Liang.
#include "util.hpp"
#include "assert.hpp"

namespace archprobe {

namespace util {

const char* path_prefix;

std::vector<uint8_t> load_file(const char* path) {
  std::ifstream f(path, std::ios::ate | std::ios::binary | std::ios::in);
  assert(f.is_open(), "unable to open file: ", path);
  size_t size = f.tellg();
  f.seekg(std::ios::beg);
  std::vector<uint8_t> buf;
  buf.resize(size);
  f.read((char*)buf.data(), size);
  f.close();
  return buf;
}
std::string load_text(const char* path) {
  char * new_path = (char *) malloc(sizeof(char ) * (strlen(path)+ strlen(util::path_prefix)+1));
  strcpy(new_path,util::path_prefix);
  strcat(new_path,path);

  std::ifstream f(new_path, std::ios::ate | std::ios::binary | std::ios::in);
  assert(f.is_open(), "unable to open file: ", new_path);
  size_t size = f.tellg();
  f.seekg(std::ios::beg);
  std::string buf;
  buf.reserve(size + 1);
  buf.resize(size);
  f.read((char*)buf.data(), size);
  f.close();
  free(new_path);
  return buf;
}
void save_file(const char* path, const void* data, size_t size) {
  std::ofstream f(path, std::ios::trunc | std::ios::out | std::ios::binary);
  assert(f.is_open(), "unable to open file: ", path);
  f.write((const char*)data, size);
  f.close();
}
void save_text(const char* path, const std::string& txt) {

  char * new_path = (char *) malloc(sizeof(char ) * (strlen(path)+ strlen(util::path_prefix)+1));
  strcpy(new_path,util::path_prefix);
  strcat(new_path,path);
  std::ofstream f(new_path, std::ios::trunc | std::ios::out | std::ios::binary);
  assert(f.is_open(), "unable to open file: ", new_path);
  f << txt;
  f.close();
}


} // namespace util

} // namespace archprobe
