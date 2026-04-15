#include "ColorData.h"

std::string RenderColorToString(RenderColor color) {
    switch (color) {
    case normal:       return RESET;
    case black:        return BLACK;
    case red:          return RED;
    case green:        return GREEN;
    case yellow:       return YELLOW;
    case blue:         return BLUE;
    case magenta:      return MAGENTA;
    case cyan:         return CYAN;
    case white:        return WHITE;
    case bold_black:   return BOLDBLACK;
    case bold_red:     return BOLDRED;
    case bold_green:   return BOLDGREEN;
    case bold_yellow:  return BOLDYELLOW;
    case bold_blue:    return BOLDBLUE;
    case bold_magenta: return BOLDMAGENTA;
    case bold_cyan:    return BOLDCYAN;
    case bold_white:   return BOLDWHITE;
    default:           return RESET;
    }
}
