#include \"Game_Picture.h\"

Game_Picture::Game_Picture(int pictureId) : _pictureId(pictureId) {
}

Game_Picture::~Game_Picture() {
}

int Game_Picture::pictureId() const {
    return _pictureId;
}

void Game_Picture::show(const QString &name, int origin, int x, int y, int scaleX, 
                       int scaleY, int opacity, int blendMode) {
}

void Game_Picture::move(int duration, int origin, int x, int y, int scaleX, 
                       int scaleY, int opacity, int blendMode) {
}

void Game_Picture::rotate(int speed) {
}

void Game_Picture::tint(int red, int green, int blue, int gray, int duration) {
}

void Game_Picture::erase() {
}

void Game_Picture::update() {
}
