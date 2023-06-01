#ifndef CAR_H
#define CAR_H
#include <QString>

namespace Car_space {
    class Car;
}
class Car{
public:
    explicit Car();
    QString KmInput;
    QString MaxSeatLine;
    QString ModelLine;
    QString RentalPriceLine;
    QString CarStatus;
    QString filePath;
    bool is_rental;

    QString get_BrandInput();
    void set_car(QString BrandInput, QString KmInput, QString ModelLine, QString CarStatus, QString MaxSeatLine, QString RentalPriceLine, QString filePath);

private:
    QString BrandInput;
};
#endif // CAR_H
