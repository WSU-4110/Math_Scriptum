#include <QtTest>

// add necessary includes here

class Buddharaju_UnitTest : public QObject
{
    Q_OBJECT

public:
    Buddharaju_UnitTest();
    ~Buddharaju_UnitTest();

private slots:
    void drawAstroid();
    void drawHypo();
    void drawCircle();
    void drawCycloid();
    void drawHuygens();

};

Buddharaju_UnitTest::Buddharaju_UnitTest()
{

}

void Buddharaju_UnitTest::drawAstroid()
{
    // check that values of x and y are always less than pi

    float t = 10;
    float pi = 3.14159;


    float cos_t = cos(t);
    float sin_t = sin(t);

    float x = 2 * cos_t * cos_t * cos_t;
    float y = 2 * sin_t * sin_t * sin_t;

    QVERIFY2(pi > x && pi > y, "Pi should be geeater than both x & y in terms of sin and cos.");
}

void Buddharaju_UnitTest::drawHypo()
{
    float t = 10;
    float pi = 3.14159;

    float x = 1.5 * (2*cos(t) + cos (2*t));
    float y = 4 * (3*sin(t) - sin(3*t));

    QVERIFY2(pi > x && pi > y, "Pi should be geeater than both x & y in terms of sin and cos.");

}

void Buddharaju_UnitTest::drawCircle()
{
    float r = 10;
    float pi = 3.14159;
    float area = pi * pow(r,2);

    float x = area / pi;
    float i = sqrt(x);

    QCOMPARE(r,i);
}

void Buddharaju_UnitTest::drawCycloid()
{
    float t = 10;
    float pi = 3.14159;

    float x = 1.5 * (1-cos(t));
    float y = 1.5 * (t-sin(t));

    QVERIFY2(pi > x || pi < y, "Pi should be geeater than x & less than y in terms of sin and cos.");

}

void Buddharaju_UnitTest::drawHuygens()
{
// 4*(3*cos(t)-cos(3*t)),4*(3*sin(t)-sin(3*t)));

    float t = 10;
    float pi = 3.14159;

    float x = 4*(3*cos(t)-cos(3*t));
    float y = 4*(3*sin(t)-sin(3*t));

    QVERIFY2(pi < x || pi > y, "Pi should be less than x & greater than y in terms of sin and cos.");

}

Buddharaju_UnitTest::~Buddharaju_UnitTest()
{

}



QTEST_APPLESS_MAIN(Buddharaju_UnitTest)

#include "tst_buddharaju_unittest.moc"
