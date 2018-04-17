#pragma once

#include <EASTL/functional.h>
#include "core/memory/memory.h"

#include "core/data/queue.h"
#include "core/data/string.h"

#include <chrono>

namespace blowbox
{
  namespace core
  {
    enum class MessageSource
    {
      Unknown,
      Core,
      Scripting,
      Engine,
      Graphics,
      Builder,
      Editor,
      Game,
      NumSources
    };

    enum class MessageType
    {
      Log,
      Warning,
      Error,
      Assert
    };

    struct Message
    {
      std::chrono::time_point<std::chrono::system_clock> time_stamp;
      MessageType type;
      MessageSource source;
      char message[1024];
    };

    class Logger
    {
    public:
      static eastl::function<void(void*, const Message&)> message_receiver;
      static void* message_receiver_userdata;

      template<typename ... Args>
      static void Log(const MessageSource& source, const String& message, Args&&... arguments);
      
      template<typename ... Args>
      static void Warn(const MessageSource& source, const String& message, Args&&... arguments);

      template<typename ... Args>
      static void Error(const MessageSource& source, const String& message, Args&&... arguments);

      template<typename ... Args>
      static void Assert(bool evaluation, const String& message, Args&&... arguments);

    private:
      template<typename ... Args>
      static void AddMessage(const MessageType& type, const MessageSource& source, const String& message, Args&&... arguments);
    };

    //------------------------------------------------------------------------------------------------------
    template<typename ...Args>
    inline void Logger::Log(const MessageSource& source, const String& message, Args&&... arguments)
    {
      Logger::AddMessage(MessageType::Log, source, message, arguments...);
    }

    //------------------------------------------------------------------------------------------------------
    template<typename ...Args>
    inline void Logger::Warn(const MessageSource& source, const String& message, Args&&... arguments)
    {
      Logger::AddMessage(MessageType::Warning, source, message, arguments...);
    }

    //------------------------------------------------------------------------------------------------------
    template<typename ...Args>
    inline void Logger::Error(const MessageSource& source, const String& message, Args&&... arguments)
    {
      Logger::AddMessage(MessageType::Error, source, message, arguments...);
    }

    //------------------------------------------------------------------------------------------------------
    template<typename ... Args>
    inline void Logger::Assert(bool evaluation, const String& message, Args&&... arguments)
    {
      if (!evaluation)
      {
        Logger::AddMessage(MessageType::Assert, MessageSource::Unknown, message, arguments...);

        EASTL_DEBUG_BREAK();
      }
    }

    //------------------------------------------------------------------------------------------------------
    template<typename ...Args>
    inline void Logger::AddMessage(const MessageType& type, const MessageSource& source, const String& message, Args&& ...arguments)
    {
      Message msg;

      msg.time_stamp = std::chrono::system_clock::now();
      msg.type = type;
      msg.source = source;
      
      sprintf_s(msg.message, sizeof(Message::message), message.c_str(), arguments...);

      if (Logger::message_receiver)
      {
        Logger::message_receiver(Logger::message_receiver_userdata, msg);
      }
    }
  }
}