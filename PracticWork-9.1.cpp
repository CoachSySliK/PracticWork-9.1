#include <iostream>
#include "functions.h"

using namespace std;

int main()
{
    string timeDeparture;
    string timeArrival;
    enterDeparture: //ввод времени отправления
    cout << "Введите время отправления в формате HH:MM\n";
    cin >> timeDeparture;
    cin.ignore(100, '\n');
    
    int timeDH = (timeDeparture[0] - 48) * 10 + (timeDeparture[1] - 48); //-48 потому что 0 в таблице аски это 48ой символ
    int timeDM = (timeDeparture[3] - 48) * 10 + (timeDeparture[4] - 48);

    if (timeDH >= 24 || timeDH < 0 || timeDM >= 60 || timeDM < 0) {
        cout << "Не правильный формат времени\n";
        goto enterDeparture;
    }

    enterArrival: //ввод времени прибытия
    cout << "Введите время прибытия в формате HH:MM\n";
    cin >> timeArrival;
    cin.ignore(100, '\n');

    int timeAH = (timeArrival[0] - 48) * 10 + (timeArrival[1] - 48);
    int timeAM = (timeArrival[3] - 48) * 10 + (timeArrival[4] - 48);

    if (timeAH >= 24 || timeAH < 0 || timeAM >= 60 || timeAM < 0) {
        cout << "Не правильный формат времени\n";
        goto enterArrival;
    }

    //cout << timeDH << ":" << timeDM << endl;
    //cout << timeAH << ":" << timeAM << endl;

    if (timeDH > timeAH || (timeDH == timeAH && timeDM > timeAM)) {
        timeAH += 24;
    }

    int deltaTimeH = ((timeAH * 60 + timeAM) - (timeDH * 60 + timeDM)) / 60;
    int deltaTimeM = ((timeAH * 60 + timeAM) - (timeDH * 60 + timeDM)) % 60;

    /*int day = 0;
    if (deltaTimeH >= 24) {
        day = deltaTimeH / 24;
    }*/

    cout << "Время в пути " /*<< day << ending(day, 100) << " " */<< deltaTimeH << ending(deltaTimeH, 104) << " " << deltaTimeM << ending(deltaTimeM, 109) << endl;

    return 0;
}

