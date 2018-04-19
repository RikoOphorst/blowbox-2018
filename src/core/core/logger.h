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
    /**
    * @brief The source of a Message.
    * 
    * When logging Messages with the Logger, you must supply a source
    * of the message. This reflects any subsystem in the engine.
    */
    enum class MessageSource
    {
      Unknown, 
      Core,
      Scripting,
      Engine,
      Graphics,
      Builder,
      Editor,
      Client,
      Game,
      NumSources
    };

    /**
    * @brief The type of a logged Message.
    * 
    * When loggin Messages with the Logger, the Logger adds an entry
    * to the Message that reflects the type of Message, such as a
    * MessageType::Log or similar.
    */
    enum class MessageType
    {
      Log,
      Warning,
      Error,
      Assert
    };

    /**
    * @brief A Message that gets logged by the Logger.
    * 
    * When the Logger adds a Message, this data structure reflects
    * all the data necessary for the Message. 
    * 
    * @remarks A message can not be longer than 1024 characters.
    */
    struct Message
    {
      std::chrono::time_point<std::chrono::system_clock> time_stamp; //!< The time at which the Message was logged.
      MessageType type; //!< The type of the Message. 
      MessageSource source; //!< The source of the Message.
      char message[1024]; //!< The actual message that gets logged.
    };

    /**
    * @brief Allows you to log Messages.
    *
    * The Logger allows you to log Messages from anywhere inside of the
    * entire blowbox project. By default, logged messages are not outputted
    * anywhere. If you want to catch Messages being logged, you must define
    * the Logger::message_receiver struct. This function is called with a
    * custom userdata void* which is settable by setting Logger::message_receiver_userdata.
    */
    class Logger
    {
    public:
      static eastl::function<void(void*, const Message&)> message_receiver; //!< Callback that gets called when messages get logged.
      static void* message_receiver_userdata; //!< The userdata pointer that gets supplied to the message_receiver callback.

      /**
      * @brief Adds a Message to the Logger of type MessageType::Log.
      * @param[in] source The source of the message.
      * @param[in] message The message that should be logged.
      * @param[in] arguments Variable number arguments of any type.
      * @tparam Args Variable number of arguments of any type.
      *
      * @remarks The message gets sprintf_s'd using the arguments you supply.
      */
      template<typename ... Args>
      static void Log(const MessageSource& source, const String& message, Args&&... arguments);

      /**
      * @brief Adds a Message to the Logger of type MessageType::Warning.
      * @param[in] source The source of the message.
      * @param[in] message The message that should be logged.
      * @param[in] arguments Variable number arguments of any type.
      * @tparam Args Variable number of arguments of any type.
      *
      * @remarks The message gets sprintf_s'd using the arguments you supply.
      */
      template<typename ... Args>
      static void Warn(const MessageSource& source, const String& message, Args&&... arguments);

      /**
      * @brief Adds a Message to the Logger of type MessageType::Error.
      * @param[in] source The source of the message.
      * @param[in] message The message that should be logged.
      * @param[in] arguments Variable number arguments of any type.
      * @tparam Args Variable number of arguments of any type.
      *
      * @remarks The message gets sprintf_s'd using the arguments you supply.
      */
      template<typename ... Args>
      static void Error(const MessageSource& source, const String& message, Args&&... arguments);

      /**
      * @brief Acts as the defacto way of doing Asserts in blowbox. If the evaluation is false, a debug break is called.
      * @param[in] evaluation The evaluation you want to assert to be true.
      * @param[in] message The message that should be logged in case the assert fails..
      * @param[in] arguments Variable number arguments of any type.
      * @tparam Args Variable number of arguments of any type.
      *
      * @remarks The message gets sprintf_s'd using the arguments you supply.
      * @remarks In Release, this function still runs the check, however it does not cause a debug break.
      */
      template<typename ... Args>
      static void Assert(bool evaluation, const String& message, Args&&... arguments);

    private:
      /**
      * @brief Adds a Message of a certain type and certain source.
      * @param[in] type The type of message.
      * @param[in] source The source of the message.
      * @param[in] message The message that should be logged.
      * @param[in] arguments Variable number arguments of any type.
      * @tparam Args Variable number of arguments of any type.
      */
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

#ifdef _DEBUG
        EASTL_DEBUG_BREAK();
#endif
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