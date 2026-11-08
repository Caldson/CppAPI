#include "file_open.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
int openFile(string fileName, string mode, string encoding = "utf-8") {
    string allowed_modes[3] = {"r", "w", "a"};
    string allowed_encodings[2] = {"utf-8", "gb2312"};
    return 0;
}