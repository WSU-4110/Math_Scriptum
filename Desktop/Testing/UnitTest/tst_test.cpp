#include <QtTest>
#include <QtTest/QtTest>
#include <QLine>

// add necessary includes here

class test : public QObject
{
    Q_OBJECT

public:
    test();
    ~test();

private slots:
    void test_Shape10();
    void test_Shape12();
    void test_Shape11();
    void testHex();
    void testLines();

};

test::test()
{

}

test::~test()
{

}

void test::test_Shape10()
{

    float t = 0;
    float cos_t = cos(t);
    float sin_t = sin(t);
    float x = 6 * cos_t * cos_t * cos_t * cos_t;
    float y = 6 * sin_t * sin_t * sin_t * sin_t;
    QVERIFY2(cos_t > sin_t, "SINE is smaller then COSINE");
}

void test::test_Shape11()
{
    float t = 0;
    float vertex = 15;
    float secondVertex = 4;

    float x = vertex * cos (t) - secondVertex * cos (vertex / secondVertex * t);
    float y = vertex * sin (t) - secondVertex * sin (vertex / secondVertex * t);
    QCOMPARE(1, cos(t));


}

void test::test_Shape12()
{
    float t = 0.8490238;
    float t1 = 9;
    float t2 = 4;
    float t3 = 9;

    float x = (t1 - t2) * cos (t) + t3 * cos (t * ((t1 - t2) / t2));
    float y = (t1 - t2) * sin (t) - t3 * sin (t * ((t1 - t2) / t2));
    QTRY_VERIFY2_WITH_TIMEOUT(x > sin(t),"SHOULD BE UNDER 4MS",5);

}

void test::testLines()
{
    float t = 1;
    float PI = 3.14159265358979323846;
    float t1 = 19;
    float t2 = 5;
    float t3 = 19;

    float x = (t1 - t2) * cos (t) + t3 * cos (t * ((t1 - t2) / t2));
    float y = (t1 - t2) * sin (t) - t3 * sin (t * ((t1 - t2) / t2));

   QTRY_VERIFY2(PI < x || PI < y, "PI SHOULD BE SMALLER THEN X AN Y IN TERMS OF SIN AND COS");

}

void test::testHex()
{
    float t = 1;
    float basicEdge = 0.841471;
    float edge1 = 2;
    float edge2 = 1;
    QPointF(edge1*cos(t), edge2*sin(t));
    QTRY_COMPARE_WITH_TIMEOUT(basicEdge, (edge1*cos(t), edge2*sin(t)), 4);

}

QTEST_APPLESS_MAIN(test)

#include "tst_test.moc"
