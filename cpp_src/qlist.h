#ifndef QLIST_H
#define QLIST_H

#include <vector>
#include <algorithm>

template<typename T>
class QList : public std::vector<T> {
public:
    void append(const T& t) { this->push_back(t); }
    int size() const { return (int)std::vector<T>::size(); }
    int count() const { return (int)std::vector<T>::size(); }
    bool isEmpty() const { return this->empty(); }
    bool contains(const T& value) const {
        return std::find(this->begin(), this->end(), value) != this->end();
    }
    int indexOf(const T& value) const {
        auto it = std::find(this->begin(), this->end(), value);
        if (it == this->end()) {
            return -1;
        }
        return (int)std::distance(this->begin(), it);
    }
    void removeAt(int index) {
        if (index >= 0 && index < size()) {
            this->erase(this->begin() + index);
        }
    }
    int removeAll(const T& value) {
        const auto oldSize = this->size();
        this->erase(std::remove(this->begin(), this->end(), value), this->end());
        return (int)(oldSize - this->size());
    }
    T& first() { return this->front(); }
    const T& first() const { return this->front(); }
    T& last() { return this->back(); }
    const T& last() const { return this->back(); }
};

#endif // QLIST_H
