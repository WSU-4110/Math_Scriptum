#include <QtTest>
#include <math.h>

// add necessary includes here

class test : public QObject
{
    Q_OBJECT

public:
    test();
    ~test();

private slots:
    void test_case1();
    void test_case2();
    void test_case3();
    void test_case4();
    void test_case5();

};

test::test()
{

}

test::~test()
{

}

void test::test_case1()
{
    float t= 0;
    float slope = -1.0;
    float yIntercept = 0;
    float x = t;
    float y = slope * x + yIntercept;
    QCOMPARE(x,y);
}

void test::test_case2()
{
    float t = 5;
    float x = t;
    float y = x * x;
    QCOMPARE(pow(x,2),y);

}
void test::test_case3()
{
    float t = 9;
    float x = t;
    float y = sqrt(x);
    QCOMPARE(3,y);
}

void test::test_case4()
{
    float t = 10;
    float x = t;
    float y = 1/x;

    QVERIFY(y == 1/x);
}

void test::test_case5()
{
float t = 7;
float x = t;
    QVERIFY(t == x);
}

QTEST_APPLESS_MAIN(test)

#include "tst_test.moc"
