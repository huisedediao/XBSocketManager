
/*******************************************************************
 
 File name: OCDefinition
 
 Description:
 1、处理所有的宏定义等
 
 Author: Mako
 
 History: 2013.5.22。
 
 *******************************************************************/
#ifndef OCNetworkDefine_h
#define OCNetworkDefine_h

//自定义测试
//#define OCDebug

#ifdef OCDebug

#define OCDebugLog(...) NSLog((@"函数:%s 行数:%d 对象:%@"), __PRETTY_FUNCTION__, __LINE__, [NSString stringWithFormat:__VA_ARGS__])
#define OCDebugBreak(...) {OCDebugLog(__VA_ARGS__); assert(0);}
#define OCDebugLogObjects(...) {NSLog(@"函数:%s 行数:%i",__PRETTY_FUNCTION__, __LINE__); OCLogObjects(__VA_ARGS__);}

#define OCDebugLogVariables(...) {NSLog(@"函数:%s 行数:%i",__PRETTY_FUNCTION__, __LINE__); OCLogVariables(__VA_ARGS__);}

#define OCMyLog(x) OCDebugLog(@#x)

#else

#define OCDebugLog(...)
#define OCDebugBreak(...)
#define OCDebugLogObjects(...)
#define OCDebugLogVariables(...)

#define OCMyLog(x) OCDebugLog(@#x)

#endif

#define OCLocalizedString(x) NSLocalizedString(x, nil)

#define OCImageNamed(x) [UIImage imageNamed:x]

#define IOS7  ([[UIDevice currentDevice].systemVersion doubleValue]>=7.0f)? YES : NO
#define IOS8  ([[UIDevice currentDevice].systemVersion doubleValue]>=8.0f)? YES : NO
#define iPhone5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)

#define TARGETS  (TESTTARGET2==0)? YES : NO

#pragma mark CS开头为C风格的字符串
#define CS_SendHead (TARGETS)? "$0700" : "$0600"
#define CS_IOS      "001IOS"
#define CS_RecvHead "CS"
#define CS_Delimiter "#"
#define CS_PackageEnd "&\r\n"

#pragma mark DS开头为D风格的字符串
#define DS_SendHead (TARGETS)? "@0700" : "@0600"
#define DS_SendHead_ZiJi  (TARGETS)? "@07" : "@06"
#define DS_RecvHead "CGW020SC"
#define DS_PackageEnd "\r\n"

//配件报警序号
#define S_Key_Acc_Alarm_Number @"S_Key_Acc_alarm_number"

//配件报警防区
#define S_Key_Defense_area @"S_Key_Defense_area"

//配件报警类型
#define S_Key_alarm_type @"S_Key_alarm_type"

//配件报警时间
#define S_Key_Alarm_Time @"S_Key_Alarm_Time"



//设备IP
#define S_Key_Device_IP @"Key_Device_IP"

//设备信息
#define S_Key_Device_Info @"Key_Device_Info"

//当前手机时间
#define S_Key_Iphone_Time @"S_Key_Iphone_Time"
//设备令牌
#define S_Key_PushToKen @"S_Key_PushToKen"
//邮箱
#define S_Key_Mailbox @"S_Key_Mailbox"

//设备IP地址
#define S_Key_Device_Ip @"S_Key_Device_Ip"

//设备是否在线
#define S_Key_On_Line  @"S_Key_On_Line"

//结果
#define S_Key_Result_Succeses  @"S_Key_Result_Succeses"

//转发的数据(或者转发回复的数据)
#define S_Key_TransmitData @"S_Key_TransmitData"

//定时功能状态
#define S_Key_TD_FunctionState @"S_Key_TD_FunctionState"




//定时器时间(第二组)
#define S_Key_TD_RingTime_Two @"S_Key_TD_RingTime_Two"

//报警器动作
#define S_Key_Alarm_Action_Two @"S_Key_Alarm_Action_Two"


//功能状态
#define S_Key_Function @"S_Key_Function"

//音量类型
#define S_Key_Volume @"S_Key_Volume"

//是否响铃
#define S_Key_Bell @"S_Key_Bell"

//响铃时间
#define S_Key_BellZ_Time @"S_Key_BellZ_Time"

//出入延时时间
#define S_Key_Out_Delay @"S_Key_Out_Delay"

