#include <QtTest>
#include <QRandomGenerator>
#include <limits>

// add necessary includes here
#include "../rechner.h"

class RechnerTest : public QObject
{
    Q_OBJECT

public:
    RechnerTest();
    ~RechnerTest();

    Rechner *r;

private slots:
    void arith_rand();
    void arith_rand_data();
    void arith_rand2();
    void arith_rand2_data();
    void arith_spz();

    void ausdruck_rand();
    void ausdruck_rand_data();
};

RechnerTest::RechnerTest()
{
    r = new Rechner();
}

RechnerTest::~RechnerTest()
{
    delete r;
}

// Datenfunktionen
void RechnerTest::arith_rand_data()
{
    QTest::addColumn<QString>("string");
    QTest::addColumn<QString>("result");
    //QTest::newRow("1") << r->calc("9999+1") << QString("%1").arg(9999 + 1);
    //QTest::newRow("2") << r->calc("0") << QString("%1").arg(0);
    int rnd;
    QString s1,s2,s3,s4;
    for (int i = 0; i < 100; i++){
        rnd =QRandomGenerator::global()->bounded(-10000,10000);
        s1 = QString("(%1)+(%2)\n").arg(rnd).arg(rnd);
        s2 = QString("(%1)-(%2)\n").arg(rnd).arg(rnd);
        s3 = QString("(%1)/(%2)\n").arg(rnd).arg(rnd);
        s4 = QString("(%1)*(%2)\n").arg(rnd).arg(rnd);
        QTest::newRow(s1.toLatin1().data()) << s1 << QString("%1").arg(rnd+rnd);
        QTest::newRow(s2.toLatin1().data()) << s2 << QString("%1").arg(rnd-rnd);
        QTest::newRow(s3.toLatin1().data()) << s3 << QString("%1").arg(rnd/rnd);
        QTest::newRow(s4.toLatin1().data()) << s4 << QString("%1").arg(rnd*rnd);
    }
}

void RechnerTest::arith_rand2_data()
{

    QTest::addColumn<QString>("string");
    QTest::addColumn<QString>("result");

    //QTest::newRow("1") << r->calc("9999+1") << QString("%1").arg(9999 + 1);
    //QTest::newRow("2") << r->calc("0") << QString("%1").arg(0);
    int rnd;
    QString s1,s2,s3,s4;
    for (int i = 0; i < 100; i++){
        rnd =QRandomGenerator::global()->bounded(-10000,10000);
        s1 = QString("%1+%2\n").arg(rnd,0,2).arg(rnd,0,2);
        s2 = QString("%1-%2\n").arg(rnd,0,2).arg(rnd,0,2);
        s3 = QString("%1/%2\n").arg(rnd,0,2).arg(rnd,0,2);
        s4 = QString("%1*%2\n").arg(rnd,0,2).arg(rnd,0,2);
        QTest::newRow(s1.toLatin1().data()) << s1 << QString("%1").arg((rnd+rnd),0,2);
        QTest::newRow(s2.toLatin1().data()) << s2 << QString("%1").arg((rnd-rnd),0,2);
        QTest::newRow(s3.toLatin1().data()) << s3 << QString("%1").arg((rnd/rnd),0,2);
        QTest::newRow(s4.toLatin1().data()) << s4 << QString("%1").arg((rnd*rnd),0,2);
    }
}

void RechnerTest::ausdruck_rand_data()
{
    QTest::addColumn<QString>("string");
    QTest::addColumn<int>("result");

    //QTest::newRow("1") << r->calc("9999+1") << QString("%1").arg(9999 + 1);
    //QTest::newRow("2") << r->calc("0") << QString("%1").arg(0);
    int rnd;
    QString s;
    for (int i = 0; i < 100; i++){
        rnd =QRandomGenerator::global()->bounded(0,10000);
        s = QString("%1").arg(rnd);

        QTest::newRow(("+ " + s).toLatin1().data()) << QString("(" + s + ")" + "+" + "(" + s + ")" ) << rnd+rnd;
        QTest::newRow(("- " + s).toLatin1().data()) << QString("(" + s + ")" + "-" + "(" + s + ")" ) << rnd-rnd;
        QTest::newRow(("/ " + s).toLatin1().data()) << QString("(" + s + ")" + "/" + "(" + s + ")" ) << rnd/rnd;
        QTest::newRow(("* " + s).toLatin1().data()) << QString("(" + s + ")" + "*" + "(" + s + ")" ) << rnd*rnd;
    }
}

// Randomisierte Testreihen:

// Prüft 'ausdruck(QChar )' über den Wrapper 'test_ausdruck(QString )'
void RechnerTest::ausdruck_rand()
{
    QSKIP("");
    QFETCH(QString, string);
    QFETCH(int, result);
    QCOMPARE(r->test_ausdruck(string + "\n"), result);
}


// Arithmetische Operationen +-'/
void RechnerTest::arith_rand()
{
    //QSKIP("");

    QFETCH(QString, string);
    QFETCH(QString, result);
    QCOMPARE(r->calc(string), result);
}

void RechnerTest::arith_rand2()
{
    //QSKIP("");

    QFETCH(QString, string);
    QFETCH(QString, result);
    QCOMPARE(r->calc(string, 2), result);
}

// Arithmetische Operationen, besondere Fälle
void RechnerTest::arith_spz() {

    //QSKIP("");

    QString s;
    s = QString("%1").arg(0x0, 0, 16);
    QCOMPARE(r->calc("0", 16), s);

    s = QString("%1").arg(0, 0 ,8);
    QCOMPARE(r->calc("0", 8), s);

    s = QString("%1").arg(0, 0 ,2);
    QCOMPARE(r->calc("0", 2), s);

    s = QString("%1").arg(0);
    QCOMPARE(r->calc("0"), s);

    s = QString("%1").arg(-1 + 1);
    QCOMPARE(r->calc("-1+1"), s);

    s = QString("%1").arg(-1 + 1);
    QCOMPARE(r->calc("-1+1"), s);

    s = QString("%1").arg(-1 + 10, 0, 2);
    QCOMPARE(r->calc("-1+10", 2), s);

    s = QString("%1").arg(-1 + 11, 0, 2);
    QCOMPARE(r->calc("-1+11", 2), s);

    s = QString("%1").arg(-0x1F + 1, 0, 16);
    QCOMPARE(r->calc("-1F+1", 16), s);

    s = QString("%1").arg(07 + 1, 0, 8);
    QCOMPARE(r->calc("7+1",8), s);
}

QTEST_MAIN(RechnerTest)

#include "tst_rechner.moc"
