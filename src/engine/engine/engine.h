#pragma once

#include <core/data/functional.h>

namespace blowbox
{
  namespace engine
  {
    using CallbackOnInitialize  = eastl::function<void(void*)>;
    using CallbackOnBeginFrame  = eastl::function<void(void*)>;
    using CallbackOnPreUpdate   = eastl::function<void(void*)>;
    using CallbackOnUpdate      = eastl::function<void(void*)>;
    using CallbackOnPostUpdate  = eastl::function<void(void*)>;
    using CallbackOnLateUpdate  = eastl::function<void(void*)>;
    using CallbackOnFixedUpdate = eastl::function<void(void*)>;
    using CallbackOnPreRender   = eastl::function<void(void*)>;
    using CallbackOnRender      = eastl::function<void(void*)>;
    using CallbackOnPostRender  = eastl::function<void(void*)>;
    using CallbackOnEndFrame    = eastl::function<void(void*)>;
    using CallbackOnShutdown    = eastl::function<void(void*)>;

    class Engine
    {
    public:
      Engine(int argc, char** argv);
      ~Engine();

      void Run();
      void Shutdown();

    public:
      void SetCallbackUserdata(void* userdata);
      void* GetCallbackUserdata();

      void SetOnInitialize(const CallbackOnInitialize& callback);
      const CallbackOnInitialize& GetOnInitialize() const;

      void SetOnBeginFrame(const CallbackOnBeginFrame& callback);
      const CallbackOnBeginFrame& GetOnBeginFrame() const;

      void SetOnPreUpdate(const CallbackOnPreUpdate& callback);
      const CallbackOnPreUpdate& GetOnPreUpdate() const;

      void SetOnUpdate(const CallbackOnUpdate& callback);
      const CallbackOnUpdate& GetOnUpdate() const;

      void SetOnPostUpdate(const CallbackOnPostUpdate& callback);
      const CallbackOnPostUpdate& GetOnPostUpdate() const;

      void SetOnFixedUpdate(const CallbackOnFixedUpdate& callback);
      const CallbackOnFixedUpdate& GetOnFixedUpdate() const;

      void SetOnPreRender(const CallbackOnPreRender& callback);
      const CallbackOnPreRender& GetOnPreRender() const;

      void SetOnRender(const CallbackOnRender& callback);
      const CallbackOnRender& GetOnRender() const;

      void SetOnPostRender(const CallbackOnPostRender& callback);
      const CallbackOnPostRender& GetOnPostRender() const;

      void SetOnEndFrame(const CallbackOnEndFrame& callback);
      const CallbackOnEndFrame& GetOnEndFrame() const;

      void SetOnShutdown(const CallbackOnShutdown& callback);
      const CallbackOnShutdown& GetOnShutdown() const;

    private:
      bool is_running_;

      void* callback_userdata_;
      CallbackOnInitialize  callback_on_initialize_;
      CallbackOnBeginFrame  callback_on_begin_frame_;
      CallbackOnPreUpdate   callback_on_pre_update_;
      CallbackOnUpdate      callback_on_update_;
      CallbackOnPostUpdate  callback_on_post_update_;
      CallbackOnLateUpdate  callback_on_late_update_;
      CallbackOnFixedUpdate callback_on_fixed_update_;
      CallbackOnPreRender   callback_on_pre_render_;
      CallbackOnRender      callback_on_render_;
      CallbackOnPostRender  callback_on_post_render_;
      CallbackOnEndFrame    callback_on_end_frame_;
      CallbackOnShutdown    callback_on_shutdown_;
    };
  }
}