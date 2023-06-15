#include <iostream>
using namespace std;
#include "Reader.h"
#include <string>
#include "Apartments.h"
int main(int argc, char *argv[]) {
    Reader::reader(argv[1], argv[2]);
    return 0;
}
