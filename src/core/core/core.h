#pragma once

namespace blowbox
{
  namespace core
  {
    class Core
    {
    public:
      Core(int argc, char** argv);
      ~Core();

      static Core* Instance();
    private:
      static Core* instance_;
    };
  }
}