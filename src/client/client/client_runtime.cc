#include "client_runtime.h"

#include <core/logger.h>
#include <core/memory/memory.h>
#include <engine/engine.h>

namespace blowbox
{
  namespace client
  {
    //------------------------------------------------------------------------------------------------------
    ClientRuntime::ClientRuntime(int argc, char** argv)
    {
      engine_ = core::Memory::Construct<engine::Engine>(&core::Memory::default_allocator(), argc, argv);

      engine_->SetCallbackUserdata(this);
      engine_->SetOnInitialize(OnInitializeFn);
      engine_->SetOnBeginFrame(OnBeginFrameFn);
      engine_->SetOnPreUpdate(OnPreUpdateFn);
      engine_->SetOnUpdate(OnUpdateFn);
      engine_->SetOnFixedUpdate(OnFixedUpdateFn);
      engine_->SetOnPostUpdate(OnPostRenderFn);
      engine_->SetOnPreRender(OnPreRenderFn);
      engine_->SetOnRender(OnRenderFn);
      engine_->SetOnPostRender(OnPostRenderFn);
      engine_->SetOnEndFrame(OnEndFrameFn);
      engine_->SetOnShutdown(OnShutdownFn);
    }

    //------------------------------------------------------------------------------------------------------
    ClientRuntime::~ClientRuntime()
    {
      core::Memory::Destruct(engine_);
    }

    //------------------------------------------------------------------------------------------------------
    void ClientRuntime::Run()
    {
      engine_->Run();
    }

    //------------------------------------------------------------------------------------------------------
    void ClientRuntime::Shutdown()
    {
      engine_->Shutdown();
    }

    //------------------------------------------------------------------------------------------------------
    void ClientRuntime::OnInitialize()
    {
      
    }

    //------------------------------------------------------------------------------------------------------
    void ClientRuntime::OnBeginFrame()
    {

    }

    //------------------------------------------------------------------------------------------------------
    void ClientRuntime::OnPreUpdate()
    {

    }

    //------------------------------------------------------------------------------------------------------
    void ClientRuntime::OnUpdate()
    {

    }

    //------------------------------------------------------------------------------------------------------
    void ClientRuntime::OnFixedUpdate()
    {

    }

    //------------------------------------------------------------------------------------------------------
    void ClientRuntime::OnPostUpdate()
    {

    }

    //------------------------------------------------------------------------------------------------------
    void ClientRuntime::OnPreRender()
    {

    }

    //------------------------------------------------------------------------------------------------------
    void ClientRuntime::OnRender()
    {

    }

    //------------------------------------------------------------------------------------------------------
    void ClientRuntime::OnPostRender()
    {

    }

    //------------------------------------------------------------------------------------------------------
    void ClientRuntime::OnEndFrame()
    {
      
    }

    //------------------------------------------------------------------------------------------------------
    void ClientRuntime::OnShutdown()
    {

    }

    //------------------------------------------------------------------------------------------------------
    void ClientRuntime::OnInitializeFn(void* userdata)
    {
      ClientRuntime* client = reinterpret_cast<ClientRuntime*>(userdata);
      client->OnInitialize();
    }

    //------------------------------------------------------------------------------------------------------
    void ClientRuntime::OnBeginFrameFn(void* userdata)
    {
      ClientRuntime* client = reinterpret_cast<ClientRuntime*>(userdata);
      client->OnBeginFrame();
    }

    //------------------------------------------------------------------------------------------------------
    void ClientRuntime::OnPreUpdateFn(void* userdata)
    {
      ClientRuntime* client = reinterpret_cast<ClientRuntime*>(userdata);
      client->OnPreUpdate();
    }

    //------------------------------------------------------------------------------------------------------
    void ClientRuntime::OnUpdateFn(void* userdata)
    {
      ClientRuntime* client = reinterpret_cast<ClientRuntime*>(userdata);
      client->OnUpdate();
    }

    //------------------------------------------------------------------------------------------------------
    void ClientRuntime::OnFixedUpdateFn(void* userdata)
    {
      ClientRuntime* client = reinterpret_cast<ClientRuntime*>(userdata);
      client->OnFixedUpdate();
    }

    //------------------------------------------------------------------------------------------------------
    void ClientRuntime::OnPostUpdateFn(void* userdata)
    {
      ClientRuntime* client = reinterpret_cast<ClientRuntime*>(userdata);
      client->OnPostUpdate();
    }

    //------------------------------------------------------------------------------------------------------
    void ClientRuntime::OnPreRenderFn(void* userdata)
    {
      ClientRuntime* client = reinterpret_cast<ClientRuntime*>(userdata);
      client->OnPreRender();
    }

    //------------------------------------------------------------------------------------------------------
    void ClientRuntime::OnRenderFn(void* userdata)
    {
      ClientRuntime* client = reinterpret_cast<ClientRuntime*>(userdata);
      client->OnRender();
    }

    //------------------------------------------------------------------------------------------------------
    void ClientRuntime::OnPostRenderFn(void* userdata)
    {
      ClientRuntime* client = reinterpret_cast<ClientRuntime*>(userdata);
      client->OnPostRender();
    }

    //------------------------------------------------------------------------------------------------------
    void ClientRuntime::OnEndFrameFn(void* userdata)
    {
      ClientRuntime* client = reinterpret_cast<ClientRuntime*>(userdata);
      client->OnEndFrame();
    }

    //------------------------------------------------------------------------------------------------------
    void ClientRuntime::OnShutdownFn(void* userdata)
    {
      ClientRuntime* client = reinterpret_cast<ClientRuntime*>(userdata);
      client->OnShutdown();
    }
  }
}