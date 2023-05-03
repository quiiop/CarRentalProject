#include <QtTest/QtTest>

class My1stUT : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase()
    {
    }

    void cleanupTestCase()
    {
    }

    void testAdd()
    {
        QVERIFY(1 + 1 == 2);
    }
};

QTEST_MAIN(My1stUT)
#include "sample.moc"
