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
        if (c != ')'){
            //std::cout << "Rechte Klammer fehlt!\n"; //*** s.u.
        }
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
    if (c == '*' || c == '/') {
        if (c == '*') {
            c = term.at(position++); // * überspringen
            s *= faktor(c);
        }
        else {
            c = term.at(position++); // / überspringen
            s /= faktor(c);
        }
    }
    return s;
}

double Rechner::ausdruck(char& c) // Übergabe per Referenz!
{
    double a{ 0 }; // Hilfsvariable für Ausdruck
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

QString Rechner::calc(QString s, int base) {
    char c;
    position = 0;

    QString term_as_str = s;//ui->lineEdit->text();

    QString term_as_new_str;
    QString result_as_str;
    int result_as_int;
    bool ok;
    QString zahl;
    int zahl_as_int;

    QStringList zahlen_liste = term_as_str.split(QRegExp("\\W"));
        // binaer in dezimal...
        for (int i = 0; i < zahlen_liste.length(); i++) {
            zahl = zahlen_liste[i];
            zahl_as_int = zahl.toInt(&ok, base);
            zahlen_liste[i] = QString::number(zahl_as_int);
        }
    int l = 0;
    int j = 0;
    int o = 0;
    char ch = '\0';
    term_as_new_str = term_as_str;
    for (int i = 0; i < term_as_str.length(); i++) {
        j = 0;
        ch = term_as_str.at(i).toLatin1();
        if (isdigit(ch) || ch == 'A' || ch == 'B' || ch =='C' || ch == 'D' || ch == 'E' || ch == 'F' ) {
            l++;
        } else {
            term_as_new_str = term_as_new_str.replace(i-l, l, zahlen_liste[o++]);
            l = 0;
        }
    }
    this->term = term_as_new_str.toStdString() + "\n";
    c = this->term.at(this->position++);
    result_as_int = (int)round(ausdruck(c));
    result_as_str = QString("%1").arg(result_as_int,0, base);
    return result_as_str;
}




