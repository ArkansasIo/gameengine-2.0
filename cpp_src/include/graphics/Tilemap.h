#ifndef TILEMAP_H
#define TILEMAP_H

#include "../graphics/Sprite.h"
#include "../core/GameMap.h"

namespace LunaLite {
namespace Graphics {

class Tilemap : public Sprite {
public:
    Tilemap(Core::GameMap* gameMap = nullptr);
    virtual ~Tilemap();
    
    // Map reference
    Core::GameMap* getGameMap() const;
    void setGameMap(Core::GameMap* gameMap);
    
    // Layer control
    int getLayerCount() const;
    bool isLayerVisible(int layer) const;
    void setLayerVisible(int layer, bool visible);
    
    // Tileset
    int getTilesetId() const;
    void setTilesetId(int id);
    
    // Position offset (for scrolling)
    float getScrollX() const;
    float getScrollY() const;
    void setScroll(float x, float y);
    void scroll(float dx, float dy);
    
    // Viewport
    int getViewportX() const;
    int getViewportY() const;
    int getViewportWidth() const;
    int getViewportHeight() const;
    
    virtual void update() override;
    
private:
    Core::GameMap* _gameMap;
    int _tilesetId;
    float _scrollX, _scrollY;
    bool _layerVisible[4];  // Typically 4 layers
};

} // namespace Graphics
} // namespace LunaLite

#endif // TILEMAP_H
