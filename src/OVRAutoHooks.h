#include "Utils.h"
#include "inline-hook/And64InlineHook.hpp"
#include "../OVRPlatformSDK/Include/OVR_AbuseReportOptions.h"
#include "../OVRPlatformSDK/Include/OVR_AbuseReportRecording.h"
#include "../OVRPlatformSDK/Include/OVR_AbuseReportType.h"
#include "../OVRPlatformSDK/Include/OVR_AchievementDefinition.h"
#include "../OVRPlatformSDK/Include/OVR_AchievementDefinitionArray.h"
#include "../OVRPlatformSDK/Include/OVR_AchievementProgress.h"
#include "../OVRPlatformSDK/Include/OVR_AchievementProgressArray.h"
#include "../OVRPlatformSDK/Include/OVR_AchievementType.h"
#include "../OVRPlatformSDK/Include/OVR_AchievementUpdate.h"
#include "../OVRPlatformSDK/Include/OVR_ApplicationOptions.h"
#include "../OVRPlatformSDK/Include/OVR_ApplicationVersion.h"
#include "../OVRPlatformSDK/Include/OVR_AssetDetails.h"
#include "../OVRPlatformSDK/Include/OVR_AssetDetailsArray.h"
#include "../OVRPlatformSDK/Include/OVR_AssetFileDeleteResult.h"
#include "../OVRPlatformSDK/Include/OVR_AssetFileDownloadCancelResult.h"
#include "../OVRPlatformSDK/Include/OVR_AssetFileDownloadResult.h"
#include "../OVRPlatformSDK/Include/OVR_AssetFileDownloadUpdate.h"
#include "../OVRPlatformSDK/Include/OVR_CalApplicationFinalized.h"
#include "../OVRPlatformSDK/Include/OVR_CalApplicationProposed.h"
#include "../OVRPlatformSDK/Include/OVR_CalApplicationSuggestion.h"
#include "../OVRPlatformSDK/Include/OVR_CalApplicationSuggestionArray.h"
#include "../OVRPlatformSDK/Include/OVR_CloudStorageConflictMetadata.h"
#include "../OVRPlatformSDK/Include/OVR_CloudStorageData.h"
#include "../OVRPlatformSDK/Include/OVR_CloudStorageDataStatus.h"
#include "../OVRPlatformSDK/Include/OVR_CloudStorageMetadata.h"
#include "../OVRPlatformSDK/Include/OVR_CloudStorageMetadataArray.h"
#include "../OVRPlatformSDK/Include/OVR_CloudStorageUpdateResponse.h"
#include "../OVRPlatformSDK/Include/OVR_CloudStorageUpdateStatus.h"
#include "../OVRPlatformSDK/Include/OVR_DataStore.h"
#include "../OVRPlatformSDK/Include/OVR_Error.h"
#include "../OVRPlatformSDK/Include/OVR_Functions_ApplicationLifecycle.h"
#include "../OVRPlatformSDK/Include/OVR_Functions_Networking.h"
#include "../OVRPlatformSDK/Include/OVR_Functions_Voip.h"
#include "../OVRPlatformSDK/Include/OVR_HttpTransferUpdate.h"
#include "../OVRPlatformSDK/Include/OVR_InstalledApplication.h"
#include "../OVRPlatformSDK/Include/OVR_InstalledApplicationArray.h"
#include "../OVRPlatformSDK/Include/OVR_KeyValuePairType.h"
#include "../OVRPlatformSDK/Include/OVR_LanguagePackInfo.h"
#include "../OVRPlatformSDK/Include/OVR_LaunchBlockFlowResult.h"
#include "../OVRPlatformSDK/Include/OVR_LaunchDetails.h"
#include "../OVRPlatformSDK/Include/OVR_LaunchFriendRequestFlowResult.h"
#include "../OVRPlatformSDK/Include/OVR_LaunchReportFlowResult.h"
#include "../OVRPlatformSDK/Include/OVR_LaunchType.h"
#include "../OVRPlatformSDK/Include/OVR_LaunchUnblockFlowResult.h"
#include "../OVRPlatformSDK/Include/OVR_LeaderboardEntry.h"
#include "../OVRPlatformSDK/Include/OVR_LeaderboardEntryArray.h"
#include "../OVRPlatformSDK/Include/OVR_LeaderboardFilterType.h"
#include "../OVRPlatformSDK/Include/OVR_LeaderboardStartAt.h"
#include "../OVRPlatformSDK/Include/OVR_LeaderboardUpdateStatus.h"
#include "../OVRPlatformSDK/Include/OVR_LinkedAccount.h"
#include "../OVRPlatformSDK/Include/OVR_LinkedAccountArray.h"
#include "../OVRPlatformSDK/Include/OVR_LivestreamingApplicationStatus.h"
#include "../OVRPlatformSDK/Include/OVR_LivestreamingAudience.h"
#include "../OVRPlatformSDK/Include/OVR_LivestreamingMicrophoneStatus.h"
#include "../OVRPlatformSDK/Include/OVR_LivestreamingStartResult.h"
#include "../OVRPlatformSDK/Include/OVR_LivestreamingStartStatus.h"
#include "../OVRPlatformSDK/Include/OVR_LivestreamingStatus.h"
#include "../OVRPlatformSDK/Include/OVR_LivestreamingVideoStats.h"
#include "../OVRPlatformSDK/Include/OVR_MatchmakingAdminSnapshot.h"
#include "../OVRPlatformSDK/Include/OVR_MatchmakingAdminSnapshotCandidate.h"
#include "../OVRPlatformSDK/Include/OVR_MatchmakingAdminSnapshotCandidateArray.h"
#include "../OVRPlatformSDK/Include/OVR_MatchmakingBrowseResult.h"
#include "../OVRPlatformSDK/Include/OVR_MatchmakingCriterionImportance.h"
#include "../OVRPlatformSDK/Include/OVR_MatchmakingEnqueuedUser.h"
#include "../OVRPlatformSDK/Include/OVR_MatchmakingEnqueuedUserArray.h"
#include "../OVRPlatformSDK/Include/OVR_MatchmakingEnqueueResult.h"
#include "../OVRPlatformSDK/Include/OVR_MatchmakingEnqueueResultAndRoom.h"
#include "../OVRPlatformSDK/Include/OVR_MatchmakingOptions.h"
#include "../OVRPlatformSDK/Include/OVR_MatchmakingRoom.h"
#include "../OVRPlatformSDK/Include/OVR_MatchmakingRoomArray.h"
#include "../OVRPlatformSDK/Include/OVR_MatchmakingStatApproach.h"
#include "../OVRPlatformSDK/Include/OVR_MatchmakingStats.h"
#include "../OVRPlatformSDK/Include/OVR_MediaContentType.h"
#include "../OVRPlatformSDK/Include/OVR_Message.h"
#include "../OVRPlatformSDK/Include/OVR_MessageType.h"
#include "../OVRPlatformSDK/Include/OVR_Microphone.h"
#include "../OVRPlatformSDK/Include/OVR_NetworkingPeer.h"
#include "../OVRPlatformSDK/Include/OVR_OrgScopedID.h"
#include "../OVRPlatformSDK/Include/OVR_Packet.h"
#include "../OVRPlatformSDK/Include/OVR_Party.h"
#include "../OVRPlatformSDK/Include/OVR_PartyID.h"
#include "../OVRPlatformSDK/Include/OVR_PartyUpdateAction.h"
#include "../OVRPlatformSDK/Include/OVR_PartyUpdateNotification.h"
#include "../OVRPlatformSDK/Include/OVR_PeerConnectionState.h"
#include "../OVRPlatformSDK/Include/OVR_PermissionGrantStatus.h"
#include "../OVRPlatformSDK/Include/OVR_PermissionType.h"
#include "../OVRPlatformSDK/Include/OVR_Pid.h"
#include "../OVRPlatformSDK/Include/OVR_PidArray.h"
#include "../OVRPlatformSDK/Include/OVR_PingResult.h"
#include "../OVRPlatformSDK/Include/OVR_Platform.h"
#include "../OVRPlatformSDK/Include/OVR_PlatformInitialize.h"
#include "../OVRPlatformSDK/Include/OVR_PlatformInitializeResult.h"
#include "../OVRPlatformSDK/Include/OVR_Product.h"
#include "../OVRPlatformSDK/Include/OVR_ProductArray.h"
#include "../OVRPlatformSDK/Include/OVR_Purchase.h"
#include "../OVRPlatformSDK/Include/OVR_PurchaseArray.h"
#include "../OVRPlatformSDK/Include/OVR_Requests_Achievements.h"
#include "../OVRPlatformSDK/Include/OVR_Requests_Application.h"
#include "../OVRPlatformSDK/Include/OVR_Requests_ApplicationLifecycle.h"
#include "../OVRPlatformSDK/Include/OVR_Requests_AssetFile.h"
#include "../OVRPlatformSDK/Include/OVR_Requests_CloudStorage.h"
#include "../OVRPlatformSDK/Include/OVR_Requests_Entitlement.h"
#include "../OVRPlatformSDK/Include/OVR_Requests_IAP.h"
#include "../OVRPlatformSDK/Include/OVR_Requests_LanguagePack.h"
#include "../OVRPlatformSDK/Include/OVR_Requests_Leaderboard.h"
#include "../OVRPlatformSDK/Include/OVR_Requests_Livestreaming.h"
#include "../OVRPlatformSDK/Include/OVR_Requests_Matchmaking.h"
#include "../OVRPlatformSDK/Include/OVR_Requests_Media.h"
#include "../OVRPlatformSDK/Include/OVR_Requests_Notification.h"
#include "../OVRPlatformSDK/Include/OVR_Requests_Party.h"
#include "../OVRPlatformSDK/Include/OVR_Requests_Room.h"
#include "../OVRPlatformSDK/Include/OVR_Requests_User.h"
#include "../OVRPlatformSDK/Include/OVR_Requests_Voip.h"
#include "../OVRPlatformSDK/Include/OVR_Room.h"
#include "../OVRPlatformSDK/Include/OVR_RoomArray.h"
#include "../OVRPlatformSDK/Include/OVR_RoomInviteNotification.h"
#include "../OVRPlatformSDK/Include/OVR_RoomInviteNotificationArray.h"
#include "../OVRPlatformSDK/Include/OVR_RoomJoinability.h"
#include "../OVRPlatformSDK/Include/OVR_RoomJoinPolicy.h"
#include "../OVRPlatformSDK/Include/OVR_RoomMembershipLockStatus.h"
#include "../OVRPlatformSDK/Include/OVR_RoomOptions.h"
#include "../OVRPlatformSDK/Include/OVR_RoomType.h"
#include "../OVRPlatformSDK/Include/OVR_SdkAccount.h"
#include "../OVRPlatformSDK/Include/OVR_SdkAccountArray.h"
#include "../OVRPlatformSDK/Include/OVR_SdkAccountType.h"
#include "../OVRPlatformSDK/Include/OVR_SendPolicy.h"
#include "../OVRPlatformSDK/Include/OVR_ServiceProvider.h"
#include "../OVRPlatformSDK/Include/OVR_ShareMediaResult.h"
#include "../OVRPlatformSDK/Include/OVR_ShareMediaStatus.h"
#include "../OVRPlatformSDK/Include/OVR_SystemPermission.h"
#include "../OVRPlatformSDK/Include/OVR_SystemVoipState.h"
#include "../OVRPlatformSDK/Include/OVR_SystemVoipStatus.h"
#include "../OVRPlatformSDK/Include/OVR_TimeWindow.h"
#include "../OVRPlatformSDK/Include/OVR_User.h"
#include "../OVRPlatformSDK/Include/OVR_UserAndRoom.h"
#include "../OVRPlatformSDK/Include/OVR_UserAndRoomArray.h"
#include "../OVRPlatformSDK/Include/OVR_UserArray.h"
#include "../OVRPlatformSDK/Include/OVR_UserOptions.h"
#include "../OVRPlatformSDK/Include/OVR_UserOrdering.h"
#include "../OVRPlatformSDK/Include/OVR_UserPresenceStatus.h"
#include "../OVRPlatformSDK/Include/OVR_UserProof.h"
#include "../OVRPlatformSDK/Include/OVR_UserReportID.h"
#include "../OVRPlatformSDK/Include/OVR_VoipBitrate.h"
#include "../OVRPlatformSDK/Include/OVR_VoipDecoder.h"
#include "../OVRPlatformSDK/Include/OVR_VoipDtxState.h"
#include "../OVRPlatformSDK/Include/OVR_VoipEncoder.h"
#include "../OVRPlatformSDK/Include/OVR_VoipMuteState.h"
#include "../OVRPlatformSDK/Include/OVR_VoipOptions.h"
#include "../OVRPlatformSDK/Include/OVR_VoipSampleRate.h"
#include "../OVRPlatformSDK/Include/OVR_Voip_LowLevel.h"

