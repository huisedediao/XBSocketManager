//
//  XBSocketManagerConfig.h
//  XBSocketManager
//
//  Created by xxb on 2017/5/31.
//  Copyright © 2017年 xxb. All rights reserved.
//

#ifndef XBSocketManagerConfig_h
#define XBSocketManagerConfig_h

#import <UIKit/UIKit.h>
#import "GCDAsyncSocket.h"


typedef enum : NSUInteger { // type对应socket返回的tag
    XBSocketResultType_connectSuccess = 10001,  //连接服务器成功
    XBSocketResultType_connectFailure = 10002,  //连接服务器失败
    XBSocketResultType_login = 10003,           //登陆
    XBSocketResultType_checkID = 10004,         //查询id是否可用
    XBSocketResultType_queryHostStatus = 10005, //查询主机状态
} XBSocketResultType;

typedef NS_ENUM(NSInteger, OCSM_Error)
{
    SM_Success           = 0,           //成功
    SM_WriteFail         = 1,           //写入数据失败，会导致关闭socket连接
    SM_NoData            = 2,           //无数据，可能原因：被后台掉、超时未返回
    //连接
    SM_NoNetwork         = 3,           //没有网络
    SM_ConnectFail       = 4,           //连接失败
    SM_LoginError        = 5,           //登录失败
    SM_GetIPerror        = 6,           //获取IP地址失败
    SM_commandMarkError  = 7,           //标记命令错误
    SM_ReadFail          = 8,           //读取失败
    SM_serverClose       = 9,           //服务器端关闭
    SM_ShakeHandsFail    =10,           //握手失败
    SM_GetDeviceTokenFail=11,             //获取设备令牌失败
    SM_ReturnError       =12            //返回失败
};


typedef void (^XBSocketErrorBlock)(void);
typedef void (^XBSocketSuccessBlock)(void);

#define kNotice_connectResult_success @"kNotice_connectResult_success"
#define kNotice_connectResult_failure @"kNotice_connectResult_failure"



#define kStatusKey @"kStatusKey"
#define kResultKey @"kResultKey"

 
#endif /* XBSocketManagerConfig_h */
