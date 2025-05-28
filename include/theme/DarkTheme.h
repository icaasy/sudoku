#ifndef DARKTHEME_H
#define DARKTHEME_H
#include "OceanTheme.h"
#include "ThemeFactory.h"

class DarkTheme : public ThemeFactory {
public:
    COLORREF getBackgroundColor() override;
    COLORREF getTextColor() override;
    COLORREF getHighlightColor() override;
    COLORREF getFixedNumberColor() override;
    COLORREF getUserNumberColor() override;
};

#endif //DARKTHEME_H
