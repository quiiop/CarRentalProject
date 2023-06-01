#ifndef PERSON_H
#define PERSON_H
#include <QString>


namespace Person_space {
    class Person;
}
class Person{
public:
    explicit Person();
    QString Account;
    QString Password;
    bool is_rental_car;
    int user_id;

private:

};

#endif // PERSON_H
