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

}

 