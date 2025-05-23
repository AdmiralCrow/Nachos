
#if defined(HW1_CONDITION) && defined(CHANGED)

#include "copyright.h"
#include "system.h"
#include "synch.h"

Lock * pingLock;
Condition *cv;

void
PingPong(int which)
{
    char *msg = (char *) which;
    int i;
    pingLock->Acquire();
    for (i = 0; i < 5; i++) {
		printf("%s\n", msg);
		cv->Signal(pingLock);
		cv->Wait(pingLock);
    }
    pingLock->Release();
}

#define HW1_CONDITION
void Ping()
{
    pingLock = new Lock("cv");
    cv = new Condition("ping pong");
    char *ping = "ping";
    char *pong = "pong";
    Thread *t = new Thread(ping);
    t->Fork(PingPong, (int) ping);
    PingPong((int) pong);

 }

 #endif
