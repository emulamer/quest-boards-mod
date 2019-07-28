#include <android/log.h>
#include "inline-hook/inlineHook.h"
#include <dlfcn.h>
#include "OVRAutoHooks.h"

#include <string>
#include "main.h"
#include "fakes.h"
#include <utility>
#include <set>
#include <curl/curl.h>
#include "Utils.h"
#include <string>

#pragma region leaderboards

bool isCustomSong(const char *leaderboardName)
{
    //todo: better
    std::string str = std::string(leaderboardName);
    if (str.find_first_of('_') == 45) {
        log("found underscore at 40 for half ass custom song identification");
        
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

HOOK_DEF(ovr_FreeMessage, void, ovrMessageHandle handle)
{
   // log("ovr_FreeMessage called");
   if (Fake::IsFake(handle))
   {
       log("deleting fake handle %d", handle);
       ((Fake*)handle)->Free();
       return;
   }
   if (handle != 0)
        log("ovr_FreeMessage called for handle %d", handle);
    ovr_FreeMessage_def(handle);
}

HOOK_DEF(ovr_Message_GetType, ovrMessageType, const ovrMessageHandle obj)
{
    if (Fake::IsFake(obj)) {
        auto fakeRet = ((FakeMessage*)obj)->MessageType;
        log("ovr_Message_GetType called for handle %d, fake identified, returning %d", obj, fakeRet);
        return fakeRet;
    }
    auto ret = ovr_Message_GetType_def(obj);
    log("ovr_Message_GetType called with handle %d, returned %d", obj, ret);
    return ret;
}
HOOK_DEF(ovr_Message_IsError, bool, const ovrMessageHandle obj)
{
    if (Fake::IsFake(obj)) {
        auto fakeRet = ((FakeMessage*)obj)->IsError;
        log("ovr_Message_IsError called for handle %d, fake identified, returning %d", obj, fakeRet);
        return fakeRet;
    }
    bool ret = ovr_Message_IsError_def(obj);    
    log("ovr_Message_IsError called with %d, returned %d", obj, ret);
    return ret;
}
HOOK_DEF(ovr_Message_GetRequestID, ovrRequest, const ovrMessageHandle obj)
{
    if (Fake::IsFake(obj)) {
        auto fakeRet = ((FakeMessage*)obj)->Request;
        log("ovr_Message_GetRequestID intercepted with fake, returning %d", fakeRet);
        return fakeRet;
    }
	auto ret = ovr_Message_GetRequestID_def(obj);
	log("ovr_Message_GetRequestID called with %d  and returned %d", obj,  ret);
	return ret;
}

HOOK_DEF(ovr_PopMessage, ovrMessageHandle )
{
    //log("ovr_PopMessage called");
    ovrMessageHandle handle = ovr_PopMessage_def();
    if (handle == 0)
    {
        FakeMessage* msg = FakeMessage::getNextReady();
        if (!msg)
            return handle;
        log("Returning next ready msg handle %d", msg);
        msg->IsHandled = true;
        return (ovrMessageHandle)msg;
    }
    ovrMessageType type = ovr_Message_GetType_def(handle);
    log("handle is %d", handle);
    const char* typeName = ovrMessageType_ToString_def(type);
    log("message type was %s", typeName);
   /* if (type == ovrMessageType::ovrMessage_Leaderboard_GetEntriesAfterRank) {
        log("popped message type ovrMessage_Leaderboard_GetEntriesAfterRank, handle val %d", handle);
        if (ovr_Message_IsError_def(handle)) {
            /*todo:
                eat this, and return a 0 to the parent.
                start a thread to do the web request
                add code above to check for when handle is 0:
                    loop through all fake messages, look for one that IsReady = true
                    send that one out

                    implement deleting stuff on free of message
             
            log("****THIS CALL WAS ERROR RESPONSE, THIS IS WHERE TO INJECT****");
            FakeLeaderboardEntryArrayMessage *m = makeFakeLeaderboard();
            auto req = ovr_Message_GetRequestID_def(handle);
            log("got req id of %d", req);
            m->Request = req;
            ovr_FreeMessage_def(handle);
            return (ovrMessageHandle)m;
        }
        else if (type == ovrMessageType::ovrMessage_Leaderboard_GetEntries) {

        }
    }*/

    return handle;
}

HOOK_DEF(ovr_Message_GetLeaderboardEntryArray, ovrLeaderboardEntryArrayHandle, const ovrMessageHandle obj)
{
    if (Fake::IsFake(obj)) {
        auto fakeRet = ((ovrLeaderboardEntryArrayHandle)obj);
        log("ovr_Message_GetLeaderboardEntryArray called for handle %d, fake identified, returning %d", obj, fakeRet);
        return fakeRet;
    }
    ovrLeaderboardEntryArrayHandle ret = ovr_Message_GetLeaderboardEntryArray_def(obj);
    log("ovr_Message_GetLeaderboardEntryArray called with %d, returning %d", obj, ret);
    return ret;
}
HOOK_DEF(ovr_LeaderboardEntryArray_GetElement, ovrLeaderboardEntryHandle, const ovrLeaderboardEntryArrayHandle obj, size_t index)
{
    if (Fake::IsFake(obj)) {
        auto fakeRet = (ovrLeaderboardEntryHandle)((FakeLeaderboardEntryArrayMessage*)obj)->Entries.at(index);
        log("ovr_LeaderboardEntryArray_GetElement called for handle %d, fake identified, returning %d", obj, fakeRet);
        return fakeRet;
    }
    log("ovr_LeaderboardEntryArray_GetElement called with %d, idx %d", obj, index);
    ovrLeaderboardEntryHandle ret = ovr_LeaderboardEntryArray_GetElement_def(obj, index);
    return ret;
}
HOOK_DEF(ovr_LeaderboardEntryArray_GetNextUrl, const char *, const ovrLeaderboardEntryArrayHandle obj)
{
    if (Fake::IsFake(obj)) {
        log("ovr_LeaderboardEntryArray_GetNextUrl called for handle %d, fake identified, returning empty string", obj);
        return "";
    }
    const char * ret = ovr_LeaderboardEntryArray_GetNextUrl_def(obj);
    log("ovr_LeaderboardEntryArray_GetNextUrl called with %d, returned %s", obj, ret);
    
    return ret;
}
HOOK_DEF(ovr_LeaderboardEntryArray_GetPreviousUrl, const char *, const ovrLeaderboardEntryArrayHandle obj)
{
    if (Fake::IsFake(obj)) {
        log("ovr_LeaderboardEntryArray_GetPreviousUrl called for handle %d, fake identified, returning an empty string", obj);
        return "";
    }
    const char * ret = ovr_LeaderboardEntryArray_GetPreviousUrl_def(obj);
    log("ovr_LeaderboardEntryArray_GetPreviousUrl called, returned: %s", ret);
    return ret;
}
HOOK_DEF(ovr_LeaderboardEntryArray_GetSize, size_t, const ovrLeaderboardEntryArrayHandle obj)
{
    if (Fake::IsFake(obj)) {
        auto fakeRet = ((FakeLeaderboardEntryArrayMessage*)obj)->Entries.size();
        log("ovr_LeaderboardEntryArray_GetSize called for handle %d, fake identified, returning %d", obj, fakeRet);
        return fakeRet;
    }
    size_t ret = ovr_LeaderboardEntryArray_GetSize_def(obj);
    log("ovr_LeaderboardEntryArray_GetSize called, returned %d", ret);
    return ret;
}
HOOK_DEF(ovr_LeaderboardEntryArray_GetTotalCount, unsigned long long, const ovrLeaderboardEntryArrayHandle obj)
{
    if (Fake::IsFake(obj)) {
        auto fakeRet = ((FakeLeaderboardEntryArrayMessage*)obj)->TotalCount;
        log("ovr_LeaderboardEntryArray_GetTotalCount called for handle %d, fake identified, returning %d", obj, fakeRet);
        return fakeRet;
    }
    unsigned long long ret = ovr_LeaderboardEntryArray_GetTotalCount_def(obj);
    log("ovr_LeaderboardEntryArray_GetTotalCount called for handle %d, returned %d",obj,  ret);
    return ret;
}

HOOK_DEF(ovr_LeaderboardEntry_GetExtraData, const char *, const ovrLeaderboardEntryHandle obj)
{
    if (Fake::IsFake(obj)) {
        log("ovr_LeaderboardEntry_GetExtraData called for handle %d, fake identified, returning null", obj);
        return "";
    }
    const char * ret = ovr_LeaderboardEntry_GetExtraData_def(obj);
    log("ovr_LeaderboardEntry_GetExtraData called with %d, returned %s", obj, ret);
    return ret;
}
HOOK_DEF(ovr_LeaderboardEntry_GetExtraDataLength, unsigned int, const ovrLeaderboardEntryHandle obj)
{
    log("ovr_LeaderboardEntry_GetExtraDataLength called with %d", obj);
    if (Fake::IsFake(obj)) {
        log("ovr_LeaderboardEntry_GetExtraDataLength called for handle %d, fake identified, returning 0", obj);
        return 0;
    }
    unsigned int ret = ovr_LeaderboardEntry_GetExtraDataLength_def(obj);
    log("ovr_LeaderboardEntry_GetExtraDataLength called, returned %d", ret);
    return ret;
}
HOOK_DEF(ovr_LeaderboardEntry_GetRank, int, const ovrLeaderboardEntryHandle obj)
{    
   if (Fake::IsFake(obj)) {
        auto fakeRet = ((FakeLeaderboardEntry*)obj)->Rank;
        log("ovr_LeaderboardEntry_GetRank called for handle %d, fake identified, returning %d", obj, fakeRet);
        return fakeRet;
    }
    int ret = ovr_LeaderboardEntry_GetRank_def(obj);
    log("ovr_LeaderboardEntry_GetRank called with %d, returned %d", obj, ret);
    return ret;
}
HOOK_DEF(ovr_LeaderboardEntry_GetScore, long long, const ovrLeaderboardEntryHandle obj)
{
    if (Fake::IsFake(obj)) {
        auto fakeRet = ((FakeLeaderboardEntry*)obj)->Score;
        log("ovr_LeaderboardEntry_GetScore called for handle %d, fake identified, returning %d", obj, fakeRet);
        return fakeRet;
    }
    long long ret = ovr_LeaderboardEntry_GetScore_def(obj);
    log("ovr_LeaderboardEntry_GetScore called with %d, returned %d", obj, ret);
    return ret;
}
HOOK_DEF(ovr_LeaderboardEntry_GetTimestamp, unsigned long long, const ovrLeaderboardEntryHandle obj)
{
    if (Fake::IsFake(obj)) {
        auto fakeRet = ((FakeLeaderboardEntry*)obj)->Timestamp;
        log("ovr_LeaderboardEntry_GetTimestamp called for handle %d, fake identified, returning %d", obj, fakeRet);
        return fakeRet;
    }
    unsigned long long ret = ovr_LeaderboardEntry_GetTimestamp_def(obj);
    log("ovr_LeaderboardEntry_GetTimestamp called, returned %d", ret);
    return ret;
}
HOOK_DEF(ovr_LeaderboardEntry_GetUser, ovrUserHandle, const ovrLeaderboardEntryHandle obj)
{
    if (Fake::IsFake(obj)) {
        auto fakeRet = (ovrUserHandle)((FakeLeaderboardEntry*)obj)->User;
        log("ovr_LeaderboardEntry_GetUser called for handle %d, fake identified, returning %d", obj, fakeRet);
        return fakeRet;
    }
    ovrUserHandle ret = ovr_LeaderboardEntry_GetUser_def(obj);
    log("ovr_LeaderboardEntry_GetUser called with %d, returning %d", obj, ret);
    return ret;
}
HOOK_DEF(ovr_User_GetOculusID, const char *, const ovrUserHandle obj)
{
    if (Fake::IsFake(obj)) {
        auto fakeRet =((FakeUser*)obj)->OculusID;
        log("ovr_User_GetOculusID called for handle %d, fake identified, returning %s", obj, fakeRet);
        return fakeRet;
    }
    const char * ret = ovr_User_GetOculusID_def(obj);
    log("ovr_User_GetOculusID called with %d, returned %s", obj, ret);
    return ret;
}
HOOK_DEF(ovr_Message_GetNativeMessage, ovrMessageHandle, const ovrMessageHandle obj)
{
    if (Fake::IsFake(obj)) {
        log("ovr_Message_GetNativeMessage called, returning original");
        return obj;
    }
    auto ret = ovr_Message_GetNativeMessage_def(obj);
    log("ovr_Message_GetNativeMessage called with %d, returned %d", obj, ret);
    return ret;
}
HOOK_DEF(ovr_User_GetPresence, const char *, const ovrUserHandle obj)
{
    if (Fake::IsFake(obj)) {
        auto fakeRet =((FakeUser*)obj)->Presence;
        log("ovr_User_GetPresence called for handle %d, fake identified, returning %s", obj, fakeRet);
        return fakeRet;
    }
    auto ret = ovr_User_GetPresence_def(obj);
    log("ovr_User_GetPresence called with %d, result: %s", obj, ret);
    return ret;
}
HOOK_DEF(ovr_User_GetPresenceStatus, ovrUserPresenceStatus, const ovrUserHandle obj)
{
    if (Fake::IsFake(obj)) {
        auto fakeRet =((FakeUser*)obj)->PresenceStatus;
        log("ovr_User_GetPresenceStatus called for handle %d, fake identified, returning %d", obj, fakeRet);
        return fakeRet;
    }
    auto ret = ovr_User_GetPresenceStatus_def(obj);
    log("ovr_User_GetPresenceStatus called with %d, result: %d", obj, ret);
    return ret;
}

HOOK_DEF(ovr_User_GetID, ovrID, const ovrUserHandle obj)
{
    if (Fake::IsFake(obj)) {
        auto fakeRet =((FakeUser*)obj)->UserID;
        log("ovr_User_GetID called for handle %d, fake identified, returning %d", obj, fakeRet);
        return fakeRet;
    }
    auto ret = ovr_User_GetID_def(obj);
    log("ovr_User_GetID called with %d, result: %d", obj, ret);
    return ret;
}
HOOK_DEF(ovr_User_GetImageUrl,const char *, const ovrUserHandle obj)
{
    if (Fake::IsFake(obj)) {
        auto fakeRet =((FakeUser*)obj)->ImageUrl;
        log("ovr_User_GetImageUrl called for handle %d, fake identified, returning %s", obj, fakeRet);
        return fakeRet;
    }
    auto ret = ovr_User_GetImageUrl_def(obj);
    log("ovr_User_GetImageUrl called with %d, result: %s", obj, ret);
    return ret;
}
HOOK_DEF(ovr_User_GetInviteToken, const char *, const ovrUserHandle obj)
{
    if (Fake::IsFake(obj)) {
        auto fakeRet =((FakeUser*)obj)->InviteToken;
        log("ovr_User_GetInviteToken called for handle %d, fake identified, returning %s", obj, fakeRet);
        return fakeRet;
    }
    auto ret = ovr_User_GetInviteToken_def(obj);
    log("ovr_User_GetInviteToken called with %d, result: %s", obj, ret);
    return ret;
}
HOOK_DEF(ovr_User_GetSmallImageUrl, const char *, const ovrUserHandle obj)
{
    if (Fake::IsFake(obj)) {
        auto fakeRet =((FakeUser*)obj)->SmallImageUrl;
        log("ovr_User_GetSmallImageUrl called for handle %d, fake identified, returning %s", obj, fakeRet);
        return fakeRet;
    }
    auto ret = ovr_User_GetSmallImageUrl_def(obj);
    log("ovr_User_GetSmallImageUrl called with %d, result: %s", obj, ret);
    return ret;
}

HOOK_DEF(ovr_Leaderboard_GetEntries, ovrRequest, const char *leaderboardName, int limit, ovrLeaderboardFilterType filter, ovrLeaderboardStartAt startAt)
{
    if (isCustomSong(leaderboardName)) {
        auto msg = makeFakeLeaderboard();
        log("%s is a custom song, intercepting ovr_Leaderboard_GetEntries request and returning request %d", leaderboardName, msg->Request);
        return (ovrRequest)msg->Request;
    }
	auto ret = ovr_Leaderboard_GetEntries_def(leaderboardName, limit, filter, startAt);
	log("ovr_Leaderboard_GetEntries called with %d %d %d %d  and returned %d", leaderboardName, limit, filter, startAt,  ret);
	return ret;
}
HOOK_DEF(ovr_Leaderboard_GetEntriesAfterRank, ovrRequest, const char *leaderboardName, int limit, unsigned long long afterRank)
{
    if (isCustomSong(leaderboardName)) {
        auto msg = makeFakeLeaderboard();
        log("%s is a custom song, intercepting ovr_Leaderboard_GetEntriesAfterRank request and returning request %d", leaderboardName, msg->Request);
        return (ovrRequest)msg->Request;
    }

	auto ret = ovr_Leaderboard_GetEntriesAfterRank_def(leaderboardName, limit, afterRank);
	log("ovr_Leaderboard_GetEntriesAfterRank called with %s %d %d  and returned %d", leaderboardName, limit, afterRank,  ret);
	return ret;
}
HOOK_DEF(ovr_Leaderboard_GetNextEntries, ovrRequest, const ovrLeaderboardEntryArrayHandle handle)
{
    if (Fake::IsFake(handle)) {
        auto msg = makeFakeLeaderboard();
        log("ovr_Leaderboard_GetNextEntries intercepted fake for handle %d, returning request %d", handle, msg->Request);
        return (ovrRequest)msg->Request;
    }
	auto ret = ovr_Leaderboard_GetNextEntries_def(handle);
	log("ovr_Leaderboard_GetNextEntries called with %d  and returned %d", handle,  ret);
	return ret;
}
HOOK_DEF(ovr_Leaderboard_GetPreviousEntries, ovrRequest, const ovrLeaderboardEntryArrayHandle handle)
{
    if (Fake::IsFake(handle)) {
        auto msg = makeFakeLeaderboard();
        log("ovr_Leaderboard_GetPreviousEntries intercepted fake for handle %d, returning request %d", handle, msg->Request);
        return (ovrRequest)msg->Request;
    }
	auto ret = ovr_Leaderboard_GetPreviousEntries_def(handle);
	log("ovr_Leaderboard_GetPreviousEntries called with %d  and returned %d", handle,  ret);
	return ret;
}
HOOK_DEF(ovr_Leaderboard_WriteEntry, ovrRequest, const char *leaderboardName, long long score, const void *extraData, unsigned int extraDataLength, bool forceUpdate)
{
    if (isCustomSong(leaderboardName)) {
        auto msg = makeFakeLeaderboard();
        log("%s is a custom song, intercepting ovr_Leaderboard_WriteEntry request and returning request %d", leaderboardName, msg->Request);
        return (ovrRequest)msg->Request;
    }
	auto ret = ovr_Leaderboard_WriteEntry_def(leaderboardName, score, extraData, extraDataLength, forceUpdate);
	log("ovr_Leaderboard_WriteEntry called with %d %d %d %d %d  and returned %d", leaderboardName, score, extraData, extraDataLength, forceUpdate,  ret);
	return ret;
}
#pragma endregion


__attribute__((constructor)) void lib_main()
{
   
    log("Init of quest-board-mod");
    void * ovrplatformHandle = dlopen("libovrplatformloader.so", RTLD_NOW);

    INIT_HOOK(ovrplatformHandle, ovr_Message_GetType);
    INIT_HOOK(ovrplatformHandle, ovr_PopMessage);
    INIT_HOOK(ovrplatformHandle, ovr_Message_GetLeaderboardEntryArray);
    INIT_HOOK(ovrplatformHandle, ovr_LeaderboardEntryArray_GetElement);
    INIT_HOOK(ovrplatformHandle, ovr_LeaderboardEntryArray_GetNextUrl);
    INIT_HOOK(ovrplatformHandle, ovr_LeaderboardEntryArray_GetPreviousUrl);
    INIT_HOOK(ovrplatformHandle, ovr_LeaderboardEntryArray_GetSize);
    INIT_HOOK(ovrplatformHandle, ovr_LeaderboardEntryArray_GetTotalCount);
    INIT_HOOK(ovrplatformHandle, ovr_LeaderboardEntry_GetExtraData);
    INIT_HOOK(ovrplatformHandle, ovr_LeaderboardEntry_GetExtraDataLength);
    INIT_HOOK(ovrplatformHandle, ovr_LeaderboardEntry_GetRank);
    INIT_HOOK(ovrplatformHandle, ovr_LeaderboardEntry_GetScore);
    INIT_HOOK(ovrplatformHandle, ovr_LeaderboardEntry_GetTimestamp);
    INIT_HOOK(ovrplatformHandle, ovr_LeaderboardEntry_GetUser);
    INIT_HOOK(ovrplatformHandle, ovr_User_GetOculusID);
    INIT_HOOK(ovrplatformHandle, ovr_Message_IsError);
    INIT_HOOK(ovrplatformHandle, ovr_FreeMessage);
    INIT_HOOK(ovrplatformHandle, ovr_Message_GetNativeMessage);
    INIT_HOOK(ovrplatformHandle, ovr_User_GetPresence);
    INIT_HOOK(ovrplatformHandle, ovr_User_GetPresenceStatus);
    INIT_HOOK(ovrplatformHandle, ovr_User_GetID);
    INIT_HOOK(ovrplatformHandle, ovr_User_GetImageUrl);
    INIT_HOOK(ovrplatformHandle, ovr_User_GetInviteToken);
    INIT_HOOK(ovrplatformHandle, ovr_User_GetSmallImageUrl);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetRequestID);
	INIT_HOOK(ovrplatformHandle, ovr_Leaderboard_GetEntries);
	INIT_HOOK(ovrplatformHandle, ovr_Leaderboard_GetEntriesAfterRank);
	INIT_HOOK(ovrplatformHandle, ovr_Leaderboard_GetNextEntries);
	INIT_HOOK(ovrplatformHandle, ovr_Leaderboard_GetPreviousEntries);
	INIT_HOOK(ovrplatformHandle, ovr_Leaderboard_WriteEntry);
    InitOVRHooks(ovrplatformHandle);
}