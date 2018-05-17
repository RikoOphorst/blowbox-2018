#pragma once

#include <core/data/path.h>

extern "C"
{
  struct lua_State;
}

namespace blowbox
{
  namespace scripting
  {
    class ScriptState
    {
    public:
      ScriptState();
      ~ScriptState();
    
      void Initialize();
      void Shutdown();

      void StackDump();

      void CompileAndRun(const Path& path_to_script);

      inline lua_State* Get() const;

      operator lua_State*() const;

    private:
      lua_State* state_;
    };

    //------------------------------------------------------------------------------------------------------
    lua_State* ScriptState::Get() const
    {
      return state_;
    }
  }
}