#include "fakes.h"
HOOK_DEF(ovr_AbuseReportOptions_Create, ovrAbuseReportOptionsHandle, )
{
	auto ret = ovr_AbuseReportOptions_Create_def();
	log("ovr_AbuseReportOptions_Create called with  and returned %d",  ret);
	return ret;
}
HOOK_DEF(ovr_AbuseReportOptions_Destroy, void, ovrAbuseReportOptionsHandle handle)
{
	log("ovr_AbuseReportOptions_Destroy called with %d ", handle);
	ovr_AbuseReportOptions_Destroy_def(handle);
}
HOOK_DEF(ovr_AbuseReportOptions_SetPreventPeopleChooser, void, ovrAbuseReportOptionsHandle handle, bool value)
{
	log("ovr_AbuseReportOptions_SetPreventPeopleChooser called with %d %d ", handle, value);
	ovr_AbuseReportOptions_SetPreventPeopleChooser_def(handle, value);
}
HOOK_DEF(ovr_AbuseReportOptions_SetReportType, void, ovrAbuseReportOptionsHandle handle, ovrAbuseReportType value)
{
	log("ovr_AbuseReportOptions_SetReportType called with %d %d ", handle, value);
	ovr_AbuseReportOptions_SetReportType_def(handle, value);
}
HOOK_DEF(ovr_AbuseReportRecording_GetRecordingUuid, const char *, const ovrAbuseReportRecordingHandle obj)
{
	auto ret = ovr_AbuseReportRecording_GetRecordingUuid_def(obj);
	log("ovr_AbuseReportRecording_GetRecordingUuid called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovrAbuseReportType_ToString, const char*, ovrAbuseReportType value)
{
	auto ret = ovrAbuseReportType_ToString_def(value);
	log("ovrAbuseReportType_ToString called with %d  and returned %s", value,  ret);
	return ret;
}
HOOK_DEF(ovrAbuseReportType_FromString, ovrAbuseReportType, const char* str)
{
	auto ret = ovrAbuseReportType_FromString_def(str);
	log("ovrAbuseReportType_FromString called with %d  and returned %d", str,  ret);
	return ret;
}
HOOK_DEF(ovr_AchievementDefinition_GetName, const char *, const ovrAchievementDefinitionHandle obj)
{
	auto ret = ovr_AchievementDefinition_GetName_def(obj);
	log("ovr_AchievementDefinition_GetName called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_AchievementDefinition_GetBitfieldLength, unsigned int, const ovrAchievementDefinitionHandle obj)
{
	auto ret = ovr_AchievementDefinition_GetBitfieldLength_def(obj);
	log("ovr_AchievementDefinition_GetBitfieldLength called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_AchievementDefinition_GetTarget, unsigned long long, const ovrAchievementDefinitionHandle obj)
{
	auto ret = ovr_AchievementDefinition_GetTarget_def(obj);
	log("ovr_AchievementDefinition_GetTarget called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_AchievementDefinition_GetType, ovrAchievementType, const ovrAchievementDefinitionHandle obj)
{
	auto ret = ovr_AchievementDefinition_GetType_def(obj);
	log("ovr_AchievementDefinition_GetType called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_AchievementDefinitionArray_GetElement, ovrAchievementDefinitionHandle, const ovrAchievementDefinitionArrayHandle obj, size_t index)
{
	auto ret = ovr_AchievementDefinitionArray_GetElement_def(obj, index);
	log("ovr_AchievementDefinitionArray_GetElement called with %d %d  and returned %d", obj, index,  ret);
	return ret;
}
HOOK_DEF(ovr_AchievementDefinitionArray_GetNextUrl, const char *, const ovrAchievementDefinitionArrayHandle obj)
{
	auto ret = ovr_AchievementDefinitionArray_GetNextUrl_def(obj);
	log("ovr_AchievementDefinitionArray_GetNextUrl called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_AchievementDefinitionArray_GetSize, size_t, const ovrAchievementDefinitionArrayHandle obj)
{
	auto ret = ovr_AchievementDefinitionArray_GetSize_def(obj);
	log("ovr_AchievementDefinitionArray_GetSize called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_AchievementDefinitionArray_HasNextPage, bool, const ovrAchievementDefinitionArrayHandle obj)
{
	auto ret = ovr_AchievementDefinitionArray_HasNextPage_def(obj);
	log("ovr_AchievementDefinitionArray_HasNextPage called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_AchievementProgress_GetBitfield, const char *, const ovrAchievementProgressHandle obj)
{
	auto ret = ovr_AchievementProgress_GetBitfield_def(obj);
	log("ovr_AchievementProgress_GetBitfield called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_AchievementProgress_GetCount, unsigned long long, const ovrAchievementProgressHandle obj)
{
	auto ret = ovr_AchievementProgress_GetCount_def(obj);
	log("ovr_AchievementProgress_GetCount called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_AchievementProgress_GetIsUnlocked, bool, const ovrAchievementProgressHandle obj)
{
	auto ret = ovr_AchievementProgress_GetIsUnlocked_def(obj);
	log("ovr_AchievementProgress_GetIsUnlocked called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_AchievementProgress_GetName, const char *, const ovrAchievementProgressHandle obj)
{
	auto ret = ovr_AchievementProgress_GetName_def(obj);
	log("ovr_AchievementProgress_GetName called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_AchievementProgress_GetUnlockTime, unsigned long long, const ovrAchievementProgressHandle obj)
{
	auto ret = ovr_AchievementProgress_GetUnlockTime_def(obj);
	log("ovr_AchievementProgress_GetUnlockTime called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_AchievementProgressArray_GetElement, ovrAchievementProgressHandle, const ovrAchievementProgressArrayHandle obj, size_t index)
{
	auto ret = ovr_AchievementProgressArray_GetElement_def(obj, index);
	log("ovr_AchievementProgressArray_GetElement called with %d %d  and returned %d", obj, index,  ret);
	return ret;
}
HOOK_DEF(ovr_AchievementProgressArray_GetNextUrl, const char *, const ovrAchievementProgressArrayHandle obj)
{
	auto ret = ovr_AchievementProgressArray_GetNextUrl_def(obj);
	log("ovr_AchievementProgressArray_GetNextUrl called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_AchievementProgressArray_GetSize, size_t, const ovrAchievementProgressArrayHandle obj)
{
	auto ret = ovr_AchievementProgressArray_GetSize_def(obj);
	log("ovr_AchievementProgressArray_GetSize called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_AchievementProgressArray_HasNextPage, bool, const ovrAchievementProgressArrayHandle obj)
{
	auto ret = ovr_AchievementProgressArray_HasNextPage_def(obj);
	log("ovr_AchievementProgressArray_HasNextPage called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovrAchievementType_ToString, const char*, ovrAchievementType value)
{
	auto ret = ovrAchievementType_ToString_def(value);
	log("ovrAchievementType_ToString called with %d  and returned %s", value,  ret);
	return ret;
}
HOOK_DEF(ovrAchievementType_FromString, ovrAchievementType, const char* str)
{
	auto ret = ovrAchievementType_FromString_def(str);
	log("ovrAchievementType_FromString called with %d  and returned %d", str,  ret);
	return ret;
}
HOOK_DEF(ovr_AchievementUpdate_GetJustUnlocked, bool, const ovrAchievementUpdateHandle obj)
{
	auto ret = ovr_AchievementUpdate_GetJustUnlocked_def(obj);
	log("ovr_AchievementUpdate_GetJustUnlocked called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_AchievementUpdate_GetName, const char *, const ovrAchievementUpdateHandle obj)
{
	auto ret = ovr_AchievementUpdate_GetName_def(obj);
	log("ovr_AchievementUpdate_GetName called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_ApplicationOptions_Create, ovrApplicationOptionsHandle, )
{
	auto ret = ovr_ApplicationOptions_Create_def();
	log("ovr_ApplicationOptions_Create called with  and returned %d",  ret);
	return ret;
}
HOOK_DEF(ovr_ApplicationOptions_Destroy, void, ovrApplicationOptionsHandle handle)
{
	log("ovr_ApplicationOptions_Destroy called with %d ", handle);
	ovr_ApplicationOptions_Destroy_def(handle);
}
HOOK_DEF(ovr_ApplicationOptions_SetDeeplinkMessage, void, ovrApplicationOptionsHandle handle, const char * value)
{
	log("ovr_ApplicationOptions_SetDeeplinkMessage called with %d %d ", handle, value);
	ovr_ApplicationOptions_SetDeeplinkMessage_def(handle, value);
}
HOOK_DEF(ovr_ApplicationVersion_GetCurrentCode, int, const ovrApplicationVersionHandle obj)
{
	auto ret = ovr_ApplicationVersion_GetCurrentCode_def(obj);
	log("ovr_ApplicationVersion_GetCurrentCode called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_ApplicationVersion_GetCurrentName, const char *, const ovrApplicationVersionHandle obj)
{
	auto ret = ovr_ApplicationVersion_GetCurrentName_def(obj);
	log("ovr_ApplicationVersion_GetCurrentName called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_ApplicationVersion_GetLatestCode, int, const ovrApplicationVersionHandle obj)
{
	auto ret = ovr_ApplicationVersion_GetLatestCode_def(obj);
	log("ovr_ApplicationVersion_GetLatestCode called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_ApplicationVersion_GetLatestName, const char *, const ovrApplicationVersionHandle obj)
{
	auto ret = ovr_ApplicationVersion_GetLatestName_def(obj);
	log("ovr_ApplicationVersion_GetLatestName called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_AssetDetails_GetAssetId, ovrID, const ovrAssetDetailsHandle obj)
{
	auto ret = ovr_AssetDetails_GetAssetId_def(obj);
	log("ovr_AssetDetails_GetAssetId called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_AssetDetails_GetAssetType, const char *, const ovrAssetDetailsHandle obj)
{
	auto ret = ovr_AssetDetails_GetAssetType_def(obj);
	log("ovr_AssetDetails_GetAssetType called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_AssetDetails_GetDownloadStatus, const char *, const ovrAssetDetailsHandle obj)
{
	auto ret = ovr_AssetDetails_GetDownloadStatus_def(obj);
	log("ovr_AssetDetails_GetDownloadStatus called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_AssetDetails_GetFilepath, const char *, const ovrAssetDetailsHandle obj)
{
	auto ret = ovr_AssetDetails_GetFilepath_def(obj);
	log("ovr_AssetDetails_GetFilepath called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_AssetDetails_GetIapStatus, const char *, const ovrAssetDetailsHandle obj)
{
	auto ret = ovr_AssetDetails_GetIapStatus_def(obj);
	log("ovr_AssetDetails_GetIapStatus called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_AssetDetails_GetLanguage, ovrLanguagePackInfoHandle, const ovrAssetDetailsHandle obj)
{
	auto ret = ovr_AssetDetails_GetLanguage_def(obj);
	log("ovr_AssetDetails_GetLanguage called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_AssetDetailsArray_GetElement, ovrAssetDetailsHandle, const ovrAssetDetailsArrayHandle obj, size_t index)
{
	auto ret = ovr_AssetDetailsArray_GetElement_def(obj, index);
	log("ovr_AssetDetailsArray_GetElement called with %d %d  and returned %d", obj, index,  ret);
	return ret;
}
HOOK_DEF(ovr_AssetDetailsArray_GetSize, size_t, const ovrAssetDetailsArrayHandle obj)
{
	auto ret = ovr_AssetDetailsArray_GetSize_def(obj);
	log("ovr_AssetDetailsArray_GetSize called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_AssetFileDeleteResult_GetAssetFileId, ovrID, const ovrAssetFileDeleteResultHandle obj)
{
	auto ret = ovr_AssetFileDeleteResult_GetAssetFileId_def(obj);
	log("ovr_AssetFileDeleteResult_GetAssetFileId called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_AssetFileDeleteResult_GetAssetId, ovrID, const ovrAssetFileDeleteResultHandle obj)
{
	auto ret = ovr_AssetFileDeleteResult_GetAssetId_def(obj);
	log("ovr_AssetFileDeleteResult_GetAssetId called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_AssetFileDeleteResult_GetFilepath, const char *, const ovrAssetFileDeleteResultHandle obj)
{
	auto ret = ovr_AssetFileDeleteResult_GetFilepath_def(obj);
	log("ovr_AssetFileDeleteResult_GetFilepath called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_AssetFileDeleteResult_GetSuccess, bool, const ovrAssetFileDeleteResultHandle obj)
{
	auto ret = ovr_AssetFileDeleteResult_GetSuccess_def(obj);
	log("ovr_AssetFileDeleteResult_GetSuccess called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_AssetFileDownloadCancelResult_GetAssetFileId, ovrID, const ovrAssetFileDownloadCancelResultHandle obj)
{
	auto ret = ovr_AssetFileDownloadCancelResult_GetAssetFileId_def(obj);
	log("ovr_AssetFileDownloadCancelResult_GetAssetFileId called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_AssetFileDownloadCancelResult_GetAssetId, ovrID, const ovrAssetFileDownloadCancelResultHandle obj)
{
	auto ret = ovr_AssetFileDownloadCancelResult_GetAssetId_def(obj);
	log("ovr_AssetFileDownloadCancelResult_GetAssetId called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_AssetFileDownloadCancelResult_GetFilepath, const char *, const ovrAssetFileDownloadCancelResultHandle obj)
{
	auto ret = ovr_AssetFileDownloadCancelResult_GetFilepath_def(obj);
	log("ovr_AssetFileDownloadCancelResult_GetFilepath called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_AssetFileDownloadCancelResult_GetSuccess, bool, const ovrAssetFileDownloadCancelResultHandle obj)
{
	auto ret = ovr_AssetFileDownloadCancelResult_GetSuccess_def(obj);
	log("ovr_AssetFileDownloadCancelResult_GetSuccess called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_AssetFileDownloadResult_GetAssetId, ovrID, const ovrAssetFileDownloadResultHandle obj)
{
	auto ret = ovr_AssetFileDownloadResult_GetAssetId_def(obj);
	log("ovr_AssetFileDownloadResult_GetAssetId called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_AssetFileDownloadResult_GetFilepath, const char *, const ovrAssetFileDownloadResultHandle obj)
{
	auto ret = ovr_AssetFileDownloadResult_GetFilepath_def(obj);
	log("ovr_AssetFileDownloadResult_GetFilepath called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_AssetFileDownloadUpdate_GetAssetFileId, ovrID, const ovrAssetFileDownloadUpdateHandle obj)
{
	auto ret = ovr_AssetFileDownloadUpdate_GetAssetFileId_def(obj);
	log("ovr_AssetFileDownloadUpdate_GetAssetFileId called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_AssetFileDownloadUpdate_GetAssetId, ovrID, const ovrAssetFileDownloadUpdateHandle obj)
{
	auto ret = ovr_AssetFileDownloadUpdate_GetAssetId_def(obj);
	log("ovr_AssetFileDownloadUpdate_GetAssetId called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_AssetFileDownloadUpdate_GetBytesTotal, unsigned int, const ovrAssetFileDownloadUpdateHandle obj)
{
	auto ret = ovr_AssetFileDownloadUpdate_GetBytesTotal_def(obj);
	log("ovr_AssetFileDownloadUpdate_GetBytesTotal called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_AssetFileDownloadUpdate_GetBytesTransferred, int, const ovrAssetFileDownloadUpdateHandle obj)
{
	auto ret = ovr_AssetFileDownloadUpdate_GetBytesTransferred_def(obj);
	log("ovr_AssetFileDownloadUpdate_GetBytesTransferred called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_AssetFileDownloadUpdate_GetCompleted, bool, const ovrAssetFileDownloadUpdateHandle obj)
{
	auto ret = ovr_AssetFileDownloadUpdate_GetCompleted_def(obj);
	log("ovr_AssetFileDownloadUpdate_GetCompleted called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_CalApplicationFinalized_GetCountdownMS, int, const ovrCalApplicationFinalizedHandle obj)
{
	auto ret = ovr_CalApplicationFinalized_GetCountdownMS_def(obj);
	log("ovr_CalApplicationFinalized_GetCountdownMS called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_CalApplicationFinalized_GetID, ovrID, const ovrCalApplicationFinalizedHandle obj)
{
	auto ret = ovr_CalApplicationFinalized_GetID_def(obj);
	log("ovr_CalApplicationFinalized_GetID called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_CalApplicationFinalized_GetLaunchDetails, const char *, const ovrCalApplicationFinalizedHandle obj)
{
	auto ret = ovr_CalApplicationFinalized_GetLaunchDetails_def(obj);
	log("ovr_CalApplicationFinalized_GetLaunchDetails called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_CalApplicationProposed_GetID, ovrID, const ovrCalApplicationProposedHandle obj)
{
	auto ret = ovr_CalApplicationProposed_GetID_def(obj);
	log("ovr_CalApplicationProposed_GetID called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_CalApplicationSuggestion_GetID, ovrID, const ovrCalApplicationSuggestionHandle obj)
{
	auto ret = ovr_CalApplicationSuggestion_GetID_def(obj);
	log("ovr_CalApplicationSuggestion_GetID called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_CalApplicationSuggestion_GetSocialContext, const char *, const ovrCalApplicationSuggestionHandle obj)
{
	auto ret = ovr_CalApplicationSuggestion_GetSocialContext_def(obj);
	log("ovr_CalApplicationSuggestion_GetSocialContext called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_CalApplicationSuggestionArray_GetElement, ovrCalApplicationSuggestionHandle, const ovrCalApplicationSuggestionArrayHandle obj, size_t index)
{
	auto ret = ovr_CalApplicationSuggestionArray_GetElement_def(obj, index);
	log("ovr_CalApplicationSuggestionArray_GetElement called with %d %d  and returned %d", obj, index,  ret);
	return ret;
}
HOOK_DEF(ovr_CalApplicationSuggestionArray_GetSize, size_t, const ovrCalApplicationSuggestionArrayHandle obj)
{
	auto ret = ovr_CalApplicationSuggestionArray_GetSize_def(obj);
	log("ovr_CalApplicationSuggestionArray_GetSize called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_CloudStorageConflictMetadata_GetLocal, ovrCloudStorageMetadataHandle, const ovrCloudStorageConflictMetadataHandle obj)
{
	auto ret = ovr_CloudStorageConflictMetadata_GetLocal_def(obj);
	log("ovr_CloudStorageConflictMetadata_GetLocal called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_CloudStorageConflictMetadata_GetRemote, ovrCloudStorageMetadataHandle, const ovrCloudStorageConflictMetadataHandle obj)
{
	auto ret = ovr_CloudStorageConflictMetadata_GetRemote_def(obj);
	log("ovr_CloudStorageConflictMetadata_GetRemote called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_CloudStorageData_GetBucket, const char *, const ovrCloudStorageDataHandle obj)
{
	auto ret = ovr_CloudStorageData_GetBucket_def(obj);
	log("ovr_CloudStorageData_GetBucket called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_CloudStorageData_GetData, const void *, const ovrCloudStorageDataHandle obj)
{
	auto ret = ovr_CloudStorageData_GetData_def(obj);
	log("ovr_CloudStorageData_GetData called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_CloudStorageData_GetDataSize, unsigned int, const ovrCloudStorageDataHandle obj)
{
	auto ret = ovr_CloudStorageData_GetDataSize_def(obj);
	log("ovr_CloudStorageData_GetDataSize called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_CloudStorageData_GetKey, const char *, const ovrCloudStorageDataHandle obj)
{
	auto ret = ovr_CloudStorageData_GetKey_def(obj);
	log("ovr_CloudStorageData_GetKey called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovrCloudStorageDataStatus_ToString, const char*, ovrCloudStorageDataStatus value)
{
	auto ret = ovrCloudStorageDataStatus_ToString_def(value);
	log("ovrCloudStorageDataStatus_ToString called with %d  and returned %s", value,  ret);
	return ret;
}
HOOK_DEF(ovrCloudStorageDataStatus_FromString, ovrCloudStorageDataStatus, const char* str)
{
	auto ret = ovrCloudStorageDataStatus_FromString_def(str);
	log("ovrCloudStorageDataStatus_FromString called with %d  and returned %d", str,  ret);
	return ret;
}
HOOK_DEF(ovr_CloudStorageMetadata_GetBucket, const char *, const ovrCloudStorageMetadataHandle obj)
{
	auto ret = ovr_CloudStorageMetadata_GetBucket_def(obj);
	log("ovr_CloudStorageMetadata_GetBucket called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_CloudStorageMetadata_GetCounter, long long, const ovrCloudStorageMetadataHandle obj)
{
	auto ret = ovr_CloudStorageMetadata_GetCounter_def(obj);
	log("ovr_CloudStorageMetadata_GetCounter called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_CloudStorageMetadata_GetDataSize, unsigned int, const ovrCloudStorageMetadataHandle obj)
{
	auto ret = ovr_CloudStorageMetadata_GetDataSize_def(obj);
	log("ovr_CloudStorageMetadata_GetDataSize called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_CloudStorageMetadata_GetExtraData, const char *, const ovrCloudStorageMetadataHandle obj)
{
	auto ret = ovr_CloudStorageMetadata_GetExtraData_def(obj);
	log("ovr_CloudStorageMetadata_GetExtraData called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_CloudStorageMetadata_GetKey, const char *, const ovrCloudStorageMetadataHandle obj)
{
	auto ret = ovr_CloudStorageMetadata_GetKey_def(obj);
	log("ovr_CloudStorageMetadata_GetKey called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_CloudStorageMetadata_GetSaveTime, unsigned long long, const ovrCloudStorageMetadataHandle obj)
{
	auto ret = ovr_CloudStorageMetadata_GetSaveTime_def(obj);
	log("ovr_CloudStorageMetadata_GetSaveTime called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_CloudStorageMetadata_GetStatus, ovrCloudStorageDataStatus, const ovrCloudStorageMetadataHandle obj)
{
	auto ret = ovr_CloudStorageMetadata_GetStatus_def(obj);
	log("ovr_CloudStorageMetadata_GetStatus called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_CloudStorageMetadata_GetVersionHandle, ovrCloudStorageVersionHandle, const ovrCloudStorageMetadataHandle obj)
{
	auto ret = ovr_CloudStorageMetadata_GetVersionHandle_def(obj);
	log("ovr_CloudStorageMetadata_GetVersionHandle called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_CloudStorageMetadataArray_GetElement, ovrCloudStorageMetadataHandle, const ovrCloudStorageMetadataArrayHandle obj, size_t index)
{
	auto ret = ovr_CloudStorageMetadataArray_GetElement_def(obj, index);
	log("ovr_CloudStorageMetadataArray_GetElement called with %d %d  and returned %d", obj, index,  ret);
	return ret;
}
HOOK_DEF(ovr_CloudStorageMetadataArray_GetNextUrl, const char *, const ovrCloudStorageMetadataArrayHandle obj)
{
	auto ret = ovr_CloudStorageMetadataArray_GetNextUrl_def(obj);
	log("ovr_CloudStorageMetadataArray_GetNextUrl called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_CloudStorageMetadataArray_GetSize, size_t, const ovrCloudStorageMetadataArrayHandle obj)
{
	auto ret = ovr_CloudStorageMetadataArray_GetSize_def(obj);
	log("ovr_CloudStorageMetadataArray_GetSize called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_CloudStorageMetadataArray_HasNextPage, bool, const ovrCloudStorageMetadataArrayHandle obj)
{
	auto ret = ovr_CloudStorageMetadataArray_HasNextPage_def(obj);
	log("ovr_CloudStorageMetadataArray_HasNextPage called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_CloudStorageUpdateResponse_GetBucket, const char *, const ovrCloudStorageUpdateResponseHandle obj)
{
	auto ret = ovr_CloudStorageUpdateResponse_GetBucket_def(obj);
	log("ovr_CloudStorageUpdateResponse_GetBucket called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_CloudStorageUpdateResponse_GetKey, const char *, const ovrCloudStorageUpdateResponseHandle obj)
{
	auto ret = ovr_CloudStorageUpdateResponse_GetKey_def(obj);
	log("ovr_CloudStorageUpdateResponse_GetKey called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_CloudStorageUpdateResponse_GetStatus, ovrCloudStorageUpdateStatus, const ovrCloudStorageUpdateResponseHandle obj)
{
	auto ret = ovr_CloudStorageUpdateResponse_GetStatus_def(obj);
	log("ovr_CloudStorageUpdateResponse_GetStatus called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_CloudStorageUpdateResponse_GetVersionHandle, ovrCloudStorageVersionHandle, const ovrCloudStorageUpdateResponseHandle obj)
{
	auto ret = ovr_CloudStorageUpdateResponse_GetVersionHandle_def(obj);
	log("ovr_CloudStorageUpdateResponse_GetVersionHandle called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovrCloudStorageUpdateStatus_ToString, const char*, ovrCloudStorageUpdateStatus value)
{
	auto ret = ovrCloudStorageUpdateStatus_ToString_def(value);
	log("ovrCloudStorageUpdateStatus_ToString called with %d  and returned %s", value,  ret);
	return ret;
}
HOOK_DEF(ovrCloudStorageUpdateStatus_FromString, ovrCloudStorageUpdateStatus, const char* str)
{
	auto ret = ovrCloudStorageUpdateStatus_FromString_def(str);
	log("ovrCloudStorageUpdateStatus_FromString called with %d  and returned %d", str,  ret);
	return ret;
}
HOOK_DEF(ovr_DataStore_Contains, unsigned int, const ovrDataStoreHandle obj, const char *key)
{
	auto ret = ovr_DataStore_Contains_def(obj, key);
	log("ovr_DataStore_Contains called with %d %d  and returned %d", obj, key,  ret);
	return ret;
}
HOOK_DEF(ovr_DataStore_GetKey, const char *, const ovrDataStoreHandle obj, int index)
{
	auto ret = ovr_DataStore_GetKey_def(obj, index);
	log("ovr_DataStore_GetKey called with %d %d  and returned %s", obj, index,  ret);
	return ret;
}
HOOK_DEF(ovr_DataStore_GetNumKeys, size_t, const ovrDataStoreHandle obj)
{
	auto ret = ovr_DataStore_GetNumKeys_def(obj);
	log("ovr_DataStore_GetNumKeys called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_DataStore_GetValue, const char *, const ovrDataStoreHandle obj, const char *key)
{
	auto ret = ovr_DataStore_GetValue_def(obj, key);
	log("ovr_DataStore_GetValue called with %d %d  and returned %s", obj, key,  ret);
	return ret;
}
HOOK_DEF(ovr_Error_GetDisplayableMessage, const char *, const ovrErrorHandle obj)
{
	auto ret = ovr_Error_GetDisplayableMessage_def(obj);
	log("ovr_Error_GetDisplayableMessage called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Error_GetMessage, const char *, const ovrErrorHandle obj)
{
	auto ret = ovr_Error_GetMessage_def(obj);
	log("ovr_Error_GetMessage called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Error_GetCode, int, const ovrErrorHandle obj)
{
	auto ret = ovr_Error_GetCode_def(obj);
	log("ovr_Error_GetCode called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Error_GetHttpCode, int, const ovrErrorHandle obj)
{
	auto ret = ovr_Error_GetHttpCode_def(obj);
	log("ovr_Error_GetHttpCode called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_ApplicationLifecycle_GetLaunchDetails, ovrLaunchDetailsHandle, )
{
	auto ret = ovr_ApplicationLifecycle_GetLaunchDetails_def();
	log("ovr_ApplicationLifecycle_GetLaunchDetails called with  and returned %d",  ret);
	return ret;
}
HOOK_DEF(ovr_Net_Accept, void, ovrID peerID)
{
	log("ovr_Net_Accept called with %d ", peerID);
	ovr_Net_Accept_def(peerID);
}
HOOK_DEF(ovr_Net_AcceptForCurrentRoom, bool, )
{
	auto ret = ovr_Net_AcceptForCurrentRoom_def();
	log("ovr_Net_AcceptForCurrentRoom called with  and returned %d",  ret);
	return ret;
}
HOOK_DEF(ovr_Net_Close, void, ovrID peerID)
{
	log("ovr_Net_Close called with %d ", peerID);
	ovr_Net_Close_def(peerID);
}
HOOK_DEF(ovr_Net_CloseForCurrentRoom, void, )
{
	log("ovr_Net_CloseForCurrentRoom called with ");
	ovr_Net_CloseForCurrentRoom_def();
}
HOOK_DEF(ovr_Net_Connect, void, ovrID peerID)
{
	log("ovr_Net_Connect called with %d ", peerID);
	ovr_Net_Connect_def(peerID);
}
HOOK_DEF(ovr_Net_IsConnected, bool, ovrID peerID)
{
	auto ret = ovr_Net_IsConnected_def(peerID);
	log("ovr_Net_IsConnected called with %d  and returned %d", peerID,  ret);
	return ret;
}
HOOK_DEF(ovr_Net_Ping, ovrRequest, ovrID peerID)
{
	auto ret = ovr_Net_Ping_def(peerID);
	log("ovr_Net_Ping called with %d  and returned %d", peerID,  ret);
	return ret;
}
HOOK_DEF(ovr_Net_ReadPacket, ovrPacketHandle, )
{
	auto ret = ovr_Net_ReadPacket_def();
	log("ovr_Net_ReadPacket called with  and returned %d",  ret);
	return ret;
}
HOOK_DEF(ovr_Net_SendPacket, bool, ovrID userID, size_t length, const void *bytes, ovrSendPolicy policy)
{
	auto ret = ovr_Net_SendPacket_def(userID, length, bytes, policy);
	log("ovr_Net_SendPacket called with %d %d %d %d  and returned %d", userID, length, bytes, policy,  ret);
	return ret;
}
HOOK_DEF(ovr_Net_SendPacketToCurrentRoom, bool, size_t length, const void *bytes, ovrSendPolicy policy)
{
	auto ret = ovr_Net_SendPacketToCurrentRoom_def(length, bytes, policy);
	log("ovr_Net_SendPacketToCurrentRoom called with %d %d %d  and returned %d", length, bytes, policy,  ret);
	return ret;
}
HOOK_DEF(ovr_Voip_Accept, void, ovrID userID)
{
	log("ovr_Voip_Accept called with %d ", userID);
	ovr_Voip_Accept_def(userID);
}
HOOK_DEF(ovr_Voip_GetIsConnectionUsingDtx, ovrVoipDtxState, ovrID peerID)
{
	auto ret = ovr_Voip_GetIsConnectionUsingDtx_def(peerID);
	log("ovr_Voip_GetIsConnectionUsingDtx called with %d  and returned %d", peerID,  ret);
	return ret;
}
HOOK_DEF(ovr_Voip_GetLocalBitrate, ovrVoipBitrate, ovrID peerID)
{
	auto ret = ovr_Voip_GetLocalBitrate_def(peerID);
	log("ovr_Voip_GetLocalBitrate called with %d  and returned %d", peerID,  ret);
	return ret;
}
HOOK_DEF(ovr_Voip_GetOutputBufferMaxSize, size_t, )
{
	auto ret = ovr_Voip_GetOutputBufferMaxSize_def();
	log("ovr_Voip_GetOutputBufferMaxSize called with  and returned %d",  ret);
	return ret;
}
HOOK_DEF(ovr_Voip_GetPCM, size_t, ovrID senderID, int16_t *outputBuffer, size_t outputBufferNumElements)
{
	auto ret = ovr_Voip_GetPCM_def(senderID, outputBuffer, outputBufferNumElements);
	log("ovr_Voip_GetPCM called with %d %d %d  and returned %d", senderID, outputBuffer, outputBufferNumElements,  ret);
	return ret;
}
HOOK_DEF(ovr_Voip_GetPCMFloat, size_t, ovrID senderID, float *outputBuffer, size_t outputBufferNumElements)
{
	auto ret = ovr_Voip_GetPCMFloat_def(senderID, outputBuffer, outputBufferNumElements);
	log("ovr_Voip_GetPCMFloat called with %d %d %d  and returned %d", senderID, outputBuffer, outputBufferNumElements,  ret);
	return ret;
}
HOOK_DEF(ovr_Voip_GetPCMSize, size_t, ovrID senderID)
{
	auto ret = ovr_Voip_GetPCMSize_def(senderID);
	log("ovr_Voip_GetPCMSize called with %d  and returned %d", senderID,  ret);
	return ret;
}
HOOK_DEF(ovr_Voip_GetPCMWithTimestamp, size_t, ovrID senderID, int16_t *outputBuffer, size_t outputBufferNumElements, uint32_t *timestamp)
{
	auto ret = ovr_Voip_GetPCMWithTimestamp_def(senderID, outputBuffer, outputBufferNumElements, timestamp);
	log("ovr_Voip_GetPCMWithTimestamp called with %d %d %d %d  and returned %d", senderID, outputBuffer, outputBufferNumElements, timestamp,  ret);
	return ret;
}
HOOK_DEF(ovr_Voip_GetPCMWithTimestampFloat, size_t, ovrID senderID, float *outputBuffer, size_t outputBufferNumElements, uint32_t *timestamp)
{
	auto ret = ovr_Voip_GetPCMWithTimestampFloat_def(senderID, outputBuffer, outputBufferNumElements, timestamp);
	log("ovr_Voip_GetPCMWithTimestampFloat called with %d %d %d %d  and returned %d", senderID, outputBuffer, outputBufferNumElements, timestamp,  ret);
	return ret;
}
HOOK_DEF(ovr_Voip_GetRemoteBitrate, ovrVoipBitrate, ovrID peerID)
{
	auto ret = ovr_Voip_GetRemoteBitrate_def(peerID);
	log("ovr_Voip_GetRemoteBitrate called with %d  and returned %d", peerID,  ret);
	return ret;
}
HOOK_DEF(ovr_Voip_GetSyncTimestamp, uint32_t, ovrID userID)
{
	auto ret = ovr_Voip_GetSyncTimestamp_def(userID);
	log("ovr_Voip_GetSyncTimestamp called with %d  and returned %d", userID,  ret);
	return ret;
}
HOOK_DEF(ovr_Voip_GetSyncTimestampDifference, long long, uint32_t lhs, uint32_t rhs)
{
	auto ret = ovr_Voip_GetSyncTimestampDifference_def(lhs, rhs);
	log("ovr_Voip_GetSyncTimestampDifference called with %d %d  and returned %d", lhs, rhs,  ret);
	return ret;
}
HOOK_DEF(ovr_Voip_GetSystemVoipMicrophoneMuted, ovrVoipMuteState, )
{
	auto ret = ovr_Voip_GetSystemVoipMicrophoneMuted_def();
	log("ovr_Voip_GetSystemVoipMicrophoneMuted called with  and returned %d",  ret);
	return ret;
}
HOOK_DEF(ovr_Voip_GetSystemVoipStatus, ovrSystemVoipStatus, )
{
	auto ret = ovr_Voip_GetSystemVoipStatus_def();
	log("ovr_Voip_GetSystemVoipStatus called with  and returned %d",  ret);
	return ret;
}
HOOK_DEF(ovr_Voip_SetMicrophoneFilterCallback, void, VoipFilterCallback cb)
{
	log("ovr_Voip_SetMicrophoneFilterCallback called with %d ", cb);
	ovr_Voip_SetMicrophoneFilterCallback_def(cb);
}
HOOK_DEF(ovr_Voip_SetMicrophoneMuted, void, ovrVoipMuteState state)
{
	log("ovr_Voip_SetMicrophoneMuted called with %d ", state);
	ovr_Voip_SetMicrophoneMuted_def(state);
}
HOOK_DEF(ovr_Voip_SetNewConnectionOptions, void, ovrVoipOptionsHandle voipOptions)
{
	log("ovr_Voip_SetNewConnectionOptions called with %d ", voipOptions);
	ovr_Voip_SetNewConnectionOptions_def(voipOptions);
}
HOOK_DEF(ovr_Voip_SetOutputSampleRate, void, ovrVoipSampleRate rate)
{
	log("ovr_Voip_SetOutputSampleRate called with %d ", rate);
	ovr_Voip_SetOutputSampleRate_def(rate);
}
HOOK_DEF(ovr_Voip_Start, void, ovrID userID)
{
	log("ovr_Voip_Start called with %d ", userID);
	ovr_Voip_Start_def(userID);
}
HOOK_DEF(ovr_Voip_Stop, void, ovrID userID)
{
	log("ovr_Voip_Stop called with %d ", userID);
	ovr_Voip_Stop_def(userID);
}
HOOK_DEF(ovr_HttpTransferUpdate_GetBytes, const void *, const ovrHttpTransferUpdateHandle obj)
{
	auto ret = ovr_HttpTransferUpdate_GetBytes_def(obj);
	log("ovr_HttpTransferUpdate_GetBytes called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_HttpTransferUpdate_GetID, ovrRequest, const ovrHttpTransferUpdateHandle obj)
{
	auto ret = ovr_HttpTransferUpdate_GetID_def(obj);
	log("ovr_HttpTransferUpdate_GetID called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_HttpTransferUpdate_GetSize, size_t, const ovrHttpTransferUpdateHandle obj)
{
	auto ret = ovr_HttpTransferUpdate_GetSize_def(obj);
	log("ovr_HttpTransferUpdate_GetSize called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_HttpTransferUpdate_IsCompleted, bool, const ovrHttpTransferUpdateHandle obj)
{
	auto ret = ovr_HttpTransferUpdate_IsCompleted_def(obj);
	log("ovr_HttpTransferUpdate_IsCompleted called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_InstalledApplication_GetApplicationId, const char *, const ovrInstalledApplicationHandle obj)
{
	auto ret = ovr_InstalledApplication_GetApplicationId_def(obj);
	log("ovr_InstalledApplication_GetApplicationId called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_InstalledApplication_GetPackageName, const char *, const ovrInstalledApplicationHandle obj)
{
	auto ret = ovr_InstalledApplication_GetPackageName_def(obj);
	log("ovr_InstalledApplication_GetPackageName called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_InstalledApplication_GetStatus, const char *, const ovrInstalledApplicationHandle obj)
{
	auto ret = ovr_InstalledApplication_GetStatus_def(obj);
	log("ovr_InstalledApplication_GetStatus called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_InstalledApplication_GetVersionCode, int, const ovrInstalledApplicationHandle obj)
{
	auto ret = ovr_InstalledApplication_GetVersionCode_def(obj);
	log("ovr_InstalledApplication_GetVersionCode called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_InstalledApplication_GetVersionName, const char *, const ovrInstalledApplicationHandle obj)
{
	auto ret = ovr_InstalledApplication_GetVersionName_def(obj);
	log("ovr_InstalledApplication_GetVersionName called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_InstalledApplicationArray_GetElement, ovrInstalledApplicationHandle, const ovrInstalledApplicationArrayHandle obj, size_t index)
{
	auto ret = ovr_InstalledApplicationArray_GetElement_def(obj, index);
	log("ovr_InstalledApplicationArray_GetElement called with %d %d  and returned %d", obj, index,  ret);
	return ret;
}
HOOK_DEF(ovr_InstalledApplicationArray_GetSize, size_t, const ovrInstalledApplicationArrayHandle obj)
{
	auto ret = ovr_InstalledApplicationArray_GetSize_def(obj);
	log("ovr_InstalledApplicationArray_GetSize called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovrKeyValuePairType_ToString, const char*, ovrKeyValuePairType value)
{
	auto ret = ovrKeyValuePairType_ToString_def(value);
	log("ovrKeyValuePairType_ToString called with %d  and returned %s", value,  ret);
	return ret;
}
HOOK_DEF(ovrKeyValuePairType_FromString, ovrKeyValuePairType, const char* str)
{
	auto ret = ovrKeyValuePairType_FromString_def(str);
	log("ovrKeyValuePairType_FromString called with %d  and returned %d", str,  ret);
	return ret;
}
HOOK_DEF(ovr_LanguagePackInfo_GetEnglishName, const char *, const ovrLanguagePackInfoHandle obj)
{
	auto ret = ovr_LanguagePackInfo_GetEnglishName_def(obj);
	log("ovr_LanguagePackInfo_GetEnglishName called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_LanguagePackInfo_GetNativeName, const char *, const ovrLanguagePackInfoHandle obj)
{
	auto ret = ovr_LanguagePackInfo_GetNativeName_def(obj);
	log("ovr_LanguagePackInfo_GetNativeName called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_LanguagePackInfo_GetTag, const char *, const ovrLanguagePackInfoHandle obj)
{
	auto ret = ovr_LanguagePackInfo_GetTag_def(obj);
	log("ovr_LanguagePackInfo_GetTag called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_LaunchBlockFlowResult_GetDidBlock, bool, const ovrLaunchBlockFlowResultHandle obj)
{
	auto ret = ovr_LaunchBlockFlowResult_GetDidBlock_def(obj);
	log("ovr_LaunchBlockFlowResult_GetDidBlock called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_LaunchBlockFlowResult_GetDidCancel, bool, const ovrLaunchBlockFlowResultHandle obj)
{
	auto ret = ovr_LaunchBlockFlowResult_GetDidCancel_def(obj);
	log("ovr_LaunchBlockFlowResult_GetDidCancel called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_LaunchDetails_GetDeeplinkMessage, const char *, const ovrLaunchDetailsHandle obj)
{
	auto ret = ovr_LaunchDetails_GetDeeplinkMessage_def(obj);
	log("ovr_LaunchDetails_GetDeeplinkMessage called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_LaunchDetails_GetLaunchSource, const char *, const ovrLaunchDetailsHandle obj)
{
	auto ret = ovr_LaunchDetails_GetLaunchSource_def(obj);
	log("ovr_LaunchDetails_GetLaunchSource called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_LaunchDetails_GetUsers, ovrUserArrayHandle, const ovrLaunchDetailsHandle obj)
{
	auto ret = ovr_LaunchDetails_GetUsers_def(obj);
	log("ovr_LaunchDetails_GetUsers called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_LaunchDetails_GetLaunchType, ovrLaunchType, const ovrLaunchDetailsHandle obj)
{
	auto ret = ovr_LaunchDetails_GetLaunchType_def(obj);
	log("ovr_LaunchDetails_GetLaunchType called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_LaunchDetails_GetRoomID, ovrID, const ovrLaunchDetailsHandle obj)
{
	auto ret = ovr_LaunchDetails_GetRoomID_def(obj);
	log("ovr_LaunchDetails_GetRoomID called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_LaunchFriendRequestFlowResult_GetDidCancel, bool, const ovrLaunchFriendRequestFlowResultHandle obj)
{
	auto ret = ovr_LaunchFriendRequestFlowResult_GetDidCancel_def(obj);
	log("ovr_LaunchFriendRequestFlowResult_GetDidCancel called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_LaunchFriendRequestFlowResult_GetDidSendRequest, bool, const ovrLaunchFriendRequestFlowResultHandle obj)
{
	auto ret = ovr_LaunchFriendRequestFlowResult_GetDidSendRequest_def(obj);
	log("ovr_LaunchFriendRequestFlowResult_GetDidSendRequest called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_LaunchReportFlowResult_GetDidCancel, bool, const ovrLaunchReportFlowResultHandle obj)
{
	auto ret = ovr_LaunchReportFlowResult_GetDidCancel_def(obj);
	log("ovr_LaunchReportFlowResult_GetDidCancel called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_LaunchReportFlowResult_GetUserReportId, ovrID, const ovrLaunchReportFlowResultHandle obj)
{
	auto ret = ovr_LaunchReportFlowResult_GetUserReportId_def(obj);
	log("ovr_LaunchReportFlowResult_GetUserReportId called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovrLaunchType_ToString, const char*, ovrLaunchType value)
{
	auto ret = ovrLaunchType_ToString_def(value);
	log("ovrLaunchType_ToString called with %d  and returned %s", value,  ret);
	return ret;
}
HOOK_DEF(ovrLaunchType_FromString, ovrLaunchType, const char* str)
{
	auto ret = ovrLaunchType_FromString_def(str);
	log("ovrLaunchType_FromString called with %d  and returned %d", str,  ret);
	return ret;
}
HOOK_DEF(ovr_LaunchUnblockFlowResult_GetDidCancel, bool, const ovrLaunchUnblockFlowResultHandle obj)
{
	auto ret = ovr_LaunchUnblockFlowResult_GetDidCancel_def(obj);
	log("ovr_LaunchUnblockFlowResult_GetDidCancel called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_LaunchUnblockFlowResult_GetDidUnblock, bool, const ovrLaunchUnblockFlowResultHandle obj)
{
	auto ret = ovr_LaunchUnblockFlowResult_GetDidUnblock_def(obj);
	log("ovr_LaunchUnblockFlowResult_GetDidUnblock called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_LeaderboardEntryArray_HasNextPage, bool, const ovrLeaderboardEntryArrayHandle obj)
{
	auto ret = ovr_LeaderboardEntryArray_HasNextPage_def(obj);
	log("ovr_LeaderboardEntryArray_HasNextPage called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_LeaderboardEntryArray_HasPreviousPage, bool, const ovrLeaderboardEntryArrayHandle obj)
{
	auto ret = ovr_LeaderboardEntryArray_HasPreviousPage_def(obj);
	log("ovr_LeaderboardEntryArray_HasPreviousPage called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovrLeaderboardFilterType_ToString, const char*, ovrLeaderboardFilterType value)
{
	auto ret = ovrLeaderboardFilterType_ToString_def(value);
	log("ovrLeaderboardFilterType_ToString called with %d  and returned %s", value,  ret);
	return ret;
}
HOOK_DEF(ovrLeaderboardFilterType_FromString, ovrLeaderboardFilterType, const char* str)
{
	auto ret = ovrLeaderboardFilterType_FromString_def(str);
	log("ovrLeaderboardFilterType_FromString called with %d  and returned %d", str,  ret);
	return ret;
}
HOOK_DEF(ovrLeaderboardStartAt_ToString, const char*, ovrLeaderboardStartAt value)
{
	auto ret = ovrLeaderboardStartAt_ToString_def(value);
	log("ovrLeaderboardStartAt_ToString called with %d  and returned %s", value,  ret);
	return ret;
}
HOOK_DEF(ovrLeaderboardStartAt_FromString, ovrLeaderboardStartAt, const char* str)
{
	auto ret = ovrLeaderboardStartAt_FromString_def(str);
	log("ovrLeaderboardStartAt_FromString called with %d  and returned %d", str,  ret);
	return ret;
}
HOOK_DEF(ovr_LeaderboardUpdateStatus_GetDidUpdate, bool, const ovrLeaderboardUpdateStatusHandle obj)
{
	auto ret = ovr_LeaderboardUpdateStatus_GetDidUpdate_def(obj);
	log("ovr_LeaderboardUpdateStatus_GetDidUpdate called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_LinkedAccount_GetAccessToken, const char *, const ovrLinkedAccountHandle obj)
{
	auto ret = ovr_LinkedAccount_GetAccessToken_def(obj);
	log("ovr_LinkedAccount_GetAccessToken called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_LinkedAccount_GetServiceProvider, ovrServiceProvider, const ovrLinkedAccountHandle obj)
{
	auto ret = ovr_LinkedAccount_GetServiceProvider_def(obj);
	log("ovr_LinkedAccount_GetServiceProvider called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_LinkedAccount_GetUserId, const char *, const ovrLinkedAccountHandle obj)
{
	auto ret = ovr_LinkedAccount_GetUserId_def(obj);
	log("ovr_LinkedAccount_GetUserId called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_LinkedAccountArray_GetElement, ovrLinkedAccountHandle, const ovrLinkedAccountArrayHandle obj, size_t index)
{
	auto ret = ovr_LinkedAccountArray_GetElement_def(obj, index);
	log("ovr_LinkedAccountArray_GetElement called with %d %d  and returned %d", obj, index,  ret);
	return ret;
}
HOOK_DEF(ovr_LinkedAccountArray_GetSize, size_t, const ovrLinkedAccountArrayHandle obj)
{
	auto ret = ovr_LinkedAccountArray_GetSize_def(obj);
	log("ovr_LinkedAccountArray_GetSize called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_LivestreamingApplicationStatus_GetStreamingEnabled, bool, const ovrLivestreamingApplicationStatusHandle obj)
{
	auto ret = ovr_LivestreamingApplicationStatus_GetStreamingEnabled_def(obj);
	log("ovr_LivestreamingApplicationStatus_GetStreamingEnabled called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovrLivestreamingAudience_ToString, const char*, ovrLivestreamingAudience value)
{
	auto ret = ovrLivestreamingAudience_ToString_def(value);
	log("ovrLivestreamingAudience_ToString called with %d  and returned %s", value,  ret);
	return ret;
}
HOOK_DEF(ovrLivestreamingAudience_FromString, ovrLivestreamingAudience, const char* str)
{
	auto ret = ovrLivestreamingAudience_FromString_def(str);
	log("ovrLivestreamingAudience_FromString called with %d  and returned %d", str,  ret);
	return ret;
}
HOOK_DEF(ovrLivestreamingMicrophoneStatus_ToString, const char*, ovrLivestreamingMicrophoneStatus value)
{
	auto ret = ovrLivestreamingMicrophoneStatus_ToString_def(value);
	log("ovrLivestreamingMicrophoneStatus_ToString called with %d  and returned %s", value,  ret);
	return ret;
}
HOOK_DEF(ovrLivestreamingMicrophoneStatus_FromString, ovrLivestreamingMicrophoneStatus, const char* str)
{
	auto ret = ovrLivestreamingMicrophoneStatus_FromString_def(str);
	log("ovrLivestreamingMicrophoneStatus_FromString called with %d  and returned %d", str,  ret);
	return ret;
}
HOOK_DEF(ovr_LivestreamingStartResult_GetStreamingResult, ovrLivestreamingStartStatus, const ovrLivestreamingStartResultHandle obj)
{
	auto ret = ovr_LivestreamingStartResult_GetStreamingResult_def(obj);
	log("ovr_LivestreamingStartResult_GetStreamingResult called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovrLivestreamingStartStatus_ToString, const char*, ovrLivestreamingStartStatus value)
{
	auto ret = ovrLivestreamingStartStatus_ToString_def(value);
	log("ovrLivestreamingStartStatus_ToString called with %d  and returned %s", value,  ret);
	return ret;
}
HOOK_DEF(ovrLivestreamingStartStatus_FromString, ovrLivestreamingStartStatus, const char* str)
{
	auto ret = ovrLivestreamingStartStatus_FromString_def(str);
	log("ovrLivestreamingStartStatus_FromString called with %d  and returned %d", str,  ret);
	return ret;
}
HOOK_DEF(ovr_LivestreamingStatus_GetCommentsVisible, bool, const ovrLivestreamingStatusHandle obj)
{
	auto ret = ovr_LivestreamingStatus_GetCommentsVisible_def(obj);
	log("ovr_LivestreamingStatus_GetCommentsVisible called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_LivestreamingStatus_GetIsPaused, bool, const ovrLivestreamingStatusHandle obj)
{
	auto ret = ovr_LivestreamingStatus_GetIsPaused_def(obj);
	log("ovr_LivestreamingStatus_GetIsPaused called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_LivestreamingStatus_GetLivestreamingEnabled, bool, const ovrLivestreamingStatusHandle obj)
{
	auto ret = ovr_LivestreamingStatus_GetLivestreamingEnabled_def(obj);
	log("ovr_LivestreamingStatus_GetLivestreamingEnabled called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_LivestreamingStatus_GetLivestreamingType, int, const ovrLivestreamingStatusHandle obj)
{
	auto ret = ovr_LivestreamingStatus_GetLivestreamingType_def(obj);
	log("ovr_LivestreamingStatus_GetLivestreamingType called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_LivestreamingStatus_GetMicEnabled, bool, const ovrLivestreamingStatusHandle obj)
{
	auto ret = ovr_LivestreamingStatus_GetMicEnabled_def(obj);
	log("ovr_LivestreamingStatus_GetMicEnabled called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_LivestreamingVideoStats_GetCommentCount, int, const ovrLivestreamingVideoStatsHandle obj)
{
	auto ret = ovr_LivestreamingVideoStats_GetCommentCount_def(obj);
	log("ovr_LivestreamingVideoStats_GetCommentCount called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_LivestreamingVideoStats_GetReactionCount, int, const ovrLivestreamingVideoStatsHandle obj)
{
	auto ret = ovr_LivestreamingVideoStats_GetReactionCount_def(obj);
	log("ovr_LivestreamingVideoStats_GetReactionCount called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_LivestreamingVideoStats_GetTotalViews, const char *, const ovrLivestreamingVideoStatsHandle obj)
{
	auto ret = ovr_LivestreamingVideoStats_GetTotalViews_def(obj);
	log("ovr_LivestreamingVideoStats_GetTotalViews called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_MatchmakingAdminSnapshot_GetCandidates, ovrMatchmakingAdminSnapshotCandidateArrayHandle, const ovrMatchmakingAdminSnapshotHandle obj)
{
	auto ret = ovr_MatchmakingAdminSnapshot_GetCandidates_def(obj);
	log("ovr_MatchmakingAdminSnapshot_GetCandidates called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_MatchmakingAdminSnapshot_GetMyCurrentThreshold, double, const ovrMatchmakingAdminSnapshotHandle obj)
{
	auto ret = ovr_MatchmakingAdminSnapshot_GetMyCurrentThreshold_def(obj);
	log("ovr_MatchmakingAdminSnapshot_GetMyCurrentThreshold called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_MatchmakingAdminSnapshotCandidate_GetCanMatch, bool, const ovrMatchmakingAdminSnapshotCandidateHandle obj)
{
	auto ret = ovr_MatchmakingAdminSnapshotCandidate_GetCanMatch_def(obj);
	log("ovr_MatchmakingAdminSnapshotCandidate_GetCanMatch called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_MatchmakingAdminSnapshotCandidate_GetMyTotalScore, double, const ovrMatchmakingAdminSnapshotCandidateHandle obj)
{
	auto ret = ovr_MatchmakingAdminSnapshotCandidate_GetMyTotalScore_def(obj);
	log("ovr_MatchmakingAdminSnapshotCandidate_GetMyTotalScore called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_MatchmakingAdminSnapshotCandidate_GetTheirCurrentThreshold, double, const ovrMatchmakingAdminSnapshotCandidateHandle obj)
{
	auto ret = ovr_MatchmakingAdminSnapshotCandidate_GetTheirCurrentThreshold_def(obj);
	log("ovr_MatchmakingAdminSnapshotCandidate_GetTheirCurrentThreshold called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_MatchmakingAdminSnapshotCandidate_GetTheirTotalScore, double, const ovrMatchmakingAdminSnapshotCandidateHandle obj)
{
	auto ret = ovr_MatchmakingAdminSnapshotCandidate_GetTheirTotalScore_def(obj);
	log("ovr_MatchmakingAdminSnapshotCandidate_GetTheirTotalScore called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_MatchmakingAdminSnapshotCandidate_GetTraceId, const char *, const ovrMatchmakingAdminSnapshotCandidateHandle obj)
{
	auto ret = ovr_MatchmakingAdminSnapshotCandidate_GetTraceId_def(obj);
	log("ovr_MatchmakingAdminSnapshotCandidate_GetTraceId called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_MatchmakingAdminSnapshotCandidateArray_GetElement, ovrMatchmakingAdminSnapshotCandidateHandle, const ovrMatchmakingAdminSnapshotCandidateArrayHandle obj, size_t index)
{
	auto ret = ovr_MatchmakingAdminSnapshotCandidateArray_GetElement_def(obj, index);
	log("ovr_MatchmakingAdminSnapshotCandidateArray_GetElement called with %d %d  and returned %d", obj, index,  ret);
	return ret;
}
HOOK_DEF(ovr_MatchmakingAdminSnapshotCandidateArray_GetSize, size_t, const ovrMatchmakingAdminSnapshotCandidateArrayHandle obj)
{
	auto ret = ovr_MatchmakingAdminSnapshotCandidateArray_GetSize_def(obj);
	log("ovr_MatchmakingAdminSnapshotCandidateArray_GetSize called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_MatchmakingBrowseResult_GetEnqueueResult, ovrMatchmakingEnqueueResultHandle, const ovrMatchmakingBrowseResultHandle obj)
{
	auto ret = ovr_MatchmakingBrowseResult_GetEnqueueResult_def(obj);
	log("ovr_MatchmakingBrowseResult_GetEnqueueResult called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_MatchmakingBrowseResult_GetRooms, ovrMatchmakingRoomArrayHandle, const ovrMatchmakingBrowseResultHandle obj)
{
	auto ret = ovr_MatchmakingBrowseResult_GetRooms_def(obj);
	log("ovr_MatchmakingBrowseResult_GetRooms called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovrMatchmakingCriterionImportance_ToString, const char*, ovrMatchmakingCriterionImportance value)
{
	auto ret = ovrMatchmakingCriterionImportance_ToString_def(value);
	log("ovrMatchmakingCriterionImportance_ToString called with %d  and returned %s", value,  ret);
	return ret;
}
HOOK_DEF(ovrMatchmakingCriterionImportance_FromString, ovrMatchmakingCriterionImportance, const char* str)
{
	auto ret = ovrMatchmakingCriterionImportance_FromString_def(str);
	log("ovrMatchmakingCriterionImportance_FromString called with %d  and returned %d", str,  ret);
	return ret;
}
HOOK_DEF(ovr_MatchmakingEnqueuedUser_GetCustomData, ovrDataStoreHandle, const ovrMatchmakingEnqueuedUserHandle obj)
{
	auto ret = ovr_MatchmakingEnqueuedUser_GetCustomData_def(obj);
	log("ovr_MatchmakingEnqueuedUser_GetCustomData called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_MatchmakingEnqueuedUser_GetUser, ovrUserHandle, const ovrMatchmakingEnqueuedUserHandle obj)
{
	auto ret = ovr_MatchmakingEnqueuedUser_GetUser_def(obj);
	log("ovr_MatchmakingEnqueuedUser_GetUser called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_MatchmakingEnqueuedUser_GetAdditionalUserID, ovrID, const ovrMatchmakingEnqueuedUserHandle obj, unsigned int index)
{
	auto ret = ovr_MatchmakingEnqueuedUser_GetAdditionalUserID_def(obj, index);
	log("ovr_MatchmakingEnqueuedUser_GetAdditionalUserID called with %d %d  and returned %d", obj, index,  ret);
	return ret;
}
HOOK_DEF(ovr_MatchmakingEnqueuedUser_GetAdditionalUserIDsSize, unsigned int, const ovrMatchmakingEnqueuedUserHandle obj)
{
	auto ret = ovr_MatchmakingEnqueuedUser_GetAdditionalUserIDsSize_def(obj);
	log("ovr_MatchmakingEnqueuedUser_GetAdditionalUserIDsSize called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_MatchmakingEnqueuedUserArray_GetElement, ovrMatchmakingEnqueuedUserHandle, const ovrMatchmakingEnqueuedUserArrayHandle obj, size_t index)
{
	auto ret = ovr_MatchmakingEnqueuedUserArray_GetElement_def(obj, index);
	log("ovr_MatchmakingEnqueuedUserArray_GetElement called with %d %d  and returned %d", obj, index,  ret);

	return ret;
}
int lastSize;
HOOK_DEF(ovr_MatchmakingEnqueuedUserArray_GetSize, size_t, const ovrMatchmakingEnqueuedUserArrayHandle obj)
{
	auto ret = ovr_MatchmakingEnqueuedUserArray_GetSize_def(obj);
	log("ovr_MatchmakingEnqueuedUserArray_GetSize called with %d  and returned %d", obj,  ret);
	lastSize = ret;
	return ret + 1;
}
HOOK_DEF(ovr_MatchmakingEnqueueResult_GetAdminSnapshot, ovrMatchmakingAdminSnapshotHandle, const ovrMatchmakingEnqueueResultHandle obj)
{
	auto ret = ovr_MatchmakingEnqueueResult_GetAdminSnapshot_def(obj);
	log("ovr_MatchmakingEnqueueResult_GetAdminSnapshot called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_MatchmakingEnqueueResult_GetAverageWait, unsigned int, const ovrMatchmakingEnqueueResultHandle obj)
{
	auto ret = ovr_MatchmakingEnqueueResult_GetAverageWait_def(obj);
	log("ovr_MatchmakingEnqueueResult_GetAverageWait called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_MatchmakingEnqueueResult_GetMatchesInLastHourCount, unsigned int, const ovrMatchmakingEnqueueResultHandle obj)
{
	auto ret = ovr_MatchmakingEnqueueResult_GetMatchesInLastHourCount_def(obj);
	log("ovr_MatchmakingEnqueueResult_GetMatchesInLastHourCount called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_MatchmakingEnqueueResult_GetMaxExpectedWait, unsigned int, const ovrMatchmakingEnqueueResultHandle obj)
{
	auto ret = ovr_MatchmakingEnqueueResult_GetMaxExpectedWait_def(obj);
	log("ovr_MatchmakingEnqueueResult_GetMaxExpectedWait called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_MatchmakingEnqueueResult_GetRecentMatchPercentage, unsigned int, const ovrMatchmakingEnqueueResultHandle obj)
{
	auto ret = ovr_MatchmakingEnqueueResult_GetRecentMatchPercentage_def(obj);
	log("ovr_MatchmakingEnqueueResult_GetRecentMatchPercentage called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_MatchmakingEnqueueResult_GetPool, const char *, const ovrMatchmakingEnqueueResultHandle obj)
{
	auto ret = ovr_MatchmakingEnqueueResult_GetPool_def(obj);
	log("ovr_MatchmakingEnqueueResult_GetPool called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_MatchmakingEnqueueResult_GetRequestHash, const char *, const ovrMatchmakingEnqueueResultHandle obj)
{
	auto ret = ovr_MatchmakingEnqueueResult_GetRequestHash_def(obj);
	log("ovr_MatchmakingEnqueueResult_GetRequestHash called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_MatchmakingEnqueueResultAndRoom_GetMatchmakingEnqueueResult, ovrMatchmakingEnqueueResultHandle, const ovrMatchmakingEnqueueResultAndRoomHandle obj)
{
	auto ret = ovr_MatchmakingEnqueueResultAndRoom_GetMatchmakingEnqueueResult_def(obj);
	log("ovr_MatchmakingEnqueueResultAndRoom_GetMatchmakingEnqueueResult called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_MatchmakingEnqueueResultAndRoom_GetRoom, ovrRoomHandle, const ovrMatchmakingEnqueueResultAndRoomHandle obj)
{
	auto ret = ovr_MatchmakingEnqueueResultAndRoom_GetRoom_def(obj);
	log("ovr_MatchmakingEnqueueResultAndRoom_GetRoom called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_MatchmakingOptions_Create, ovrMatchmakingOptionsHandle, )
{
	auto ret = ovr_MatchmakingOptions_Create_def();
	log("ovr_MatchmakingOptions_Create called with  and returned %d",  ret);
	return ret;
}
HOOK_DEF(ovr_MatchmakingOptions_Destroy, void, ovrMatchmakingOptionsHandle handle)
{
	log("ovr_MatchmakingOptions_Destroy called with %d ", handle);
	ovr_MatchmakingOptions_Destroy_def(handle);
}
HOOK_DEF(ovr_MatchmakingOptions_SetCreateRoomDataStoreString, void, ovrMatchmakingOptionsHandle handle, const char* key, const char* value)
{
	log("ovr_MatchmakingOptions_SetCreateRoomDataStoreString called with %d %d %d ", handle, key, value);
	ovr_MatchmakingOptions_SetCreateRoomDataStoreString_def(handle, key, value);
}
HOOK_DEF(ovr_MatchmakingOptions_ClearCreateRoomDataStore, void, ovrMatchmakingOptionsHandle handle)
{
	log("ovr_MatchmakingOptions_ClearCreateRoomDataStore called with %d ", handle);
	ovr_MatchmakingOptions_ClearCreateRoomDataStore_def(handle);
}
HOOK_DEF(ovr_MatchmakingOptions_SetCreateRoomJoinPolicy, void, ovrMatchmakingOptionsHandle handle, ovrRoomJoinPolicy value)
{
	log("ovr_MatchmakingOptions_SetCreateRoomJoinPolicy called with %d %d ", handle, value);
	ovr_MatchmakingOptions_SetCreateRoomJoinPolicy_def(handle, value);
}
HOOK_DEF(ovr_MatchmakingOptions_SetCreateRoomMaxUsers, void, ovrMatchmakingOptionsHandle handle, unsigned int value)
{
	log("ovr_MatchmakingOptions_SetCreateRoomMaxUsers called with %d %d ", handle, value);
	ovr_MatchmakingOptions_SetCreateRoomMaxUsers_def(handle, value);
}
HOOK_DEF(ovr_MatchmakingOptions_AddEnqueueAdditionalUser, void, ovrMatchmakingOptionsHandle handle, ovrID value)
{
	log("ovr_MatchmakingOptions_AddEnqueueAdditionalUser called with %d %d ", handle, value);
	ovr_MatchmakingOptions_AddEnqueueAdditionalUser_def(handle, value);
}
HOOK_DEF(ovr_MatchmakingOptions_ClearEnqueueAdditionalUsers, void, ovrMatchmakingOptionsHandle handle)
{
	log("ovr_MatchmakingOptions_ClearEnqueueAdditionalUsers called with %d ", handle);
	ovr_MatchmakingOptions_ClearEnqueueAdditionalUsers_def(handle);
}
HOOK_DEF(ovr_MatchmakingOptions_SetEnqueueDataSettingsInt, void, ovrMatchmakingOptionsHandle handle, const char* key, int value)
{
	log("ovr_MatchmakingOptions_SetEnqueueDataSettingsInt called with %d %d %d ", handle, key, value);
	ovr_MatchmakingOptions_SetEnqueueDataSettingsInt_def(handle, key, value);
}
HOOK_DEF(ovr_MatchmakingOptions_SetEnqueueDataSettingsDouble, void, ovrMatchmakingOptionsHandle handle, const char* key, double value)
{
	log("ovr_MatchmakingOptions_SetEnqueueDataSettingsDouble called with %d %d %d ", handle, key, value);
	ovr_MatchmakingOptions_SetEnqueueDataSettingsDouble_def(handle, key, value);
}
HOOK_DEF(ovr_MatchmakingOptions_SetEnqueueDataSettingsString, void, ovrMatchmakingOptionsHandle handle, const char* key, const char* value)
{
	log("ovr_MatchmakingOptions_SetEnqueueDataSettingsString called with %d %d %d ", handle, key, value);
	ovr_MatchmakingOptions_SetEnqueueDataSettingsString_def(handle, key, value);
}
HOOK_DEF(ovr_MatchmakingOptions_ClearEnqueueDataSettings, void, ovrMatchmakingOptionsHandle handle)
{
	log("ovr_MatchmakingOptions_ClearEnqueueDataSettings called with %d ", handle);
	ovr_MatchmakingOptions_ClearEnqueueDataSettings_def(handle);
}
HOOK_DEF(ovr_MatchmakingOptions_SetEnqueueIsDebug, void, ovrMatchmakingOptionsHandle handle, bool value)
{
	log("ovr_MatchmakingOptions_SetEnqueueIsDebug called with %d %d ", handle, value);
	ovr_MatchmakingOptions_SetEnqueueIsDebug_def(handle, value);
}
HOOK_DEF(ovr_MatchmakingOptions_SetEnqueueQueryKey, void, ovrMatchmakingOptionsHandle handle, const char * value)
{
	log("ovr_MatchmakingOptions_SetEnqueueQueryKey called with %d %d ", handle, value);
	ovr_MatchmakingOptions_SetEnqueueQueryKey_def(handle, value);
}
HOOK_DEF(ovr_MatchmakingRoom_GetPingTime, unsigned int, const ovrMatchmakingRoomHandle obj)
{
	auto ret = ovr_MatchmakingRoom_GetPingTime_def(obj);
	log("ovr_MatchmakingRoom_GetPingTime called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_MatchmakingRoom_GetRoom, ovrRoomHandle, const ovrMatchmakingRoomHandle obj)
{
	auto ret = ovr_MatchmakingRoom_GetRoom_def(obj);
	log("ovr_MatchmakingRoom_GetRoom called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_MatchmakingRoom_HasPingTime, bool, const ovrMatchmakingRoomHandle obj)
{
	auto ret = ovr_MatchmakingRoom_HasPingTime_def(obj);
	log("ovr_MatchmakingRoom_HasPingTime called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_MatchmakingRoomArray_GetElement, ovrMatchmakingRoomHandle, const ovrMatchmakingRoomArrayHandle obj, size_t index)
{
	auto ret = ovr_MatchmakingRoomArray_GetElement_def(obj, index);
	log("ovr_MatchmakingRoomArray_GetElement called with %d %d  and returned %d", obj, index,  ret);
	return ret;
}
HOOK_DEF(ovr_MatchmakingRoomArray_GetSize, size_t, const ovrMatchmakingRoomArrayHandle obj)
{
	auto ret = ovr_MatchmakingRoomArray_GetSize_def(obj);
	log("ovr_MatchmakingRoomArray_GetSize called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovrMatchmakingStatApproach_ToString, const char*, ovrMatchmakingStatApproach value)
{
	auto ret = ovrMatchmakingStatApproach_ToString_def(value);
	log("ovrMatchmakingStatApproach_ToString called with %d  and returned %s", value,  ret);
	return ret;
}
HOOK_DEF(ovrMatchmakingStatApproach_FromString, ovrMatchmakingStatApproach, const char* str)
{
	auto ret = ovrMatchmakingStatApproach_FromString_def(str);
	log("ovrMatchmakingStatApproach_FromString called with %d  and returned %d", str,  ret);
	return ret;
}
HOOK_DEF(ovr_MatchmakingStats_GetDrawCount, unsigned int, const ovrMatchmakingStatsHandle obj)
{
	auto ret = ovr_MatchmakingStats_GetDrawCount_def(obj);
	log("ovr_MatchmakingStats_GetDrawCount called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_MatchmakingStats_GetLossCount, unsigned int, const ovrMatchmakingStatsHandle obj)
{
	auto ret = ovr_MatchmakingStats_GetLossCount_def(obj);
	log("ovr_MatchmakingStats_GetLossCount called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_MatchmakingStats_GetSkillLevel, unsigned int, const ovrMatchmakingStatsHandle obj)
{
	auto ret = ovr_MatchmakingStats_GetSkillLevel_def(obj);
	log("ovr_MatchmakingStats_GetSkillLevel called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_MatchmakingStats_GetWinCount, unsigned int, const ovrMatchmakingStatsHandle obj)
{
	auto ret = ovr_MatchmakingStats_GetWinCount_def(obj);
	log("ovr_MatchmakingStats_GetWinCount called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovrMediaContentType_ToString, const char*, ovrMediaContentType value)
{
	auto ret = ovrMediaContentType_ToString_def(value);
	log("ovrMediaContentType_ToString called with %d  and returned %s", value,  ret);
	return ret;
}
HOOK_DEF(ovrMediaContentType_FromString, ovrMediaContentType, const char* str)
{
	auto ret = ovrMediaContentType_FromString_def(str);
	log("ovrMediaContentType_FromString called with %d  and returned %d", str,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetAbuseReportRecording, ovrAbuseReportRecordingHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetAbuseReportRecording_def(obj);
	log("ovr_Message_GetAbuseReportRecording called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetAchievementDefinitionArray, ovrAchievementDefinitionArrayHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetAchievementDefinitionArray_def(obj);
	log("ovr_Message_GetAchievementDefinitionArray called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetAchievementProgressArray, ovrAchievementProgressArrayHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetAchievementProgressArray_def(obj);
	log("ovr_Message_GetAchievementProgressArray called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetAchievementUpdate, ovrAchievementUpdateHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetAchievementUpdate_def(obj);
	log("ovr_Message_GetAchievementUpdate called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetApplicationVersion, ovrApplicationVersionHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetApplicationVersion_def(obj);
	log("ovr_Message_GetApplicationVersion called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetAssetDetails, ovrAssetDetailsHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetAssetDetails_def(obj);
	log("ovr_Message_GetAssetDetails called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetAssetDetailsArray, ovrAssetDetailsArrayHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetAssetDetailsArray_def(obj);
	log("ovr_Message_GetAssetDetailsArray called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetAssetFileDeleteResult, ovrAssetFileDeleteResultHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetAssetFileDeleteResult_def(obj);
	log("ovr_Message_GetAssetFileDeleteResult called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetAssetFileDownloadCancelResult, ovrAssetFileDownloadCancelResultHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetAssetFileDownloadCancelResult_def(obj);
	log("ovr_Message_GetAssetFileDownloadCancelResult called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetAssetFileDownloadResult, ovrAssetFileDownloadResultHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetAssetFileDownloadResult_def(obj);
	log("ovr_Message_GetAssetFileDownloadResult called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetAssetFileDownloadUpdate, ovrAssetFileDownloadUpdateHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetAssetFileDownloadUpdate_def(obj);
	log("ovr_Message_GetAssetFileDownloadUpdate called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetCalApplicationFinalized, ovrCalApplicationFinalizedHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetCalApplicationFinalized_def(obj);
	log("ovr_Message_GetCalApplicationFinalized called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetCalApplicationProposed, ovrCalApplicationProposedHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetCalApplicationProposed_def(obj);
	log("ovr_Message_GetCalApplicationProposed called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetCalApplicationSuggestionArray, ovrCalApplicationSuggestionArrayHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetCalApplicationSuggestionArray_def(obj);
	log("ovr_Message_GetCalApplicationSuggestionArray called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetCloudStorageConflictMetadata, ovrCloudStorageConflictMetadataHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetCloudStorageConflictMetadata_def(obj);
	log("ovr_Message_GetCloudStorageConflictMetadata called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetCloudStorageData, ovrCloudStorageDataHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetCloudStorageData_def(obj);
	log("ovr_Message_GetCloudStorageData called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetCloudStorageMetadata, ovrCloudStorageMetadataHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetCloudStorageMetadata_def(obj);
	log("ovr_Message_GetCloudStorageMetadata called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetCloudStorageMetadataArray, ovrCloudStorageMetadataArrayHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetCloudStorageMetadataArray_def(obj);
	log("ovr_Message_GetCloudStorageMetadataArray called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetCloudStorageUpdateResponse, ovrCloudStorageUpdateResponseHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetCloudStorageUpdateResponse_def(obj);
	log("ovr_Message_GetCloudStorageUpdateResponse called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetError, ovrErrorHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetError_def(obj);
	log("ovr_Message_GetError called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetHttpTransferUpdate, ovrHttpTransferUpdateHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetHttpTransferUpdate_def(obj);
	log("ovr_Message_GetHttpTransferUpdate called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetInstalledApplicationArray, ovrInstalledApplicationArrayHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetInstalledApplicationArray_def(obj);
	log("ovr_Message_GetInstalledApplicationArray called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetLaunchBlockFlowResult, ovrLaunchBlockFlowResultHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetLaunchBlockFlowResult_def(obj);
	log("ovr_Message_GetLaunchBlockFlowResult called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetLaunchFriendRequestFlowResult, ovrLaunchFriendRequestFlowResultHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetLaunchFriendRequestFlowResult_def(obj);
	log("ovr_Message_GetLaunchFriendRequestFlowResult called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetLaunchReportFlowResult, ovrLaunchReportFlowResultHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetLaunchReportFlowResult_def(obj);
	log("ovr_Message_GetLaunchReportFlowResult called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetLaunchUnblockFlowResult, ovrLaunchUnblockFlowResultHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetLaunchUnblockFlowResult_def(obj);
	log("ovr_Message_GetLaunchUnblockFlowResult called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetLeaderboardUpdateStatus, ovrLeaderboardUpdateStatusHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetLeaderboardUpdateStatus_def(obj);
	log("ovr_Message_GetLeaderboardUpdateStatus called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetLinkedAccountArray, ovrLinkedAccountArrayHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetLinkedAccountArray_def(obj);
	log("ovr_Message_GetLinkedAccountArray called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetLivestreamingApplicationStatus, ovrLivestreamingApplicationStatusHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetLivestreamingApplicationStatus_def(obj);
	log("ovr_Message_GetLivestreamingApplicationStatus called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetLivestreamingStartResult, ovrLivestreamingStartResultHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetLivestreamingStartResult_def(obj);
	log("ovr_Message_GetLivestreamingStartResult called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetLivestreamingStatus, ovrLivestreamingStatusHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetLivestreamingStatus_def(obj);
	log("ovr_Message_GetLivestreamingStatus called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetLivestreamingVideoStats, ovrLivestreamingVideoStatsHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetLivestreamingVideoStats_def(obj);
	log("ovr_Message_GetLivestreamingVideoStats called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetMatchmakingAdminSnapshot, ovrMatchmakingAdminSnapshotHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetMatchmakingAdminSnapshot_def(obj);
	log("ovr_Message_GetMatchmakingAdminSnapshot called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetMatchmakingBrowseResult, ovrMatchmakingBrowseResultHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetMatchmakingBrowseResult_def(obj);
	log("ovr_Message_GetMatchmakingBrowseResult called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetMatchmakingEnqueueResult, ovrMatchmakingEnqueueResultHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetMatchmakingEnqueueResult_def(obj);
	log("ovr_Message_GetMatchmakingEnqueueResult called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetMatchmakingEnqueueResultAndRoom, ovrMatchmakingEnqueueResultAndRoomHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetMatchmakingEnqueueResultAndRoom_def(obj);
	log("ovr_Message_GetMatchmakingEnqueueResultAndRoom called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetMatchmakingRoomArray, ovrMatchmakingRoomArrayHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetMatchmakingRoomArray_def(obj);
	log("ovr_Message_GetMatchmakingRoomArray called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetMatchmakingStats, ovrMatchmakingStatsHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetMatchmakingStats_def(obj);
	log("ovr_Message_GetMatchmakingStats called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetNetworkingPeer, ovrNetworkingPeerHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetNetworkingPeer_def(obj);
	log("ovr_Message_GetNetworkingPeer called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetOrgScopedID, ovrOrgScopedIDHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetOrgScopedID_def(obj);
	log("ovr_Message_GetOrgScopedID called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetParty, ovrPartyHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetParty_def(obj);
	log("ovr_Message_GetParty called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetPartyID, ovrPartyIDHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetPartyID_def(obj);
	log("ovr_Message_GetPartyID called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetPartyUpdateNotification, ovrPartyUpdateNotificationHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetPartyUpdateNotification_def(obj);
	log("ovr_Message_GetPartyUpdateNotification called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetPidArray, ovrPidArrayHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetPidArray_def(obj);
	log("ovr_Message_GetPidArray called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetPingResult, ovrPingResultHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetPingResult_def(obj);
	log("ovr_Message_GetPingResult called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetPlatformInitialize, ovrPlatformInitializeHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetPlatformInitialize_def(obj);
	log("ovr_Message_GetPlatformInitialize called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetProductArray, ovrProductArrayHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetProductArray_def(obj);
	log("ovr_Message_GetProductArray called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetPurchase, ovrPurchaseHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetPurchase_def(obj);
	log("ovr_Message_GetPurchase called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetPurchaseArray, ovrPurchaseArrayHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetPurchaseArray_def(obj);
	log("ovr_Message_GetPurchaseArray called with %d  and returned %d", obj,  ret);
	return ret;
}

HOOK_DEF(ovr_Message_GetRoom, ovrRoomHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetRoom_def(obj);
	log("ovr_Message_GetRoom called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetRoomArray, ovrRoomArrayHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetRoomArray_def(obj);
	log("ovr_Message_GetRoomArray called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetRoomInviteNotification, ovrRoomInviteNotificationHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetRoomInviteNotification_def(obj);
	log("ovr_Message_GetRoomInviteNotification called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetRoomInviteNotificationArray, ovrRoomInviteNotificationArrayHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetRoomInviteNotificationArray_def(obj);
	log("ovr_Message_GetRoomInviteNotificationArray called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetSdkAccountArray, ovrSdkAccountArrayHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetSdkAccountArray_def(obj);
	log("ovr_Message_GetSdkAccountArray called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetShareMediaResult, ovrShareMediaResultHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetShareMediaResult_def(obj);
	log("ovr_Message_GetShareMediaResult called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetString, const char *, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetString_def(obj);
	log("ovr_Message_GetString called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetSystemPermission, ovrSystemPermissionHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetSystemPermission_def(obj);
	log("ovr_Message_GetSystemPermission called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetSystemVoipState, ovrSystemVoipStateHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetSystemVoipState_def(obj);
	log("ovr_Message_GetSystemVoipState called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetUser, ovrUserHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetUser_def(obj);
	log("ovr_Message_GetUser called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetUserAndRoomArray, ovrUserAndRoomArrayHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetUserAndRoomArray_def(obj);
	log("ovr_Message_GetUserAndRoomArray called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetUserArray, ovrUserArrayHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetUserArray_def(obj);
	log("ovr_Message_GetUserArray called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetUserProof, ovrUserProofHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetUserProof_def(obj);
	log("ovr_Message_GetUserProof called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Message_GetUserReportID, ovrUserReportIDHandle, const ovrMessageHandle obj)
{
	auto ret = ovr_Message_GetUserReportID_def(obj);
	log("ovr_Message_GetUserReportID called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovrMessageType_ToString, const char*, ovrMessageType value)
{
	auto ret = ovrMessageType_ToString_def(value);
	log("ovrMessageType_ToString called with %d  and returned %s", value,  ret);
	return ret;
}
HOOK_DEF(ovrMessageType_IsNotification, bool, ovrMessageType value)
{
	auto ret = ovrMessageType_IsNotification_def(value);
	log("ovrMessageType_IsNotification called with %d  and returned %d", value,  ret);
	return ret;
}
HOOK_DEF(ovr_Microphone_GetNumSamplesAvailable, size_t, const ovrMicrophoneHandle obj)
{
	auto ret = ovr_Microphone_GetNumSamplesAvailable_def(obj);
	log("ovr_Microphone_GetNumSamplesAvailable called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Microphone_GetOutputBufferMaxSize, size_t, const ovrMicrophoneHandle obj)
{
	auto ret = ovr_Microphone_GetOutputBufferMaxSize_def(obj);
	log("ovr_Microphone_GetOutputBufferMaxSize called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Microphone_GetPCM, size_t, const ovrMicrophoneHandle obj, int16_t *outputBuffer, size_t outputBufferNumElements)
{
	auto ret = ovr_Microphone_GetPCM_def(obj, outputBuffer, outputBufferNumElements);
	log("ovr_Microphone_GetPCM called with %d %d %d  and returned %d", obj, outputBuffer, outputBufferNumElements,  ret);
	return ret;
}
HOOK_DEF(ovr_Microphone_GetPCMFloat, size_t, const ovrMicrophoneHandle obj, float *outputBuffer, size_t outputBufferNumElements)
{
	auto ret = ovr_Microphone_GetPCMFloat_def(obj, outputBuffer, outputBufferNumElements);
	log("ovr_Microphone_GetPCMFloat called with %d %d %d  and returned %d", obj, outputBuffer, outputBufferNumElements,  ret);
	return ret;
}
HOOK_DEF(ovr_Microphone_ReadData, size_t, const ovrMicrophoneHandle obj, float *outputBuffer, size_t outputBufferSize)
{
	auto ret = ovr_Microphone_ReadData_def(obj, outputBuffer, outputBufferSize);
	log("ovr_Microphone_ReadData called with %d %d %d  and returned %d", obj, outputBuffer, outputBufferSize,  ret);
	return ret;
}
HOOK_DEF(ovr_Microphone_SetAcceptableRecordingDelayHint, void, const ovrMicrophoneHandle obj, size_t delayMs)
{
	log("ovr_Microphone_SetAcceptableRecordingDelayHint called with %d %d ", obj, delayMs);
	ovr_Microphone_SetAcceptableRecordingDelayHint_def(obj, delayMs);
}
HOOK_DEF(ovr_Microphone_SetAudioDataAvailableCallback, void, const ovrMicrophoneHandle obj, MicrophoneDataAvailableCallback cb, void *userData)
{
	log("ovr_Microphone_SetAudioDataAvailableCallback called with %d %d %d ", obj, cb, userData);
	ovr_Microphone_SetAudioDataAvailableCallback_def(obj, cb, userData);
}
HOOK_DEF(ovr_Microphone_Start, void, const ovrMicrophoneHandle obj)
{
	log("ovr_Microphone_Start called with %d ", obj);
	ovr_Microphone_Start_def(obj);
}
HOOK_DEF(ovr_Microphone_Stop, void, const ovrMicrophoneHandle obj)
{
	log("ovr_Microphone_Stop called with %d ", obj);
	ovr_Microphone_Stop_def(obj);
}
HOOK_DEF(ovr_NetworkingPeer_GetID, ovrID, const ovrNetworkingPeerHandle obj)
{
	auto ret = ovr_NetworkingPeer_GetID_def(obj);
	log("ovr_NetworkingPeer_GetID called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_NetworkingPeer_GetState, ovrPeerConnectionState, const ovrNetworkingPeerHandle obj)
{
	auto ret = ovr_NetworkingPeer_GetState_def(obj);
	log("ovr_NetworkingPeer_GetState called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_OrgScopedID_GetID, ovrID, const ovrOrgScopedIDHandle obj)
{
	auto ret = ovr_OrgScopedID_GetID_def(obj);
	log("ovr_OrgScopedID_GetID called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Packet_Free, void, const ovrPacketHandle obj)
{
	log("ovr_Packet_Free called with %d ", obj);
	ovr_Packet_Free_def(obj);
}
HOOK_DEF(ovr_Packet_GetBytes, const void *, const ovrPacketHandle obj)
{
	auto ret = ovr_Packet_GetBytes_def(obj);
	log("ovr_Packet_GetBytes called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Packet_GetSendPolicy, ovrSendPolicy, const ovrPacketHandle obj)
{
	auto ret = ovr_Packet_GetSendPolicy_def(obj);
	log("ovr_Packet_GetSendPolicy called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Packet_GetSenderID, ovrID, const ovrPacketHandle obj)
{
	auto ret = ovr_Packet_GetSenderID_def(obj);
	log("ovr_Packet_GetSenderID called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Packet_GetSize, size_t, const ovrPacketHandle obj)
{
	auto ret = ovr_Packet_GetSize_def(obj);
	log("ovr_Packet_GetSize called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Party_GetInvitedUsers, ovrUserArrayHandle, const ovrPartyHandle obj)
{
	auto ret = ovr_Party_GetInvitedUsers_def(obj);
	log("ovr_Party_GetInvitedUsers called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Party_GetLeader, ovrUserHandle, const ovrPartyHandle obj)
{
	auto ret = ovr_Party_GetLeader_def(obj);
	log("ovr_Party_GetLeader called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Party_GetRoom, ovrRoomHandle, const ovrPartyHandle obj)
{
	auto ret = ovr_Party_GetRoom_def(obj);
	log("ovr_Party_GetRoom called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Party_GetUsers, ovrUserArrayHandle, const ovrPartyHandle obj)
{
	auto ret = ovr_Party_GetUsers_def(obj);
	log("ovr_Party_GetUsers called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Party_GetID, ovrID, const ovrPartyHandle obj)
{
	auto ret = ovr_Party_GetID_def(obj);
	log("ovr_Party_GetID called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_PartyID_GetID, ovrID, const ovrPartyIDHandle obj)
{
	auto ret = ovr_PartyID_GetID_def(obj);
	log("ovr_PartyID_GetID called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovrPartyUpdateAction_ToString, const char*, ovrPartyUpdateAction value)
{
	auto ret = ovrPartyUpdateAction_ToString_def(value);
	log("ovrPartyUpdateAction_ToString called with %d  and returned %s", value,  ret);
	return ret;
}
HOOK_DEF(ovrPartyUpdateAction_FromString, ovrPartyUpdateAction, const char* str)
{
	auto ret = ovrPartyUpdateAction_FromString_def(str);
	log("ovrPartyUpdateAction_FromString called with %d  and returned %d", str,  ret);
	return ret;
}
HOOK_DEF(ovr_PartyUpdateNotification_GetAction, ovrPartyUpdateAction, const ovrPartyUpdateNotificationHandle obj)
{
	auto ret = ovr_PartyUpdateNotification_GetAction_def(obj);
	log("ovr_PartyUpdateNotification_GetAction called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_PartyUpdateNotification_GetPartyId, ovrID, const ovrPartyUpdateNotificationHandle obj)
{
	auto ret = ovr_PartyUpdateNotification_GetPartyId_def(obj);
	log("ovr_PartyUpdateNotification_GetPartyId called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_PartyUpdateNotification_GetSenderId, ovrID, const ovrPartyUpdateNotificationHandle obj)
{
	auto ret = ovr_PartyUpdateNotification_GetSenderId_def(obj);
	log("ovr_PartyUpdateNotification_GetSenderId called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_PartyUpdateNotification_GetUpdateTimestamp, const char *, const ovrPartyUpdateNotificationHandle obj)
{
	auto ret = ovr_PartyUpdateNotification_GetUpdateTimestamp_def(obj);
	log("ovr_PartyUpdateNotification_GetUpdateTimestamp called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_PartyUpdateNotification_GetUserAlias, const char *, const ovrPartyUpdateNotificationHandle obj)
{
	auto ret = ovr_PartyUpdateNotification_GetUserAlias_def(obj);
	log("ovr_PartyUpdateNotification_GetUserAlias called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_PartyUpdateNotification_GetUserId, ovrID, const ovrPartyUpdateNotificationHandle obj)
{
	auto ret = ovr_PartyUpdateNotification_GetUserId_def(obj);
	log("ovr_PartyUpdateNotification_GetUserId called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_PartyUpdateNotification_GetUserName, const char *, const ovrPartyUpdateNotificationHandle obj)
{
	auto ret = ovr_PartyUpdateNotification_GetUserName_def(obj);
	log("ovr_PartyUpdateNotification_GetUserName called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovrPeerConnectionState_ToString, const char*, ovrPeerConnectionState value)
{
	auto ret = ovrPeerConnectionState_ToString_def(value);
	log("ovrPeerConnectionState_ToString called with %d  and returned %s", value,  ret);
	return ret;
}
HOOK_DEF(ovrPeerConnectionState_FromString, ovrPeerConnectionState, const char* str)
{
	auto ret = ovrPeerConnectionState_FromString_def(str);
	log("ovrPeerConnectionState_FromString called with %d  and returned %d", str,  ret);
	return ret;
}
HOOK_DEF(ovrPermissionGrantStatus_ToString, const char*, ovrPermissionGrantStatus value)
{
	auto ret = ovrPermissionGrantStatus_ToString_def(value);
	log("ovrPermissionGrantStatus_ToString called with %d  and returned %s", value,  ret);
	return ret;
}
HOOK_DEF(ovrPermissionGrantStatus_FromString, ovrPermissionGrantStatus, const char* str)
{
	auto ret = ovrPermissionGrantStatus_FromString_def(str);
	log("ovrPermissionGrantStatus_FromString called with %d  and returned %d", str,  ret);
	return ret;
}
HOOK_DEF(ovrPermissionType_ToString, const char*, ovrPermissionType value)
{
	auto ret = ovrPermissionType_ToString_def(value);
	log("ovrPermissionType_ToString called with %d  and returned %s", value,  ret);
	return ret;
}
HOOK_DEF(ovrPermissionType_FromString, ovrPermissionType, const char* str)
{
	auto ret = ovrPermissionType_FromString_def(str);
	log("ovrPermissionType_FromString called with %d  and returned %d", str,  ret);
	return ret;
}
HOOK_DEF(ovr_Pid_GetId, const char *, const ovrPidHandle obj)
{
	auto ret = ovr_Pid_GetId_def(obj);
	log("ovr_Pid_GetId called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_PidArray_GetElement, ovrPidHandle, const ovrPidArrayHandle obj, size_t index)
{
	auto ret = ovr_PidArray_GetElement_def(obj, index);
	log("ovr_PidArray_GetElement called with %d %d  and returned %d", obj, index,  ret);
	return ret;
}
HOOK_DEF(ovr_PidArray_GetSize, size_t, const ovrPidArrayHandle obj)
{
	auto ret = ovr_PidArray_GetSize_def(obj);
	log("ovr_PidArray_GetSize called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_PingResult_GetID, ovrID, const ovrPingResultHandle obj)
{
	auto ret = ovr_PingResult_GetID_def(obj);
	log("ovr_PingResult_GetID called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_PingResult_GetPingTimeUsec, unsigned long long, const ovrPingResultHandle obj)
{
	auto ret = ovr_PingResult_GetPingTimeUsec_def(obj);
	log("ovr_PingResult_GetPingTimeUsec called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_PingResult_IsTimeout, bool, const ovrPingResultHandle obj)
{
	auto ret = ovr_PingResult_IsTimeout_def(obj);
	log("ovr_PingResult_IsTimeout called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_IsPlatformInitialized, bool, )
{
	auto ret = ovr_IsPlatformInitialized_def();
	log("ovr_IsPlatformInitialized called with  and returned %d",  ret);
	return ret;
}
HOOK_DEF(ovr_PlatformInitializeAndroid, ovrPlatformInitializeResult, const char* appId, jobject activityObject, JNIEnv * jni)
{
	auto ret = ovr_PlatformInitializeAndroid_def(appId, activityObject, jni);
	log("ovr_PlatformInitializeAndroid called with %d %d %d  and returned %d", appId, activityObject, jni,  ret);
	return ret;
}
HOOK_DEF(ovr_PlatformInitializeAndroidAsynchronous, ovrRequest, const char* appId, jobject activityObject, JNIEnv * jni)
{
	auto ret = ovr_PlatformInitializeAndroidAsynchronous_def(appId, activityObject, jni);
	log("ovr_PlatformInitializeAndroidAsynchronous called with %d %d %d  and returned %d", appId, activityObject, jni,  ret);
	return ret;
}
HOOK_DEF(ovr_PlatformInitializeWindows, ovrPlatformInitializeResult, const char* appId)
{
	auto ret = ovr_PlatformInitializeWindows_def(appId);
	log("ovr_PlatformInitializeWindows called with %d  and returned %d", appId,  ret);
	return ret;
}
HOOK_DEF(ovr_PlatformInitializeWindowsAsynchronous, ovrRequest, const char* appId)
{
	auto ret = ovr_PlatformInitializeWindowsAsynchronous_def(appId);
	log("ovr_PlatformInitializeWindowsAsynchronous called with %d  and returned %d", appId,  ret);
	return ret;
}
HOOK_DEF(ovr_PlatformInitializeWindowsEx, ovrPlatformInitializeResult, const char* appId, int productVersion, int majorVersion)
{
	auto ret = ovr_PlatformInitializeWindowsEx_def(appId, productVersion, majorVersion);
	log("ovr_PlatformInitializeWindowsEx called with %d %d %d  and returned %d", appId, productVersion, majorVersion,  ret);
	return ret;
}
HOOK_DEF(ovr_PlatformInitializeWindowsAsynchronousEx, ovrRequest, const char* appId, ovrPlatformInitializeResult *outResult, int productVersion, int majorVersion)
{
	auto ret = ovr_PlatformInitializeWindowsAsynchronousEx_def(appId, outResult, productVersion, majorVersion);
	log("ovr_PlatformInitializeWindowsAsynchronousEx called with %d %d %d %d  and returned %d", appId, outResult, productVersion, majorVersion,  ret);
	return ret;
}
HOOK_DEF(ovr_GetLoggedInUserID, ovrID, )
{
	auto ret = ovr_GetLoggedInUserID_def();
	log("ovr_GetLoggedInUserID called with  and returned %d",  ret);
	return ret;
}
HOOK_DEF(ovr_GetLoggedInUserLocale, const char*, )
{
	auto ret = ovr_GetLoggedInUserLocale_def();
	log("ovr_GetLoggedInUserLocale called with  and returned %s",  ret);
	return ret;
}
HOOK_DEF(ovr_SetDeveloperAccessToken, void, const char *accessToken)
{
	log("ovr_SetDeveloperAccessToken called with %d ", accessToken);
	ovr_SetDeveloperAccessToken_def(accessToken);
}
HOOK_DEF(ovr_PlatformInitialize_GetResult, ovrPlatformInitializeResult, const ovrPlatformInitializeHandle obj)
{
	auto ret = ovr_PlatformInitialize_GetResult_def(obj);
	log("ovr_PlatformInitialize_GetResult called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovrPlatformInitializeResult_ToString, const char*, ovrPlatformInitializeResult value)
{
	auto ret = ovrPlatformInitializeResult_ToString_def(value);
	log("ovrPlatformInitializeResult_ToString called with %d  and returned %s", value,  ret);
	return ret;
}
HOOK_DEF(ovrPlatformInitializeResult_FromString, ovrPlatformInitializeResult, const char* str)
{
	auto ret = ovrPlatformInitializeResult_FromString_def(str);
	log("ovrPlatformInitializeResult_FromString called with %d  and returned %d", str,  ret);
	return ret;
}
HOOK_DEF(ovr_Product_GetDescription, const char *, const ovrProductHandle obj)
{
	auto ret = ovr_Product_GetDescription_def(obj);
	log("ovr_Product_GetDescription called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Product_GetFormattedPrice, const char *, const ovrProductHandle obj)
{
	auto ret = ovr_Product_GetFormattedPrice_def(obj);
	log("ovr_Product_GetFormattedPrice called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Product_GetName, const char *, const ovrProductHandle obj)
{
	auto ret = ovr_Product_GetName_def(obj);
	log("ovr_Product_GetName called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Product_GetSKU, const char *, const ovrProductHandle obj)
{
	auto ret = ovr_Product_GetSKU_def(obj);
	log("ovr_Product_GetSKU called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_ProductArray_GetElement, ovrProductHandle, const ovrProductArrayHandle obj, size_t index)
{
	auto ret = ovr_ProductArray_GetElement_def(obj, index);
	log("ovr_ProductArray_GetElement called with %d %d  and returned %d", obj, index,  ret);
	return ret;
}
HOOK_DEF(ovr_ProductArray_GetNextUrl, const char *, const ovrProductArrayHandle obj)
{
	auto ret = ovr_ProductArray_GetNextUrl_def(obj);
	log("ovr_ProductArray_GetNextUrl called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_ProductArray_GetSize, size_t, const ovrProductArrayHandle obj)
{
	auto ret = ovr_ProductArray_GetSize_def(obj);
	log("ovr_ProductArray_GetSize called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_ProductArray_HasNextPage, bool, const ovrProductArrayHandle obj)
{
	auto ret = ovr_ProductArray_HasNextPage_def(obj);
	log("ovr_ProductArray_HasNextPage called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Purchase_GetExpirationTime, unsigned long long, const ovrPurchaseHandle obj)
{
	auto ret = ovr_Purchase_GetExpirationTime_def(obj);
	log("ovr_Purchase_GetExpirationTime called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Purchase_GetGrantTime, unsigned long long, const ovrPurchaseHandle obj)
{
	auto ret = ovr_Purchase_GetGrantTime_def(obj);
	log("ovr_Purchase_GetGrantTime called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Purchase_GetPurchaseID, ovrID, const ovrPurchaseHandle obj)
{
	auto ret = ovr_Purchase_GetPurchaseID_def(obj);
	log("ovr_Purchase_GetPurchaseID called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Purchase_GetSKU, const char *, const ovrPurchaseHandle obj)
{
	auto ret = ovr_Purchase_GetSKU_def(obj);
	log("ovr_Purchase_GetSKU called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_PurchaseArray_GetElement, ovrPurchaseHandle, const ovrPurchaseArrayHandle obj, size_t index)
{
	auto ret = ovr_PurchaseArray_GetElement_def(obj, index);
	log("ovr_PurchaseArray_GetElement called with %d %d  and returned %d", obj, index,  ret);
	return ret;
}
HOOK_DEF(ovr_PurchaseArray_GetNextUrl, const char *, const ovrPurchaseArrayHandle obj)
{
	auto ret = ovr_PurchaseArray_GetNextUrl_def(obj);
	log("ovr_PurchaseArray_GetNextUrl called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_PurchaseArray_GetSize, size_t, const ovrPurchaseArrayHandle obj)
{
	auto ret = ovr_PurchaseArray_GetSize_def(obj);
	log("ovr_PurchaseArray_GetSize called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_PurchaseArray_HasNextPage, bool, const ovrPurchaseArrayHandle obj)
{
	auto ret = ovr_PurchaseArray_HasNextPage_def(obj);
	log("ovr_PurchaseArray_HasNextPage called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Achievements_AddCount, ovrRequest, const char *name, unsigned long long count)
{
	auto ret = ovr_Achievements_AddCount_def(name, count);
	log("ovr_Achievements_AddCount called with %d %d  and returned %d", name, count,  ret);
	return ret;
}
HOOK_DEF(ovr_Achievements_AddFields, ovrRequest, const char *name, const char *fields)
{
	auto ret = ovr_Achievements_AddFields_def(name, fields);
	log("ovr_Achievements_AddFields called with %d %d  and returned %d", name, fields,  ret);
	return ret;
}
HOOK_DEF(ovr_Achievements_GetAllDefinitions, ovrRequest, )
{
	auto ret = ovr_Achievements_GetAllDefinitions_def();
	log("ovr_Achievements_GetAllDefinitions called with  and returned %d",  ret);
	return ret;
}
HOOK_DEF(ovr_Achievements_GetAllProgress, ovrRequest, )
{
	auto ret = ovr_Achievements_GetAllProgress_def();
	log("ovr_Achievements_GetAllProgress called with  and returned %d",  ret);
	return ret;
}
HOOK_DEF(ovr_Achievements_GetDefinitionsByName, ovrRequest, const char **names, int count)
{
	auto ret = ovr_Achievements_GetDefinitionsByName_def(names, count);
	log("ovr_Achievements_GetDefinitionsByName called with %d %d  and returned %d", names, count,  ret);
	return ret;
}
HOOK_DEF(ovr_Achievements_GetNextAchievementDefinitionArrayPage, ovrRequest, ovrAchievementDefinitionArrayHandle handle)
{
	auto ret = ovr_Achievements_GetNextAchievementDefinitionArrayPage_def(handle);
	log("ovr_Achievements_GetNextAchievementDefinitionArrayPage called with %d  and returned %d", handle,  ret);
	return ret;
}
HOOK_DEF(ovr_Achievements_GetNextAchievementProgressArrayPage, ovrRequest, ovrAchievementProgressArrayHandle handle)
{
	auto ret = ovr_Achievements_GetNextAchievementProgressArrayPage_def(handle);
	log("ovr_Achievements_GetNextAchievementProgressArrayPage called with %d  and returned %d", handle,  ret);
	return ret;
}
HOOK_DEF(ovr_Achievements_GetProgressByName, ovrRequest, const char **names, int count)
{
	auto ret = ovr_Achievements_GetProgressByName_def(names, count);
	log("ovr_Achievements_GetProgressByName called with %d %d  and returned %d", names, count,  ret);
	return ret;
}
HOOK_DEF(ovr_Achievements_Unlock, ovrRequest, const char *name)
{
	auto ret = ovr_Achievements_Unlock_def(name);
	log("ovr_Achievements_Unlock called with %d  and returned %d", name,  ret);
	return ret;
}
HOOK_DEF(ovr_Application_GetVersion, ovrRequest, )
{
	auto ret = ovr_Application_GetVersion_def();
	log("ovr_Application_GetVersion called with  and returned %d",  ret);
	return ret;
}
HOOK_DEF(ovr_Application_LaunchOtherApp, ovrRequest, ovrID appID, ovrApplicationOptionsHandle deeplink_options)
{
	auto ret = ovr_Application_LaunchOtherApp_def(appID, deeplink_options);
	log("ovr_Application_LaunchOtherApp called with %d %d  and returned %d", appID, deeplink_options,  ret);
	return ret;
}
HOOK_DEF(ovr_ApplicationLifecycle_GetRegisteredPIDs, ovrRequest, )
{
	auto ret = ovr_ApplicationLifecycle_GetRegisteredPIDs_def();
	log("ovr_ApplicationLifecycle_GetRegisteredPIDs called with  and returned %d",  ret);
	return ret;
}
HOOK_DEF(ovr_ApplicationLifecycle_GetSessionKey, ovrRequest, )
{
	auto ret = ovr_ApplicationLifecycle_GetSessionKey_def();
	log("ovr_ApplicationLifecycle_GetSessionKey called with  and returned %d",  ret);
	return ret;
}
HOOK_DEF(ovr_ApplicationLifecycle_RegisterSessionKey, ovrRequest, const char *sessionKey)
{
	auto ret = ovr_ApplicationLifecycle_RegisterSessionKey_def(sessionKey);
	log("ovr_ApplicationLifecycle_RegisterSessionKey called with %d  and returned %d", sessionKey,  ret);
	return ret;
}
HOOK_DEF(ovr_AssetFile_Delete, ovrRequest, ovrID assetFileID)
{
	auto ret = ovr_AssetFile_Delete_def(assetFileID);
	log("ovr_AssetFile_Delete called with %d  and returned %d", assetFileID,  ret);
	return ret;
}
HOOK_DEF(ovr_AssetFile_DeleteById, ovrRequest, ovrID assetFileID)
{
	auto ret = ovr_AssetFile_DeleteById_def(assetFileID);
	log("ovr_AssetFile_DeleteById called with %d  and returned %d", assetFileID,  ret);
	return ret;
}
HOOK_DEF(ovr_AssetFile_DeleteByName, ovrRequest, const char *assetFileName)
{
	auto ret = ovr_AssetFile_DeleteByName_def(assetFileName);
	log("ovr_AssetFile_DeleteByName called with %d  and returned %d", assetFileName,  ret);
	return ret;
}
HOOK_DEF(ovr_AssetFile_Download, ovrRequest, ovrID assetFileID)
{
	auto ret = ovr_AssetFile_Download_def(assetFileID);
	log("ovr_AssetFile_Download called with %d  and returned %d", assetFileID,  ret);
	return ret;
}
HOOK_DEF(ovr_AssetFile_DownloadById, ovrRequest, ovrID assetFileID)
{
	auto ret = ovr_AssetFile_DownloadById_def(assetFileID);
	log("ovr_AssetFile_DownloadById called with %d  and returned %d", assetFileID,  ret);
	return ret;
}
HOOK_DEF(ovr_AssetFile_DownloadByName, ovrRequest, const char *assetFileName)
{
	auto ret = ovr_AssetFile_DownloadByName_def(assetFileName);
	log("ovr_AssetFile_DownloadByName called with %d  and returned %d", assetFileName,  ret);
	return ret;
}
HOOK_DEF(ovr_AssetFile_DownloadCancel, ovrRequest, ovrID assetFileID)
{
	auto ret = ovr_AssetFile_DownloadCancel_def(assetFileID);
	log("ovr_AssetFile_DownloadCancel called with %d  and returned %d", assetFileID,  ret);
	return ret;
}
HOOK_DEF(ovr_AssetFile_DownloadCancelById, ovrRequest, ovrID assetFileID)
{
	auto ret = ovr_AssetFile_DownloadCancelById_def(assetFileID);
	log("ovr_AssetFile_DownloadCancelById called with %d  and returned %d", assetFileID,  ret);
	return ret;
}
HOOK_DEF(ovr_AssetFile_DownloadCancelByName, ovrRequest, const char *assetFileName)
{
	auto ret = ovr_AssetFile_DownloadCancelByName_def(assetFileName);
	log("ovr_AssetFile_DownloadCancelByName called with %d  and returned %d", assetFileName,  ret);
	return ret;
}
HOOK_DEF(ovr_AssetFile_GetList, ovrRequest, )
{
	auto ret = ovr_AssetFile_GetList_def();
	log("ovr_AssetFile_GetList called with  and returned %d",  ret);
	return ret;
}
HOOK_DEF(ovr_AssetFile_Status, ovrRequest, ovrID assetFileID)
{
	auto ret = ovr_AssetFile_Status_def(assetFileID);
	log("ovr_AssetFile_Status called with %d  and returned %d", assetFileID,  ret);
	return ret;
}
HOOK_DEF(ovr_AssetFile_StatusById, ovrRequest, ovrID assetFileID)
{
	auto ret = ovr_AssetFile_StatusById_def(assetFileID);
	log("ovr_AssetFile_StatusById called with %d  and returned %d", assetFileID,  ret);
	return ret;
}
HOOK_DEF(ovr_AssetFile_StatusByName, ovrRequest, const char *assetFileName)
{
	auto ret = ovr_AssetFile_StatusByName_def(assetFileName);
	log("ovr_AssetFile_StatusByName called with %d  and returned %d", assetFileName,  ret);
	return ret;
}
HOOK_DEF(ovr_CloudStorage_Delete, ovrRequest, const char *bucket, const char *key)
{
	auto ret = ovr_CloudStorage_Delete_def(bucket, key);
	log("ovr_CloudStorage_Delete called with %d %d  and returned %d", bucket, key,  ret);
	return ret;
}
HOOK_DEF(ovr_CloudStorage_GetNextCloudStorageMetadataArrayPage, ovrRequest, ovrCloudStorageMetadataArrayHandle handle)
{
	auto ret = ovr_CloudStorage_GetNextCloudStorageMetadataArrayPage_def(handle);
	log("ovr_CloudStorage_GetNextCloudStorageMetadataArrayPage called with %d  and returned %d", handle,  ret);
	return ret;
}
HOOK_DEF(ovr_CloudStorage_Load, ovrRequest, const char *bucket, const char *key)
{
	auto ret = ovr_CloudStorage_Load_def(bucket, key);
	log("ovr_CloudStorage_Load called with %d %d  and returned %d", bucket, key,  ret);
	return ret;
}
HOOK_DEF(ovr_CloudStorage_LoadBucketMetadata, ovrRequest, const char *bucket)
{
	auto ret = ovr_CloudStorage_LoadBucketMetadata_def(bucket);
	log("ovr_CloudStorage_LoadBucketMetadata called with %d  and returned %d", bucket,  ret);
	return ret;
}
HOOK_DEF(ovr_CloudStorage_LoadConflictMetadata, ovrRequest, const char *bucket, const char *key)
{
	auto ret = ovr_CloudStorage_LoadConflictMetadata_def(bucket, key);
	log("ovr_CloudStorage_LoadConflictMetadata called with %d %d  and returned %d", bucket, key,  ret);
	return ret;
}
HOOK_DEF(ovr_CloudStorage_LoadHandle, ovrRequest, ovrCloudStorageVersionHandle handle)
{
	auto ret = ovr_CloudStorage_LoadHandle_def(handle);
	log("ovr_CloudStorage_LoadHandle called with %d  and returned %d", handle,  ret);
	return ret;
}
HOOK_DEF(ovr_CloudStorage_LoadMetadata, ovrRequest, const char *bucket, const char *key)
{
	auto ret = ovr_CloudStorage_LoadMetadata_def(bucket, key);
	log("ovr_CloudStorage_LoadMetadata called with %d %d  and returned %d", bucket, key,  ret);
	return ret;
}
HOOK_DEF(ovr_CloudStorage_ResolveKeepLocal, ovrRequest, const char *bucket, const char *key, ovrCloudStorageVersionHandle remoteHandle)
{
	auto ret = ovr_CloudStorage_ResolveKeepLocal_def(bucket, key, remoteHandle);
	log("ovr_CloudStorage_ResolveKeepLocal called with %d %d %d  and returned %d", bucket, key, remoteHandle,  ret);
	return ret;
}
HOOK_DEF(ovr_CloudStorage_ResolveKeepRemote, ovrRequest, const char *bucket, const char *key, ovrCloudStorageVersionHandle remoteHandle)
{
	auto ret = ovr_CloudStorage_ResolveKeepRemote_def(bucket, key, remoteHandle);
	log("ovr_CloudStorage_ResolveKeepRemote called with %d %d %d  and returned %d", bucket, key, remoteHandle,  ret);
	return ret;
}
HOOK_DEF(ovr_CloudStorage_Save, ovrRequest, const char *bucket, const char *key, const void *data, unsigned int dataSize, long long counter, const char *extraData)
{
	auto ret = ovr_CloudStorage_Save_def(bucket, key, data, dataSize, counter, extraData);
	log("ovr_CloudStorage_Save called with %d %d %d %d %d %d  and returned %d", bucket, key, data, dataSize, counter, extraData,  ret);
	return ret;
}
HOOK_DEF(ovr_Entitlement_GetIsViewerEntitled, ovrRequest, )
{
	auto ret = ovr_Entitlement_GetIsViewerEntitled_def();
	log("ovr_Entitlement_GetIsViewerEntitled called with  and returned %d",  ret);
	return ret;
}
HOOK_DEF(ovr_IAP_ConsumePurchase, ovrRequest, const char *sku)
{
	auto ret = ovr_IAP_ConsumePurchase_def(sku);
	log("ovr_IAP_ConsumePurchase called with %d  and returned %d", sku,  ret);
	return ret;
}
HOOK_DEF(ovr_IAP_GetNextProductArrayPage, ovrRequest, ovrProductArrayHandle handle)
{
	auto ret = ovr_IAP_GetNextProductArrayPage_def(handle);
	log("ovr_IAP_GetNextProductArrayPage called with %d  and returned %d", handle,  ret);
	return ret;
}
HOOK_DEF(ovr_IAP_GetNextPurchaseArrayPage, ovrRequest, ovrPurchaseArrayHandle handle)
{
	auto ret = ovr_IAP_GetNextPurchaseArrayPage_def(handle);
	log("ovr_IAP_GetNextPurchaseArrayPage called with %d  and returned %d", handle,  ret);
	return ret;
}
HOOK_DEF(ovr_IAP_GetProductsBySKU, ovrRequest, const char **skus, int count)
{
	auto ret = ovr_IAP_GetProductsBySKU_def(skus, count);
	log("ovr_IAP_GetProductsBySKU called with %d %d  and returned %d", skus, count,  ret);
	return ret;
}
HOOK_DEF(ovr_IAP_GetViewerPurchases, ovrRequest, )
{
	auto ret = ovr_IAP_GetViewerPurchases_def();
	log("ovr_IAP_GetViewerPurchases called with  and returned %d",  ret);
	return ret;
}
HOOK_DEF(ovr_IAP_LaunchCheckoutFlow, ovrRequest, const char *sku)
{
	auto ret = ovr_IAP_LaunchCheckoutFlow_def(sku);
	log("ovr_IAP_LaunchCheckoutFlow called with %d  and returned %d", sku,  ret);
	return ret;
}
HOOK_DEF(ovr_LanguagePack_GetCurrent, ovrRequest, )
{
	auto ret = ovr_LanguagePack_GetCurrent_def();
	log("ovr_LanguagePack_GetCurrent called with  and returned %d",  ret);
	return ret;
}
HOOK_DEF(ovr_LanguagePack_SetCurrent, ovrRequest, const char *tag)
{
	auto ret = ovr_LanguagePack_SetCurrent_def(tag);
	log("ovr_LanguagePack_SetCurrent called with %d  and returned %d", tag,  ret);
	return ret;
}


HOOK_DEF(ovr_Livestreaming_GetStatus, ovrRequest, )
{
	auto ret = ovr_Livestreaming_GetStatus_def();
	log("ovr_Livestreaming_GetStatus called with  and returned %d",  ret);
	return ret;
}
HOOK_DEF(ovr_Livestreaming_PauseStream, ovrRequest, )
{
	auto ret = ovr_Livestreaming_PauseStream_def();
	log("ovr_Livestreaming_PauseStream called with  and returned %d",  ret);
	return ret;
}
HOOK_DEF(ovr_Livestreaming_ResumeStream, ovrRequest, )
{
	auto ret = ovr_Livestreaming_ResumeStream_def();
	log("ovr_Livestreaming_ResumeStream called with  and returned %d",  ret);
	return ret;
}
HOOK_DEF(ovr_Matchmaking_Browse, ovrRequest, const char *pool, ovrMatchmakingCustomQueryData *customQueryData)
{
	auto ret = ovr_Matchmaking_Browse_def(pool, customQueryData);
	log("ovr_Matchmaking_Browse called with %d %d  and returned %d", pool, customQueryData,  ret);
	return ret;
}
HOOK_DEF(ovr_Matchmaking_Browse2, ovrRequest, const char *pool, ovrMatchmakingOptionsHandle matchmakingOptions)
{
	auto ret = ovr_Matchmaking_Browse2_def(pool, matchmakingOptions);
	log("ovr_Matchmaking_Browse2 called with %d %d  and returned %d", pool, matchmakingOptions,  ret);
	return ret;
}
HOOK_DEF(ovr_Matchmaking_Cancel, ovrRequest, const char *pool, const char *requestHash)
{
	auto ret = ovr_Matchmaking_Cancel_def(pool, requestHash);
	log("ovr_Matchmaking_Cancel called with %d %d  and returned %d", pool, requestHash,  ret);
	return ret;
}
HOOK_DEF(ovr_Matchmaking_Cancel2, ovrRequest, )
{
	auto ret = ovr_Matchmaking_Cancel2_def();
	log("ovr_Matchmaking_Cancel2 called with  and returned %d",  ret);
	return ret;
}
HOOK_DEF(ovr_Matchmaking_CreateAndEnqueueRoom, ovrRequest, const char *pool, unsigned int maxUsers, bool subscribeToUpdates, ovrMatchmakingCustomQueryData *customQueryData)
{
	auto ret = ovr_Matchmaking_CreateAndEnqueueRoom_def(pool, maxUsers, subscribeToUpdates, customQueryData);
	log("ovr_Matchmaking_CreateAndEnqueueRoom called with %d %d %d %d  and returned %d", pool, maxUsers, subscribeToUpdates, customQueryData,  ret);
	return ret;
}
HOOK_DEF(ovr_Matchmaking_CreateAndEnqueueRoom2, ovrRequest, const char *pool, ovrMatchmakingOptionsHandle matchmakingOptions)
{
	auto ret = ovr_Matchmaking_CreateAndEnqueueRoom2_def(pool, matchmakingOptions);
	log("ovr_Matchmaking_CreateAndEnqueueRoom2 called with %d %d  and returned %d", pool, matchmakingOptions,  ret);
	return ret;
}
HOOK_DEF(ovr_Matchmaking_CreateRoom, ovrRequest, const char *pool, unsigned int maxUsers, bool subscribeToUpdates)
{
	auto ret = ovr_Matchmaking_CreateRoom_def(pool, maxUsers, subscribeToUpdates);
	log("ovr_Matchmaking_CreateRoom called with %d %d %d  and returned %d", pool, maxUsers, subscribeToUpdates,  ret);
	return ret;
}
HOOK_DEF(ovr_Matchmaking_CreateRoom2, ovrRequest, const char *pool, ovrMatchmakingOptionsHandle matchmakingOptions)
{
	auto ret = ovr_Matchmaking_CreateRoom2_def(pool, matchmakingOptions);
	log("ovr_Matchmaking_CreateRoom2 called with %d %d  and returned %d", pool, matchmakingOptions,  ret);
	return ret;
}
HOOK_DEF(ovr_Matchmaking_Enqueue, ovrRequest, const char *pool, ovrMatchmakingCustomQueryData *customQueryData)
{
	auto ret = ovr_Matchmaking_Enqueue_def(pool, customQueryData);
	log("ovr_Matchmaking_Enqueue called with %d %d  and returned %d", pool, customQueryData,  ret);
	return ret;
}
HOOK_DEF(ovr_Matchmaking_Enqueue2, ovrRequest, const char *pool, ovrMatchmakingOptionsHandle matchmakingOptions)
{
	auto ret = ovr_Matchmaking_Enqueue2_def(pool, matchmakingOptions);
	log("ovr_Matchmaking_Enqueue2 called with %d %d  and returned %d", pool, matchmakingOptions,  ret);
	return ret;
}
HOOK_DEF(ovr_Matchmaking_EnqueueRoom, ovrRequest, ovrID roomID, ovrMatchmakingCustomQueryData *customQueryData)
{
	auto ret = ovr_Matchmaking_EnqueueRoom_def(roomID, customQueryData);
	log("ovr_Matchmaking_EnqueueRoom called with %d %d  and returned %d", roomID, customQueryData,  ret);
	return ret;
}
HOOK_DEF(ovr_Matchmaking_EnqueueRoom2, ovrRequest, ovrID roomID, ovrMatchmakingOptionsHandle matchmakingOptions)
{
	auto ret = ovr_Matchmaking_EnqueueRoom2_def(roomID, matchmakingOptions);
	log("ovr_Matchmaking_EnqueueRoom2 called with %d %d  and returned %d", roomID, matchmakingOptions,  ret);
	return ret;
}
HOOK_DEF(ovr_Matchmaking_GetAdminSnapshot, ovrRequest, )
{
	auto ret = ovr_Matchmaking_GetAdminSnapshot_def();
	log("ovr_Matchmaking_GetAdminSnapshot called with  and returned %d",  ret);
	return ret;
}
HOOK_DEF(ovr_Matchmaking_GetStats, ovrRequest, const char *pool, unsigned int maxLevel, ovrMatchmakingStatApproach approach)
{
	auto ret = ovr_Matchmaking_GetStats_def(pool, maxLevel, approach);
	log("ovr_Matchmaking_GetStats called with %d %d %d  and returned %d", pool, maxLevel, approach,  ret);
	return ret;
}
HOOK_DEF(ovr_Matchmaking_JoinRoom, ovrRequest, ovrID roomID, bool subscribeToUpdates)
{
	auto ret = ovr_Matchmaking_JoinRoom_def(roomID, subscribeToUpdates);
	log("ovr_Matchmaking_JoinRoom called with %d %d  and returned %d", roomID, subscribeToUpdates,  ret);
	return ret;
}
HOOK_DEF(ovr_Matchmaking_ReportResultInsecure, ovrRequest, ovrID roomID, ovrKeyValuePair *data, unsigned int numItems)
{
	auto ret = ovr_Matchmaking_ReportResultInsecure_def(roomID, data, numItems);
	log("ovr_Matchmaking_ReportResultInsecure called with %d %d %d  and returned %d", roomID, data, numItems,  ret);
	return ret;
}
HOOK_DEF(ovr_Matchmaking_StartMatch, ovrRequest, ovrID roomID)
{
	auto ret = ovr_Matchmaking_StartMatch_def(roomID);
	log("ovr_Matchmaking_StartMatch called with %d  and returned %d", roomID,  ret);
	return ret;
}
HOOK_DEF(ovr_Media_ShareToFacebook, ovrRequest, const char *postTextSuggestion, const char *filePath, ovrMediaContentType contentType)
{
	auto ret = ovr_Media_ShareToFacebook_def(postTextSuggestion, filePath, contentType);
	log("ovr_Media_ShareToFacebook called with %d %d %d  and returned %d", postTextSuggestion, filePath, contentType,  ret);
	return ret;
}
HOOK_DEF(ovr_Notification_GetNextRoomInviteNotificationArrayPage, ovrRequest, ovrRoomInviteNotificationArrayHandle handle)
{
	auto ret = ovr_Notification_GetNextRoomInviteNotificationArrayPage_def(handle);
	log("ovr_Notification_GetNextRoomInviteNotificationArrayPage called with %d  and returned %d", handle,  ret);
	return ret;
}
HOOK_DEF(ovr_Notification_GetRoomInvites, ovrRequest, )
{
	auto ret = ovr_Notification_GetRoomInvites_def();
	log("ovr_Notification_GetRoomInvites called with  and returned %d",  ret);
	return ret;
}
HOOK_DEF(ovr_Notification_MarkAsRead, ovrRequest, ovrID notificationID)
{
	auto ret = ovr_Notification_MarkAsRead_def(notificationID);
	log("ovr_Notification_MarkAsRead called with %d  and returned %d", notificationID,  ret);
	return ret;
}
HOOK_DEF(ovr_Party_GetCurrent, ovrRequest, )
{
	auto ret = ovr_Party_GetCurrent_def();
	log("ovr_Party_GetCurrent called with  and returned %d",  ret);
	return ret;
}
HOOK_DEF(ovr_Room_CreateAndJoinPrivate, ovrRequest, ovrRoomJoinPolicy joinPolicy, unsigned int maxUsers, bool subscribeToUpdates)
{
	auto ret = ovr_Room_CreateAndJoinPrivate_def(joinPolicy, maxUsers, subscribeToUpdates);
	log("ovr_Room_CreateAndJoinPrivate called with %d %d %d  and returned %d", joinPolicy, maxUsers, subscribeToUpdates,  ret);
	return ret;
}
HOOK_DEF(ovr_Room_CreateAndJoinPrivate2, ovrRequest, ovrRoomJoinPolicy joinPolicy, unsigned int maxUsers, ovrRoomOptionsHandle roomOptions)
{
	auto ret = ovr_Room_CreateAndJoinPrivate2_def(joinPolicy, maxUsers, roomOptions);
	log("ovr_Room_CreateAndJoinPrivate2 called with %d %d %d  and returned %d", joinPolicy, maxUsers, roomOptions,  ret);
	return ret;
}
HOOK_DEF(ovr_Room_Get, ovrRequest, ovrID roomID)
{
	auto ret = ovr_Room_Get_def(roomID);
	log("ovr_Room_Get called with %d  and returned %d", roomID,  ret);
	return ret;
}
HOOK_DEF(ovr_Room_GetCurrent, ovrRequest, )
{
	auto ret = ovr_Room_GetCurrent_def();
	log("ovr_Room_GetCurrent called with  and returned %d",  ret);
	return ret;
}
HOOK_DEF(ovr_Room_GetCurrentForUser, ovrRequest, ovrID userID)
{
	auto ret = ovr_Room_GetCurrentForUser_def(userID);
	log("ovr_Room_GetCurrentForUser called with %d  and returned %d", userID,  ret);
	return ret;
}
HOOK_DEF(ovr_Room_GetInvitableUsers, ovrRequest, )
{
	auto ret = ovr_Room_GetInvitableUsers_def();
	log("ovr_Room_GetInvitableUsers called with  and returned %d",  ret);
	return ret;
}
HOOK_DEF(ovr_Room_GetInvitableUsers2, ovrRequest, ovrRoomOptionsHandle roomOptions)
{
	auto ret = ovr_Room_GetInvitableUsers2_def(roomOptions);
	log("ovr_Room_GetInvitableUsers2 called with %d  and returned %d", roomOptions,  ret);
	return ret;
}
HOOK_DEF(ovr_Room_GetModeratedRooms, ovrRequest, )
{
	auto ret = ovr_Room_GetModeratedRooms_def();
	log("ovr_Room_GetModeratedRooms called with  and returned %d",  ret);
	return ret;
}
HOOK_DEF(ovr_Room_GetNextRoomArrayPage, ovrRequest, ovrRoomArrayHandle handle)
{
	auto ret = ovr_Room_GetNextRoomArrayPage_def(handle);
	log("ovr_Room_GetNextRoomArrayPage called with %d  and returned %d", handle,  ret);
	return ret;
}
HOOK_DEF(ovr_Room_InviteUser, ovrRequest, ovrID roomID, const char *inviteToken)
{
	auto ret = ovr_Room_InviteUser_def(roomID, inviteToken);
	log("ovr_Room_InviteUser called with %d %d  and returned %d", roomID, inviteToken,  ret);
	return ret;
}
HOOK_DEF(ovr_Room_Join, ovrRequest, ovrID roomID, bool subscribeToUpdates)
{
	auto ret = ovr_Room_Join_def(roomID, subscribeToUpdates);
	log("ovr_Room_Join called with %d %d  and returned %d", roomID, subscribeToUpdates,  ret);
	return ret;
}
HOOK_DEF(ovr_Room_Join2, ovrRequest, ovrID roomID, ovrRoomOptionsHandle roomOptions)
{
	auto ret = ovr_Room_Join2_def(roomID, roomOptions);
	log("ovr_Room_Join2 called with %d %d  and returned %d", roomID, roomOptions,  ret);
	return ret;
}
HOOK_DEF(ovr_Room_KickUser, ovrRequest, ovrID roomID, ovrID userID, int kickDurationSeconds)
{
	auto ret = ovr_Room_KickUser_def(roomID, userID, kickDurationSeconds);
	log("ovr_Room_KickUser called with %d %d %d  and returned %d", roomID, userID, kickDurationSeconds,  ret);
	return ret;
}
HOOK_DEF(ovr_Room_LaunchInvitableUserFlow, ovrRequest, ovrID roomID)
{
	auto ret = ovr_Room_LaunchInvitableUserFlow_def(roomID);
	log("ovr_Room_LaunchInvitableUserFlow called with %d  and returned %d", roomID,  ret);
	return ret;
}
HOOK_DEF(ovr_Room_Leave, ovrRequest, ovrID roomID)
{
	auto ret = ovr_Room_Leave_def(roomID);
	log("ovr_Room_Leave called with %d  and returned %d", roomID,  ret);
	return ret;
}
HOOK_DEF(ovr_Room_SetDescription, ovrRequest, ovrID roomID, const char *description)
{
	auto ret = ovr_Room_SetDescription_def(roomID, description);
	log("ovr_Room_SetDescription called with %d %d  and returned %d", roomID, description,  ret);
	return ret;
}
HOOK_DEF(ovr_Room_UpdateDataStore, ovrRequest, ovrID roomID, ovrKeyValuePair *data, unsigned int numItems)
{
	auto ret = ovr_Room_UpdateDataStore_def(roomID, data, numItems);
	log("ovr_Room_UpdateDataStore called with %d %d %d  and returned %d", roomID, data, numItems,  ret);
	return ret;
}
HOOK_DEF(ovr_Room_UpdateMembershipLockStatus, ovrRequest, ovrID roomID, ovrRoomMembershipLockStatus membershipLockStatus)
{
	auto ret = ovr_Room_UpdateMembershipLockStatus_def(roomID, membershipLockStatus);
	log("ovr_Room_UpdateMembershipLockStatus called with %d %d  and returned %d", roomID, membershipLockStatus,  ret);
	return ret;
}
HOOK_DEF(ovr_Room_UpdateOwner, ovrRequest, ovrID roomID, ovrID userID)
{
	auto ret = ovr_Room_UpdateOwner_def(roomID, userID);
	log("ovr_Room_UpdateOwner called with %d %d  and returned %d", roomID, userID,  ret);
	return ret;
}
HOOK_DEF(ovr_Room_UpdatePrivateRoomJoinPolicy, ovrRequest, ovrID roomID, ovrRoomJoinPolicy newJoinPolicy)
{
	auto ret = ovr_Room_UpdatePrivateRoomJoinPolicy_def(roomID, newJoinPolicy);
	log("ovr_Room_UpdatePrivateRoomJoinPolicy called with %d %d  and returned %d", roomID, newJoinPolicy,  ret);
	return ret;
}
HOOK_DEF(ovr_User_Get, ovrRequest, ovrID userID)
{
	auto ret = ovr_User_Get_def(userID);
	log("ovr_User_Get called with %d  and returned %d", userID,  ret);
	return ret;
}
HOOK_DEF(ovr_User_GetAccessToken, ovrRequest, )
{
	auto ret = ovr_User_GetAccessToken_def();
	log("ovr_User_GetAccessToken called with  and returned %d",  ret);
	return ret;
}
HOOK_DEF(ovr_User_GetLoggedInUser, ovrRequest, )
{
	auto ret = ovr_User_GetLoggedInUser_def();
	log("ovr_User_GetLoggedInUser called with  and returned %d",  ret);
	return ret;
}
HOOK_DEF(ovr_User_GetLoggedInUserFriends, ovrRequest, )
{
	auto ret = ovr_User_GetLoggedInUserFriends_def();
	log("ovr_User_GetLoggedInUserFriends called with  and returned %d",  ret);
	return ret;
}
HOOK_DEF(ovr_User_GetLoggedInUserFriendsAndRooms, ovrRequest, )
{
	auto ret = ovr_User_GetLoggedInUserFriendsAndRooms_def();
	log("ovr_User_GetLoggedInUserFriendsAndRooms called with  and returned %d",  ret);
	return ret;
}
HOOK_DEF(ovr_User_GetLoggedInUserRecentlyMetUsersAndRooms, ovrRequest, ovrUserOptionsHandle userOptions)
{
	auto ret = ovr_User_GetLoggedInUserRecentlyMetUsersAndRooms_def(userOptions);
	log("ovr_User_GetLoggedInUserRecentlyMetUsersAndRooms called with %d  and returned %d", userOptions,  ret);
	return ret;
}
HOOK_DEF(ovr_User_GetNextUserAndRoomArrayPage, ovrRequest, ovrUserAndRoomArrayHandle handle)
{
	auto ret = ovr_User_GetNextUserAndRoomArrayPage_def(handle);
	log("ovr_User_GetNextUserAndRoomArrayPage called with %d  and returned %d", handle,  ret);
	return ret;
}
HOOK_DEF(ovr_User_GetNextUserArrayPage, ovrRequest, ovrUserArrayHandle handle)
{
	auto ret = ovr_User_GetNextUserArrayPage_def(handle);
	log("ovr_User_GetNextUserArrayPage called with %d  and returned %d", handle,  ret);
	return ret;
}
HOOK_DEF(ovr_User_GetOrgScopedID, ovrRequest, ovrID userID)
{
	auto ret = ovr_User_GetOrgScopedID_def(userID);
	log("ovr_User_GetOrgScopedID called with %d  and returned %d", userID,  ret);
	return ret;
}
HOOK_DEF(ovr_User_GetSdkAccounts, ovrRequest, )
{
	auto ret = ovr_User_GetSdkAccounts_def();
	log("ovr_User_GetSdkAccounts called with  and returned %d",  ret);
	return ret;
}
HOOK_DEF(ovr_User_GetUserProof, ovrRequest, )
{
	auto ret = ovr_User_GetUserProof_def();
	log("ovr_User_GetUserProof called with  and returned %d",  ret);
	return ret;
}
HOOK_DEF(ovr_User_LaunchFriendRequestFlow, ovrRequest, ovrID userID)
{
	auto ret = ovr_User_LaunchFriendRequestFlow_def(userID);
	log("ovr_User_LaunchFriendRequestFlow called with %d  and returned %d", userID,  ret);
	return ret;
}
HOOK_DEF(ovr_User_LaunchProfile, ovrRequest, ovrID userID)
{
	auto ret = ovr_User_LaunchProfile_def(userID);
	log("ovr_User_LaunchProfile called with %d  and returned %d", userID,  ret);
	return ret;
}
HOOK_DEF(ovr_Voip_SetSystemVoipSuppressed, ovrRequest, bool suppressed)
{
	auto ret = ovr_Voip_SetSystemVoipSuppressed_def(suppressed);
	log("ovr_Voip_SetSystemVoipSuppressed called with %d  and returned %d", suppressed,  ret);
	return ret;
}
HOOK_DEF(ovr_Room_GetDataStore, ovrDataStoreHandle, const ovrRoomHandle obj)
{
	auto ret = ovr_Room_GetDataStore_def(obj);
	log("ovr_Room_GetDataStore called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Room_GetInvitedUsers, ovrUserArrayHandle, const ovrRoomHandle obj)
{
	auto ret = ovr_Room_GetInvitedUsers_def(obj);
	log("ovr_Room_GetInvitedUsers called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Room_GetMatchedUsers, ovrMatchmakingEnqueuedUserArrayHandle, const ovrRoomHandle obj)
{
	auto ret = ovr_Room_GetMatchedUsers_def(obj);
	log("ovr_Room_GetMatchedUsers called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Room_GetOwner, ovrUserHandle, const ovrRoomHandle obj)
{
	auto ret = ovr_Room_GetOwner_def(obj);
	log("ovr_Room_GetOwner called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Room_GetUsers, ovrUserArrayHandle, const ovrRoomHandle obj)
{
	auto ret = ovr_Room_GetUsers_def(obj);
	log("ovr_Room_GetUsers called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Room_GetApplicationID, ovrID, const ovrRoomHandle obj)
{
	auto ret = ovr_Room_GetApplicationID_def(obj);
	log("ovr_Room_GetApplicationID called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Room_GetDescription, const char *, const ovrRoomHandle obj)
{
	auto ret = ovr_Room_GetDescription_def(obj);
	log("ovr_Room_GetDescription called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Room_GetID, ovrID, const ovrRoomHandle obj)
{
	auto ret = ovr_Room_GetID_def(obj);
	log("ovr_Room_GetID called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Room_GetIsMembershipLocked, bool, const ovrRoomHandle obj)
{
	auto ret = ovr_Room_GetIsMembershipLocked_def(obj);
	log("ovr_Room_GetIsMembershipLocked called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Room_GetJoinPolicy, ovrRoomJoinPolicy, const ovrRoomHandle obj)
{
	auto ret = ovr_Room_GetJoinPolicy_def(obj);
	log("ovr_Room_GetJoinPolicy called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Room_GetJoinability, ovrRoomJoinability, const ovrRoomHandle obj)
{
	auto ret = ovr_Room_GetJoinability_def(obj);
	log("ovr_Room_GetJoinability called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Room_GetMaxUsers, unsigned int, const ovrRoomHandle obj)
{
	auto ret = ovr_Room_GetMaxUsers_def(obj);
	log("ovr_Room_GetMaxUsers called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Room_GetName, const char *, const ovrRoomHandle obj)
{
	auto ret = ovr_Room_GetName_def(obj);
	log("ovr_Room_GetName called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Room_GetType, ovrRoomType, const ovrRoomHandle obj)
{
	auto ret = ovr_Room_GetType_def(obj);
	log("ovr_Room_GetType called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_Room_GetVersion, unsigned int, const ovrRoomHandle obj)
{
	auto ret = ovr_Room_GetVersion_def(obj);
	log("ovr_Room_GetVersion called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_RoomArray_GetElement, ovrRoomHandle, const ovrRoomArrayHandle obj, size_t index)
{
	auto ret = ovr_RoomArray_GetElement_def(obj, index);
	log("ovr_RoomArray_GetElement called with %d %d  and returned %d", obj, index,  ret);
	return ret;
}
HOOK_DEF(ovr_RoomArray_GetNextUrl, const char *, const ovrRoomArrayHandle obj)
{
	auto ret = ovr_RoomArray_GetNextUrl_def(obj);
	log("ovr_RoomArray_GetNextUrl called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_RoomArray_GetSize, size_t, const ovrRoomArrayHandle obj)
{
	auto ret = ovr_RoomArray_GetSize_def(obj);
	log("ovr_RoomArray_GetSize called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_RoomArray_HasNextPage, bool, const ovrRoomArrayHandle obj)
{
	auto ret = ovr_RoomArray_HasNextPage_def(obj);
	log("ovr_RoomArray_HasNextPage called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_RoomInviteNotification_GetID, ovrID, const ovrRoomInviteNotificationHandle obj)
{
	auto ret = ovr_RoomInviteNotification_GetID_def(obj);
	log("ovr_RoomInviteNotification_GetID called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_RoomInviteNotification_GetRoomID, ovrID, const ovrRoomInviteNotificationHandle obj)
{
	auto ret = ovr_RoomInviteNotification_GetRoomID_def(obj);
	log("ovr_RoomInviteNotification_GetRoomID called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_RoomInviteNotification_GetSenderID, ovrID, const ovrRoomInviteNotificationHandle obj)
{
	auto ret = ovr_RoomInviteNotification_GetSenderID_def(obj);
	log("ovr_RoomInviteNotification_GetSenderID called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_RoomInviteNotification_GetSentTime, unsigned long long, const ovrRoomInviteNotificationHandle obj)
{
	auto ret = ovr_RoomInviteNotification_GetSentTime_def(obj);
	log("ovr_RoomInviteNotification_GetSentTime called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_RoomInviteNotificationArray_GetElement, ovrRoomInviteNotificationHandle, const ovrRoomInviteNotificationArrayHandle obj, size_t index)
{
	auto ret = ovr_RoomInviteNotificationArray_GetElement_def(obj, index);
	log("ovr_RoomInviteNotificationArray_GetElement called with %d %d  and returned %d", obj, index,  ret);
	return ret;
}
HOOK_DEF(ovr_RoomInviteNotificationArray_GetNextUrl, const char *, const ovrRoomInviteNotificationArrayHandle obj)
{
	auto ret = ovr_RoomInviteNotificationArray_GetNextUrl_def(obj);
	log("ovr_RoomInviteNotificationArray_GetNextUrl called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_RoomInviteNotificationArray_GetSize, size_t, const ovrRoomInviteNotificationArrayHandle obj)
{
	auto ret = ovr_RoomInviteNotificationArray_GetSize_def(obj);
	log("ovr_RoomInviteNotificationArray_GetSize called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_RoomInviteNotificationArray_HasNextPage, bool, const ovrRoomInviteNotificationArrayHandle obj)
{
	auto ret = ovr_RoomInviteNotificationArray_HasNextPage_def(obj);
	log("ovr_RoomInviteNotificationArray_HasNextPage called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovrRoomJoinability_ToString, const char*, ovrRoomJoinability value)
{
	auto ret = ovrRoomJoinability_ToString_def(value);
	log("ovrRoomJoinability_ToString called with %d  and returned %s", value,  ret);
	return ret;
}
HOOK_DEF(ovrRoomJoinability_FromString, ovrRoomJoinability, const char* str)
{
	auto ret = ovrRoomJoinability_FromString_def(str);
	log("ovrRoomJoinability_FromString called with %d  and returned %d", str,  ret);
	return ret;
}
HOOK_DEF(ovrRoomJoinPolicy_ToString, const char*, ovrRoomJoinPolicy value)
{
	auto ret = ovrRoomJoinPolicy_ToString_def(value);
	log("ovrRoomJoinPolicy_ToString called with %d  and returned %s", value,  ret);
	return ret;
}
HOOK_DEF(ovrRoomJoinPolicy_FromString, ovrRoomJoinPolicy, const char* str)
{
	auto ret = ovrRoomJoinPolicy_FromString_def(str);
	log("ovrRoomJoinPolicy_FromString called with %d  and returned %d", str,  ret);
	return ret;
}
HOOK_DEF(ovrRoomMembershipLockStatus_ToString, const char*, ovrRoomMembershipLockStatus value)
{
	auto ret = ovrRoomMembershipLockStatus_ToString_def(value);
	log("ovrRoomMembershipLockStatus_ToString called with %d  and returned %s", value,  ret);
	return ret;
}
HOOK_DEF(ovrRoomMembershipLockStatus_FromString, ovrRoomMembershipLockStatus, const char* str)
{
	auto ret = ovrRoomMembershipLockStatus_FromString_def(str);
	log("ovrRoomMembershipLockStatus_FromString called with %d  and returned %d", str,  ret);
	return ret;
}
HOOK_DEF(ovr_RoomOptions_Create, ovrRoomOptionsHandle, )
{
	auto ret = ovr_RoomOptions_Create_def();
	log("ovr_RoomOptions_Create called with  and returned %d",  ret);
	return ret;
}
HOOK_DEF(ovr_RoomOptions_Destroy, void, ovrRoomOptionsHandle handle)
{
	log("ovr_RoomOptions_Destroy called with %d ", handle);
	ovr_RoomOptions_Destroy_def(handle);
}
HOOK_DEF(ovr_RoomOptions_SetDataStoreString, void, ovrRoomOptionsHandle handle, const char* key, const char* value)
{
	log("ovr_RoomOptions_SetDataStoreString called with %d %d %d ", handle, key, value);
	ovr_RoomOptions_SetDataStoreString_def(handle, key, value);
}
HOOK_DEF(ovr_RoomOptions_ClearDataStore, void, ovrRoomOptionsHandle handle)
{
	log("ovr_RoomOptions_ClearDataStore called with %d ", handle);
	ovr_RoomOptions_ClearDataStore_def(handle);
}
HOOK_DEF(ovr_RoomOptions_SetExcludeRecentlyMet, void, ovrRoomOptionsHandle handle, bool value)
{
	log("ovr_RoomOptions_SetExcludeRecentlyMet called with %d %d ", handle, value);
	ovr_RoomOptions_SetExcludeRecentlyMet_def(handle, value);
}
HOOK_DEF(ovr_RoomOptions_SetMaxUserResults, void, ovrRoomOptionsHandle handle, unsigned int value)
{
	log("ovr_RoomOptions_SetMaxUserResults called with %d %d ", handle, value);
	ovr_RoomOptions_SetMaxUserResults_def(handle, value);
}
HOOK_DEF(ovr_RoomOptions_SetOrdering, void, ovrRoomOptionsHandle handle, ovrUserOrdering value)
{
	log("ovr_RoomOptions_SetOrdering called with %d %d ", handle, value);
	ovr_RoomOptions_SetOrdering_def(handle, value);
}
HOOK_DEF(ovr_RoomOptions_SetRecentlyMetTimeWindow, void, ovrRoomOptionsHandle handle, ovrTimeWindow value)
{
	log("ovr_RoomOptions_SetRecentlyMetTimeWindow called with %d %d ", handle, value);
	ovr_RoomOptions_SetRecentlyMetTimeWindow_def(handle, value);
}
HOOK_DEF(ovr_RoomOptions_SetRoomId, void, ovrRoomOptionsHandle handle, ovrID value)
{
	log("ovr_RoomOptions_SetRoomId called with %d %d ", handle, value);
	ovr_RoomOptions_SetRoomId_def(handle, value);
}
HOOK_DEF(ovr_RoomOptions_SetTurnOffUpdates, void, ovrRoomOptionsHandle handle, bool value)
{
	log("ovr_RoomOptions_SetTurnOffUpdates called with %d %d ", handle, value);
	ovr_RoomOptions_SetTurnOffUpdates_def(handle, value);
}
HOOK_DEF(ovrRoomType_ToString, const char*, ovrRoomType value)
{
	auto ret = ovrRoomType_ToString_def(value);
	log("ovrRoomType_ToString called with %d  and returned %s", value,  ret);
	return ret;
}
HOOK_DEF(ovrRoomType_FromString, ovrRoomType, const char* str)
{
	auto ret = ovrRoomType_FromString_def(str);
	log("ovrRoomType_FromString called with %d  and returned %d", str,  ret);
	return ret;
}
HOOK_DEF(ovr_SdkAccount_GetAccountType, ovrSdkAccountType, const ovrSdkAccountHandle obj)
{
	auto ret = ovr_SdkAccount_GetAccountType_def(obj);
	log("ovr_SdkAccount_GetAccountType called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_SdkAccount_GetUserId, ovrID, const ovrSdkAccountHandle obj)
{
	auto ret = ovr_SdkAccount_GetUserId_def(obj);
	log("ovr_SdkAccount_GetUserId called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_SdkAccountArray_GetElement, ovrSdkAccountHandle, const ovrSdkAccountArrayHandle obj, size_t index)
{
	auto ret = ovr_SdkAccountArray_GetElement_def(obj, index);
	log("ovr_SdkAccountArray_GetElement called with %d %d  and returned %d", obj, index,  ret);
	return ret;
}
HOOK_DEF(ovr_SdkAccountArray_GetSize, size_t, const ovrSdkAccountArrayHandle obj)
{
	auto ret = ovr_SdkAccountArray_GetSize_def(obj);
	log("ovr_SdkAccountArray_GetSize called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovrSdkAccountType_ToString, const char*, ovrSdkAccountType value)
{
	auto ret = ovrSdkAccountType_ToString_def(value);
	log("ovrSdkAccountType_ToString called with %d  and returned %s", value,  ret);
	return ret;
}
HOOK_DEF(ovrSdkAccountType_FromString, ovrSdkAccountType, const char* str)
{
	auto ret = ovrSdkAccountType_FromString_def(str);
	log("ovrSdkAccountType_FromString called with %d  and returned %d", str,  ret);
	return ret;
}
HOOK_DEF(ovrSendPolicy_ToString, const char*, ovrSendPolicy value)
{
	auto ret = ovrSendPolicy_ToString_def(value);
	log("ovrSendPolicy_ToString called with %d  and returned %s", value,  ret);
	return ret;
}
HOOK_DEF(ovrSendPolicy_FromString, ovrSendPolicy, const char* str)
{
	auto ret = ovrSendPolicy_FromString_def(str);
	log("ovrSendPolicy_FromString called with %d  and returned %d", str,  ret);
	return ret;
}
HOOK_DEF(ovrServiceProvider_ToString, const char*, ovrServiceProvider value)
{
	auto ret = ovrServiceProvider_ToString_def(value);
	log("ovrServiceProvider_ToString called with %d  and returned %s", value,  ret);
	return ret;
}
HOOK_DEF(ovrServiceProvider_FromString, ovrServiceProvider, const char* str)
{
	auto ret = ovrServiceProvider_FromString_def(str);
	log("ovrServiceProvider_FromString called with %d  and returned %d", str,  ret);
	return ret;
}
HOOK_DEF(ovr_ShareMediaResult_GetStatus, ovrShareMediaStatus, const ovrShareMediaResultHandle obj)
{
	auto ret = ovr_ShareMediaResult_GetStatus_def(obj);
	log("ovr_ShareMediaResult_GetStatus called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovrShareMediaStatus_ToString, const char*, ovrShareMediaStatus value)
{
	auto ret = ovrShareMediaStatus_ToString_def(value);
	log("ovrShareMediaStatus_ToString called with %d  and returned %s", value,  ret);
	return ret;
}
HOOK_DEF(ovrShareMediaStatus_FromString, ovrShareMediaStatus, const char* str)
{
	auto ret = ovrShareMediaStatus_FromString_def(str);
	log("ovrShareMediaStatus_FromString called with %d  and returned %d", str,  ret);
	return ret;
}
HOOK_DEF(ovr_SystemPermission_GetHasPermission, bool, const ovrSystemPermissionHandle obj)
{
	auto ret = ovr_SystemPermission_GetHasPermission_def(obj);
	log("ovr_SystemPermission_GetHasPermission called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_SystemPermission_GetPermissionGrantStatus, ovrPermissionGrantStatus, const ovrSystemPermissionHandle obj)
{
	auto ret = ovr_SystemPermission_GetPermissionGrantStatus_def(obj);
	log("ovr_SystemPermission_GetPermissionGrantStatus called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_SystemVoipState_GetMicrophoneMuted, ovrVoipMuteState, const ovrSystemVoipStateHandle obj)
{
	auto ret = ovr_SystemVoipState_GetMicrophoneMuted_def(obj);
	log("ovr_SystemVoipState_GetMicrophoneMuted called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_SystemVoipState_GetStatus, ovrSystemVoipStatus, const ovrSystemVoipStateHandle obj)
{
	auto ret = ovr_SystemVoipState_GetStatus_def(obj);
	log("ovr_SystemVoipState_GetStatus called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovrSystemVoipStatus_ToString, const char*, ovrSystemVoipStatus value)
{
	auto ret = ovrSystemVoipStatus_ToString_def(value);
	log("ovrSystemVoipStatus_ToString called with %d  and returned %s", value,  ret);
	return ret;
}
HOOK_DEF(ovrSystemVoipStatus_FromString, ovrSystemVoipStatus, const char* str)
{
	auto ret = ovrSystemVoipStatus_FromString_def(str);
	log("ovrSystemVoipStatus_FromString called with %d  and returned %d", str,  ret);
	return ret;
}
HOOK_DEF(ovrTimeWindow_ToString, const char*, ovrTimeWindow value)
{
	auto ret = ovrTimeWindow_ToString_def(value);
	log("ovrTimeWindow_ToString called with %d  and returned %s", value,  ret);
	return ret;
}
HOOK_DEF(ovrTimeWindow_FromString, ovrTimeWindow, const char* str)
{
	auto ret = ovrTimeWindow_FromString_def(str);
	log("ovrTimeWindow_FromString called with %d  and returned %d", str,  ret);
	return ret;
}
HOOK_DEF(ovr_UserAndRoom_GetRoom, ovrRoomHandle, const ovrUserAndRoomHandle obj)
{
	auto ret = ovr_UserAndRoom_GetRoom_def(obj);
	log("ovr_UserAndRoom_GetRoom called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_UserAndRoom_GetUser, ovrUserHandle, const ovrUserAndRoomHandle obj)
{
	auto ret = ovr_UserAndRoom_GetUser_def(obj);
	log("ovr_UserAndRoom_GetUser called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_UserAndRoomArray_GetElement, ovrUserAndRoomHandle, const ovrUserAndRoomArrayHandle obj, size_t index)
{
	auto ret = ovr_UserAndRoomArray_GetElement_def(obj, index);
	log("ovr_UserAndRoomArray_GetElement called with %d %d  and returned %d", obj, index,  ret);
	return ret;
}
HOOK_DEF(ovr_UserAndRoomArray_GetNextUrl, const char *, const ovrUserAndRoomArrayHandle obj)
{
	auto ret = ovr_UserAndRoomArray_GetNextUrl_def(obj);
	log("ovr_UserAndRoomArray_GetNextUrl called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_UserAndRoomArray_GetSize, size_t, const ovrUserAndRoomArrayHandle obj)
{
	auto ret = ovr_UserAndRoomArray_GetSize_def(obj);
	log("ovr_UserAndRoomArray_GetSize called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_UserAndRoomArray_HasNextPage, bool, const ovrUserAndRoomArrayHandle obj)
{
	auto ret = ovr_UserAndRoomArray_HasNextPage_def(obj);
	log("ovr_UserAndRoomArray_HasNextPage called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_UserArray_GetElement, ovrUserHandle, const ovrUserArrayHandle obj, size_t index)
{
	auto ret = ovr_UserArray_GetElement_def(obj, index);
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
HOOK_DEF(ovr_UserOptions_Create, ovrUserOptionsHandle, )
{
	auto ret = ovr_UserOptions_Create_def();
	log("ovr_UserOptions_Create called with  and returned %d",  ret);
	return ret;
}
HOOK_DEF(ovr_UserOptions_Destroy, void, ovrUserOptionsHandle handle)
{
	log("ovr_UserOptions_Destroy called with %d ", handle);
	ovr_UserOptions_Destroy_def(handle);
}
HOOK_DEF(ovr_UserOptions_SetMaxUsers, void, ovrUserOptionsHandle handle, unsigned int value)
{
	log("ovr_UserOptions_SetMaxUsers called with %d %d ", handle, value);
	ovr_UserOptions_SetMaxUsers_def(handle, value);
}
HOOK_DEF(ovr_UserOptions_AddServiceProvider, void, ovrUserOptionsHandle handle, ovrServiceProvider value)
{
	log("ovr_UserOptions_AddServiceProvider called with %d %d ", handle, value);
	ovr_UserOptions_AddServiceProvider_def(handle, value);
}
HOOK_DEF(ovr_UserOptions_ClearServiceProviders, void, ovrUserOptionsHandle handle)
{
	log("ovr_UserOptions_ClearServiceProviders called with %d ", handle);
	ovr_UserOptions_ClearServiceProviders_def(handle);
}
HOOK_DEF(ovr_UserOptions_SetTimeWindow, void, ovrUserOptionsHandle handle, ovrTimeWindow value)
{
	log("ovr_UserOptions_SetTimeWindow called with %d %d ", handle, value);
	ovr_UserOptions_SetTimeWindow_def(handle, value);
}
HOOK_DEF(ovrUserOrdering_ToString, const char*, ovrUserOrdering value)
{
	auto ret = ovrUserOrdering_ToString_def(value);
	log("ovrUserOrdering_ToString called with %d  and returned %s", value,  ret);
	return ret;
}
HOOK_DEF(ovrUserOrdering_FromString, ovrUserOrdering, const char* str)
{
	auto ret = ovrUserOrdering_FromString_def(str);
	log("ovrUserOrdering_FromString called with %d  and returned %d", str,  ret);
	return ret;
}
HOOK_DEF(ovrUserPresenceStatus_ToString, const char*, ovrUserPresenceStatus value)
{
	auto ret = ovrUserPresenceStatus_ToString_def(value);
	log("ovrUserPresenceStatus_ToString called with %d  and returned %s", value,  ret);
	return ret;
}
HOOK_DEF(ovrUserPresenceStatus_FromString, ovrUserPresenceStatus, const char* str)
{
	auto ret = ovrUserPresenceStatus_FromString_def(str);
	log("ovrUserPresenceStatus_FromString called with %d  and returned %d", str,  ret);
	return ret;
}
HOOK_DEF(ovr_UserProof_GetNonce, const char *, const ovrUserProofHandle obj)
{
	auto ret = ovr_UserProof_GetNonce_def(obj);
	log("ovr_UserProof_GetNonce called with %d  and returned %s", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_UserReportID_GetDidCancel, bool, const ovrUserReportIDHandle obj)
{
	auto ret = ovr_UserReportID_GetDidCancel_def(obj);
	log("ovr_UserReportID_GetDidCancel called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovr_UserReportID_GetID, ovrID, const ovrUserReportIDHandle obj)
{
	auto ret = ovr_UserReportID_GetID_def(obj);
	log("ovr_UserReportID_GetID called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovrVoipBitrate_ToString, const char*, ovrVoipBitrate value)
{
	auto ret = ovrVoipBitrate_ToString_def(value);
	log("ovrVoipBitrate_ToString called with %d  and returned %s", value,  ret);
	return ret;
}
HOOK_DEF(ovrVoipBitrate_FromString, ovrVoipBitrate, const char* str)
{
	auto ret = ovrVoipBitrate_FromString_def(str);
	log("ovrVoipBitrate_FromString called with %d  and returned %d", str,  ret);
	return ret;
}
HOOK_DEF(ovr_VoipDecoder_Decode, void, const ovrVoipDecoderHandle obj, const unsigned char *compressedData, size_t compressedSize)
{
	log("ovr_VoipDecoder_Decode called with %d %d %d ", obj, compressedData, compressedSize);
	ovr_VoipDecoder_Decode_def(obj, compressedData, compressedSize);
}
HOOK_DEF(ovr_VoipDecoder_GetDecodedPCM, size_t, const ovrVoipDecoderHandle obj, float *outputBuffer, size_t outputBufferSize)
{
	auto ret = ovr_VoipDecoder_GetDecodedPCM_def(obj, outputBuffer, outputBufferSize);
	log("ovr_VoipDecoder_GetDecodedPCM called with %d %d %d  and returned %d", obj, outputBuffer, outputBufferSize,  ret);
	return ret;
}
HOOK_DEF(ovrVoipDtxState_ToString, const char*, ovrVoipDtxState value)
{
	auto ret = ovrVoipDtxState_ToString_def(value);
	log("ovrVoipDtxState_ToString called with %d  and returned %s", value,  ret);
	return ret;
}
HOOK_DEF(ovrVoipDtxState_FromString, ovrVoipDtxState, const char* str)
{
	auto ret = ovrVoipDtxState_FromString_def(str);
	log("ovrVoipDtxState_FromString called with %d  and returned %d", str,  ret);
	return ret;
}
HOOK_DEF(ovr_VoipEncoder_AddPCM, void, const ovrVoipEncoderHandle obj, const float *inputData, unsigned int inputSize)
{
	log("ovr_VoipEncoder_AddPCM called with %d %d %d ", obj, inputData, inputSize);
	ovr_VoipEncoder_AddPCM_def(obj, inputData, inputSize);
}
HOOK_DEF(ovr_VoipEncoder_GetCompressedData, size_t, const ovrVoipEncoderHandle obj, unsigned char *outputBuffer, size_t intputSize)
{
	auto ret = ovr_VoipEncoder_GetCompressedData_def(obj, outputBuffer, intputSize);
	log("ovr_VoipEncoder_GetCompressedData called with %d %d %d  and returned %d", obj, outputBuffer, intputSize,  ret);
	return ret;
}
HOOK_DEF(ovr_VoipEncoder_GetCompressedDataSize, size_t, const ovrVoipEncoderHandle obj)
{
	auto ret = ovr_VoipEncoder_GetCompressedDataSize_def(obj);
	log("ovr_VoipEncoder_GetCompressedDataSize called with %d  and returned %d", obj,  ret);
	return ret;
}
HOOK_DEF(ovrVoipMuteState_ToString, const char*, ovrVoipMuteState value)
{
	auto ret = ovrVoipMuteState_ToString_def(value);
	log("ovrVoipMuteState_ToString called with %d  and returned %s", value,  ret);
	return ret;
}
HOOK_DEF(ovrVoipMuteState_FromString, ovrVoipMuteState, const char* str)
{
	auto ret = ovrVoipMuteState_FromString_def(str);
	log("ovrVoipMuteState_FromString called with %d  and returned %d", str,  ret);
	return ret;
}
HOOK_DEF(ovr_VoipOptions_Create, ovrVoipOptionsHandle, )
{
	auto ret = ovr_VoipOptions_Create_def();
	log("ovr_VoipOptions_Create called with  and returned %d",  ret);
	return ret;
}
HOOK_DEF(ovr_VoipOptions_Destroy, void, ovrVoipOptionsHandle handle)
{
	log("ovr_VoipOptions_Destroy called with %d ", handle);
	ovr_VoipOptions_Destroy_def(handle);
}
HOOK_DEF(ovr_VoipOptions_SetBitrateForNewConnections, void, ovrVoipOptionsHandle handle, ovrVoipBitrate value)
{
	log("ovr_VoipOptions_SetBitrateForNewConnections called with %d %d ", handle, value);
	ovr_VoipOptions_SetBitrateForNewConnections_def(handle, value);
}
HOOK_DEF(ovr_VoipOptions_SetCreateNewConnectionUseDtx, void, ovrVoipOptionsHandle handle, ovrVoipDtxState value)
{
	log("ovr_VoipOptions_SetCreateNewConnectionUseDtx called with %d %d ", handle, value);
	ovr_VoipOptions_SetCreateNewConnectionUseDtx_def(handle, value);
}
HOOK_DEF(ovrVoipSampleRate_ToString, const char*, ovrVoipSampleRate value)
{
	auto ret = ovrVoipSampleRate_ToString_def(value);
	log("ovrVoipSampleRate_ToString called with %d  and returned %s", value,  ret);
	return ret;
}
HOOK_DEF(ovrVoipSampleRate_FromString, ovrVoipSampleRate, const char* str)
{
	auto ret = ovrVoipSampleRate_FromString_def(str);
	log("ovrVoipSampleRate_FromString called with %d  and returned %d", str,  ret);
	return ret;
}
HOOK_DEF(ovr_Voip_CreateEncoder, ovrVoipEncoderHandle, )
{
	auto ret = ovr_Voip_CreateEncoder_def();
	log("ovr_Voip_CreateEncoder called with  and returned %d",  ret);
	return ret;
}
HOOK_DEF(ovr_Voip_DestroyEncoder, void, ovrVoipEncoderHandle encoder)
{
	log("ovr_Voip_DestroyEncoder called with %d ", encoder);
	ovr_Voip_DestroyEncoder_def(encoder);
}
HOOK_DEF(ovr_Voip_CreateDecoder, ovrVoipDecoderHandle, )
{
	auto ret = ovr_Voip_CreateDecoder_def();
	log("ovr_Voip_CreateDecoder called with  and returned %d",  ret);
	return ret;
}
HOOK_DEF(ovr_Voip_DestroyDecoder, void, ovrVoipDecoderHandle decoder)
{
	log("ovr_Voip_DestroyDecoder called with %d ", decoder);
	ovr_Voip_DestroyDecoder_def(decoder);
}
HOOK_DEF(ovr_Microphone_Create, ovrMicrophoneHandle, )
{
	auto ret = ovr_Microphone_Create_def();
	log("ovr_Microphone_Create called with  and returned %d",  ret);
	return ret;
}
HOOK_DEF(ovr_Microphone_Destroy, void, ovrMicrophoneHandle obj)
{
	log("ovr_Microphone_Destroy called with %d ", obj);
	ovr_Microphone_Destroy_def(obj);
}


void InitOVRHooks(void * ovrplatformHandle)
{
	INIT_HOOK(ovrplatformHandle, ovr_AbuseReportOptions_Create);
	INIT_HOOK(ovrplatformHandle, ovr_AbuseReportOptions_Destroy);
	INIT_HOOK(ovrplatformHandle, ovr_AbuseReportOptions_SetPreventPeopleChooser);
	INIT_HOOK(ovrplatformHandle, ovr_AbuseReportOptions_SetReportType);
	INIT_HOOK(ovrplatformHandle, ovr_AbuseReportRecording_GetRecordingUuid);
	INIT_HOOK(ovrplatformHandle, ovrAbuseReportType_ToString);
	INIT_HOOK(ovrplatformHandle, ovrAbuseReportType_FromString);
	INIT_HOOK(ovrplatformHandle, ovr_AchievementDefinition_GetName);
	INIT_HOOK(ovrplatformHandle, ovr_AchievementDefinition_GetBitfieldLength);
	INIT_HOOK(ovrplatformHandle, ovr_AchievementDefinition_GetTarget);
	INIT_HOOK(ovrplatformHandle, ovr_AchievementDefinition_GetType);
	INIT_HOOK(ovrplatformHandle, ovr_AchievementDefinitionArray_GetElement);
	INIT_HOOK(ovrplatformHandle, ovr_AchievementDefinitionArray_GetNextUrl);
	INIT_HOOK(ovrplatformHandle, ovr_AchievementDefinitionArray_GetSize);
	INIT_HOOK(ovrplatformHandle, ovr_AchievementDefinitionArray_HasNextPage);
	INIT_HOOK(ovrplatformHandle, ovr_AchievementProgress_GetBitfield);
	INIT_HOOK(ovrplatformHandle, ovr_AchievementProgress_GetCount);
	INIT_HOOK(ovrplatformHandle, ovr_AchievementProgress_GetIsUnlocked);
	INIT_HOOK(ovrplatformHandle, ovr_AchievementProgress_GetName);
	INIT_HOOK(ovrplatformHandle, ovr_AchievementProgress_GetUnlockTime);
	INIT_HOOK(ovrplatformHandle, ovr_AchievementProgressArray_GetElement);
	INIT_HOOK(ovrplatformHandle, ovr_AchievementProgressArray_GetNextUrl);
	INIT_HOOK(ovrplatformHandle, ovr_AchievementProgressArray_GetSize);
	INIT_HOOK(ovrplatformHandle, ovr_AchievementProgressArray_HasNextPage);
	INIT_HOOK(ovrplatformHandle, ovrAchievementType_ToString);
	INIT_HOOK(ovrplatformHandle, ovrAchievementType_FromString);
	INIT_HOOK(ovrplatformHandle, ovr_AchievementUpdate_GetJustUnlocked);
	INIT_HOOK(ovrplatformHandle, ovr_AchievementUpdate_GetName);
	INIT_HOOK(ovrplatformHandle, ovr_ApplicationOptions_Create);
	INIT_HOOK(ovrplatformHandle, ovr_ApplicationOptions_Destroy);
	INIT_HOOK(ovrplatformHandle, ovr_ApplicationOptions_SetDeeplinkMessage);
	INIT_HOOK(ovrplatformHandle, ovr_ApplicationVersion_GetCurrentCode);
	INIT_HOOK(ovrplatformHandle, ovr_ApplicationVersion_GetCurrentName);
	INIT_HOOK(ovrplatformHandle, ovr_ApplicationVersion_GetLatestCode);
	INIT_HOOK(ovrplatformHandle, ovr_ApplicationVersion_GetLatestName);
	INIT_HOOK(ovrplatformHandle, ovr_AssetDetails_GetAssetId);
	INIT_HOOK(ovrplatformHandle, ovr_AssetDetails_GetAssetType);
	INIT_HOOK(ovrplatformHandle, ovr_AssetDetails_GetDownloadStatus);
	INIT_HOOK(ovrplatformHandle, ovr_AssetDetails_GetFilepath);
	INIT_HOOK(ovrplatformHandle, ovr_AssetDetails_GetIapStatus);
	INIT_HOOK(ovrplatformHandle, ovr_AssetDetails_GetLanguage);
	INIT_HOOK(ovrplatformHandle, ovr_AssetDetailsArray_GetElement);
	INIT_HOOK(ovrplatformHandle, ovr_AssetDetailsArray_GetSize);
	INIT_HOOK(ovrplatformHandle, ovr_AssetFileDeleteResult_GetAssetFileId);
	INIT_HOOK(ovrplatformHandle, ovr_AssetFileDeleteResult_GetAssetId);
	INIT_HOOK(ovrplatformHandle, ovr_AssetFileDeleteResult_GetFilepath);
	INIT_HOOK(ovrplatformHandle, ovr_AssetFileDeleteResult_GetSuccess);
	INIT_HOOK(ovrplatformHandle, ovr_AssetFileDownloadCancelResult_GetAssetFileId);
	INIT_HOOK(ovrplatformHandle, ovr_AssetFileDownloadCancelResult_GetAssetId);
	INIT_HOOK(ovrplatformHandle, ovr_AssetFileDownloadCancelResult_GetFilepath);
	INIT_HOOK(ovrplatformHandle, ovr_AssetFileDownloadCancelResult_GetSuccess);
	INIT_HOOK(ovrplatformHandle, ovr_AssetFileDownloadResult_GetAssetId);
	INIT_HOOK(ovrplatformHandle, ovr_AssetFileDownloadResult_GetFilepath);
	INIT_HOOK(ovrplatformHandle, ovr_AssetFileDownloadUpdate_GetAssetFileId);
	INIT_HOOK(ovrplatformHandle, ovr_AssetFileDownloadUpdate_GetAssetId);
	INIT_HOOK(ovrplatformHandle, ovr_AssetFileDownloadUpdate_GetBytesTotal);
	INIT_HOOK(ovrplatformHandle, ovr_AssetFileDownloadUpdate_GetBytesTransferred);
	INIT_HOOK(ovrplatformHandle, ovr_AssetFileDownloadUpdate_GetCompleted);
	INIT_HOOK(ovrplatformHandle, ovr_CalApplicationFinalized_GetCountdownMS);
	INIT_HOOK(ovrplatformHandle, ovr_CalApplicationFinalized_GetID);
	INIT_HOOK(ovrplatformHandle, ovr_CalApplicationFinalized_GetLaunchDetails);
	INIT_HOOK(ovrplatformHandle, ovr_CalApplicationProposed_GetID);
	INIT_HOOK(ovrplatformHandle, ovr_CalApplicationSuggestion_GetID);
	INIT_HOOK(ovrplatformHandle, ovr_CalApplicationSuggestion_GetSocialContext);
	INIT_HOOK(ovrplatformHandle, ovr_CalApplicationSuggestionArray_GetElement);
	INIT_HOOK(ovrplatformHandle, ovr_CalApplicationSuggestionArray_GetSize);
	INIT_HOOK(ovrplatformHandle, ovr_CloudStorageConflictMetadata_GetLocal);
	INIT_HOOK(ovrplatformHandle, ovr_CloudStorageConflictMetadata_GetRemote);
	INIT_HOOK(ovrplatformHandle, ovr_CloudStorageData_GetBucket);
	INIT_HOOK(ovrplatformHandle, ovr_CloudStorageData_GetData);
	INIT_HOOK(ovrplatformHandle, ovr_CloudStorageData_GetDataSize);
	INIT_HOOK(ovrplatformHandle, ovr_CloudStorageData_GetKey);
	INIT_HOOK(ovrplatformHandle, ovrCloudStorageDataStatus_ToString);
	INIT_HOOK(ovrplatformHandle, ovrCloudStorageDataStatus_FromString);
	INIT_HOOK(ovrplatformHandle, ovr_CloudStorageMetadata_GetBucket);
	INIT_HOOK(ovrplatformHandle, ovr_CloudStorageMetadata_GetCounter);
	INIT_HOOK(ovrplatformHandle, ovr_CloudStorageMetadata_GetDataSize);
	INIT_HOOK(ovrplatformHandle, ovr_CloudStorageMetadata_GetExtraData);
	INIT_HOOK(ovrplatformHandle, ovr_CloudStorageMetadata_GetKey);
	INIT_HOOK(ovrplatformHandle, ovr_CloudStorageMetadata_GetSaveTime);
	INIT_HOOK(ovrplatformHandle, ovr_CloudStorageMetadata_GetStatus);
	INIT_HOOK(ovrplatformHandle, ovr_CloudStorageMetadata_GetVersionHandle);
	INIT_HOOK(ovrplatformHandle, ovr_CloudStorageMetadataArray_GetElement);
	INIT_HOOK(ovrplatformHandle, ovr_CloudStorageMetadataArray_GetNextUrl);
	INIT_HOOK(ovrplatformHandle, ovr_CloudStorageMetadataArray_GetSize);
	INIT_HOOK(ovrplatformHandle, ovr_CloudStorageMetadataArray_HasNextPage);
	INIT_HOOK(ovrplatformHandle, ovr_CloudStorageUpdateResponse_GetBucket);
	INIT_HOOK(ovrplatformHandle, ovr_CloudStorageUpdateResponse_GetKey);
	INIT_HOOK(ovrplatformHandle, ovr_CloudStorageUpdateResponse_GetStatus);
	INIT_HOOK(ovrplatformHandle, ovr_CloudStorageUpdateResponse_GetVersionHandle);
	INIT_HOOK(ovrplatformHandle, ovrCloudStorageUpdateStatus_ToString);
	INIT_HOOK(ovrplatformHandle, ovrCloudStorageUpdateStatus_FromString);
	INIT_HOOK(ovrplatformHandle, ovr_DataStore_Contains);
	INIT_HOOK(ovrplatformHandle, ovr_DataStore_GetKey);
	INIT_HOOK(ovrplatformHandle, ovr_DataStore_GetNumKeys);
	INIT_HOOK(ovrplatformHandle, ovr_DataStore_GetValue);
	INIT_HOOK(ovrplatformHandle, ovr_Error_GetDisplayableMessage);
	INIT_HOOK(ovrplatformHandle, ovr_Error_GetMessage);
	INIT_HOOK(ovrplatformHandle, ovr_Error_GetCode);
	INIT_HOOK(ovrplatformHandle, ovr_Error_GetHttpCode);
	INIT_HOOK(ovrplatformHandle, ovr_ApplicationLifecycle_GetLaunchDetails);
	INIT_HOOK(ovrplatformHandle, ovr_Net_Accept);
	INIT_HOOK(ovrplatformHandle, ovr_Net_AcceptForCurrentRoom);
	INIT_HOOK(ovrplatformHandle, ovr_Net_Close);
	INIT_HOOK(ovrplatformHandle, ovr_Net_CloseForCurrentRoom);
	INIT_HOOK(ovrplatformHandle, ovr_Net_Connect);
	INIT_HOOK(ovrplatformHandle, ovr_Net_IsConnected);
	INIT_HOOK(ovrplatformHandle, ovr_Net_Ping);
	INIT_HOOK(ovrplatformHandle, ovr_Net_ReadPacket);
	INIT_HOOK(ovrplatformHandle, ovr_Net_SendPacket);
	INIT_HOOK(ovrplatformHandle, ovr_Net_SendPacketToCurrentRoom);
	INIT_HOOK(ovrplatformHandle, ovr_Voip_Accept);
	INIT_HOOK(ovrplatformHandle, ovr_Voip_GetIsConnectionUsingDtx);
	INIT_HOOK(ovrplatformHandle, ovr_Voip_GetLocalBitrate);
	INIT_HOOK(ovrplatformHandle, ovr_Voip_GetOutputBufferMaxSize);
	INIT_HOOK(ovrplatformHandle, ovr_Voip_GetPCM);
	INIT_HOOK(ovrplatformHandle, ovr_Voip_GetPCMFloat);
	INIT_HOOK(ovrplatformHandle, ovr_Voip_GetPCMSize);
	INIT_HOOK(ovrplatformHandle, ovr_Voip_GetPCMWithTimestamp);
	INIT_HOOK(ovrplatformHandle, ovr_Voip_GetPCMWithTimestampFloat);
	INIT_HOOK(ovrplatformHandle, ovr_Voip_GetRemoteBitrate);
	INIT_HOOK(ovrplatformHandle, ovr_Voip_GetSyncTimestamp);
	INIT_HOOK(ovrplatformHandle, ovr_Voip_GetSyncTimestampDifference);
	INIT_HOOK(ovrplatformHandle, ovr_Voip_GetSystemVoipMicrophoneMuted);
	INIT_HOOK(ovrplatformHandle, ovr_Voip_GetSystemVoipStatus);
	INIT_HOOK(ovrplatformHandle, ovr_Voip_SetMicrophoneFilterCallback);
	INIT_HOOK(ovrplatformHandle, ovr_Voip_SetMicrophoneMuted);
	INIT_HOOK(ovrplatformHandle, ovr_Voip_SetNewConnectionOptions);
	INIT_HOOK(ovrplatformHandle, ovr_Voip_SetOutputSampleRate);
	INIT_HOOK(ovrplatformHandle, ovr_Voip_Start);
	INIT_HOOK(ovrplatformHandle, ovr_Voip_Stop);
	INIT_HOOK(ovrplatformHandle, ovr_HttpTransferUpdate_GetBytes);
	INIT_HOOK(ovrplatformHandle, ovr_HttpTransferUpdate_GetID);
	INIT_HOOK(ovrplatformHandle, ovr_HttpTransferUpdate_GetSize);
	INIT_HOOK(ovrplatformHandle, ovr_HttpTransferUpdate_IsCompleted);
	INIT_HOOK(ovrplatformHandle, ovr_InstalledApplication_GetApplicationId);
	INIT_HOOK(ovrplatformHandle, ovr_InstalledApplication_GetPackageName);
	INIT_HOOK(ovrplatformHandle, ovr_InstalledApplication_GetStatus);
	INIT_HOOK(ovrplatformHandle, ovr_InstalledApplication_GetVersionCode);
	INIT_HOOK(ovrplatformHandle, ovr_InstalledApplication_GetVersionName);
	INIT_HOOK(ovrplatformHandle, ovr_InstalledApplicationArray_GetElement);
	INIT_HOOK(ovrplatformHandle, ovr_InstalledApplicationArray_GetSize);
	INIT_HOOK(ovrplatformHandle, ovrKeyValuePairType_ToString);
	INIT_HOOK(ovrplatformHandle, ovrKeyValuePairType_FromString);
	INIT_HOOK(ovrplatformHandle, ovr_LanguagePackInfo_GetEnglishName);
	INIT_HOOK(ovrplatformHandle, ovr_LanguagePackInfo_GetNativeName);
	INIT_HOOK(ovrplatformHandle, ovr_LanguagePackInfo_GetTag);
	INIT_HOOK(ovrplatformHandle, ovr_LaunchBlockFlowResult_GetDidBlock);
	INIT_HOOK(ovrplatformHandle, ovr_LaunchBlockFlowResult_GetDidCancel);
	INIT_HOOK(ovrplatformHandle, ovr_LaunchDetails_GetDeeplinkMessage);
	INIT_HOOK(ovrplatformHandle, ovr_LaunchDetails_GetLaunchSource);
	INIT_HOOK(ovrplatformHandle, ovr_LaunchDetails_GetUsers);
	INIT_HOOK(ovrplatformHandle, ovr_LaunchDetails_GetLaunchType);
	INIT_HOOK(ovrplatformHandle, ovr_LaunchDetails_GetRoomID);
	INIT_HOOK(ovrplatformHandle, ovr_LaunchFriendRequestFlowResult_GetDidCancel);
	INIT_HOOK(ovrplatformHandle, ovr_LaunchFriendRequestFlowResult_GetDidSendRequest);
	INIT_HOOK(ovrplatformHandle, ovr_LaunchReportFlowResult_GetDidCancel);
	INIT_HOOK(ovrplatformHandle, ovr_LaunchReportFlowResult_GetUserReportId);
	INIT_HOOK(ovrplatformHandle, ovrLaunchType_ToString);
	INIT_HOOK(ovrplatformHandle, ovrLaunchType_FromString);
	INIT_HOOK(ovrplatformHandle, ovr_LaunchUnblockFlowResult_GetDidCancel);
	INIT_HOOK(ovrplatformHandle, ovr_LaunchUnblockFlowResult_GetDidUnblock);
	INIT_HOOK(ovrplatformHandle, ovr_LeaderboardEntryArray_HasNextPage);
	INIT_HOOK(ovrplatformHandle, ovr_LeaderboardEntryArray_HasPreviousPage);
	INIT_HOOK(ovrplatformHandle, ovrLeaderboardFilterType_ToString);
	INIT_HOOK(ovrplatformHandle, ovrLeaderboardFilterType_FromString);
	INIT_HOOK(ovrplatformHandle, ovrLeaderboardStartAt_ToString);
	INIT_HOOK(ovrplatformHandle, ovrLeaderboardStartAt_FromString);
	INIT_HOOK(ovrplatformHandle, ovr_LeaderboardUpdateStatus_GetDidUpdate);
	INIT_HOOK(ovrplatformHandle, ovr_LinkedAccount_GetAccessToken);
	INIT_HOOK(ovrplatformHandle, ovr_LinkedAccount_GetServiceProvider);
	INIT_HOOK(ovrplatformHandle, ovr_LinkedAccount_GetUserId);
	INIT_HOOK(ovrplatformHandle, ovr_LinkedAccountArray_GetElement);
	INIT_HOOK(ovrplatformHandle, ovr_LinkedAccountArray_GetSize);
	INIT_HOOK(ovrplatformHandle, ovr_LivestreamingApplicationStatus_GetStreamingEnabled);
	INIT_HOOK(ovrplatformHandle, ovrLivestreamingAudience_ToString);
	INIT_HOOK(ovrplatformHandle, ovrLivestreamingAudience_FromString);
	INIT_HOOK(ovrplatformHandle, ovrLivestreamingMicrophoneStatus_ToString);
	INIT_HOOK(ovrplatformHandle, ovrLivestreamingMicrophoneStatus_FromString);
	INIT_HOOK(ovrplatformHandle, ovr_LivestreamingStartResult_GetStreamingResult);
	INIT_HOOK(ovrplatformHandle, ovrLivestreamingStartStatus_ToString);
	INIT_HOOK(ovrplatformHandle, ovrLivestreamingStartStatus_FromString);
	INIT_HOOK(ovrplatformHandle, ovr_LivestreamingStatus_GetCommentsVisible);
	INIT_HOOK(ovrplatformHandle, ovr_LivestreamingStatus_GetIsPaused);
	INIT_HOOK(ovrplatformHandle, ovr_LivestreamingStatus_GetLivestreamingEnabled);
	INIT_HOOK(ovrplatformHandle, ovr_LivestreamingStatus_GetLivestreamingType);
	INIT_HOOK(ovrplatformHandle, ovr_LivestreamingStatus_GetMicEnabled);
	INIT_HOOK(ovrplatformHandle, ovr_LivestreamingVideoStats_GetCommentCount);
	INIT_HOOK(ovrplatformHandle, ovr_LivestreamingVideoStats_GetReactionCount);
	INIT_HOOK(ovrplatformHandle, ovr_LivestreamingVideoStats_GetTotalViews);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingAdminSnapshot_GetCandidates);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingAdminSnapshot_GetMyCurrentThreshold);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingAdminSnapshotCandidate_GetCanMatch);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingAdminSnapshotCandidate_GetMyTotalScore);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingAdminSnapshotCandidate_GetTheirCurrentThreshold);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingAdminSnapshotCandidate_GetTheirTotalScore);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingAdminSnapshotCandidate_GetTraceId);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingAdminSnapshotCandidateArray_GetElement);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingAdminSnapshotCandidateArray_GetSize);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingBrowseResult_GetEnqueueResult);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingBrowseResult_GetRooms);
	INIT_HOOK(ovrplatformHandle, ovrMatchmakingCriterionImportance_ToString);
	INIT_HOOK(ovrplatformHandle, ovrMatchmakingCriterionImportance_FromString);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingEnqueuedUser_GetCustomData);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingEnqueuedUser_GetUser);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingEnqueuedUser_GetAdditionalUserID);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingEnqueuedUser_GetAdditionalUserIDsSize);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingEnqueuedUserArray_GetElement);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingEnqueuedUserArray_GetSize);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingEnqueueResult_GetAdminSnapshot);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingEnqueueResult_GetAverageWait);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingEnqueueResult_GetMatchesInLastHourCount);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingEnqueueResult_GetMaxExpectedWait);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingEnqueueResult_GetRecentMatchPercentage);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingEnqueueResult_GetPool);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingEnqueueResult_GetRequestHash);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingEnqueueResultAndRoom_GetMatchmakingEnqueueResult);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingEnqueueResultAndRoom_GetRoom);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingOptions_Create);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingOptions_Destroy);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingOptions_SetCreateRoomDataStoreString);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingOptions_ClearCreateRoomDataStore);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingOptions_SetCreateRoomJoinPolicy);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingOptions_SetCreateRoomMaxUsers);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingOptions_AddEnqueueAdditionalUser);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingOptions_ClearEnqueueAdditionalUsers);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingOptions_SetEnqueueDataSettingsInt);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingOptions_SetEnqueueDataSettingsDouble);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingOptions_SetEnqueueDataSettingsString);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingOptions_ClearEnqueueDataSettings);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingOptions_SetEnqueueIsDebug);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingOptions_SetEnqueueQueryKey);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingRoom_GetPingTime);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingRoom_GetRoom);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingRoom_HasPingTime);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingRoomArray_GetElement);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingRoomArray_GetSize);
	INIT_HOOK(ovrplatformHandle, ovrMatchmakingStatApproach_ToString);
	INIT_HOOK(ovrplatformHandle, ovrMatchmakingStatApproach_FromString);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingStats_GetDrawCount);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingStats_GetLossCount);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingStats_GetSkillLevel);
	INIT_HOOK(ovrplatformHandle, ovr_MatchmakingStats_GetWinCount);
	INIT_HOOK(ovrplatformHandle, ovrMediaContentType_ToString);
	INIT_HOOK(ovrplatformHandle, ovrMediaContentType_FromString);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetAbuseReportRecording);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetAchievementDefinitionArray);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetAchievementProgressArray);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetAchievementUpdate);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetApplicationVersion);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetAssetDetails);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetAssetDetailsArray);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetAssetFileDeleteResult);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetAssetFileDownloadCancelResult);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetAssetFileDownloadResult);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetAssetFileDownloadUpdate);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetCalApplicationFinalized);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetCalApplicationProposed);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetCalApplicationSuggestionArray);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetCloudStorageConflictMetadata);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetCloudStorageData);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetCloudStorageMetadata);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetCloudStorageMetadataArray);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetCloudStorageUpdateResponse);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetError);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetHttpTransferUpdate);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetInstalledApplicationArray);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetLaunchBlockFlowResult);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetLaunchFriendRequestFlowResult);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetLaunchReportFlowResult);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetLaunchUnblockFlowResult);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetLeaderboardUpdateStatus);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetLinkedAccountArray);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetLivestreamingApplicationStatus);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetLivestreamingStartResult);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetLivestreamingStatus);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetLivestreamingVideoStats);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetMatchmakingAdminSnapshot);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetMatchmakingBrowseResult);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetMatchmakingEnqueueResult);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetMatchmakingEnqueueResultAndRoom);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetMatchmakingRoomArray);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetMatchmakingStats);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetNetworkingPeer);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetOrgScopedID);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetParty);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetPartyID);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetPartyUpdateNotification);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetPidArray);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetPingResult);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetPlatformInitialize);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetProductArray);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetPurchase);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetPurchaseArray);

	INIT_HOOK(ovrplatformHandle, ovr_Message_GetRoom);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetRoomArray);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetRoomInviteNotification);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetRoomInviteNotificationArray);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetSdkAccountArray);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetShareMediaResult);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetString);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetSystemPermission);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetSystemVoipState);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetUser);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetUserAndRoomArray);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetUserArray);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetUserProof);
	INIT_HOOK(ovrplatformHandle, ovr_Message_GetUserReportID);
	INIT_HOOK(ovrplatformHandle, ovrMessageType_ToString);
	INIT_HOOK(ovrplatformHandle, ovrMessageType_IsNotification);
	INIT_HOOK(ovrplatformHandle, ovr_Microphone_GetNumSamplesAvailable);
	INIT_HOOK(ovrplatformHandle, ovr_Microphone_GetOutputBufferMaxSize);
	INIT_HOOK(ovrplatformHandle, ovr_Microphone_GetPCM);
	INIT_HOOK(ovrplatformHandle, ovr_Microphone_GetPCMFloat);
	INIT_HOOK(ovrplatformHandle, ovr_Microphone_ReadData);
	INIT_HOOK(ovrplatformHandle, ovr_Microphone_SetAcceptableRecordingDelayHint);
	INIT_HOOK(ovrplatformHandle, ovr_Microphone_SetAudioDataAvailableCallback);
	INIT_HOOK(ovrplatformHandle, ovr_Microphone_Start);
	INIT_HOOK(ovrplatformHandle, ovr_Microphone_Stop);
	INIT_HOOK(ovrplatformHandle, ovr_NetworkingPeer_GetID);
	INIT_HOOK(ovrplatformHandle, ovr_NetworkingPeer_GetState);
	INIT_HOOK(ovrplatformHandle, ovr_OrgScopedID_GetID);
	INIT_HOOK(ovrplatformHandle, ovr_Packet_Free);
	INIT_HOOK(ovrplatformHandle, ovr_Packet_GetBytes);
	INIT_HOOK(ovrplatformHandle, ovr_Packet_GetSendPolicy);
	INIT_HOOK(ovrplatformHandle, ovr_Packet_GetSenderID);
	INIT_HOOK(ovrplatformHandle, ovr_Packet_GetSize);
	INIT_HOOK(ovrplatformHandle, ovr_Party_GetInvitedUsers);
	INIT_HOOK(ovrplatformHandle, ovr_Party_GetLeader);
	INIT_HOOK(ovrplatformHandle, ovr_Party_GetRoom);
	INIT_HOOK(ovrplatformHandle, ovr_Party_GetUsers);
	INIT_HOOK(ovrplatformHandle, ovr_Party_GetID);
	INIT_HOOK(ovrplatformHandle, ovr_PartyID_GetID);
	INIT_HOOK(ovrplatformHandle, ovrPartyUpdateAction_ToString);
	INIT_HOOK(ovrplatformHandle, ovrPartyUpdateAction_FromString);
	INIT_HOOK(ovrplatformHandle, ovr_PartyUpdateNotification_GetAction);
	INIT_HOOK(ovrplatformHandle, ovr_PartyUpdateNotification_GetPartyId);
	INIT_HOOK(ovrplatformHandle, ovr_PartyUpdateNotification_GetSenderId);
	INIT_HOOK(ovrplatformHandle, ovr_PartyUpdateNotification_GetUpdateTimestamp);
	INIT_HOOK(ovrplatformHandle, ovr_PartyUpdateNotification_GetUserAlias);
	INIT_HOOK(ovrplatformHandle, ovr_PartyUpdateNotification_GetUserId);
	INIT_HOOK(ovrplatformHandle, ovr_PartyUpdateNotification_GetUserName);
	INIT_HOOK(ovrplatformHandle, ovrPeerConnectionState_ToString);
	INIT_HOOK(ovrplatformHandle, ovrPeerConnectionState_FromString);
	INIT_HOOK(ovrplatformHandle, ovrPermissionGrantStatus_ToString);
	INIT_HOOK(ovrplatformHandle, ovrPermissionGrantStatus_FromString);
	INIT_HOOK(ovrplatformHandle, ovrPermissionType_ToString);
	INIT_HOOK(ovrplatformHandle, ovrPermissionType_FromString);
	INIT_HOOK(ovrplatformHandle, ovr_Pid_GetId);
	INIT_HOOK(ovrplatformHandle, ovr_PidArray_GetElement);
	INIT_HOOK(ovrplatformHandle, ovr_PidArray_GetSize);
	INIT_HOOK(ovrplatformHandle, ovr_PingResult_GetID);
	INIT_HOOK(ovrplatformHandle, ovr_PingResult_GetPingTimeUsec);
	INIT_HOOK(ovrplatformHandle, ovr_PingResult_IsTimeout);
	INIT_HOOK(ovrplatformHandle, ovr_IsPlatformInitialized);
	INIT_HOOK(ovrplatformHandle, ovr_PlatformInitializeAndroid);
	INIT_HOOK(ovrplatformHandle, ovr_PlatformInitializeAndroidAsynchronous);
	INIT_HOOK(ovrplatformHandle, ovr_PlatformInitializeWindows);
	INIT_HOOK(ovrplatformHandle, ovr_PlatformInitializeWindowsAsynchronous);
	INIT_HOOK(ovrplatformHandle, ovr_PlatformInitializeWindowsEx);
	INIT_HOOK(ovrplatformHandle, ovr_PlatformInitializeWindowsAsynchronousEx);
	INIT_HOOK(ovrplatformHandle, ovr_GetLoggedInUserID);
	INIT_HOOK(ovrplatformHandle, ovr_GetLoggedInUserLocale);
	INIT_HOOK(ovrplatformHandle, ovr_SetDeveloperAccessToken);
	INIT_HOOK(ovrplatformHandle, ovr_PlatformInitialize_GetResult);
	INIT_HOOK(ovrplatformHandle, ovrPlatformInitializeResult_ToString);
	INIT_HOOK(ovrplatformHandle, ovrPlatformInitializeResult_FromString);
	INIT_HOOK(ovrplatformHandle, ovr_Product_GetDescription);
	INIT_HOOK(ovrplatformHandle, ovr_Product_GetFormattedPrice);
	INIT_HOOK(ovrplatformHandle, ovr_Product_GetName);
	INIT_HOOK(ovrplatformHandle, ovr_Product_GetSKU);
	INIT_HOOK(ovrplatformHandle, ovr_ProductArray_GetElement);
	INIT_HOOK(ovrplatformHandle, ovr_ProductArray_GetNextUrl);
	INIT_HOOK(ovrplatformHandle, ovr_ProductArray_GetSize);
	INIT_HOOK(ovrplatformHandle, ovr_ProductArray_HasNextPage);
	INIT_HOOK(ovrplatformHandle, ovr_Purchase_GetExpirationTime);
	INIT_HOOK(ovrplatformHandle, ovr_Purchase_GetGrantTime);
	INIT_HOOK(ovrplatformHandle, ovr_Purchase_GetPurchaseID);
	INIT_HOOK(ovrplatformHandle, ovr_Purchase_GetSKU);
	INIT_HOOK(ovrplatformHandle, ovr_PurchaseArray_GetElement);
	INIT_HOOK(ovrplatformHandle, ovr_PurchaseArray_GetNextUrl);
	INIT_HOOK(ovrplatformHandle, ovr_PurchaseArray_GetSize);
	INIT_HOOK(ovrplatformHandle, ovr_PurchaseArray_HasNextPage);
	INIT_HOOK(ovrplatformHandle, ovr_Achievements_AddCount);
	INIT_HOOK(ovrplatformHandle, ovr_Achievements_AddFields);
	INIT_HOOK(ovrplatformHandle, ovr_Achievements_GetAllDefinitions);
	INIT_HOOK(ovrplatformHandle, ovr_Achievements_GetAllProgress);
	INIT_HOOK(ovrplatformHandle, ovr_Achievements_GetDefinitionsByName);
	INIT_HOOK(ovrplatformHandle, ovr_Achievements_GetNextAchievementDefinitionArrayPage);
	INIT_HOOK(ovrplatformHandle, ovr_Achievements_GetNextAchievementProgressArrayPage);
	INIT_HOOK(ovrplatformHandle, ovr_Achievements_GetProgressByName);
	INIT_HOOK(ovrplatformHandle, ovr_Achievements_Unlock);
	INIT_HOOK(ovrplatformHandle, ovr_Application_GetVersion);
	INIT_HOOK(ovrplatformHandle, ovr_Application_LaunchOtherApp);
	INIT_HOOK(ovrplatformHandle, ovr_ApplicationLifecycle_GetRegisteredPIDs);
	INIT_HOOK(ovrplatformHandle, ovr_ApplicationLifecycle_GetSessionKey);
	INIT_HOOK(ovrplatformHandle, ovr_ApplicationLifecycle_RegisterSessionKey);
	INIT_HOOK(ovrplatformHandle, ovr_AssetFile_Delete);
	INIT_HOOK(ovrplatformHandle, ovr_AssetFile_DeleteById);
	INIT_HOOK(ovrplatformHandle, ovr_AssetFile_DeleteByName);
	INIT_HOOK(ovrplatformHandle, ovr_AssetFile_Download);
	INIT_HOOK(ovrplatformHandle, ovr_AssetFile_DownloadById);
	INIT_HOOK(ovrplatformHandle, ovr_AssetFile_DownloadByName);
	INIT_HOOK(ovrplatformHandle, ovr_AssetFile_DownloadCancel);
	INIT_HOOK(ovrplatformHandle, ovr_AssetFile_DownloadCancelById);
	INIT_HOOK(ovrplatformHandle, ovr_AssetFile_DownloadCancelByName);
	INIT_HOOK(ovrplatformHandle, ovr_AssetFile_GetList);
	INIT_HOOK(ovrplatformHandle, ovr_AssetFile_Status);
	INIT_HOOK(ovrplatformHandle, ovr_AssetFile_StatusById);
	INIT_HOOK(ovrplatformHandle, ovr_AssetFile_StatusByName);
	INIT_HOOK(ovrplatformHandle, ovr_CloudStorage_Delete);
	INIT_HOOK(ovrplatformHandle, ovr_CloudStorage_GetNextCloudStorageMetadataArrayPage);
	INIT_HOOK(ovrplatformHandle, ovr_CloudStorage_Load);
	INIT_HOOK(ovrplatformHandle, ovr_CloudStorage_LoadBucketMetadata);
	INIT_HOOK(ovrplatformHandle, ovr_CloudStorage_LoadConflictMetadata);
	INIT_HOOK(ovrplatformHandle, ovr_CloudStorage_LoadHandle);
	INIT_HOOK(ovrplatformHandle, ovr_CloudStorage_LoadMetadata);
	INIT_HOOK(ovrplatformHandle, ovr_CloudStorage_ResolveKeepLocal);
	INIT_HOOK(ovrplatformHandle, ovr_CloudStorage_ResolveKeepRemote);
	INIT_HOOK(ovrplatformHandle, ovr_CloudStorage_Save);
	INIT_HOOK(ovrplatformHandle, ovr_Entitlement_GetIsViewerEntitled);
	INIT_HOOK(ovrplatformHandle, ovr_IAP_ConsumePurchase);
	INIT_HOOK(ovrplatformHandle, ovr_IAP_GetNextProductArrayPage);
	INIT_HOOK(ovrplatformHandle, ovr_IAP_GetNextPurchaseArrayPage);
	INIT_HOOK(ovrplatformHandle, ovr_IAP_GetProductsBySKU);
	INIT_HOOK(ovrplatformHandle, ovr_IAP_GetViewerPurchases);
	INIT_HOOK(ovrplatformHandle, ovr_IAP_LaunchCheckoutFlow);
	INIT_HOOK(ovrplatformHandle, ovr_LanguagePack_GetCurrent);
	INIT_HOOK(ovrplatformHandle, ovr_LanguagePack_SetCurrent);

	INIT_HOOK(ovrplatformHandle, ovr_Livestreaming_GetStatus);
	INIT_HOOK(ovrplatformHandle, ovr_Livestreaming_PauseStream);
	INIT_HOOK(ovrplatformHandle, ovr_Livestreaming_ResumeStream);
	INIT_HOOK(ovrplatformHandle, ovr_Matchmaking_Browse);
	INIT_HOOK(ovrplatformHandle, ovr_Matchmaking_Browse2);
	INIT_HOOK(ovrplatformHandle, ovr_Matchmaking_Cancel);
	INIT_HOOK(ovrplatformHandle, ovr_Matchmaking_Cancel2);
	INIT_HOOK(ovrplatformHandle, ovr_Matchmaking_CreateAndEnqueueRoom);
	INIT_HOOK(ovrplatformHandle, ovr_Matchmaking_CreateAndEnqueueRoom2);
	INIT_HOOK(ovrplatformHandle, ovr_Matchmaking_CreateRoom);
	INIT_HOOK(ovrplatformHandle, ovr_Matchmaking_CreateRoom2);
	INIT_HOOK(ovrplatformHandle, ovr_Matchmaking_Enqueue);
	INIT_HOOK(ovrplatformHandle, ovr_Matchmaking_Enqueue2);
	INIT_HOOK(ovrplatformHandle, ovr_Matchmaking_EnqueueRoom);
	INIT_HOOK(ovrplatformHandle, ovr_Matchmaking_EnqueueRoom2);
	INIT_HOOK(ovrplatformHandle, ovr_Matchmaking_GetAdminSnapshot);
	INIT_HOOK(ovrplatformHandle, ovr_Matchmaking_GetStats);
	INIT_HOOK(ovrplatformHandle, ovr_Matchmaking_JoinRoom);
	INIT_HOOK(ovrplatformHandle, ovr_Matchmaking_ReportResultInsecure);
	INIT_HOOK(ovrplatformHandle, ovr_Matchmaking_StartMatch);
	INIT_HOOK(ovrplatformHandle, ovr_Media_ShareToFacebook);
	INIT_HOOK(ovrplatformHandle, ovr_Notification_GetNextRoomInviteNotificationArrayPage);
	INIT_HOOK(ovrplatformHandle, ovr_Notification_GetRoomInvites);
	INIT_HOOK(ovrplatformHandle, ovr_Notification_MarkAsRead);
	INIT_HOOK(ovrplatformHandle, ovr_Party_GetCurrent);
	INIT_HOOK(ovrplatformHandle, ovr_Room_CreateAndJoinPrivate);
	INIT_HOOK(ovrplatformHandle, ovr_Room_CreateAndJoinPrivate2);
	INIT_HOOK(ovrplatformHandle, ovr_Room_Get);
	INIT_HOOK(ovrplatformHandle, ovr_Room_GetCurrent);
	INIT_HOOK(ovrplatformHandle, ovr_Room_GetCurrentForUser);
	INIT_HOOK(ovrplatformHandle, ovr_Room_GetInvitableUsers);
	INIT_HOOK(ovrplatformHandle, ovr_Room_GetInvitableUsers2);
	INIT_HOOK(ovrplatformHandle, ovr_Room_GetModeratedRooms);
	INIT_HOOK(ovrplatformHandle, ovr_Room_GetNextRoomArrayPage);
	INIT_HOOK(ovrplatformHandle, ovr_Room_InviteUser);
	INIT_HOOK(ovrplatformHandle, ovr_Room_Join);
	INIT_HOOK(ovrplatformHandle, ovr_Room_Join2);
	INIT_HOOK(ovrplatformHandle, ovr_Room_KickUser);
	INIT_HOOK(ovrplatformHandle, ovr_Room_LaunchInvitableUserFlow);
	INIT_HOOK(ovrplatformHandle, ovr_Room_Leave);
	INIT_HOOK(ovrplatformHandle, ovr_Room_SetDescription);
	INIT_HOOK(ovrplatformHandle, ovr_Room_UpdateDataStore);
	INIT_HOOK(ovrplatformHandle, ovr_Room_UpdateMembershipLockStatus);
	INIT_HOOK(ovrplatformHandle, ovr_Room_UpdateOwner);
	INIT_HOOK(ovrplatformHandle, ovr_Room_UpdatePrivateRoomJoinPolicy);
	INIT_HOOK(ovrplatformHandle, ovr_User_Get);
	INIT_HOOK(ovrplatformHandle, ovr_User_GetAccessToken);
	INIT_HOOK(ovrplatformHandle, ovr_User_GetLoggedInUser);
	INIT_HOOK(ovrplatformHandle, ovr_User_GetLoggedInUserFriends);
	INIT_HOOK(ovrplatformHandle, ovr_User_GetLoggedInUserFriendsAndRooms);
	INIT_HOOK(ovrplatformHandle, ovr_User_GetLoggedInUserRecentlyMetUsersAndRooms);
	INIT_HOOK(ovrplatformHandle, ovr_User_GetNextUserAndRoomArrayPage);
	INIT_HOOK(ovrplatformHandle, ovr_User_GetNextUserArrayPage);
	INIT_HOOK(ovrplatformHandle, ovr_User_GetOrgScopedID);
	INIT_HOOK(ovrplatformHandle, ovr_User_GetSdkAccounts);
	INIT_HOOK(ovrplatformHandle, ovr_User_GetUserProof);
	INIT_HOOK(ovrplatformHandle, ovr_User_LaunchFriendRequestFlow);
	INIT_HOOK(ovrplatformHandle, ovr_User_LaunchProfile);
	INIT_HOOK(ovrplatformHandle, ovr_Voip_SetSystemVoipSuppressed);
	INIT_HOOK(ovrplatformHandle, ovr_Room_GetDataStore);
	INIT_HOOK(ovrplatformHandle, ovr_Room_GetInvitedUsers);
	INIT_HOOK(ovrplatformHandle, ovr_Room_GetMatchedUsers);
	INIT_HOOK(ovrplatformHandle, ovr_Room_GetOwner);
	INIT_HOOK(ovrplatformHandle, ovr_Room_GetUsers);
	INIT_HOOK(ovrplatformHandle, ovr_Room_GetApplicationID);
	INIT_HOOK(ovrplatformHandle, ovr_Room_GetDescription);
	INIT_HOOK(ovrplatformHandle, ovr_Room_GetID);
	INIT_HOOK(ovrplatformHandle, ovr_Room_GetIsMembershipLocked);
	INIT_HOOK(ovrplatformHandle, ovr_Room_GetJoinPolicy);
	INIT_HOOK(ovrplatformHandle, ovr_Room_GetJoinability);
	INIT_HOOK(ovrplatformHandle, ovr_Room_GetMaxUsers);
	INIT_HOOK(ovrplatformHandle, ovr_Room_GetName);
	INIT_HOOK(ovrplatformHandle, ovr_Room_GetType);
	INIT_HOOK(ovrplatformHandle, ovr_Room_GetVersion);
	INIT_HOOK(ovrplatformHandle, ovr_RoomArray_GetElement);
	INIT_HOOK(ovrplatformHandle, ovr_RoomArray_GetNextUrl);
	INIT_HOOK(ovrplatformHandle, ovr_RoomArray_GetSize);
	INIT_HOOK(ovrplatformHandle, ovr_RoomArray_HasNextPage);
	INIT_HOOK(ovrplatformHandle, ovr_RoomInviteNotification_GetID);
	INIT_HOOK(ovrplatformHandle, ovr_RoomInviteNotification_GetRoomID);
	INIT_HOOK(ovrplatformHandle, ovr_RoomInviteNotification_GetSenderID);
	INIT_HOOK(ovrplatformHandle, ovr_RoomInviteNotification_GetSentTime);
	INIT_HOOK(ovrplatformHandle, ovr_RoomInviteNotificationArray_GetElement);
	INIT_HOOK(ovrplatformHandle, ovr_RoomInviteNotificationArray_GetNextUrl);
	INIT_HOOK(ovrplatformHandle, ovr_RoomInviteNotificationArray_GetSize);
	INIT_HOOK(ovrplatformHandle, ovr_RoomInviteNotificationArray_HasNextPage);
	INIT_HOOK(ovrplatformHandle, ovrRoomJoinability_ToString);
	INIT_HOOK(ovrplatformHandle, ovrRoomJoinability_FromString);
	INIT_HOOK(ovrplatformHandle, ovrRoomJoinPolicy_ToString);
	INIT_HOOK(ovrplatformHandle, ovrRoomJoinPolicy_FromString);
	INIT_HOOK(ovrplatformHandle, ovrRoomMembershipLockStatus_ToString);
	INIT_HOOK(ovrplatformHandle, ovrRoomMembershipLockStatus_FromString);
	INIT_HOOK(ovrplatformHandle, ovr_RoomOptions_Create);
	INIT_HOOK(ovrplatformHandle, ovr_RoomOptions_Destroy);
	INIT_HOOK(ovrplatformHandle, ovr_RoomOptions_SetDataStoreString);
	INIT_HOOK(ovrplatformHandle, ovr_RoomOptions_ClearDataStore);
	INIT_HOOK(ovrplatformHandle, ovr_RoomOptions_SetExcludeRecentlyMet);
	INIT_HOOK(ovrplatformHandle, ovr_RoomOptions_SetMaxUserResults);
	INIT_HOOK(ovrplatformHandle, ovr_RoomOptions_SetOrdering);
	INIT_HOOK(ovrplatformHandle, ovr_RoomOptions_SetRecentlyMetTimeWindow);
	INIT_HOOK(ovrplatformHandle, ovr_RoomOptions_SetRoomId);
	INIT_HOOK(ovrplatformHandle, ovr_RoomOptions_SetTurnOffUpdates);
	INIT_HOOK(ovrplatformHandle, ovrRoomType_ToString);
	INIT_HOOK(ovrplatformHandle, ovrRoomType_FromString);
	INIT_HOOK(ovrplatformHandle, ovr_SdkAccount_GetAccountType);
	INIT_HOOK(ovrplatformHandle, ovr_SdkAccount_GetUserId);
	INIT_HOOK(ovrplatformHandle, ovr_SdkAccountArray_GetElement);
	INIT_HOOK(ovrplatformHandle, ovr_SdkAccountArray_GetSize);
	INIT_HOOK(ovrplatformHandle, ovrSdkAccountType_ToString);
	INIT_HOOK(ovrplatformHandle, ovrSdkAccountType_FromString);
	INIT_HOOK(ovrplatformHandle, ovrSendPolicy_ToString);
	INIT_HOOK(ovrplatformHandle, ovrSendPolicy_FromString);
	INIT_HOOK(ovrplatformHandle, ovrServiceProvider_ToString);
	INIT_HOOK(ovrplatformHandle, ovrServiceProvider_FromString);
	INIT_HOOK(ovrplatformHandle, ovr_ShareMediaResult_GetStatus);
	INIT_HOOK(ovrplatformHandle, ovrShareMediaStatus_ToString);
	INIT_HOOK(ovrplatformHandle, ovrShareMediaStatus_FromString);
	INIT_HOOK(ovrplatformHandle, ovr_SystemPermission_GetHasPermission);
	INIT_HOOK(ovrplatformHandle, ovr_SystemPermission_GetPermissionGrantStatus);
	INIT_HOOK(ovrplatformHandle, ovr_SystemVoipState_GetMicrophoneMuted);
	INIT_HOOK(ovrplatformHandle, ovr_SystemVoipState_GetStatus);
	INIT_HOOK(ovrplatformHandle, ovrSystemVoipStatus_ToString);
	INIT_HOOK(ovrplatformHandle, ovrSystemVoipStatus_FromString);
	INIT_HOOK(ovrplatformHandle, ovrTimeWindow_ToString);
	INIT_HOOK(ovrplatformHandle, ovrTimeWindow_FromString);
	INIT_HOOK(ovrplatformHandle, ovr_UserAndRoom_GetRoom);
	INIT_HOOK(ovrplatformHandle, ovr_UserAndRoom_GetUser);
	INIT_HOOK(ovrplatformHandle, ovr_UserAndRoomArray_GetElement);
	INIT_HOOK(ovrplatformHandle, ovr_UserAndRoomArray_GetNextUrl);
	INIT_HOOK(ovrplatformHandle, ovr_UserAndRoomArray_GetSize);
	INIT_HOOK(ovrplatformHandle, ovr_UserAndRoomArray_HasNextPage);
	INIT_HOOK(ovrplatformHandle, ovr_UserArray_GetElement);
	INIT_HOOK(ovrplatformHandle, ovr_UserArray_GetNextUrl);
	INIT_HOOK(ovrplatformHandle, ovr_UserArray_GetSize);
	INIT_HOOK(ovrplatformHandle, ovr_UserArray_HasNextPage);
	INIT_HOOK(ovrplatformHandle, ovr_UserOptions_Create);
	INIT_HOOK(ovrplatformHandle, ovr_UserOptions_Destroy);
	INIT_HOOK(ovrplatformHandle, ovr_UserOptions_SetMaxUsers);
	INIT_HOOK(ovrplatformHandle, ovr_UserOptions_AddServiceProvider);
	INIT_HOOK(ovrplatformHandle, ovr_UserOptions_ClearServiceProviders);
	INIT_HOOK(ovrplatformHandle, ovr_UserOptions_SetTimeWindow);
	INIT_HOOK(ovrplatformHandle, ovrUserOrdering_ToString);
	INIT_HOOK(ovrplatformHandle, ovrUserOrdering_FromString);
	INIT_HOOK(ovrplatformHandle, ovrUserPresenceStatus_ToString);
	INIT_HOOK(ovrplatformHandle, ovrUserPresenceStatus_FromString);
	INIT_HOOK(ovrplatformHandle, ovr_UserProof_GetNonce);
	INIT_HOOK(ovrplatformHandle, ovr_UserReportID_GetDidCancel);
	INIT_HOOK(ovrplatformHandle, ovr_UserReportID_GetID);
	INIT_HOOK(ovrplatformHandle, ovrVoipBitrate_ToString);
	INIT_HOOK(ovrplatformHandle, ovrVoipBitrate_FromString);
	INIT_HOOK(ovrplatformHandle, ovr_VoipDecoder_Decode);
	INIT_HOOK(ovrplatformHandle, ovr_VoipDecoder_GetDecodedPCM);
	INIT_HOOK(ovrplatformHandle, ovrVoipDtxState_ToString);
	INIT_HOOK(ovrplatformHandle, ovrVoipDtxState_FromString);
	INIT_HOOK(ovrplatformHandle, ovr_VoipEncoder_AddPCM);
	INIT_HOOK(ovrplatformHandle, ovr_VoipEncoder_GetCompressedData);
	INIT_HOOK(ovrplatformHandle, ovr_VoipEncoder_GetCompressedDataSize);
	INIT_HOOK(ovrplatformHandle, ovrVoipMuteState_ToString);
	INIT_HOOK(ovrplatformHandle, ovrVoipMuteState_FromString);
	INIT_HOOK(ovrplatformHandle, ovr_VoipOptions_Create);
	INIT_HOOK(ovrplatformHandle, ovr_VoipOptions_Destroy);
	INIT_HOOK(ovrplatformHandle, ovr_VoipOptions_SetBitrateForNewConnections);
	INIT_HOOK(ovrplatformHandle, ovr_VoipOptions_SetCreateNewConnectionUseDtx);
	INIT_HOOK(ovrplatformHandle, ovrVoipSampleRate_ToString);
	INIT_HOOK(ovrplatformHandle, ovrVoipSampleRate_FromString);
	INIT_HOOK(ovrplatformHandle, ovr_Voip_CreateEncoder);
	INIT_HOOK(ovrplatformHandle, ovr_Voip_DestroyEncoder);
	INIT_HOOK(ovrplatformHandle, ovr_Voip_CreateDecoder);
	INIT_HOOK(ovrplatformHandle, ovr_Voip_DestroyDecoder);
	INIT_HOOK(ovrplatformHandle, ovr_Microphone_Create);
	INIT_HOOK(ovrplatformHandle, ovr_Microphone_Destroy);
}
