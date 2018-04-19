#include "engine.h"

#include "core/logger.h"

namespace blowbox
{
  namespace engine
  {
    Engine* Engine::instance_ = nullptr;

    //------------------------------------------------------------------------------------------------------
    Engine::Engine(int argc, char** argv) :
      is_running_(false)
    {
      core::Logger::Assert(instance_ == nullptr, "Tried creating a second Engine instance which is not supported.");

      instance_ = this;
    }
    
    //------------------------------------------------------------------------------------------------------
    Engine::~Engine()
    {
      core::Logger::Assert(is_running_ == false, "Tried destructing the Engine instance while it is still running. Call Engine::Shutdown() before destructing the Engine instance.");

      instance_ = nullptr;
    }

    //------------------------------------------------------------------------------------------------------
    Engine& Engine::Instance()
    {
      core::Logger::Assert(instance_ != nullptr, "Tried retrieving the instance of the engine, but there is no instance alive yet.");
      return *instance_;
    }
    
    //------------------------------------------------------------------------------------------------------
    void Engine::Run()
    {
      is_running_ = true;

      ExecuteCallbackSafely(callback_on_initialize_, callback_userdata_);

      while (is_running_)
      {
        ExecuteCallbackSafely(callback_on_begin_frame_, callback_userdata_);

        ExecuteCallbackSafely(callback_on_pre_update_, callback_userdata_);
        ExecuteCallbackSafely(callback_on_update_, callback_userdata_);

        ExecuteCallbackSafely(callback_on_fixed_update_, callback_userdata_);
        ExecuteCallbackSafely(callback_on_post_update_, callback_userdata_);

        ExecuteCallbackSafely(callback_on_pre_render_, callback_userdata_);
        ExecuteCallbackSafely(callback_on_render_, callback_userdata_);
        ExecuteCallbackSafely(callback_on_post_render_, callback_userdata_);
        
        ExecuteCallbackSafely(callback_on_end_frame_, callback_userdata_);
      }

      ExecuteCallbackSafely(callback_on_shutdown_, callback_userdata_);
    }

    //------------------------------------------------------------------------------------------------------
    void Engine::Shutdown()
    {
      is_running_ = false;
    }
    
    //------------------------------------------------------------------------------------------------------
    void Engine::SetCallbackUserdata(void* userdata)
    {
      callback_userdata_ = userdata;
    }

    //------------------------------------------------------------------------------------------------------
    void* Engine::GetCallbackUserdata() const
    {
      return callback_userdata_;
    }

    //------------------------------------------------------------------------------------------------------
    void Engine::SetOnInitialize(const CallbackOnInitialize& callback)
    {
      callback_on_initialize_ = callback;
    }

    //------------------------------------------------------------------------------------------------------
    const CallbackOnInitialize& Engine::GetOnInitialize() const
    {
      return callback_on_initialize_;
    }

    //------------------------------------------------------------------------------------------------------
    void Engine::SetOnBeginFrame(const CallbackOnBeginFrame& callback)
    {
      callback_on_begin_frame_ = callback;
    }

    //------------------------------------------------------------------------------------------------------
    const CallbackOnBeginFrame& Engine::GetOnBeginFrame() const
    {
      return callback_on_begin_frame_;
    }

    //------------------------------------------------------------------------------------------------------
    void Engine::SetOnPreUpdate(const CallbackOnPreUpdate& callback)
    {
      callback_on_pre_update_ = callback;
    }

    //------------------------------------------------------------------------------------------------------
    const CallbackOnPreUpdate& Engine::GetOnPreUpdate() const
    {
      return callback_on_pre_update_;
    }

    //------------------------------------------------------------------------------------------------------
    void Engine::SetOnUpdate(const CallbackOnUpdate& callback)
    {
      callback_on_update_ = callback;
    }

    //------------------------------------------------------------------------------------------------------
    const CallbackOnUpdate& Engine::GetOnUpdate() const
    {
      return callback_on_update_;
    }

    //------------------------------------------------------------------------------------------------------
    void Engine::SetOnPostUpdate(const CallbackOnPostUpdate& callback)
    {
      callback_on_post_update_ = callback;
    }

    //------------------------------------------------------------------------------------------------------
    const CallbackOnPostUpdate& Engine::GetOnPostUpdate() const
    {
      return callback_on_post_update_;
    }

    //------------------------------------------------------------------------------------------------------
    void Engine::SetOnFixedUpdate(const CallbackOnFixedUpdate& callback)
    {
      callback_on_fixed_update_ = callback;
    }

    //------------------------------------------------------------------------------------------------------
    const CallbackOnFixedUpdate& Engine::GetOnFixedUpdate() const
    {
      return callback_on_fixed_update_;
    }

    //------------------------------------------------------------------------------------------------------
    void Engine::SetOnPreRender(const CallbackOnPreRender& callback)
    {
      callback_on_pre_render_ = callback;
    }

    //------------------------------------------------------------------------------------------------------
    const CallbackOnPreRender& Engine::GetOnPreRender() const
    {
      return callback_on_pre_render_;
    }

    //------------------------------------------------------------------------------------------------------
    void Engine::SetOnRender(const CallbackOnRender& callback)
    {
      callback_on_render_ = callback;
    }

    //------------------------------------------------------------------------------------------------------
    const CallbackOnRender& Engine::GetOnRender() const
    {
      return callback_on_render_;
    }

    //------------------------------------------------------------------------------------------------------
    void Engine::SetOnPostRender(const CallbackOnPostRender& callback)
    {
      callback_on_post_render_ = callback;
    }

    //------------------------------------------------------------------------------------------------------
    const CallbackOnPostRender& Engine::GetOnPostRender() const
    {
      return callback_on_post_render_;
    }

    //------------------------------------------------------------------------------------------------------
    void Engine::SetOnEndFrame(const CallbackOnEndFrame& callback)
    {
      callback_on_end_frame_ = callback;
    }

    //------------------------------------------------------------------------------------------------------
    const CallbackOnEndFrame& Engine::GetOnEndFrame() const
    {
      return callback_on_end_frame_;
    }

    //------------------------------------------------------------------------------------------------------
    void Engine::SetOnShutdown(const CallbackOnShutdown& callback)
    {
      callback_on_shutdown_ = callback;
    }

    //------------------------------------------------------------------------------------------------------
    const CallbackOnShutdown& Engine::GetOnShutdown() const
    {
      return callback_on_shutdown_;
    }
  }
}