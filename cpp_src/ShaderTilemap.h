#ifndef SHADERTILEMAP_H
#define SHADERTILEMAP_H

class ShaderTilemap {
public:
    ShaderTilemap();
    ~ShaderTilemap();

    void initialize();
    void update();
    void refresh();
    
    void setShaderProgram(const QString &program);

private:
};

#endif // SHADERTILEMAP_H
