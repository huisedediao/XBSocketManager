//
//  XBSocketManager.h
//  socketChat
//
//  Created by xxb on 2017/5/31.
//  Copyright © 2017年 XXB. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XBSocketManagerConfig.h"

@interface XBSocketManager : NSObject

+ (instancetype _Nullable )shared;




///连接服务器,返回值为nil说明超时了,timeOut传0则默认超时15秒
- (NSDictionary *_Nullable)connectToHost:(NSString *_Nullable)host onPort:(int)port withTimeout:(CGFloat)timeout;
///发送请求，返回值为nil说明超时了,timeOut传0则默认超时15秒
-(NSDictionary *_Nullable)sendMsg:(NSString *_Nullable)msg type:(XBSocketResultType)type timeOut:(CGFloat)timeout;
///发送请求，返回值为nil说明超时了,timeOut传0则默认超时15秒
-(NSDictionary *_Nullable)sendMsgData:(NSData *_Nullable)data type:(XBSocketResultType)type timeOut:(CGFloat)timeout;

@end
