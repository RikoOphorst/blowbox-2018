#pragma once

namespace blowbox
{
  namespace core
  {
    class Core
    {
    protected:
      Core();
      ~Core();

    public:
      static Core* Instance();

    private:

    };
  }
}