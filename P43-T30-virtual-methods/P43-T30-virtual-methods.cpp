#include "Employee.h"
#include "Teacher.h"
#include "Manager.h"
#include <vector>
#include <algorithm>
#include <typeinfo>

int main()
{
    Employee a("Sopin Kyrylo", 15'000);
    Teacher b("Spiridonov Yaroslav", 10'000, 2'000, 50);
    Manager d("Eremenko Volodomyr", 10'000, 20, 100'000);

    vector<Employee*> arr = {
        &a, &b, &d,
        new Teacher("Gudzenko Dmytro", 13'000, 1'500, 20),
        new Manager("Dudolad Yaroslav", 30'000, 10, 200'000)
    };

    arr.push_back(new Manager("Zotov Petro", 23'000, 50, 100'000));

    for (int i = 0; i < arr.size(); i++)
    {
        //cout << arr[i] << endl; // address
        //(*arr[i]).showInfo();
        //arr[i]->showInfo();
        cout << i + 1 << ". " << arr[i]->getName() << endl; 
    }
    cout << "======================================\n\n";
    //Вивести на екран лише менеджерів
    cout << "List of managers: \n";
    for (int i = 0; i < arr.size(); i++)
    {
        // cout << typeid(*arr[i]).name() << endl;

        if (typeid(*arr[i]) == typeid(Manager)) {
            arr[i]->showInfo();
        }
    }

    cout << "======================================\n\n";
    //Кожному викладечеві збільшити вартість заняття на 50 грн

    for (int i = 0; i < arr.size(); i++)
    {
       /* if (typeid(*arr[i]) == typeid(Teacher)) {
            Teacher* p = (Teacher*)arr[i];
            p->setCost(p->getCost() + 50);
            p->showInfo();
        }*/
        Teacher* p = dynamic_cast<Teacher*>(arr[i]);
        if (p != nullptr) {
            p->setCost(p->getCost() + 50);
            p->showInfo();
        }
    }

}

 