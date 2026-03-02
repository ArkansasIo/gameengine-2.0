#ifndef BITMAP_H
#define BITMAP_H

#include <string>
#include <functional>

class Bitmap {
public:
    Bitmap(int width = 0, int height = 0);
    ~Bitmap();
    
    // Properties
    std::string fontFace;
    int fontSize;
    bool fontItalic;
    std::string textColor;
    std::string outlineColor;
    int outlineWidth;
    std::string url;
    int width;
    int height;
    bool smooth;
    int paintOpacity;
    
    // Methods
    bool isReady() const;
    bool isError() const;
    void resize(int width, int height);
    void blt(Bitmap* source, int sx, int sy, int sw, int sh, int dx, int dy, int dw = -1, int dh = -1);
    std::string getPixel(int x, int y) const;
    std::string getAlphaPixel(int x, int y) const;
    void clearRect(int x, int y, int width, int height);
    void clear();
    void fillRect(int x, int y, int width, int height, const std::string& color);
    void fillAll(const std::string& color);
    void gradientFillRect(int x, int y, int width, int height, const std::string& color1, const std::string& color2, bool vertical = false);
    void drawCircle(int x, int y, int radius, const std::string& color);
    void drawText(const std::string& text, int x, int y, int maxWidth, int lineHeight, const std::string& align = "left");
    int measureTextWidth(const std::string& text) const;
    void adjustTone(int r, int g, int b);
    void rotateHue(int offset);
    void blur();
    void addLoadListener(std::function<void(Bitmap*)> listener);
    void touch();
    
    static Bitmap* load(const std::string& url);
    
private:
    bool _ready;
    bool _error;
};

#endif // BITMAP_H
