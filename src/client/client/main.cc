#include "client/client_runtime.h"

using namespace blowbox;

int main(int argc, char** argv)
{
  client::ClientRuntime client(argc, argv);

  client.Run();
  
  return 0;
}