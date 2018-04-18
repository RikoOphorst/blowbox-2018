#pragma once

#include "core/memory/allocators/eastl_allocator.h"
#include <EASTL/string.h>

namespace blowbox
{
  /** @brief 8bit char based string typedef wrapping eastl::string with the blowbox EASTL allocator. */
  using String = eastl::basic_string<char, core::EASTLAllocator>;

  /** @brief 16bit wchar based string typedef wrapping eastl::wstring with the blowbox EASTL allocator. */
  using WString = eastl::basic_string<wchar_t, core::EASTLAllocator>;
}