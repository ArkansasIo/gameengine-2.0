#ifndef QOBJECT_H
#define QOBJECT_H

#include "qstring.h"

#ifndef QOBJECT_CLASS_DEFINED
#define QOBJECT_CLASS_DEFINED
class QObject {
public:
    virtual ~QObject() {}
};
#endif

#endif // QOBJECT_H
