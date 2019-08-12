#include <android/log.h>
#include "inline-hook/inlineHook.h"
#include <string>
#include "main.h"
#include "fakes.h"
#include <utility>
#include <set>
#include "Utils.h"
#include <string>
#include "Leaderboards.h"

#pragma region leaderboards

bool isCustomSong(const char *leaderboardName)
{
    //todo: better
    std::string str = std::string(leaderboardName);
    if (str.find_first_of('_') == 45) {
        log("found underscore at 45 for half ass custom song identification");
        
        return true;
    }
    return false;
}

FakeLeaderboardEntryArrayMessage* makeFakeLeaderboard()
{
    FakeLeaderboardEntryArrayMessage *m = new FakeLeaderboardEntryArrayMessage();
    m->TotalCount = 10;
    FakeLeaderboardEntry *e1 = new FakeLeaderboardEntry();
    e1->Rank = 1;
    e1->Score = 1000000;
    e1->User = new FakeUser();
    e1->User->OculusID = "Agent42";
    e1->User->UserID = 87563900;
    e1->User->InviteToken = NULL;
    FakeLeaderboardEntry *e2 = new FakeLeaderboardEntry();
    e2->Rank = 2;
    e2->Score = 500012;
    e2->User = new FakeUser();
    e2->User->OculusID = "Sc2ad";
    e2->User->UserID = 628144315;
    e2->User->InviteToken = NULL;
    FakeLeaderboardEntry *e3 = new FakeLeaderboardEntry();
    e3->Rank = 3;
    e3->Score = 49999;
    e3->User = new FakeUser();
    e3->User->OculusID = "Kyle 1413";
    e3->User->UserID = 240778293;
    e3->User->InviteToken = NULL;
    FakeLeaderboardEntry *e4 = new FakeLeaderboardEntry();
    e4->Rank = 4;
    e4->Score = 25445;
    e4->User = new FakeUser();
    e4->User->OculusID = "RedBrumbler";
    e4->User->UserID = 1918823910;
    e4->User->InviteToken = NULL;
    FakeLeaderboardEntry *e5 = new FakeLeaderboardEntry();
    e5->Rank = 5;
    e5->Score = 1258;
    e5->User = new FakeUser();
    e5->User->OculusID = "eliottate";
    e5->User->UserID = -1739110509;
    e5->User->InviteToken = NULL;
    FakeLeaderboardEntry *e6 = new FakeLeaderboardEntry();
    e6->Rank = 6;
    e6->Score = 1000;
    e6->User = new FakeUser();
    e6->User->OculusID = "trishume";
    e6->User->UserID = -168749367;
    e6->User->InviteToken = NULL;
    FakeLeaderboardEntry *e7 = new FakeLeaderboardEntry();
    e7->Rank = 7;
    e7->Score = 900;
    e7->User = new FakeUser();
    e7->User->OculusID = "shaneharris";
    e7->User->UserID = 87563900;
    e7->User->InviteToken = NULL;
    FakeLeaderboardEntry *e8 = new FakeLeaderboardEntry();
    e8->Rank = 8;
    e8->Score = 876;
    e8->User = new FakeUser();
    e8->User->OculusID = "karldeux";
    e8->User->UserID = 835128350;
    e8->User->InviteToken = NULL;
    FakeLeaderboardEntry *e9 = new FakeLeaderboardEntry();
    e9->Rank = 9;
    e9->Score = 765;
    e9->User = new FakeUser();
    e9->User->OculusID = "Assistant";
    e9->User->UserID = 25252311;
    e9->User->InviteToken = NULL;
    FakeLeaderboardEntry *e10 = new FakeLeaderboardEntry();
    e10->Rank = 10;
    e10->Score = 9999999;
    e10->User = new FakeUser();
    e10->User->OculusID = "lolpants";
    e10->User->UserID = 926097583;
    e10->User->InviteToken = NULL;
    
    m->Entries.push_back(e1);
    m->Entries.push_back(e2);
    m->Entries.push_back(e3);
    m->Entries.push_back(e4);
    m->Entries.push_back(e5);
    m->Entries.push_back(e6);
    m->Entries.push_back(e7);
    m->Entries.push_back(e8);
    m->Entries.push_back(e9);
    m->Entries.push_back(e10);
    
    m->IsReady = true;
    return m;
}



FakeLeaderboardEntryArrayMessage* customLeaderboardRequest_Friends(const char *leaderboardName, int limit, const char * csvFriendIds)
{
    log("FRIENDS with %s", csvFriendIds);
    return makeFakeLeaderboard();
}

FakeLeaderboardEntryArrayMessage* customLeaderboardRequest_PlayerCentered(const char *leaderboardName, int limit)
{
    return makeFakeLeaderboard();
}

FakeLeaderboardEntryArrayMessage* customLeaderboardRequest(const char *leaderboardName, int limit, unsigned long long afterRank)
{
    return makeFakeLeaderboard();
}

FakeUpdateLeaderboardStatusMessage* customLeaderboardUpdate(const char* leaderboardName, long long score)
{
    log("UPDATE CALLED with %s for %d", leaderboardName, score);
    auto msg = new FakeUpdateLeaderboardStatusMessage();
    msg->didUpdate = true;
    return msg;
}


#pragma endregion


__attribute__((constructor)) void lib_main()
{   
    log("Init of quest-board-mod");
    initLeaderboardHooks();
}