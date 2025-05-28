#ifndef LIGHTTHEME_H
#define LIGHTTHEME_H
#include "DarkTheme.h"
#include "ThemeFactory.h"

class LightTheme : public ThemeFactory {
public:
    COLORREF getBackgroundColor() override { return RGB(255, 255, 255); }
    COLORREF getTextColor() override { return RGB(0, 0, 0); }
    COLORREF getHighlightColor() override { return RGB(173, 216, 230); }
    COLORREF getFixedNumberColor() override { return RGB(0, 0, 139); }
    COLORREF getUserNumberColor() override { return RGB(0, 100, 0); }
};


#endif //LIGHTTHEME_H
