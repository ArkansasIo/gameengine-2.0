#ifndef JSONEX_H
#define JSONEX_H

#include <string>

class JsonEx {
public:
    static int maxDepth;
    
    template<typename T>
    static T makeDeepCopy(const T& object);
    
    template<typename T>
    static std::string stringify(const T& object);
    
    template<typename T>
    static T parse(const std::string& json);
    
private:
    JsonEx() = delete;
};

#endif // JSONEX_H
