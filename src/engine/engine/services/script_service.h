#pragma once

#include "engine/services/iservice.h"

#include <core/memory/memory.h>
#include <scripting/script_state.h>

namespace blowbox
{
  namespace engine
  {
    class ScriptService : public IService<ScriptService>
    {
    public:
      ScriptService();
      ~ScriptService();
    
      virtual void Initialize() override;
      virtual void Shutdown() override;

    private:
      UniquePtr<scripting::ScriptState> state_;
    };
  };
}