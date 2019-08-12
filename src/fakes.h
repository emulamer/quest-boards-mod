#include <vector>
#include <set>
#include "../OVRPlatformSDK/Include/OVR_MessageType.h"
#include "../OVRPlatformSDK/Include/OVR_UserPresenceStatus.h"
#ifndef fakes_h
#define fakes_h


class Fake
{
    public:
        Fake();
        virtual ~Fake();
        static bool IsFake(void *);
        virtual void Free();
    protected:
        void trackFake(void *);
        void untrackFake(void *);
    private:
        static std::set<void *> fakePtrs;
};

class FakeMessage : public Fake
{
    public:
        FakeMessage();
        ~FakeMessage();
        ovrMessageType MessageType;
        bool IsError = false;
        bool IsReady = false;
        bool IsHandled = false;
        uint64_t Request;
        static FakeMessage* getNextReady();
        void Free();
    private:
        static uint64_t requestCounter;
        static std::set<FakeMessage *> fakeMsgs;
};

class FakeUser : public Fake
{
    public: 
        const char *OculusID;
        const char *Presence = "Offline";
        uint64_t UserID = 1520223074;
        const char *ImageUrl = "";
        const char *InviteToken = NULL;
        const char *SmallImageUrl = "";
        ovrUserPresenceStatus PresenceStatus = ovrUserPresenceStatus::ovrUserPresenceStatus_Offline;
        void Free();
};

class FakeLeaderboardEntry : public Fake
{
    public:
        long long Score;
        int Rank;
        unsigned long long Timestamp;
        FakeUser* User;
        void Free();
};

class FakeUpdateLeaderboardStatusMessage : public FakeMessage
{
    public:
        FakeUpdateLeaderboardStatusMessage();
        bool didUpdate;
        void Free();
};

class FakeLeaderboardEntryArrayMessage : public FakeMessage
{
    public:
        FakeLeaderboardEntryArrayMessage();
        unsigned long long TotalCount = 1704;
        std::vector<FakeLeaderboardEntry*> Entries;    
        void Free();
};


#endif