#include <QtTest>

// add necessary includes here

class test : public QObject
{
    Q_OBJECT

public:
    test();
    ~test();

private slots:
    void test_case1();

};

test::test()
{

}

test::~test()
{

}

void test::test_case1()
{
    QString str = "Helli";
    QCOMPARE(str, QString("Hello"));
}

QTEST_APPLESS_MAIN(test)

#include "tst_test.moc"
