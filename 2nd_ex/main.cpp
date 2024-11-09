#include "menu.h"

using namespace std;

int main(int argc, char **argv) {
  try {
    if (argc != 5 || string(argv[1]) != "--file" ||
        string(argv[3]) != "--query") {
      throw runtime_error(
          "Err: use pattern: program --file <filename> --query <query>");
    }

    menu(argv[2], argv[4]);
  } catch (const exception &e) {
    cerr << e.what() << endl;
  }

  return 0;
}
