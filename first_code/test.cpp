#include <stdio.h>
#include <signal.h>

volatile int flag = 0;

void handler(int signo)
{
    flag = 1;
    printf("chage flag to 1\n");
}

int main()
{
    signal(2, handler);
    while(!flag);
    printf("proc done...\n");
    return 0;
}
//#include <iostream>
//#include <signal.h>
//#include <unistd.h>
//
//using namespace std;

//void handler(int signo)
//{
//
//}
//
int MySleep(int sec)
{
    struct sigaction act, oact;
    act.sa_handler = handler;
    sigemptyset(&act.sa_mask);

    sigaction(SIGALRM, &act, &oact);

    alarm(sec);
    pause();

    int ret = alarm(0);
    sigaction(SIGALRM, &oact, NULL);

    return ret;
}
//
//int main()
//{
//    while(1){
//        MySleep(1);
//        cout << "wake up..." << endl;
//    }
//    return 0;
//}
//
////void handler(int signo)
////{
////    cout << "catch a sig : " << signo << endl;
////}
////
////int main()
////{
////    struct sigaction act, oact;
////    act.sa_handler = SIG_DFL;
////    sigemptyset(&act.sa_mask);
////
////    sigaction(2, &act, &oact);
////    int ret = pause();
////    cout << ret << endl;
////
//////    while(1){
//////        cout << " hello world " << endl;
//////        sleep(1);
//////    }
////    return 0;
////}
