#ifndef REPORT_H
#define REPORT_H
#include <QString>


namespace Report_space {
    class Report;
}

class Report{
public:
    explicit Report();
    QString user_id;
    QString car_id;
    QString order_id;
    QString Evaluation;
    bool engine;
    bool tire;
    bool battery;

private:
};

#endif // REPORT_H
