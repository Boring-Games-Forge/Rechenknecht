#include "rechner.h"

Rechner::Rechner(QObject *parent) : QObject(parent)
{

}

long double Rechner::zahl(char& c)
{
    long double z{ 0 };
    long double z2{ 0 };
    // isdigit() ist eine Funktion (genauer: ein Makro), das zu true ausgewertet wird,
    // falls c ein Ziffernzeichen ist. Die Verwendung setzt #include <cctype> voraus.
    while (isdigit(c) || c == '.') { // d.h. c >= '0' && c <= '9'
    // Zur Subtraktion von '0' siehe Seite 57.
        if (isdigit(c)) {
            z = 10L * z + double(c - '0'); // implizite Typumwandlung
            c = term.at(position++);
        }
        else {
            c = term.at(position++);
            while (isdigit(c)) {
                z2 = z2 + 1.0/10.0 * double(c- '0');
                c = term.at(position++);
            }
            return z + z2;
        }
    }
    return z + z2;
}

long double Rechner::faktor(char& c)
{
    long double f{ 0 };
    if (c == '(') {
        c = term.at(position++); // ( überspringen
        f = ausdruck(c);
        if (c != ')')
            std::cout << "Rechte Klammer fehlt!\n"; //*** s.u.
        else
            c = term.at(position++); // ) überspringen
    }
    else
        f = zahl(c);
    return f;
}

long double Rechner::summand(char& c)
{
    long double s{ faktor(c) };
    if (c == '*' || c == '/')
        if (c == '*') {
            c = term.at(position++); // * überspringen
            s *= faktor(c);
        }
        else {
            c = term.at(position++); // / überspringen
            s /= faktor(c);
        }
    return s;
}

long double Rechner::ausdruck(char& c) // Übergabe per Referenz!
{
    long double a{ 0 }; // Hilfsvariable für Ausdruck
    if (c == '-') {
        c = term.at(position++); // - im Eingabestrom überspringen
        a = -summand(c); // Rest an summand() übergeben
    }
    else {
        if (c == '+')
            c = term.at(position++); // + überspringen
        a = summand(c);
    }
    if (c == '+' || c == '-') {
        if (c == '+') {
            c = term.at(position++); // + überspringen
            a += summand(c);
        }
        else {
            c = term.at(position++); // - überspringen
            a -= summand(c);
        }
    }
    return a;
}

//int main()
//{
//	char c{'\n'};
//	c = term.at(position++);
//	std::cout << ausdruck(c);
//}
