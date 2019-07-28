#include "fakes.h"
#include <android/log.h>

#define log(...) __android_log_print(ANDROID_LOG_INFO, "VRAPIHook", __VA_ARGS__)
#define err(...) __android_log_print(ANDROID_LOG_ERROR, "VRAPIHook", __VA_ARGS__)
std::set<void *> Fake::fakePtrs;
std::set<FakeMessage *> FakeMessage::fakeMsgs;
Fake::Fake()
{
    trackFake(this);
}

Fake::~Fake()
{
    log("Fake destructing");
    untrackFake(this);
}
void Fake::Free()
{
    delete this; 
}
void FakeMessage::Free()
{
    delete this; 
}
void FakeUser::Free()
{
    delete this; 
}
void FakeLeaderboardEntryArrayMessage::Free()
{
    std::vector<FakeLeaderboardEntry*>::iterator it;
    for (it = Entries.begin(); it !=  Entries.end(); ++it)
    {
        FakeLeaderboardEntry* m = *it;
        m->Free();
    }
    delete this; 
}
void FakeLeaderboardEntry::Free()
{
    User->Free();
    delete this; 
}
void Fake::trackFake(void* handle)
{
    log("tracking fake %d", handle);
    Fake::fakePtrs.insert(handle);
}

void Fake::untrackFake(void* handle)
{
    log("Untracking fake %d", handle);
    Fake::fakePtrs.erase(handle);
}

bool Fake::IsFake(void* handle)
{

    return Fake::fakePtrs.find(handle) != fakePtrs.end();
}

FakeLeaderboardEntryArrayMessage::FakeLeaderboardEntryArrayMessage()
{
    MessageType = ovrMessageType::ovrMessage_Leaderboard_GetEntriesAfterRank;
}
uint64_t FakeMessage::requestCounter;
FakeMessage::FakeMessage() 
{
    Request = FakeMessage::requestCounter++;
    log("Tracking fake message %d", this);
    FakeMessage::fakeMsgs.insert(this);
}

FakeMessage::~FakeMessage()
{
    log("Untracking fake message %d", this);
    FakeMessage::fakeMsgs.erase(this);
}


FakeMessage* FakeMessage::getNextReady()
{
    std::set<FakeMessage*>::iterator it;
    for (it =  FakeMessage::fakeMsgs.begin(); it !=  FakeMessage::fakeMsgs.end(); ++it)
    {
        FakeMessage* m = *it;
        if (m->IsReady && !m->IsHandled)
            return m;
    }

    return NULL;
}