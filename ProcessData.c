#include "ProcessData.h"
#include <stdlib.h>

size_t separateToken(char *str, char del, char ** strArr, size_t dim) {

    if(dim <= 0) {
        return 0;
    }

    *strArr = str;

    int i = 0;

    while (str[i] != del && str[i] != 0){
        i++;
    }
    if(str[i] == del){
        str[i] = 0;
        return 1 + separateToken(str + i + 1, del, strArr + 1, dim - 1);
    } else {
        return 1;
    }

}

int
isUnknownOACI(const char * airportOACI){

    int formatA, formatB;
    int aux;

    formatA = sscanf(airportOACI, "SA%2d", &aux);
    formatB = sscanf(airportOACI, "AR-%4d", &aux);

    return formatA || formatB;

}

int
dateToDayOfWeek (const char * date, int * dayCode, int * monthCode, int * yearCode){

    int day, month, year;
    getDate(date, &day, &month, &year);

    int dayOfWeekIndex = dayCode[day % 7] + monthCode[month - 1] + yearCode[year - 2014];

    return dayOfWeekIndex % 7;

}

void
getDate (const char * date, int * day, int * month, int * year){

    int args = sscanf(date, "%2d/%2d/%4d", day, month, year);
    return;

}

int
verifyYear (const char * date, int yearGiven){

    int year;

    int args = sscanf(date, "%*d/%*d/%4d", &year);

    return year == yearGiven;

}