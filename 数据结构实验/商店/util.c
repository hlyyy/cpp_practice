#pragma once

#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "constvar.h"

// 获取当前时间
char *getCurrentTime() {
    time_t currentTime;
    struct tm *p;

    time(&currentTime);
    p = localtime(&currentTime);
    
    char *date;
    date = (char*)malloc(100 * sizeof(char));
    sprintf(date, "%d/%d/%d %d:%d:%d", p->tm_year + 1900, p->tm_mon, p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec);

    return  date;
}

// log
void logInfo(Status status, INFO info) {
    char *currentTime = getCurrentTime();
    printf("%s: [STATUS]:%s, [INFO]:%s\n", currentTime, status, info);

    return;
}

void newLine() {
    printf("\n");

    return;
}
