#include <QApplication>
#include "APIGUIWindow.h"

/**
 * @file main.cpp
 * @brief Entry point for the LunaLite API GUI Desktop Application
 */

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    
    // Set application properties
    app.setApplicationName("LunaLite API Reference");
    app.setApplicationVersion("1.0.0");
    app.setApplicationDisplayName("LunaLite API Reference - RPG Maker MZ & MV");
    
    // Create and show main window
    APIGUIWindow window;
    window.show();
    
    return app.exec();
}
