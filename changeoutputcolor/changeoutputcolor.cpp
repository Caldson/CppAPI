#include "changeoutputcolor.h"
#include <map>
#include <algorithm>
#include <cctype>
#include <stdexcept>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

/* ---------- int version (core logic) ---------- */
int changeOutputColor(int ColorHex) {
    SetConsoleTextAttribute(hConsole, ColorHex);
    return 0;
}

/* ---------- string version (wrapper + map) ---------- */
int changeOutputColor(string ColorName) {
    // to lower (C++98 compatible)
    for (string::iterator it = ColorName.begin(); it != ColorName.end(); ++it) {
        *it = tolower((unsigned char)*it);
    }

    // color map (C++98 constructor style)
    map<string, int> colorMap;
    colorMap["black"]       = 0;
    colorMap["blue"]        = 1;
    colorMap["green"]       = 2;
    colorMap["cyan"]        = 3;
    colorMap["red"]         = 4;
    colorMap["purple"]      = 5;
    colorMap["yellow"]      = 6;
    colorMap["grey"]        = 7;
    colorMap["gray"]        = 7;

    colorMap["darkgray"]    = 8;
    colorMap["darkgrey"]    = 8;
    colorMap["lightblue"]   = 9;
    colorMap["lightgreen"]  = 10;
    colorMap["lightcyan"]   = 11;
    colorMap["lightred"]    = 12;
    colorMap["lightpurple"] = 13;
    colorMap["lightyellow"] = 14;
    colorMap["lightgray"]   = 15;
    colorMap["lightgrey"]   = 15;
    colorMap["white"]       = 15;

    map<string, int>::const_iterator it = colorMap.find(ColorName);
    if (it != colorMap.end()) {
        // reuse int version (downward compatible core)
        return changeOutputColor(it->second);
    }

    // not found
    changeOutputColor(7); // reset to default
    throw runtime_error("This color isn't in the map!");
}
