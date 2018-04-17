#include "logger.h"

namespace blowbox
{
  namespace core
  {
    eastl::function<void(void*, const Message&)> Logger::message_receiver = eastl::function<void(void*, const Message&)>();
    void* Logger::message_receiver_userdata = nullptr;
  }
}