//进入延时时间
#define S_Key_Enter_Delay @"S_Key_Enter_Delay"



//失败类型
#define S_Key_Failure_Type @"S_Key_Failure_Type"

//配件
#define S_Key_Fitting @"S_Key_Fitting"

//配件序号
#define S_Key_Fitting_No @"S_Key_Fitting_No"

//配件类型
#define S_Key_Fitting_Type @"S_Key_Fitting_Type"

//系统模式
#define S_Key_System_Mode @"S_Key_System_Mode"

//报警解除的状态
#define S_Key_Relieve_Alarm_Status @"S_Key_Relieve_Alarm_Status"

//配件报警序号
#define S_Key_Accessories_Alarm_Number @"S_Key_Accessories_Alarm_Number"

//配件报警防区
#define S_Key_Accessories_Alarm_Zone @"S_Key_Accessories_Alarm_Zone"

//配件报警类型
#define S_Key_Accessories_Alarm_Type @"S_Key_Accessories_Alarm_Type"

//密码
#define S_Key_Pass_Word @"S_Key_Pass_Word"

//邮箱地址
#define S_Key_Verify_Mail @"S_Key_Verify_Mail"

//语言类型
#define S_Key_Language_Type @"S_Key_Language_Type"

//用户ID
#define S_Key_User_ID @"S_Key_User_ID"

//用户名
#define S_Key_User_Name @"S_Key_User_Name"

//lastName
#define S_Key_Last_Name @"S_Key_Last_Name"

//验证码
#define S_Key_Captcha @"S_Key_Captcha"

//设备令牌
#define S_Key_Equipment_Token @"S_Key_Equipment_Token"

//MAC地址
#define S_Key_Mac_Address @"S_Key_Mac_Address"





#pragma mark  新的E5

//子机有无定时功能
#define S_Key_is_subTime @"S_Key_is_subTime"

//
#define S_Key_Error @"S_Key_Error"

//用户ID
#define S_Key_User_ID @"S_Key_User_ID"

//成功或失败
#define S_Key_Success_Failure @"S_Key_Success_Failure"

//appID
#define S_Key_App_ID @"S_Key_App_ID"

//设备ID
#define S_Key_Device_ID @"Key_Device_ID"

//开关打开或关闭
#define S_Key_On_Off  @"S_Key_On_Off"

//现在是周几
#define S_Key_current_Week  @"S_Key_current_Week"

#define S_Key_currentOnOff  @"S_Key_currentOnOff"

//时间组ID
#define S_Key_Groud_ID @"S_Key_Groud_ID"

//定时器时间
#define S_Key_TD_RingTime @"S_Key_TD_RingTime"

//定时动作
#define S_Key_Alarm_Action @"S_Key_Alarm_Action"

//定时组数
#define S_Key_Time_Group @"S_Key_Time_Group"

//子机在线状态
#define S_Key_Online_Status @"S_Key_Online_Status"

//子机序号
#define S_Key_Sub_No @"S_Key_Sub_No"

//设备名字

#define S_Key_Device_Name @"S_Key_Device_Name"

//设备图片

#define S_Key_Device_Img @"S_Key_Device_Img"

//子机列表数据

#define S_Key_Sub_Data   @"S_Key_Sub_Data"

//路由器的SSID

#define S_Key_SSID      @"S_Key_SSID"

//路由器的密钥

#define S_Key_PassWord   @"S_Key_PassWord"

//认证模式

#define S_Key_AUTH   @"S_Key_AUTH"

//加密算法
#define S_Key_ENCRY   @"S_Key_ENCRY"

//页数
#define S_Key_Page   @"S_Key_Page"

//定时序号
#define S_Key_Nmuber   @"S_Key_Nmuber"

//子机开启
#define S_Key_Sub_On   @"S_Key_Time_On"

//子机关闭
#define S_Key_Sub_Off   @"S_Key_Sub_Off"

//周期
#define S_Key_Cycle @"S_Key_Cycle"

//子机开启时间
#define S_Key_On_Sub_Time @"S_Key_On_Sub_Time"

//子机关闭时间
#define S_Key_Off_Sub_Time @"S_Key_Off_Sub_Time"

//子机定时组数
#define S_Key_Sub_Time_Group @"S_Key_Sub_Time_Group"

#endif
