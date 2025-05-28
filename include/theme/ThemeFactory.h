#ifndef THEMEFACTORY_H
#define THEMEFACTORY_H

class ThemeFactory {
public:
    virtual COLORREF getBackgroundColor() = 0;
    virtual COLORREF getTextColor() = 0;
    virtual COLORREF getHighlightColor() = 0;
    virtual COLORREF getFixedNumberColor() = 0;
    virtual COLORREF getUserNumberColor() = 0;
    virtual ~ThemeFactory() {}
};

#endif //THEMEFACTORY_H
