#include <QtTest>

// add necessary includes here
#include "../rechner.h"

class Rechnertest : public QObject
{
    Q_OBJECT

public:
    Rechnertest();
    ~Rechnertest();

    Rechner *r;

private slots:
    void test_case1();

};

Rechnertest::Rechnertest()
{
    r = new Rechner();
}

Rechnertest::~Rechnertest()
{
    delete r;
}

void Rechnertest::test_case1()
{
    QString s = QString("%1").arg(9999 + 1);
    QCOMPARE(r->calc("9999+1"), s);

    s = QString("%1").arg(0xF + 1, 0, 16);
    QCOMPARE(r->calc("F+1", 16), s);

    s = QString("%1").arg(0xFFF + 1, 0 ,16);
    QCOMPARE(r->calc("FFF+1", 16), s);

    s = QString("%1").arg(1 + 1, 0 ,2);
    QCOMPARE(r->calc("1+1", 2), s);

    s = QString("%1").arg(0);
    QCOMPARE(r->calc("0"), s);

    s = QString("%1").arg(-1 + 1);
    QCOMPARE(r->calc("-1+1"), s);

    s = QString("%1").arg(-1 + 1);
    QCOMPARE(r->calc("-1+2"), s);

    s = QString("%1").arg(-1 + 1, 0, 2);
    QCOMPARE(r->calc("-1+10", 2), s);

    s = QString("%1").arg(-0x1F + 1, 0, 16);
    QCOMPARE(r->calc("-1F+1", 16), s);

    s = QString("%1").arg(07 + 1, 0, 8);
    QCOMPARE(r->calc("7+1",8), s);
}

QTEST_APPLESS_MAIN(Rechnertest)

#include "tst_rechner.moc"
