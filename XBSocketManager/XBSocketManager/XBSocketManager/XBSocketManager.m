//
//  XBSocketManager.m
//  socketChat
//
//  Created by xxb on 2017/5/31.
//  Copyright © 2017年 XXB. All rights reserved.
//

#import "XBSocketManager.h"
#import "OCNetworkDefine.h"

#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>


@interface XBSocketManager () <GCDAsyncSocketDelegate>
{
    ///用于线程睡眠和唤醒
    pthread_cond_t cond;
    pthread_mutex_t mutex;
    
    
    //包含状态和获取到的结果
    /*
        status = OCSM_Error枚举
        result = 对象
     */
    NSDictionary *tempDic;
}
@property (nonatomic,strong) GCDAsyncSocket *socket;

@end

@implementation XBSocketManager


#pragma mark - 单例
+ (instancetype)shared
{
    return [XBSocketManager new];
}

-(instancetype)init
{
    if (self = [super init])
    {
        static dispatch_once_t onceToken;
        dispatch_once(&onceToken, ^{
            pthread_mutex_init(&mutex, NULL);
            pthread_cond_init(&cond, NULL);
        });
    }
    return self;
}

+ (instancetype)allocWithZone:(struct _NSZone *)zone
{
    static XBSocketManager *manager = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        manager = [super allocWithZone:zone];
    });
    return manager;
}



#pragma mark - 延迟
///发送消息
-(NSDictionary *)sendMsg:(NSString *)msg type:(XBSocketResultType)type timeOut:(CGFloat)timeout
{
    NSLog(@"sendStart");
    if (timeout <= 0)
    {
        timeout = 15;
    }
    
    tempDic = nil;
    
    NSData *data=[msg dataUsingEncoding:NSUTF8StringEncoding];
    //输出流写数据,传给服务器
    [self.socket writeData:data withTimeout:-1 tag:type];
    [self.socket readDataWithTimeout:-1 tag:type];
    
    
    struct timespec outtime;
    
    pthread_mutex_lock(&mutex);
    
    outtime.tv_sec =[NSDate date].timeIntervalSince1970 + timeout;
    outtime.tv_nsec =0;
    pthread_cond_timedwait(&cond, &mutex, &outtime);
    pthread_mutex_unlock(&mutex);
    
    
    NSLog(@"sendEnd");
    
    return tempDic;
}


-(NSDictionary *_Nullable)sendMsgData:(NSData *_Nullable)data type:(XBSocketResultType)type timeOut:(CGFloat)timeout
{
    NSLog(@"sendStart");
    if (timeout <= 0)
    {
        timeout = 15;
    }
    
    tempDic = nil;
    
    //NSData *data=[msg dataUsingEncoding:NSUTF8StringEncoding];
    //输出流写数据,传给服务器
    [self.socket writeData:data withTimeout:-1 tag:type];
    [self.socket readDataWithTimeout:-1 tag:type];
    
    
    struct timespec outtime;
    
    pthread_mutex_lock(&mutex);
    
    outtime.tv_sec =[NSDate date].timeIntervalSince1970 + timeout;
    outtime.tv_nsec =0;
    pthread_cond_timedwait(&cond, &mutex, &outtime);
    pthread_mutex_unlock(&mutex);
    
    
    NSLog(@"sendEnd");
    
    return tempDic;
}


///连接到服务器
- (NSDictionary *)connectToHost:(NSString *)host onPort:(int)port withTimeout:(CGFloat)timeout
{
    NSLog(@"sendStart");
    if (timeout <= 0)
    {
        timeout = 15;
    }
    
    tempDic = nil;

    [self.socket connectToHost:host onPort:port withTimeout:-1 error:nil];

    
    struct timespec outtime;
    
    pthread_mutex_lock(&mutex);
    
    outtime.tv_sec =[NSDate date].timeIntervalSince1970 + timeout;
    outtime.tv_nsec =0;
    pthread_cond_timedwait(&cond, &mutex, &outtime);
    pthread_mutex_unlock(&mutex);
    
    
    NSLog(@"sendEnd");
    
    return tempDic;
}




#pragma mark - socket代理方法

-(void)socket:(GCDAsyncSocket *)sock didConnectToHost:(NSString *)host port:(uint16_t)port
{
    NSLog(@"XBSocketManager连接服务器成功");
    //把端口和地址传过去
    [self handleReceiveDataWithType:XBSocketResultType_connectSuccess data:[NSString stringWithFormat:@"%@-%zd",host,port]];
}


// 断开连接(可能是出错,可能是正常断开连接)
-(void)socketDidDisconnect:(GCDAsyncSocket *)sock withError:(NSError *)err
{
    [self handleReceiveDataWithType:XBSocketResultType_connectFailure data:err];
    
    if(err)
    {
        NSLog(@"XBSocketManager连接出错,错误原因:");
        NSLog(@"XBSocketManager%@",err);
    }
    else
    {
        NSLog(@"XBSocketManager正常断开连接");
    }
}

-(void)socket:(GCDAsyncSocket *)sock didReadData:(NSData *)data withTag:(long)tag
{
    NSString *receiveStr=[[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
    NSLog(@"\r接收到的数据为：%@tag为：%zd\r",receiveStr,tag);
    
    //处理数据
    [self handleReceiveDataWithType:tag data:data];
}



#pragma mark - 处理数据
- (void)handleReceiveDataWithType:(XBSocketResultType)type data:(id)data
{
    //NSString *receiveStr=[[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
    
    OCSM_Error status;
    id result = nil;
    
    switch (type)
    {
        case XBSocketResultType_connectSuccess:
        {
            status = SM_Success;
        }
            break;
        case XBSocketResultType_connectFailure:
        {
            status = SM_ConnectFail;
        }
            break;
        case XBSocketResultType_login://登陆结果
        {
            /*
             00 成功
             01用户名不存在
             99未知错误
             */
            NSString *logintResult = [self handleResultWith:data result:&result];
            if ([logintResult isEqualToString:@"00"])
            {
                status = SM_Success;
            }
            else
            {
                status = SM_LoginError;
            }
        }
        case XBSocketResultType_checkID:
        {
            /*
             10可用
             11已占用
             12预留"
             */
            NSString *logintResult = [self handleResultWith:data result:&result];
            if ([logintResult isEqualToString:@"10"])
            {
                status = SM_Success;
            }
            else
            {
                status = SM_LoginError;
            }
        }
            break;
        case XBSocketResultType_queryHostStatus:
        {

        }
            break;
            
            
        default:
            break;
    }
    
    NSMutableDictionary *dicM = [NSMutableDictionary new];
    dicM[kStatusKey] = @(status);
    dicM[kResultKey] = result;
    
    tempDic = dicM;
    
    //唤醒线程
    pthread_cond_signal(&cond);
}

-(NSString *)handleResultWith:(NSData *)data result:(id *)result
{
    NSString *loginResult = [[[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding] substringWithRange:NSMakeRange(11, 2)];

    NSMutableDictionary *dicM = [NSMutableDictionary new];
    dicM[S_Key_Success_Failure] = loginResult;
    *result = dicM;
    
    return loginResult;
}


#pragma mark - 懒加载
-(GCDAsyncSocket *)socket
{
    if (!_socket) {
        _socket=[[GCDAsyncSocket alloc] initWithDelegate:self delegateQueue:dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0)];
    }
    return _socket;
}

@end
