#include <QtTest>
#include <QCoreApplication>

class MyTest : public QObject
{
    Q_OBJECT

private slots:
    void testExample()
    {
        QString str = "Hello, World!";
        QCOMPARE(str.toUpper(), QString("HELLO, WORLD!"));
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    MyTest test;
    QTest::qExec(&test);

    return 0;
}

#include "unit_test.moc"
