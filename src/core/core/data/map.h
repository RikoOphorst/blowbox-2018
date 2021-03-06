#pragma once

#include "core/memory/allocators/eastl_allocator.h"
#include <EASTL/map.h>

namespace blowbox
{
  /**
  * @brief An ordered map, based on eastl::map.
  * @tparam Key The key of the map.
  * @tparam T The value of the map.
  * @tparam Compare How keys are compared to each other. Defaults to eastl::less<Key>.
  * @tparam Allocator The allocator to use for the map. Default to core::EASTLAllocator.
  */
  template<typename Key, typename T, typename Compare = eastl::less<Key>, typename Allocator = core::EASTLAllocator>
  using Map = eastl::map<Key, T, Compare, Allocator>;
}