#pragma once

#include <filesystem/path.h>
#include <filesystem/resolver.h>

namespace blowbox
{
  /** 
  * @brief Wraps the filesystem::path object. 
  * 
  * In the future, we might want to replace the filesystem::path with a 
  * custom blowbox path class, hence this typedef. 
  */
  using Path = filesystem::path;

  /** 
  * @brief Wraps the filesystem::resolver object. 
  *
  * In the future, we might want to replace the filesystem::resolver with 
  * a custom blowbox path resolver, hence this typedef. 
  */
  using PathResolver = filesystem::resolver;
}