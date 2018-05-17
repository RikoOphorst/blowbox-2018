#include "script_service.h"

namespace blowbox
{
  namespace engine
  {
    //------------------------------------------------------------------------------------------------------
    ScriptService::ScriptService() :
      IService("ScriptService")
    {
      
    }

    //------------------------------------------------------------------------------------------------------
    ScriptService::~ScriptService()
    {

    }

    //------------------------------------------------------------------------------------------------------
    void ScriptService::Initialize()
    {
      state_ = core::Memory::ConstructUnique<scripting::ScriptState>(&core::Memory::default_allocator());

      state_->Initialize();

      state_->CompileAndRun("E:/Projects/blowbox-2018/projects/test/main.lua");
    }

    //------------------------------------------------------------------------------------------------------
    void ScriptService::Shutdown()
    {
      state_->Shutdown();
    }
  }
}