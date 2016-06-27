//
//  ViewController.m
//  XWEasyKVOBlock
//
//  Created by wazrx on 16/6/27.
//  Copyright © 2016年 wazrx. All rights reserved.
//

#import "ViewController.h"
#import "NSObject+XWAdd.h"
#import "XWTestObject.h"

@interface ViewController ()
@property (nonatomic, strong) XWTestObject *objA;
@end

@implementation ViewController

- (void)viewDidLoad{
    [super viewDidLoad];
    _objA = [XWTestObject new];
    [_objA xw_addObserverBlockForKeyPath:@"name" block:^(id obj, id oldVal, id newVal) {
        NSLog(@"kvo，修改name为%@", newVal);
    }];
    [self xw_addNotificationForName:@"XWTestNotificaton" block:^(NSNotification *notification) {
        NSLog(@"收到通知1：%@", notification.userInfo);
    }];
    
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event{
    [[NSNotificationCenter defaultCenter] postNotificationName:@"XWTestNotificaton" object:nil userInfo:@{@"test" : @"1"}];
    static BOOL flag = NO;
    if (!flag) {
        _objA.name = @"wazrx";
        flag = YES;
    }else{
        _objA = nil;//objA 销毁的时候其绑定的KVO会自己移除
    }
}

@end
