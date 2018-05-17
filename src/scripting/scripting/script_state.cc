#include "script_state.h"

#include "scripting/script_util.h"

#include <core/logger.h>

extern "C"
{
#include <luajit.h>
#include <lauxlib.h>
#include <lualib.h>
}

#include <fstream>

namespace blowbox
{
  namespace scripting
  {
    //------------------------------------------------------------------------------------------------------
    ScriptState::ScriptState() :
      state_(nullptr)
    {

    }
    
    //------------------------------------------------------------------------------------------------------
    ScriptState::~ScriptState()
    {
      Shutdown();
    }
    
    //------------------------------------------------------------------------------------------------------
    void ScriptState::Initialize()
    {
      state_ = lua_open();

      luaL_openlibs(state_);
    }
    
    //------------------------------------------------------------------------------------------------------
    void ScriptState::Shutdown()
    {
      lua_close(state_);
    }

    //------------------------------------------------------------------------------------------------------
    void ScriptState::StackDump()
    {
      int top = lua_gettop(state_);

      core::Logger::Log(0, core::MessageSource::Scripting, "Dumping Lua C stack of size %i..", top);

      for (int i = 1; i <= top; i++)
      {
        int type = lua_type(state_, i);
        int ni = lua_postoneg(state_, i);

        switch (type)
        {
        case LUA_TSTRING:
          core::Logger::Log(0, core::MessageSource::Scripting, "%i or %i : STRING : %s", i, ni, lua_tostring(state_, i));
          break;

        case LUA_TBOOLEAN:
          core::Logger::Log(0, core::MessageSource::Scripting, "%i or %i : BOOLEAN : %s", i, ni, lua_toboolean(state_, i) == 1 ? "true" : "false");
          break;

        case LUA_TNUMBER:
          core::Logger::Log(0, core::MessageSource::Scripting, "%i or %i : NUMBER : %f", i, ni, lua_tonumber(state_, i));
          break;

        case LUA_TFUNCTION:
          core::Logger::Log(0, core::MessageSource::Scripting, "%i or %i : FUNCTION", i, ni);
          break;

        case LUA_TNIL:
          core::Logger::Log(0, core::MessageSource::Scripting, "%i or %i : NIL", i, ni);
          break;

        case LUA_TTABLE:
          core::Logger::Log(0, core::MessageSource::Scripting, "%i or %i : TABLE", i, ni);
          break;

        case LUA_TTHREAD:
          core::Logger::Log(0, core::MessageSource::Scripting, "%i or %i : THREAD", i, ni);
          break;

        case LUA_TUSERDATA:
          core::Logger::Log(0, core::MessageSource::Scripting, "%i or %i : USERDATA", i, ni);
          break;

        case LUA_TLIGHTUSERDATA:
          core::Logger::Log(0, core::MessageSource::Scripting, "%i or %i : LIGHTUSERDATA", i, ni);
          break;

        case LUA_TNONE:
          core::Logger::Log(0, core::MessageSource::Scripting, "%i or %i : NONE", i, ni);
          break;

        default:
          core::Logger::Log(0, core::MessageSource::Scripting, "%i or %i : %s", i, ni, lua_typename(state_, i));
          break;
        }
      }
    }

    //------------------------------------------------------------------------------------------------------
    void ScriptState::CompileAndRun(const Path& path)
    {
      if (!path.is_file())
      {
        core::Logger::Error(0, core::MessageSource::Scripting, "Tried to compile a script at %s but it doesn't point to a file. Doing nothing instead.", path.str().c_str());
      }

      if (path.extension() != "lua")
      {
        core::Logger::Error(0, core::MessageSource::Scripting, "Tried to compile a script at %s but it doesn't have the .lua extension. Doing nothing instead.", path.str().c_str());
      }

      std::ifstream file;
      file.open(path.str(), std::ios::ate);

      size_t s = file.tellg();

      char* somestr = new char[s + 1];

      file.seekg(0);
      file.read(somestr, s);

      somestr[s] = '\0';

      core::Logger::Assert(0, luaL_loadstring(state_, somestr) == 0, "uh1");
      core::Logger::Assert(0, lua_pcall(state_, 0, LUA_MULTRET, 0) == 0, "uh2");

      lua_getfield(state_, LUA_GLOBALSINDEX, "_VERSION");
      //double mynum= lua_tonumber(state_, -1);

      core::Logger::Log(0, core::MessageSource::Scripting, "%s", lua_tostring(state_, -1));
    }

    //------------------------------------------------------------------------------------------------------
    ScriptState::operator lua_State*() const
    {
      return state_;
    }
  }
}