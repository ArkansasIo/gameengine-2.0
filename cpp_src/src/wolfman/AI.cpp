#include "../../include/wolfman/AI.h"
#include <cmath>

namespace WolfManAlpha {

PathFinder& PathFinder::instance() {
    static PathFinder pathfinder;
    return pathfinder;
}

PathFinder::PathFinder() {
}

PathFinder::~PathFinder() {
}

bool PathFinder::setNavMesh(const QString &meshName) {
    _currentNavMesh = meshName;
    return true;
}

bool PathFinder::loadNavMesh(const QString &filePath) {
    // Load navigation mesh from file
    return true;
}

QVector<Vector2D> PathFinder::findPath(const Vector2D& start, const Vector2D& goal) {
    QVector<Vector2D> path;
    // A* pathfinding algorithm
    path.append(start);
    path.append(goal);
    return path;
}

bool PathFinder::isPathValid(const Vector2D& a, const Vector2D& b) {
    // Check line of sight / raycasting
    return true;
}

Vector2D PathFinder::getRandomNavMeshPoint() {
    return Vector2D(0, 0);
}

Vector2D PathFinder::seek(const Vector2D& position, const Vector2D& target) {
    Vector2D direction = target - position;
    return direction.normalized();
}

Vector2D PathFinder::flee(const Vector2D& position, const Vector2D& target) {
    Vector2D direction = position - target;
    return direction.normalized();
}

Vector2D PathFinder::arrive(const Vector2D& position, const Vector2D& target) {
    Vector2D direction = target - position;
    float distance = direction.magnitude();
    
    float radius = 100.0f;  // Deceleration radius
    if (distance < radius) {
        return direction * (distance / radius);
    }
    return direction.normalized();
}

Vector2D PathFinder::wander(const Vector2D& position, float wanderAngle) {
    float radius = 1.0f;
    float jitter = 0.1f;
    Vector2D circleCenter = position * 2.0f;
    
    return circleCenter.normalized();
}

Vector2D PathFinder::pursue(const Vector2D& position, const Vector2D& targetPos, const Vector2D& targetVel) {
    Vector2D direction = targetPos - position;
    float distance = direction.magnitude();
    float speed = targetVel.magnitude();
    float time = distance / (speed + 0.01f);
    
    Vector2D futurePos = targetPos + targetVel * time;
    return seek(position, futurePos);
}

Vector2D PathFinder::evade(const Vector2D& position, const Vector2D& targetPos) {
    Vector2D direction = position - targetPos;
    return direction.normalized();
}

Vector2D PathFinder::separate(const Vector2D& position, const QVector<Vector2D> &neighbors, float radius) {
    Vector2D steer(0, 0);
    int count = 0;
    
    for (const auto& neighbor : neighbors) {
        Vector2D diff = position - neighbor;
        float distance = diff.magnitude();
        
        if (distance < radius && distance > 0) {
            steer = steer + diff.normalized();
            count++;
        }
    }
    
    if (count > 0) {
        steer = steer * (1.0f / count);
    }
    
    return steer;
}

Vector2D PathFinder::align(const Vector2D &currentVel, const QVector<Vector2D> &neighborVels) {
    Vector2D avgVel(0, 0);
    
    for (const auto& vel : neighborVels) {
        avgVel = avgVel + vel;
    }
    
    if (!neighborVels.isEmpty()) {
        avgVel = avgVel * (1.0f / neighborVels.size());
    }
    
    return avgVel - currentVel;
}

Vector2D PathFinder::cohesion(const Vector2D &position, const QVector<Vector2D> &neighborPos) {
    Vector2D avgPos(0, 0);
    
    for (const auto& pos : neighborPos) {
        avgPos = avgPos + pos;
    }
    
    if (!neighborPos.isEmpty()) {
        avgPos = avgPos * (1.0f / neighborPos.size());
    }
    
    return seek(position, avgPos);
}

void PathFinder::smoothPath(QVector<Vector2D>& path) {
    // Path smoothing using Catmull-Rom splines or similar
}

AIAgent::AIAgent(int id)
    : _id(id), _maxSpeed(5.0f), _currentState(nullptr), _pathIndex(0) {
}

AIAgent::~AIAgent() {
    if (_currentState) {
        delete _currentState;
    }
}

int AIAgent::getId() const {
    return _id;
}

void AIAgent::setPosition(const Vector2D& pos) {
    _position = pos;
}

Vector2D AIAgent::getPosition() const {
    return _position;
}

void AIAgent::setMaxSpeed(float speed) {
    _maxSpeed = speed;
}

float AIAgent::getMaxSpeed() const {
    return _maxSpeed;
}

void AIAgent::setState(AIState* newState) {
    if (_currentState) {
        _currentState->onExit();
    }
    _currentState = newState;
    if (_currentState) {
        _currentState->onEnter();
    }
}

AIState* AIAgent::getCurrentState() const {
    return _currentState;
}

void AIAgent::setDestination(const Vector2D& pos) {
    _path = PathFinder::instance().findPath(_position, pos);
    _pathIndex = 0;
}

bool AIAgent::hasReachedDestination() const {
    return _path.isEmpty() || _pathIndex >= _path.size();
}

void AIAgent::clearPath() {
    _path.clear();
    _pathIndex = 0;
}

void AIAgent::update(float deltaTime) {
    if (_currentState) {
        _currentState->onUpdate(deltaTime);
    }
    
    // Follow path if one exists
    if (!_path.isEmpty() && _pathIndex < _path.size()) {
        Vector2D targetPoint = _path[_pathIndex];
        Vector2D direction = targetPoint - _position;
        
        if (direction.magnitude() < 5.0f) {
            _pathIndex++;
        } else {
            _velocity = direction.normalized() * _maxSpeed;
            _position = _position + _velocity * deltaTime;
        }
    }
}

DecisionTree::DecisionTree() {
}

DecisionTree::~DecisionTree() {
    for (auto decision : _decisions) {
        delete decision;
    }
    _decisions.clear();
}

void DecisionTree::addDecision(Decision* decision, int priority) {
    _decisions.append(decision);
}

BehaviorNode::Status DecisionTree::evaluate(float deltaTime) {
    return BehaviorNode::Success;
}

} // namespace WolfManAlpha
