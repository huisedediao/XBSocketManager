//
//  ViewController.m
//  XBSocketManager
//
//  Created by xxb on 2017/5/31.
//  Copyright © 2017年 xxb. All rights reserved.
//

#import "ViewController.h"
#import "XBSocketManager.h"

#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>



@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    

}





#pragma mark - 点击事件

- (IBAction)login:(UIButton *)sender {
    /*
    NSString *msg =@"$060000010CP06021126062001IOS50&\r\n";//登陆
    NSDictionary *dic = [[XBSocketManager shared] sendMsg:msg type:XBSocketResultType_login timeOut:0];
     
    NSString *msg = @"$060000010CP06021126062001IOS50&\r\n";//查询id是否可用
    NSDictionary *dic = [[XBSocketManager shared] sendMsg:msg type:XBSocketResultType_checkID timeOut:0];
    */
    
    NSLog(@"%zd",@"@0500200244335944P0602112606202240018".length);
    NSLog(@"%zd",@"#1#0#0#0000000#0000#0#0*".length);
    
    NSString *msg = @"@0600P06021126062200244335944022400002A&\r\n";//查询主机状态
    NSDictionary *dic = [[XBSocketManager shared] sendMsg:msg type:XBSocketResultType_queryHostStatus timeOut:0];
}




-(void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event
{
    //[[XBSocketManager shared] connectToHost:@"www.4g-alarm.com" onPort:40000 withTimeout:10 error:nil];
    NSDictionary *dic = [[XBSocketManager shared] connectToHost:@"www.4g-alarm.com" onPort:40000 withTimeout:15];
}



@end
