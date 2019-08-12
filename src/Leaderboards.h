#include "fakes.h"
#ifndef leaderboards_h
#define leaderboards_h

FakeLeaderboardEntryArrayMessage* customLeaderboardRequest_Friends(const char *leaderboardName, int limit, const char * csvFriendIds);

FakeLeaderboardEntryArrayMessage* customLeaderboardRequest_PlayerCentered(const char *leaderboardName, int limit);

FakeLeaderboardEntryArrayMessage* customLeaderboardRequest(const char *leaderboardName, int limit, unsigned long long afterRank);

FakeUpdateLeaderboardStatusMessage* customLeaderboardUpdate(const char*leaderboardName, long long score);

bool isCustomSong(const char *leaderboardName);

void initLeaderboardHooks();

#endif