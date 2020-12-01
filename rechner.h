#ifndef RECHNER_H
#define RECHNER_H

#include <QObject>
#include <QChar>
#include <QString>
#include <iostream>
/*
 * Diese Klasse berechnet nach dem Prinzip des Rekursiven Abstiegs
 * aus einem Term ein Ergebnis.
 * TODO
 * Dies soll mit allen Zahlensystemen funktionieren. Dabei wird in-
 * tern im Dezimalsystem gerechnet. Vor und nach der Berechnung und
 * zur Ausgabe und bei der Eingabe wird das eigentliche System
 * verwendet und dargestellt.
 *
 * Aufruf: rechner.calc("FF+E1*(9F-3)\n",16);
 */
class Rechner : public QObject
{
    Q_OBJECT
public:
    QString term;
    int position;
    int base;

    explicit Rechner(QObject *parent = nullptr);
    QString calc(QString s, int base = 10);
    QString base2Dec(QString term, int base, bool& ok);

    long test_ausdruck(QString term) {
        this->term = term;
        position = 0;
        QChar ch = this->term.at(position++);
        return ausdruck(ch);
    }

private:
    long ausdruck(QChar& c);
    long zahl(QChar& c);
    long faktor(QChar& c);
    long summand(QChar& c);

signals:

};

#endif // RECHNER_H
