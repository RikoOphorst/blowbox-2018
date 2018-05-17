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
      * @brief Any message that has a verbosity lower than or equal to this verbosity level value will be logged.
      * @remarks 0-10     = highest priority, lowest verbosity.
      * @remarks 10-20    = high priority, low verbosity.
      * @remarks 20-30    = medium priority, medium verbosity.
      * @remarks 40-50    = low priority, high verbosity.
      * @remarks 50+      = lowest priority, highest verbosity.
      */
      static unsigned int verbosity_level;

      /**
      * @brief Adds a Message to the Logger of type MessageType::Log.
      * @param[in] verbosity The verbosity of this message. Lower is less verbose and thus more likely to be logged, higher is more verbose and less likely to be logged.
      * @param[in] source The source of the message.
      * @param[in] message The message that should be logged.
      * @param[in] arguments Variable number arguments of any type.
      * @tparam Args Variable number of arguments of any type.
      *
      * @remarks The message gets sprintf_s'd using the arguments you supply.
      */
      template<typename ... Args>
      static void Log(unsigned int verbosity, const MessageSource& source, const char* message, Args&&... arguments);

      /**
      * @brief Adds a Message to the Logger of type MessageType::Warning.
      * @param[in] verbosity The verbosity of this message. Lower is less verbose and thus more likely to be logged, higher is more verbose and less likely to be logged.
      * @param[in] source The source of the message.
      * @param[in] message The message that should be logged.
      * @param[in] arguments Variable number arguments of any type.
      * @tparam Args Variable number of arguments of any type.
      *
      * @remarks The message gets sprintf_s'd using the arguments you supply.
      */
      template<typename ... Args>
      static void Warn(unsigned int verbosity, const MessageSource& source, const char* message, Args&&... arguments);

      /**
      * @brief Adds a Message to the Logger of type MessageType::Error.
      * @param[in] verbosity The verbosity of this message. Lower is less verbose and thus more likely to be logged, higher is more verbose and less likely to be logged.
      * @param[in] source The source of the message.
      * @param[in] message The message that should be logged.
      * @param[in] arguments Variable number arguments of any type.
      * @tparam Args Variable number of arguments of any type.
      *
      * @remarks The message gets sprintf_s'd using the arguments you supply.
      */
      template<typename ... Args>
      static void Error(unsigned int verbosity, const MessageSource& source, const char* message, Args&&... arguments);

      /**
      * @brief Acts as the defacto way of doing Asserts in blowbox. If the evaluation is false, a debug break is called.
      * @param[in] verbosity The verbosity of this message. Lower is less verbose and thus more likely to be logged, higher is more verbose and less likely to be logged.
      * @param[in] evaluation The evaluation you want to assert to be true.
      * @param[in] message The message that should be logged in case the assert fails..
      * @param[in] arguments Variable number arguments of any type.
      * @tparam Args Variable number of arguments of any type.
      *
      * @remarks The message gets sprintf_s'd using the arguments you supply.
      * @remarks In Release, this function still runs the check, however it does not cause a debug break.
      * @remarks Technically it does not make sense for asserts to have a verbosity level associated with them, since
      *          you will always want an assert to log in case it fails. However, it is possible to set a verbosity
      *          level for an assertion, in case you only want it to log under certain higher levels of verbosity. If
      *          you wish to always log the assert (you probably do!), you should use a verbosity of 0.
      */
      template<typename ... Args>
      static void Assert(unsigned int verbosity, bool evaluation, const char* message, Args&&... arguments);

    private:
      /**
      * @brief Adds a Message of a certain type and certain source.
      * @param[in] verbosity The verbosity of this message. Lower is less verbose and thus more likely to be logged, higher is more verbose and less likely to be logged.
      * @param[in] type The type of message.
      * @param[in] source The source of the message.
      * @param[in] message The message that should be logged.
      * @param[in] arguments Variable number arguments of any type.
      * @tparam Args Variable number of arguments of any type.
      */
      template<typename ... Args>
      static void AddMessage(unsigned int verbosity, const MessageType& type, const MessageSource& source, const char* message, Args&&... arguments);
    };

    //------------------------------------------------------------------------------------------------------
    template<typename ...Args>
    inline void Logger::Log(unsigned int verbosity, const MessageSource& source, const char* message, Args&&... arguments)
    {
      Logger::AddMessage(verbosity, MessageType::Log, source, message, arguments...);
    }

    //------------------------------------------------------------------------------------------------------
    template<typename ...Args>
    inline void Logger::Warn(unsigned int verbosity, const MessageSource& source, const char* message, Args&&... arguments)
    {
      Logger::AddMessage(verbosity, MessageType::Warning, source, message, arguments...);
    }

    //------------------------------------------------------------------------------------------------------
    template<typename ...Args>
    inline void Logger::Error(unsigned int verbosity, const MessageSource& source, const char* message, Args&&... arguments)
    {
      Logger::AddMessage(verbosity, MessageType::Error, source, message, arguments...);
    }

    //------------------------------------------------------------------------------------------------------
    template<typename ... Args>
    inline void Logger::Assert(unsigned int verbosity, bool evaluation, const char* message, Args&&... arguments)
    {
      if (!evaluation)
      {
        Logger::AddMessage(verbosity, MessageType::Assert, MessageSource::Unknown, message, arguments...);

#ifdef _DEBUG
        EASTL_DEBUG_BREAK();
#endif
      }
    }

    //------------------------------------------------------------------------------------------------------
    template<typename ...Args>
    inline void Logger::AddMessage(unsigned int verbosity, const MessageType& type, const MessageSource& source, const char* message, Args&& ...arguments)
    {
      if (verbosity <= verbosity_level)
      {
        Message msg;

        msg.time_stamp = std::chrono::system_clock::now();
        msg.type = type;
        msg.source = source;

        sprintf_s(msg.message, sizeof(Message::message), message, arguments...);

        if (Logger::message_receiver)
        {
          Logger::message_receiver(Logger::message_receiver_userdata, msg);
        }
      }
    }
  }
}