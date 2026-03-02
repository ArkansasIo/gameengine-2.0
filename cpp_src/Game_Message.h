#ifndef GAME_MESSAGE_H
#define GAME_MESSAGE_H

#include <string>
#include <vector>
#include <functional>

class Game_Message {
public:
    Game_Message();
    ~Game_Message();
    
    void initialize();
    void clear();
    std::vector<std::string> texts() const;
    std::vector<std::string> choices() const;
    std::string faceName() const;
    int faceIndex() const;
    int background() const;
    int positionType() const;
    void add(const std::string& text);
    void setFaceImage(const std::string& faceName, int faceIndex);
    void setBackground(int background);
    void setPositionType(int positionType);
    void setChoices(const std::vector<std::string>& choices, int defaultType, int cancelType);
    int choiceDefaultType() const;
    int choiceCancelType() const;
    void setChoiceBackground(int background);
    void setChoicePositionType(int positionType);
    int choiceBackground() const;
    int choicePositionType() const;
    void setNumberInput(int variableId, int maxDigits);
    int numInputVariableId() const;
    int numInputMaxDigits() const;
    void setItemChoice(int variableId, int itemType);
    int itemChoiceVariableId() const;
    int itemChoiceItypeId() const;
    void setScroll(int speed, bool noFast);
    int scrollSpeed() const;
    bool scrollNoFast() const;
    int choiceCallback() const;
    bool isBusy() const;
    bool isChoice() const;
    bool isNumberInput() const;
    bool isItemChoice() const;
    bool hasText() const;
    void newPage();
    std::vector<std::string> allText() const;
    
private:
    std::vector<std::string> _texts;
    std::vector<std::string> _choices;
    std::string _faceName;
    int _faceIndex;
    int _background;
    int _positionType;
    int _choiceDefaultType;
    int _choiceCancelType;
    int _choiceBackground;
    int _choicePositionType;
    int _numInputVariableId;
    int _numInputMaxDigits;
    int _itemChoiceVariableId;
    int _itemChoiceItypeId;
    int _scrollSpeed;
    bool _scrollNoFast;
};

#endif // GAME_MESSAGE_H
