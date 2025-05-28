#ifndef OCEANTHEME_H
#define OCEANTHEME_H
#include <windows.h>

#include "ThemeFactory.h"

class OceanTheme : public ThemeFactory {
public:
    COLORREF getBackgroundColor() override;
    COLORREF getTextColor() override;
    COLORREF getHighlightColor() override;
    COLORREF getFixedNumberColor() override;
    COLORREF getUserNumberColor() override;
};

#endif //OCEANTHEME_H
