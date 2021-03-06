/*
* Copyright (c) 2015-2017 Easiio, Inc. All Rights Reserved.
*  
* 版权：厦门奥极亿通讯科技有限公司
* 描述：该头文件仅用于第三方集成本公司Windows PC版VoIP通讯相关的动态库。
* 网址：http://www.easiio.cn
* 邮箱：gavin.zhuang@easiio.com  or  cisson.hong@easiio.com
* 
*/

#ifndef EASIIOLIBRARY_H
#define EASIIOLIBRARY_H

#ifdef EASIIOLIBRARY_EXPORTS

#define DLLOPTION _declspec(dllexport)

#else

#define DLLOPTION _declspec(dllimport)

#endif

#ifdef __cplusplus
extern "C"
{
#endif

	//登录可选参数
	static const char* LOGIN_PARAM_USER_FLAG = "user_flag"; // 第三方集成用户标识
	static const char* LOGIN_PARAM_EASIIO_PSTN = "easiio_pstn"; // 落地权限：1开通，0关闭
	static const char* LOGIN_PARAM_CITY_CALL = "city_call"; // 市话权限：1开通，0关闭
	static const char* LOGIN_PARAM_NATIONAL_CALL = "national_call"; // 国内长途权限：1开通，0关闭
	static const char* LOGIN_PARAM_INTERNATIONAL_CALL = "international_call"; // 国际长途权限：1开通，0关闭
	static const char* LOGIN_PARAM_SERVER_URL = "server_url"; // 第三方服务端地址验证参数
	static const char* LOGIN_PARAM_ACCESS_TOKEN = "access_token";// 第三方服务端token验证参数


	enum{// PJSIP 状态
		PJSIP_SC_TRYING = 100, // Trying: extended search being performed may take a significant time so a forking proxy must send a 100 Trying response
		PJSIP_SC_RINGING = 180, // Ringing
		PJSIP_SC_CALL_BEING_FORWARDED = 181, // Call Is Being Forwarded
		PJSIP_SC_QUEUED = 182, // Queued
		PJSIP_SC_PROGRESS = 183, // Session Progress

		PJSIP_SC_OK = 200, // OK
		PJSIP_SC_ACCEPTED = 202, // accepted: It Indicates that the request has been understood but actually can't be processed

		PJSIP_SC_MULTIPLE_CHOICES = 300, // Multiple Choices
		PJSIP_SC_MOVED_PERMANENTLY = 301, // Moved Permanently
		PJSIP_SC_MOVED_TEMPORARILY = 302, // Moved Temporarily
		PJSIP_SC_USE_PROXY = 305, // Use Proxy
		PJSIP_SC_ALTERNATIVE_SERVICE = 380, // Alternative Service

		PJSIP_SC_BAD_REQUEST = 400, // Bad Request
		PJSIP_SC_UNAUTHORIZED = 401, // Unauthorized (Used only by registrars or user agents. Proxies should use proxy authorization 407
		PJSIP_SC_PAYMENT_REQUIRED = 402, // Payment Required (Reserved for future use)
		PJSIP_SC_FORBIDDEN = 403, // Forbidden"),
		PJSIP_SC_NOT_FOUND = 404, // Not Found (User not found)
		PJSIP_SC_METHOD_NOT_ALLOWED = 405, // Method Not Allowed
		PJSIP_SC_NOT_ACCEPTABLE = 406, // Not Acceptable
		PJSIP_SC_PROXY_AUTHENTICATION_REQUIRED = 407, // Proxy Authentication Required
		PJSIP_SC_REQUEST_TIMEOUT = 408, // Request Timeout (Couldn't find the user in time)
		PJSIP_SC_GONE = 410, // Gone (The user existed once, but is not available here any more.)
		PJSIP_SC_REQUEST_ENTITY_TOO_LARGE = 413, // Request Entity Too Large
		PJSIP_SC_REQUEST_URI_TOO_LONG = 414, // Request-URI Too Long
		PJSIP_SC_UNSUPPORTED_MEDIA_TYPE = 415, // Unsupported Media Type
		PJSIP_SC_UNSUPPORTED_URI_SCHEME = 416, // Unsupported URI Scheme
		PJSIP_SC_BAD_EXTENSION = 420, // Bad Extension (Bad SIP Protocol Extension used, not understood by the server)
		PJSIP_SC_EXTENSION_REQUIRED = 421, // Extension Required
		PJSIP_SC_SESSION_TIMER_TOO_SMALL = 422, // Session Interval Too Small
		PJSIP_SC_INTERVAL_TOO_BRIEF = 423, // Interval Too Brief
		PJSIP_SC_TEMPORARILY_UNAVAILABLE = 480, // Temporarily Unavailable
		PJSIP_SC_CALL_TSX_DOES_NOT_EXIST = 481, // Call/Transaction Does Not Exist
		PJSIP_SC_LOOP_DETECTED = 482, // Loop Detected
		PJSIP_SC_TOO_MANY_HOPS = 483, // Too Many Hops
		PJSIP_SC_ADDRESS_INCOMPLETE = 484, // Address Incomplete
		PJSIP_AC_AMBIGUOUS = 485, // Ambiguous
		PJSIP_SC_BUSY_HERE = 486, // Busy Here
		PJSIP_SC_REQUEST_TERMINATED = 487, // Request Terminated
		PJSIP_SC_NOT_ACCEPTABLE_HERE = 488, // Not Acceptable Here
		PJSIP_SC_BAD_EVENT = 489, // Bad Event
		PJSIP_SC_REQUEST_UPDATED = 490, // Request Updated
		PJSIP_SC_REQUEST_PENDING = 491, // Request Pending
		PJSIP_SC_UNDECIPHERABLE = 493, // Undecipherable (Could not decrypt S/MIME body part)

		PJSIP_SC_INTERNAL_SERVER_ERROR = 500, // Server Internal Error
		PJSIP_SC_NOT_IMPLEMENTED = 501, // Not Implemented: The SIP request method is not implemented here
		PJSIP_SC_BAD_GATEWAY = 502, // Bad Gateway
		PJSIP_SC_SERVICE_UNAVAILABLE = 503, // Service Unavailable
		PJSIP_SC_SERVER_TIMEOUT = 504, // Server Time-out
		PJSIP_SC_VERSION_NOT_SUPPORTED = 505, // Version Not Supported: The server does not support this version of the SIP protocol
		PJSIP_SC_MESSAGE_TOO_LARGE = 513, // Message Too Large
		PJSIP_SC_PRECONDITION_FAILURE = 580, // Precondition Failure

		PJSIP_SC_BUSY_EVERYWHERE = 600, // Busy Everywhere
		PJSIP_SC_DECLINE = 603, // Decline
		PJSIP_SC_DOES_NOT_EXIST_ANYWHERE = 604, // Does Not Exist Anywhere
		PJSIP_SC_NOT_ACCEPTABLE_ANYWHERE = 606, // Not Acceptable

		PJSIP_EXTENSION_OAUTH_CHECK_FAILED = 1000, // 第三方账号验证失败
	};

	enum{ // 登录结果
		LOGIN_SUCCESS = 0, // 登录成功
		LOGIN_FAILED_KEY_OR_TOKEN_IS_ERROR, // Developer key 或者 token是错误的
		LOGIN_FAILED_KEY_OR_TOKEN_IS_EMPTY, // Developer key 或者 token是空的
		LOGIN_FAILED_NO_PERMISSION_TO_CREATE_USER, // 该developer key 创建新用户的权限已经关闭
		LOGIN_FAILED_GET_DOMAIN_FAILED, //获取Domain信息失败
		LOGIN_FAILED_GET_USER_INFO_FAILED, //获取用户信息失败
		LOGIN_FAILED_LOGIN_PBX, // 登录PBX平台失败
		LOGIN_FAILED_GET_SIP_PROVISION, // 获取SIP配置信息失败
		LOGIN_FAILED_LIBRARY_ERROR, // Library内部出错
	};
	enum {  //会议
		MEETING_FAILED_GET_DATA = 3, //解析数据失败
		MEETING_FAILED_DOMAIN_IS_EMPTY = 4, //domain信息获取失败
		MEETING_FAILED_SIP_OR_USERINFO_IS_EMPTY = 5, //SIP配置或者用户信息为空
		MEETING_FAILED_WRONG_MEETING_KEY = 98, //错误的meeting_key
		MEETING_FAILED_REQUEST = 99, // http请求结果失败
		MEETING_FAILED = 100, //会议操作失败
	};
	enum {  //创建会议结果
		MEETING_SUCCESS_CREATE = 0, //创建会议成功
		MEETING_FAILED_CREATE_DESC_IS_EMPTY = 1, //会议描述为空
		MEETING_FAILED_CREATE_EXCEED_LIMIT = 2,  //会议数已达上限(免费用户上限为1)
	};
	enum { //获取会议列表
		MEETING_SUCCESS_GET_MEETINGLIST = 0,   //获取成功
		MEETING_FAILED_GET_MEETINGLIST_NO_MEETING_INFO = 1,//没有会议信息
	};
	enum { //更新会议
		MEETING_SUCCESS_UPDATE_MEETING = 0,  //更新会议成功
		MEETING_FAILED_UPDATE_DESC_IS_EMPTY = 1, //会议描述为空
		MEETING_FAILED_UPDATE_WRONG_MEETING_KEY = 2, //错误的meeting_key
	};
	enum { //删除会议
		MEETING_SUCCESS_DELETE_MEETING = 0, //删除成功
	};
	enum { //开启会议
		MEETING_SUCCESS_START_MEETING = 0, // 开启成功
		MEETING_FAILED_START_ALREADY_STARTED,//已启动会议
	};
	enum { //结束会议
        MEETING_SUCCESS_STOP_MEETING = 0, //结束成功
		MEETING_FAILED_STOP_WRONG_PLATFORM = 1, //错误的平台
	};
	enum { //获取参会信息
		MEETING_SUCCESS_GET_PARTICIPANTINFO = 0, //成功
		MEETING_FAILED_GET_PARTICIPANTINFO_NUMBER_LIMIT = 1, //会议人数超过限制
	};
	enum { //加入会议
		MEETING_SUCCESS_JOIN_MEETING = 0, //成功
		MEETING_FAILED_MEETING_IS_CLOSE,  //会议关闭
	};

	enum{ // VoIP通话状态
		CALL_STATE_INCOMING = 0,
		CALL_STATE_INIT,
		CALL_STATE_EARLY,
		CALL_STATE_CONNECTING,
		CALL_STATE_CONFIRMED,
		CALL_STATE_DISCONNECTED
	};

	enum{ //双向呼叫状态
		TWO_WAY_CALL_STATE_CALLING,
		TWO_WAY_CALL_STATE_RINGING,
		TWO_WAY_CALL_STATE_EARLY,
		TWO_WAY_CALL_STATE_ANSWERED,
		TWO_WAY_CALL_STATE_BRIDGED,
		TWO_WAY_CALL_STATE_HANGUP
	};

	enum{ // 消息类型
		MSG_TYPE_TEXT = 0, // 文本消息
		MSG_TYPE_VOICE = 1, // 语音消息
		MSG_TYPE_IMAGE = 2, // 图片消息
		MSG_TYPE_FILE = 3, // 文件消息
		MSG_TYPE_CONF_INVITE = 10, // 会议邀请
		MSG_TYPE_CONF_NOTIFY = 11, // 会议通知
		MSG_TYPE_TWO_WAY_CALL_STATE = 201 // 双向呼叫状态消息
	};

	enum{// 呼叫类型
		VOICE_CALL = 0, // 语音呼叫
		VIDEO_CALL  // 语音视频呼叫
	};

	enum{ // 请求回调结果
		REQUEST_SUCCESS = 0, // 调用成功
		REQUEST_FAILED,      // 调用失败

	};
	enum{
		RECORD_STOP = 0,   // 停止录音
		RECORD_START // 开始录音
	};

	enum{
		RECORD_CLOSE = 0, // 录音关闭
		RECORD_OPEN       // 录音开启
	};

	enum{ // 获取录音类型
		RECORD_TYPE_FROM_CALL_START = 0, // 通话一开始就录音
		RECORD_TYPE_IN_CALL  // 通话中的录音
	};

	enum{
		ORIENTATION_PORTRAIT = 0, // 竖屏
		ORIENTATION_LANDSCAPE = 1 // 横屏
	};

	typedef struct _EasiioLoginParams{ // 登录可选参数
		char* param_key; // 参数名
		char* param_value; // 参数值
	}EasiioLoginParams;

	// 单个通话录音目录
	typedef struct _EasiioRecord{
		char* from_user;    // 主叫
		char* call_uuid;      // 通话ID
		int record_count;   // 录音数量
		char* direction;    // 呼出或呼入
		char* to_user;      // 被叫
		char* answer_time;  // 应答时间
	}EasiioRecord;

	// 单个录音文件
	typedef struct _EasiioRecordItem{
		char* insert_time;   // 插入时间
		char* uri;           // 录音地址
		char* uuid;          // 录音ID
		double record_ms;    // 录音时长（秒）
		char* answer_time;   // 应答时间
	}EasiioRecordItem;

	//回调错误码及描述
	typedef struct _EasiioResponseReason
	{
		int reason;//原因
		char* msg;//原因描述
	}EasiioResponseReason;

	//视频会议信息
	typedef struct _MeetingInfo {
		char *easiio_id; //创建会议的用户号码
		char *meeting_key;  //会议号码
	    char *desc;   //会议描述
		int priority; //会议优先级
		char *create_time;  //创建时间
		int status;  //会议状态   开启:1  关闭: 0
	}MeetingInfo;
	typedef struct _ParticipantInfo {
		int count;   //参会人数
		char* origin_host;  //主持人
		char* join_host;   //加会拨打号码
		char* resolution;
		char participant[32][20];  //参会人员
	}ParticipantInfo;


	// 回调
	typedef struct _EASIIO_CALLBACK_INTERFACE{
		void(*onLoginResult)(int resultCode, const char* resultMsg); // 登录结果
		void(*onPJSIPServiceStateChanged)(int stateCode); // PJSIP状态变化通知
		void(*onCallStatusChanged)(int callId, int callState, const char* resultCode, const char* callUUID); // 通话状态变化通知
		void(*onTwoWayCallStatusChanged)(int callState, const char* callUUID, const char* caller, const char* callee, int retrying); // 双向呼叫通话状态通知
		void(*onIncomingCall)(int callId, int callType, const char* fromNumber, const char* postValue,const char* meeting_key); // 来电通知

		// response
		void(*onMakeTwoWayCallResult)(EasiioResponseReason reason, const char* caller, const char* callee, const char* callUUID, const char* retryId); //双向呼叫结果
		void(*onCallRecordingReaponse)(EasiioResponseReason reason, int switchRecord, const char* callUUID); // 通话中开启、停止录音调用结果
		void(*onGetAllRecordResponse)(EasiioResponseReason reason, int count, EasiioRecord *record); //获取所有录音回调结果 
		void(*onGetRecordResponse)(EasiioResponseReason reason, const char* callUUID, int count, EasiioRecordItem *recordItem); //获取单次通话录音回调结果
		void(*onMakeCallResult)(int callId, const char* toNumber,const char* meetingkey); 
		void(*onMeetingResult)(EasiioResponseReason reason,int count, MeetingInfo *info);  //获取会议信息
	}EASIIO_CALLBACK_INTERFACE;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 初始化和配置
	
	/* @function
	************************************************************************************
	函数名   : EasiioInit
	功能     : 初始化。
	参数     : [IN]  CallbackInterface     : 回调函数指针结构体EASIIO_CALLBACK_INTERFACE
	返回值   : 是否成功 0：成功； 非0失败
	************************************************************************************/
	DLLOPTION int EasiioInit(EASIIO_CALLBACK_INTERFACE *CallbackInterface);

	/* @function
	************************************************************************************
	函数名   : EasiioInitDeveloperKeyAndToken
	功能     : 初始化开发者密钥和信令。
	参数     : [IN]  developerKey     :  开发者密钥
			   [IN]  token            :  项目信令
	返回值   : 是否成功 0：成功； 非0失败
	************************************************************************************/
	DLLOPTION int EasiioInitDeveloperKeyAndToken(const char* developerKey, const char* token);

	/* @function
	************************************************************************************
	函数名   : EasiioLogin
	功能     : 账号登录。
	参数     : [IN]  account     :  第三方应用账号
			   [IN]  paramCount  :  登录可选参数数量
	           [IN]  params      :  登录可选参数
	返回值   : 是否成功 0：成功； 非0失败
	回调函数 : void(*onLoginResult)(int resultCode, const char* resultMsg); // 登录结果
	************************************************************************************/
	DLLOPTION int EasiioLogin(const char* account, int paramCount, EasiioLoginParams* params);

	/* @function
	************************************************************************************
	函数名   : EasiioLogout
	功能     : 账号登出。
	返回值   : 是否成功 0：成功； 非0失败
	************************************************************************************/
	DLLOPTION int EasiioLogout();

	/* @function
	************************************************************************************
	函数名   : EasiioMakeCall
	功能     : VoIP呼叫
	参数     : [IN] number    : 呼叫号码
	           [IN] callType  : 呼叫类型
			        VOICE_CALL, // 语音呼叫
			        VIDEO_CALL  // 语音视频呼叫
			   [IN] postValue : 需要传递给被叫方的值，长度最好不超过256，且最好用BASE64加密
	返回值   : 返回Call Id
			       call id : >=0    成功呼叫
							 -1     呼叫失败
							 -300   没有麦克风输入
							 -301   没有麦克风输出
							 -302   没有麦克风输入输出
	回调函数 : void(*onCallStatusChanged)(int callId, int callState, const char* resultCode, const char* callUUID); // 通话状态变化通知
	           void(*onMakeCallResult)(int callId, const char* toNumber,const char* meetingkey);
	************************************************************************************/
	DLLOPTION int EasiioMakeCall(const char* number, int callType, const char* postValue);

	/* @function
	************************************************************************************
	函数名   : EasiioMakeCallWithRecording
	功能     : VoIP呼叫
	参数     : [IN] number    : 呼叫号码
	[IN] callType  : 呼叫类型
	VOICE_CALL, // 语音呼叫
	VIDEO_CALL  // 语音视频呼叫
	[IN] postValue : 需要传递给被叫方的值，长度最好不超过256，且最好用BASE64加密
	返回值   : 返回Call Id
	call id : >=0    成功呼叫
	-1     呼叫失败
	-300   没有麦克风输入
	-301   没有麦克风输出
	-302   没有麦克风输入输出
	回调函数 : void(*onCallStatusChanged)(int callId, int callState, const char* resultCode, const char* callUUID); // 通话状态变化通知
	           void(*onMakeCallResult)(int callId, const char* toNumber);
	************************************************************************************/
	DLLOPTION int EasiioMakeCallWithRecording(const char* number, int callType);

	/* @function
	************************************************************************************
	函数名   : EasiioMakeTwoWayCall
	功能     : 双向呼叫
	参数     : [IN] toNumber    : 被叫号码
	           [IN] fromNumber  : 主叫号码
			   [IN] openRecord  : 开启录音
	返回值   : 是否成功 0：成功； 非0失败
	回调函数 : void(*onMakeTwoWayCallResult)(EasiioResponseReason reason, const char* caller, const char* callee, const char* callId, const char* retryId); //双向呼叫结果
	           void(*onTwoWayCallStatusChanged)(int callState, const char* callId, const char* caller, const char* callee, int retrying); // 双向呼叫通话状态通知
	************************************************************************************/
	DLLOPTION int EasiioMakeTwoWayCall(const char* toNumber, const char* fromNumber, int openRecord);

	/* @function
	************************************************************************************
	函数名   : EasiioAnswerCall
	功能     : 来电应答
	参数     : [IN] callId    : 来电通话ID
			   [IN] callType  : 应答类型
					VOICE_CALL, // 语音应答
					VIDEO_CALL  // 视频应答
	返回值   : 是否成功 0：成功； 非0失败
	回调函数 : void(*onCallStatusChanged)(int callId, int callState, const char* resultCode); // 通话状态变化通知
	************************************************************************************/
	DLLOPTION int EasiioAnswerCall(int callId, int callType);

	/* @function
	************************************************************************************
	函数名   : EasiioRejectCall
	功能     : 拒接来电
	参数     : [IN] callId    : 来电通话ID
	返回值   : 是否成功 0：成功； 非0失败
	回调函数 : void(*onCallStatusChanged)(int callId, int callState, const char* resultCode); // 通话状态变化通知
	************************************************************************************/
	DLLOPTION int EasiioRejectCall(int callId);

	/* @function
	************************************************************************************
	函数名   : EasiioHangupCall
	功能     : 挂断通话
	参数     : [IN] callId    : 通话ID
	返回值   : 是否成功 0：成功； 非0失败
	回调函数 : void(*onCallStatusChanged)(int callId, int callState, const char* resultCode); // 通话状态变化通知
	************************************************************************************/
	DLLOPTION int EasiioHangupCall(int callId);

	/* @function
	************************************************************************************
	函数名   : EasiioHoldCall
	功能     : 通话保持
	参数     : [IN] callId    : 通话ID
	返回值   : 是否成功 0：成功； 非0失败
	************************************************************************************/
	DLLOPTION int EasiioHoldCall(int callId);

	/* @function
	************************************************************************************
	函数名   : EasiioUnHoldCall
	功能     : 解除通话保持
	参数     : [IN] callId    : 通话ID
	返回值   : 是否成功 0：成功； 非0失败
	************************************************************************************/
	DLLOPTION int EasiioUnHoldCall(int callId);

	/* @function
	************************************************************************************
	函数名   : EasiioMuteCall
	功能     : 通话静音
	参数     : [IN] callId    : 通话ID
	返回值   : 是否成功 0：成功； 非0失败
	************************************************************************************/
	DLLOPTION int EasiioMuteCall(int callId);

	/* @function
	************************************************************************************
	函数名   : EasiioUnMuteCall
	功能     : 解除通话静音
	参数     : [IN] callId    : 通话ID
	返回值   : 是否成功 0：成功； 非0失败
	************************************************************************************/
	DLLOPTION int EasiioUnMuteCall(int callId);

	/* @function
	************************************************************************************
	函数名   : EasiioAdjustMicLevel
	功能     : 调整通话麦克风音量
	参数     : [IN] callId    : 通话ID
	           [IN] level     : 麦克风音量大小 0 - 40
	返回值   : 是否成功 0：成功； 非0失败
	************************************************************************************/
	DLLOPTION int EasiioAdjustMicLevel(int callId, int level);

	/* @function
	************************************************************************************
	函数名   : EasiioSendDTMF
	功能     : 发送DTMF
	参数     : [IN] callId    : 通话ID
	           [IN] dtmf      : DTMF值
	返回值   : 是否成功 0：成功； 非0失败
	************************************************************************************/
	DLLOPTION int EasiioSendDTMF(int callId, const char* dtmf);

	/* @function
	************************************************************************************
	函数名   : EasiioSwitchRecordInCall
	功能     : 通话中开始或停止录音
	参数     : [IN] recordSwitch : 开始或停止录音
	                RECORD_START, // 开始录音
		            RECORD_STOP   // 停止录音
	           [IN] callUUID     : 通话的UUID，可从状态变化获取
	返回值   : 是否成功 0：成功； 非0失败
	回调函数 : void(*onCallRecordingReaponse)(EasiioResponseReason reason, int switchRecord, const char* callUUID); // 通话中开启、停止录音调用结果
	************************************************************************************/
	DLLOPTION int EasiioSwitchRecordInCall(int recordSwitch, const char* callUUID);

	/* @function
	************************************************************************************
	函数名   : EasiioGetCurrentPBXAccount
	功能     : 获取当前PBX号码
	参数     : [OUT] pbxAccount    : 当前登录的PBX号码
	返回值   : 是否成功 0：成功； 非0失败
	************************************************************************************/
	DLLOPTION int EasiioGetCurrentPBXAccount(char* pbxAccount);

	/* @function
	************************************************************************************
	函数名   : EasiioGetAllRecord
	功能     : 获取所有录音列表目录
	参数     : [IN] recordType  : 录音类型
				RECORD_TYPE_FROM_CALL_START = 0, // 通话一开始就录音
				RECORD_TYPE_IN_CALL  // 通话中的录音
	返回值   : 是否成功 0：成功； 非0失败
	回调函数 : void(*onGetAllRecordResponse)(EasiioResponseReason reason, int count, EasiioRecord *record); //获取所有录音回调结果 
	************************************************************************************/
	DLLOPTION int EasiioGetAllRecord(int recordType);

	/* @function
	************************************************************************************
	函数名   : EasiioGetRecord
	功能     : 获取单次通话录音
	参数     : [IN] recordType  : 录音类型
				RECORD_TYPE_FROM_CALL_START = 0, // 通话一开始就录音
				RECORD_TYPE_IN_CALL  // 通话中的录音
			   [IN] callUUID     : 录音ID， 可以从获取所有录音里取出，也可以在通话结束后
			                       使用通话状态回调的callUUID
	返回值   : 是否成功 0：成功； 非0失败
	回调函数 : void(*onGetRecordResponse)(EasiioResponseReason reason, const char* callUUID, int count, EasiioRecordItem *recordItem); //获取单次通话录音回调结果
	************************************************************************************/
	DLLOPTION int EasiioGetRecord(int recordType, const char* callUUID);

	/* @function
	************************************************************************************
	函数名   : EasiioDestroy
	功能     : 销毁，第三方应用退出时调用，区别于EasiioLogout
	返回值   : 是否成功 0：成功； 非0失败
	************************************************************************************/
	DLLOPTION int EasiioDestroy();

	/* @function
	************************************************************************************
	函数名   : EasiioRefreshMic
	功能     : 刷新麦克风
	返回值   : 0      正常
	************************************************************************************/
	DLLOPTION int EasiioRefreshMic();

	/* @function
	************************************************************************************
	函数名   : EasiioSetLogDir
	功能     : 设置日志保存路径
	************************************************************************************/
	DLLOPTION void EasiioSetLogDir(const char* logDir);

	/* @function
	************************************************************************************
	函数名   : EasiioSetProxyUrl
	功能     : 设定代理地址
	************************************************************************************/
	DLLOPTION void EasiioSetProxyUrl(const char* proxuUrl);

	/* @function
	************************************************************************************
	函数名   : EasiioSetProxyInfo
	功能     : 设定代理参数
	************************************************************************************/
	DLLOPTION void EasiioSetProxyInfo(int type, const char* account, const char* password);


	/* @function
	************************************************************************************
	函数名   : EasiioNotifyVideoOrientation
	功能     : 屏幕切换通知
	参数     : [IN] callId : 通话ID
	                orientation : 屏幕  ORIENTATION_PORTRAIT = 0, // 竖屏
										ORIENTATION_LANDSCAPE = 1 // 横屏
	************************************************************************************/
	DLLOPTION int EasiioNotifyVideoOrientation(int callId, int orientation);

	/* @function
	************************************************************************************
	函数名   : EasiioVideoSetAllSettings
	功能     : 视频配置  
	参数     : [IN] camindex:摄像头索引 
	                width x height: 分辨率 qvga:320 x 240   vga:640 x 480
					                       720p:1280 x 720  1080p:1920 x 1080
                    frame_rate: 帧率       5 or 15 or 30
					bit_rate : 比特率      0
					p2pSupport : p2p开启:1  关闭:0 
	************************************************************************************/
	DLLOPTION void EasiioVideoSetAllSettings(int camIndex, int width, int height, int frame_rate, int bit_rate, int p2pSupport);

	DLLOPTION int EasiioStartSendKeyframe(int callid);
	DLLOPTION int EasiioStopSendVideo(int callid);
	DLLOPTION int EasiioStartSendVideo(int callid);

	/* @function
	************************************************************************************
	函数名   : EasiioRestartSip
	功能     : Sip复位
	************************************************************************************/
	DLLOPTION void EasiioRestartSip();

	/* @function
	************************************************************************************
	函数名   : EasiioGetCamera
	功能     : 获取摄像头名
	************************************************************************************/
	DLLOPTION void EasiioGetCamera(int index, char* name);

	DLLOPTION void EasiioEnableICE(int enable);

	/* @function
	************************************************************************************
	函数名   : EasiioGetLastAvePktLostRate
	功能     : 获取语音丢包率
	返回值   : 语音丢包率
	************************************************************************************/
	DLLOPTION double EasiioGetLastAvePktLostRate();


	/***********************************监控摄像头*************************************/
	/* @function
	************************************************************************************
	函数名   : EasiioGetDeviceCount
	功能     : 获取设备数
	************************************************************************************/
	DLLOPTION int EasiioGetDeviceCount(int *DevCount);

	/* @function
	************************************************************************************
	函数名   : EasiioGetDeviceInfoById
	功能     : 获取设备信息
	参数     : [OUT] deviceInfo : 监控摄像头信息(可从中获取rtsp流的url)
	************************************************************************************/
	DLLOPTION int EasiioGetDeviceInfoById(int index, char *deviceInfo);

	/* @function
	************************************************************************************
	函数名   : EasiioStartPreview
	功能     : 启动监控预览
	参数     : [IN] size : rtsp流的url数量
	                urlArray : url数组指针
	************************************************************************************/
	DLLOPTION void EasiioStartPreview(int size, char **urlArray);

	/* @function
	************************************************************************************
	函数名   : EasiioStopPreview
	功能     : 关闭监控预览
	************************************************************************************/
	DLLOPTION void EasiioStopPreview();

	/* @function
	************************************************************************************
	函数名   : EasiioPreviewStatus
	功能     : 监控预览状态
	参数     : [OUT] status : 开启1  关闭0
	************************************************************************************/
	DLLOPTION int EasiioPreviewStatus(int *status);



    /************************************视频会议**************************************/
	/* @function
	************************************************************************************
	函数名   : EasiioCreateMeeting
	功能     : 创建会议
	参数     : [IN] desc: meeting_key描述，如 My meeting
	                priority: meeting_key优先级 取值范围1-10 默认5，1最高，10最低
    返回值   : 是否成功 0：成功； 非0失败
	回调函数 : void(*onMeetingResult)(EasiioResponseReason reason,int count, MeetingInfo *info);  //获取会议信息
	************************************************************************************/
	DLLOPTION int EasiioCreateMeeting(const char* desc, int priority);

	/* @function
	************************************************************************************
	函数名   : EasiioGetMeetingList
	功能     : 获取会议列表
	返回值   : 是否成功 0：成功； 非0失败
	回调函数 : void(*onMeetingResult)(EasiioResponseReason reason,int count, MeetingInfo *info); //获取会议信息 
	************************************************************************************/
	DLLOPTION int EasiioGetMeetingList();

	/* @function
	************************************************************************************
	函数名   : EasiioUpdateMeeting
	功能     : 更新会议
	参数     : [IN] meeting_key: 会议号码
	                desc : 会议描述
					priority : 优先级
	返回值   : 是否成功 0：成功； 非0失败(详情请看枚举)
	************************************************************************************/
	DLLOPTION int EasiioUpdateMeeting(const char* meeting_key,const char* desc,int priority);

	/* @function
	************************************************************************************
	函数名   : EasiioDeleteMeeting
	功能     : 删除会议
	参数     : [IN] meeting_key: 会议号码
	返回值   : 是否成功 0：成功； 非0失败 (详情请看枚举)
	************************************************************************************/
	DLLOPTION int EasiioDeleteMeeting(const char* meeting_key);

	/* @function
	************************************************************************************
	函数名   : EasiioStartMeeting
	功能     : 开启会议
	参数     : [IN] meeting_key: 会议号码
	                reolution: 会议分辨率   reolution= "vga"  640x480  
											reolution= "720p" 1080x720 
											reolution= "1080p"  1920x1080
					platform: 开启会议平台  对应值：windows、mac、android、ios 
                [OUT] start_time: 会议开始时间
	返回值   : 是否成功 0：成功； 非0失败(详情请看枚举) 
	************************************************************************************/
	DLLOPTION int EasiioStartMeeting(const char* meeting_key,const char* resolution,const char* platform,char* start_time);

	/* @function
	************************************************************************************
	函数名   : EasiioStopMeeting
	功能     : 结束会议
	参数     : [IN] meeting_key: 会议号码
				    resolution: 结束会议后正常视频分辨率   resolution= "qvga" 320x240
					                                      resolution= "vga"  640x480
										                  resolution= "720p" 1080x720
										                  resolution= "1080p"  1920x1080
	                platform: 结束会议平台  对应值：windows、mac、android、ios
	返回值   : 是否成功 0：成功； 非0失败(详情请看枚举)
	************************************************************************************/
	DLLOPTION int EasiioStopMeeting(const char* meeting_key, const char* resolution, const char* platform);

	/* @function
	************************************************************************************
	函数名   : EasiioGetParticipants
	功能     : 获取参会人员
	参数     : [IN] meeting_key: 会议号码
	           [OUT] ParticipantInfo: 参会信息 			         
	返回值   : 是否成功 0：成功； 非0失败(详情请看枚举)
	************************************************************************************/
	DLLOPTION int EasiioGetParticipantInfo(const char* meeting_key, ParticipantInfo *participantinfo);

	/* @function
	************************************************************************************
	函数名   : EasiioGetMeetingStatus
	功能     : 会议状态
	参数     : [IN] meeting_key: 会议号码
	返回值   : 0:关闭   1:开启   非0、1失败(详情请看枚举)
	************************************************************************************/
	DLLOPTION int EasiioGetMeetingStatus(const char* meeting_key);

	/* @function
	************************************************************************************
	函数名   : EasiioJoinMeeting
	功能     : 加入会议
	参数     : [IN] meeting_key: 会议号码
	返回值   : 是否成功 0：成功； 非0失败(详情请看枚举)
	回调函数 : void(*onMakeCallResult)(int callId, const char* toNumber,const char* meetingkey);
	************************************************************************************/
	DLLOPTION int EasiioJoinMeeting(const char* meeting_key);

	/* @function
	************************************************************************************
	函数名   : EasiioSetVideoResolution
	功能     : 设置视频分辨率
    参数     : [IN] resolution: 退出会议后视频分辨率 resolution= "qvga" 320x240
					                                resolution= "vga"  640x480
										            resolution= "720p" 1080x720
										            resolution= "1080p"  1920x1080
	************************************************************************************/
	DLLOPTION void EasiioSetVideoResolution(const char* resolution);

	/* @function
	************************************************************************************
	函数名   : EasiioUpdateJoinMeetingInfo
	功能     : 更新参会时的信息
	参数     : [IN] meeting_key: 会议号码
	                operate: 会议操作    operate = "leave"  离开会议
					                     operate = "join"   加入会议
                    easiio_id: easiio号码    
	返回值   : 是否成功 0：成功； 非0失败
	************************************************************************************/
	DLLOPTION int EasiioUpdateJoinMeetingInfo(const char* meeting_key,const char* operate,const char* easiio_id);

	/* @function
	************************************************************************************
	函数名   : EasiioSendSwitchUpstreamRequest
	功能     : 参会人员退出会议时切换请求
	参数     : [IN] callId: 会议callid
	                type:   0: 通知下一层重新加会   1:通知下层的下层重新加会
	************************************************************************************/
	DLLOPTION void EasiioSendSwitchUpstreamRequest(int callId, int type);
#ifdef __cplusplus 
}
#endif
#endif