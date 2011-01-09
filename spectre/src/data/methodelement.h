#ifndef METHODELEMENT_H
#define METHODELEMENT_H

#include "base.h"

class MethodElement: public Base
{
public:
    enum ElementType
    {
        Condition = 0,
        Send,
        Activate,
        None //на всякий случай, хотя в терии нереальный
    };

public:
    MethodElement(const DomElement &domElement = DomElement(), XmlData *xmlData = 0);

    ElementType elementType();
    void setElementType(ElementType type);

    string id() const;
    string method() const;
    string port() const;
    float x() const;
    float y() const;
    string rem() const;

    void setId(string value);
    void setMethod(string value);
    void setPort(string value);
    void setX(float value);
    void setY(float value);
    void setRem(string value);

//    Method parent() const;

    static const string CONDITION_NAME;
    static const string SEND_NAME;
    static const string ACTIVATE_NAME;
    static const string ID;
    static const string METHOD;
    static const string PORT;
    static const string X;
    static const string Y;
    static const string REM;
};

#endif // METHODELEMENT_H
