#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <string>

class Graphics {
public:
    static int frameCount;
    static const int BLEND_NORMAL = 0;
    static const int BLEND_ADD = 1;
    static const int BLEND_MULTIPLY = 2;
    static const int BLEND_SCREEN = 3;
    
    static int width;
    static int height;
    static int boxWidth;
    static int boxHeight;
    static double scale;
    
    static void initialize(int width = 816, int height = 624, const std::string& type = "auto");
    static void tickStart();
    static void tickEnd();
    static void render();
    static bool isWebGL();
    static bool hasWebGL();
    static bool canUseDifferenceBlend();
    static bool canUseSaturationBlend();
    static void setLoadingImage(const std::string& src);
    static void startLoading();
    static void updateLoading();
    static void endLoading();
    static void printError(const std::string& name, const std::string& message);
    static void showFps();
    static void hideFps();
    static void loadFont(const std::string& name, const std::string& url);
    static bool isFontLoaded(const std::string& name);
    static void playVideo(const std::string& src);
    static bool isVideoPlaying();
    static bool canPlayVideoType(const std::string& type);
    static double pageToCanvasX(double x);
    static double pageToCanvasY(double y);
    static bool isInsideCanvas(double x, double y);
    static void callGC();
    
private:
    Graphics() = delete;
};

#endif // GRAPHICS_H
