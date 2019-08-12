#include <android/log.h>
#include "inline-hook/inlineHook.h"
#include <dlfcn.h>
#include "Leaderboards.h"
#include <string>
#include "main.h"
#include "fakes.h"
#include <utility>
#include <set>
#include "Utils.h"
#include <string>
#include "../OVRPlatformSDK/Include/OVR_LeaderboardEntry.h"
#include "../OVRPlatformSDK/Include/OVR_LeaderboardEntryArray.h"
#include "../OVRPlatformSDK/Include/OVR_LeaderboardFilterType.h"
#include "../OVRPlatformSDK/Include/OVR_LeaderboardStartAt.h"
#include "../OVRPlatformSDK/Include/OVR_LeaderboardUpdateStatus.h"
#include "../OVRPlatformSDK/Include/OVR_Message.h"
#include "../OVRPlatformSDK/Include/OVR_MessageType.h"
#include "../OVRPlatformSDK/Include/OVR_Requests_Leaderboard.h"
#include "../OVRPlatformSDK/Include/OVR_User.h"
#include "../OVRPlatformSDK/Include/OVR_UserArray.h"
std::set<ovrRequest> knownRequests;

std::string friendIds;

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
HOOK_DEF(ovrMessageType_ToString, const char*, ovrMessageType value)
{
	auto ret = ovrMessageType_ToString_def(value);
	log("ovrMessageType_ToString called with %d  and returned %s", value,  ret);
	return ret;
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
        FakeLeaderboardEntryArrayMessage* msg;
        if (filter == ovrLeaderboardFilterType::ovrLeaderboard_FilterFriends) {
            msg = customLeaderboardRequest_Friends(leaderboardName, limit, friendIds.c_str());
        } else if (startAt == ovrLeaderboardStartAt::ovrLeaderboard_StartAtCenteredOnViewer || startAt == ovrLeaderboardStartAt::ovrLeaderboard_StartAtCenteredOnViewerOrTop) {
            msg = customLeaderboardRequest_PlayerCentered(leaderboardName, limit);
        }
        else {
            msg = customLeaderboardRequest(leaderboardName, limit, 0);
        }
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
        auto msg = customLeaderboardRequest(leaderboardName, limit, afterRank);
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
        auto msg = new FakeLeaderboardEntryArrayMessage();
        log("ovr_Leaderboard_GetNextEntries intercepted fake for handle %d, but this isn't implemented!", handle);
        return (ovrRequest)msg->Request;
    }
	auto ret = ovr_Leaderboard_GetNextEntries_def(handle);
	log("ovr_Leaderboard_GetNextEntries called with %d  and returned %d", handle,  ret);
	return ret;
}
HOOK_DEF(ovr_Leaderboard_GetPreviousEntries, ovrRequest, const ovrLeaderboardEntryArrayHandle handle)
{
    if (Fake::IsFake(handle)) {
        auto msg = new FakeLeaderboardEntryArrayMessage();
        log("ovr_Leaderboard_GetPreviousEntries intercepted fake for handle %d, but this isn't implemented!", handle);
        return (ovrRequest)msg->Request;
    }
	auto ret = ovr_Leaderboard_GetPreviousEntries_def(handle);
	log("ovr_Leaderboard_GetPreviousEntries called with %d  and returned %d", handle,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetLeaderboardUpdateStatus, ovrLeaderboardUpdateStatusHandle, const ovrMessageHandle obj)
{
    if (Fake::IsFake(obj)) {
        auto fakeRet = ((FakeUpdateLeaderboardStatusMessage*)obj);
        log("ovr_Message_GetLeaderboardUpdateStatus intercepted fake for handle %d, returned %d", obj, fakeRet);
        return (ovrLeaderboardUpdateStatusHandle)fakeRet;
    }
	auto ret = ovr_Message_GetLeaderboardUpdateStatus_def(obj);
	log("ovr_Message_GetLeaderboardUpdateStatus called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_LeaderboardUpdateStatus_GetDidUpdate, bool, const ovrLeaderboardUpdateStatusHandle obj)
{
    if (Fake::IsFake(obj)) {
        auto fakeRet = ((FakeUpdateLeaderboardStatusMessage*)obj)->didUpdate;
        log("ovr_Message_GetLeaderboardUpdateStatus intercepted fake for handle %d, returned %d", obj, fakeRet);
        return fakeRet;
    }
	auto ret = ovr_LeaderboardUpdateStatus_GetDidUpdate_def(obj);
	log("ovr_LeaderboardUpdateStatus_GetDidUpdate called with %d  and returned %d", obj,  ret);
	return ret;
}

HOOK_DEF(ovr_UserArray_GetElement, ovrUserHandle, const ovrUserArrayHandle obj, size_t index)
{
	auto ret = ovr_UserArray_GetElement_def(obj, index);
	log("ovr_UserArray_GetElement called with %d %d  and returned %d", obj, index,  ret);
	return ret;
}
HOOK_DEF(ovr_UserArray_GetNextUrl, const char *, const ovrUserArrayHandle obj)
{
	auto ret = ovr_UserArray_GetNextUrl_def(obj);
	log("ovr_UserArray_GetNextUrl called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_UserArray_GetSize, size_t, const ovrUserArrayHandle obj)
{
	auto ret = ovr_UserArray_GetSize_def(obj);
	log("ovr_UserArray_GetSize called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_UserArray_HasNextPage, bool, const ovrUserArrayHandle obj)
{
	auto ret = ovr_UserArray_HasNextPage_def(obj);
	log("ovr_UserArray_HasNextPage called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetUserArray, ovrUserArrayHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetUserArray_def(obj);
	log("ovr_Message_GetUserArray called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_User_GetLoggedInUserFriends, ovrRequest, )
{
	auto ret = ovr_User_GetLoggedInUserFriends_def();
	log("ovr_User_GetLoggedInUserFriends called with  and returned %d",  ret);
	return ret;
}

void requestFriends() {
    log("Requesting friends");
    friendIds.clear();
    ovrRequest req = ovr_User_GetLoggedInUserFriends_def();
    knownRequests.insert(req);
}

void getFriendIdCsv(const ovrMessageHandle obj)
{
    if (ovr_Message_IsError_def(obj)) {
        log("get friends message response was an error!");
        ovr_FreeMessage_def(obj);
        return;
    }
    log("getting friend ids csv");
    ovrUserArrayHandle userArrayHandle = ovr_Message_GetUserArray_def(obj);
    size_t size = ovr_UserArray_GetSize_def(userArrayHandle);
    log("friends size is %d", size);
    for (int i = 0; i < size; i++) {
        ovrUserHandle userHandle = ovr_UserArray_GetElement_def(userArrayHandle, i);
        ovrID userId = ovr_User_GetID_def(userHandle);
        if (friendIds.length() > 0)         {
            friendIds.append(",");
        }
        friendIds.append(std::to_string(userId));
    }
    ovr_FreeMessage_def(obj);
    //todo: more pages?  how does that work?
    //ovr_UserArray_HasNextPage?    
}

bool friendsUpdated = false;
HOOK_DEF(ovr_PopMessage, ovrMessageHandle)
{
    //todo: sort of stupid, should hook platform init or something.
    //this assumes things are initted by the time the message loop is being read
    if (!friendsUpdated) {
        requestFriends();
        friendsUpdated = true;
    }
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

    //check and see if the request is a known one that this code generated rather than the game.  if so, it will be handled by this code.
    ovrRequest req = ovr_Message_GetRequestID_def(handle);
    if (knownRequests.find(req) != knownRequests.end()) {
        //now that it's been handled, un-know it
        knownRequests.erase(req);
        switch (type) {
            case ovrMessageType::ovrMessage_User_GetLoggedInUserFriends:
            getFriendIdCsv(handle);
            break;
        }
    } else {
        return handle;
    }
}
HOOK_DEF(ovr_Leaderboard_WriteEntry, ovrRequest, const char *leaderboardName, long long score, const void *extraData, unsigned int extraDataLength, bool forceUpdate)
{
    if (isCustomSong(leaderboardName)) {
        auto msg = customLeaderboardUpdate(leaderboardName, score);
        log("%s is a custom song, intercepting ovr_Leaderboard_WriteEntry request and returning request %d", leaderboardName, msg->Request);
        return (ovrRequest)msg->Request;
    }
	auto ret = ovr_Leaderboard_WriteEntry_def(leaderboardName, score, extraData, extraDataLength, forceUpdate);
	log("ovr_Leaderboard_WriteEntry called with %d %d %d %d %d  and returned %d", leaderboardName, score, extraData, extraDataLength, forceUpdate,  ret);
	return ret;
}

void initLeaderboardHooks() {
    void *ovrplatformHandle = dlopen("libovrplatformloader.so", RTLD_NOW);

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
    INIT_HOOK(ovrplatformHandle, ovrMessageType_ToString);
    INIT_HOOK(ovrplatformHandle, ovr_Message_GetLeaderboardUpdateStatus);
    INIT_HOOK(ovrplatformHandle, ovr_LeaderboardUpdateStatus_GetDidUpdate);

    //I think these don't need to be hooked, just loaded
    INIT_HOOK(ovrplatformHandle, ovr_UserArray_GetElement);
    INIT_HOOK(ovrplatformHandle, ovr_UserArray_GetNextUrl);
    INIT_HOOK(ovrplatformHandle, ovr_UserArray_GetSize);
    INIT_HOOK(ovrplatformHandle, ovr_UserArray_HasNextPage);
    INIT_HOOK(ovrplatformHandle, ovr_Message_GetUserArray);
    INIT_HOOK(ovrplatformHandle, ovr_User_GetLoggedInUserFriends);

}