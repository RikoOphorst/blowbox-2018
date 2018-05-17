#pragma once

#define lua_postoneg(L, i) (i - lua_gettop(L) - 1)
#define lua_negtopos(L, i) (i + lua_gettop(L) + 1)