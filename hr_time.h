#ifndef hr_timer
#define hr_timer

typedef struct {
    LARGE_INTEGER start;
    LARGE_INTEGER stop;
} stopWatch;

void startTimer( stopWatch *timer) ;
void stopTimer( stopWatch *timer) ;
double LIToSecs( LARGE_INTEGER * L) ;
double getElapsedTime( stopWatch *timer) ; 

#endif