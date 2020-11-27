#ifndef RECHNER_H
#define RECHNER_H

#include <QObject>
//#include <iostream>
#include <string>

class Rechner : public QObject
{
    Q_OBJECT
public:
    std::string term{ "(1.2+2.4)*4.0\n" };
    int position = 0;

    explicit Rechner(QObject *parent = nullptr);
    double calc(QString s);

private:
    double ausdruck(char& c);
    long double zahl(char& c);
    long double faktor(char& c);
    long double summand(char& c);

signals:

};

#endif // RECHNER_H
