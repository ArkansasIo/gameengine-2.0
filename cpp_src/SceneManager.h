#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

class Scene;

class SceneManager {
public:
    static void run();
    static void initialize();
    static void initGraphics();
    static void initAudio();
    static void initInput();
    static void initNwjs();
    static void checkBrowser();
    static void checkPluginErrors();
    static void setupErrorHandlers();
    static void requestUpdate();
    static void update();
    static void terminate();
    static void onError(const char* error);
    static void onKeyDown(int event);
    static void catchException(const char* error);
    static void updateInputData();
    static void updateMain();
    static void changeScene();
    static void updateScene();
    static void renderScene();
    static void onSceneCreate();
    static void onSceneStart();
    static void onSceneLoading();
    static bool isSceneChanging();
    static bool isCurrentSceneBusy();
    static bool isCurrentSceneStarted();
    static bool isNextScene(Scene* sceneClass);
    static void goto_(Scene* sceneClass);
    static void push(Scene* sceneClass);
    static void pop();
    static void exit();
    static void clearStack();
    static void stop();
    static void prepareNextScene();
    static void snap();
    static void snapForBackground();
    static void backgroundBitmap();
    
private:
    SceneManager() = delete;
    static Scene* _scene;
    static Scene* _nextScene;
    static bool _sceneStarted;
    static bool _exiting;
    static bool _previousClass;
    static bool _backgroundBitmap;
    static int _screenWidth;
    static int _screenHeight;
    static int _boxWidth;
    static int _boxHeight;
    static int _deltaTime;
    static long long _currentTime;
    static long long _accumulator;
};

class Scene {
public:
    virtual ~Scene() {}
    virtual void create() = 0;
    virtual void start() = 0;
    virtual void update() = 0;
    virtual void stop() = 0;
    virtual void terminate() = 0;
    virtual bool isReady() = 0;
    virtual bool isBusy() = 0;
};

#endif // SCENE_MANAGER_H
