// Example program

#include <iostream>
#include <process/future.hpp>
#include <process/subprocess.hpp>
#include <string>

using std::endl;
using std::string;
using std::cout;
using namespace process;

/*Future<string> test(const char& **cmd) const {
  Try<Subprocess> s = subprocess(
    join(cmd, " "),
    Subprocess::Path("/dev/null"),
    Subprocess::PIPE(),
    Subprocess::PIPE());

  if (s.isError()) {
    return sprintf("%s returned error: %s", cmd, s.error());
  }

  return s.out().get();
}*/


int main(int argc, char** argv) {
    //string taskId = "redis10.f7d96c4e-4699-11e5-a731-024243951092";

    cout << "TEST";
}
