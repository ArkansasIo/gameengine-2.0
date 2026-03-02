#include "Game_Message.h"

Game_Message::Game_Message() 
    : _faceIndex(0), _background(0), _positionType(2),
      _choiceDefaultType(0), _choiceCancelType(0),
      _choiceBackground(0), _choicePositionType(2),
      _numInputVariableId(0), _numInputMaxDigits(0),
      _itemChoiceVariableId(0), _itemChoiceItypeId(0),
      _scrollSpeed(2), _scrollNoFast(false) {
}

Game_Message::~Game_Message() {
}

void Game_Message::initialize() {
    clear();
}

void Game_Message::clear() {
    _texts.clear();
    _choices.clear();
    _faceName = "";
    _faceIndex = 0;
    _background = 0;
    _positionType = 2;
    _choiceDefaultType = 0;
    _choiceCancelType = 0;
    _choiceBackground = 0;
    _choicePositionType = 2;
    _numInputVariableId = 0;
    _numInputMaxDigits = 0;
    _itemChoiceVariableId = 0;
    _itemChoiceItypeId = 0;
    _scrollSpeed = 2;
    _scrollNoFast = false;
}

std::vector<std::string> Game_Message::texts() const {
    return _texts;
}

std::vector<std::string> Game_Message::choices() const {
    return _choices;
}

std::string Game_Message::faceName() const {
    return _faceName;
}

int Game_Message::faceIndex() const {
    return _faceIndex;
}

int Game_Message::background() const {
    return _background;
}

int Game_Message::positionType() const {
    return _positionType;
}

void Game_Message::add(const std::string& text) {
    _texts.push_back(text);
}

void Game_Message::setFaceImage(const std::string& faceName, int faceIndex) {
    _faceName = faceName;
    _faceIndex = faceIndex;
}

void Game_Message::setBackground(int background) {
    _background = background;
}

void Game_Message::setPositionType(int positionType) {
    _positionType = positionType;
}

void Game_Message::setChoices(const std::vector<std::string>& choices, int defaultType, int cancelType) {
    _choices = choices;
    _choiceDefaultType = defaultType;
    _choiceCancelType = cancelType;
}

int Game_Message::choiceDefaultType() const {
    return _choiceDefaultType;
}

int Game_Message::choiceCancelType() const {
    return _choiceCancelType;
}

void Game_Message::setChoiceBackground(int background) {
    _choiceBackground = background;
}

void Game_Message::setChoicePositionType(int positionType) {
    _choicePositionType = positionType;
}

int Game_Message::choiceBackground() const {
    return _choiceBackground;
}

int Game_Message::choicePositionType() const {
    return _choicePositionType;
}

void Game_Message::setNumberInput(int variableId, int maxDigits) {
    _numInputVariableId = variableId;
    _numInputMaxDigits = maxDigits;
}

int Game_Message::numInputVariableId() const {
    return _numInputVariableId;
}

int Game_Message::numInputMaxDigits() const {
    return _numInputMaxDigits;
}

void Game_Message::setItemChoice(int variableId, int itemType) {
    _itemChoiceVariableId = variableId;
    _itemChoiceItypeId = itemType;
}

int Game_Message::itemChoiceVariableId() const {
    return _itemChoiceVariableId;
}

int Game_Message::itemChoiceItypeId() const {
    return _itemChoiceItypeId;
}

void Game_Message::setScroll(int speed, bool noFast) {
    _scrollSpeed = speed;
    _scrollNoFast = noFast;
}

int Game_Message::scrollSpeed() const {
    return _scrollSpeed;
}

bool Game_Message::scrollNoFast() const {
    return _scrollNoFast;
}

int Game_Message::choiceCallback() const {
    return 0;
}

bool Game_Message::isBusy() const {
    return hasText() || isChoice() || isNumberInput() || isItemChoice();
}

bool Game_Message::isChoice() const {
    return !_choices.empty();
}

bool Game_Message::isNumberInput() const {
    return _numInputVariableId > 0;
}

bool Game_Message::isItemChoice() const {
    return _itemChoiceVariableId > 0;
}

bool Game_Message::hasText() const {
    return !_texts.empty();
}

void Game_Message::newPage() {
    if (!_texts.empty()) {
        _texts.back() += "\f";
    }
}

std::vector<std::string> Game_Message::allText() const {
    return _texts;
}
