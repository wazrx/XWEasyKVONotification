//
//  NSObject+XWAdd.h
//  XWEasyKVOBlock
//
//  Created by wazrx on 16/6/27.
//  Copyright © 2016年 wazrx. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (XWAdd)

#pragma mark - KVO

/**
 *  通过Block方式注册一个KVO，通过该方式注册的KVO无需手动移除，其会在被监听对象销毁的时候自动移除,所以下面的两个移除方法一般无需使用
 *
 *  @param keyPath 监听路径
 *  @param block   KVO回调block，obj为监听对象，oldVal为旧值，newVal为新值
 */
- (void)xw_addObserverBlockForKeyPath:(NSString*)keyPath block:(void (^)(id obj, id oldVal, id newVal))block;

/**
 *  提前移除指定KeyPath下的BlockKVO(一般无需使用，如果需要提前注销KVO才需要)
 *
 *  @param keyPath 移除路径
 */
- (void)xw_removeObserverBlockForKeyPath:(NSString *)keyPath;

/**
 *  提前移除所有的KVOBlock(一般无需使用)
 */
- (void)xw_removeAllObserverBlocks;

#pragma mark - Notification

/**
 *  通过block方式注册通知，通过该方式注册的通知无需手动移除，同样会自动移除
 *
 *  @param name  通知名
 *  @param block 通知的回调Block，notification为回调的通知对象
 */
- (void)xw_addNotificationForName:(NSString *)name block:(void (^)(NSNotification *notification))block;

/**
 *  提前移除某一个name的通知
 *
 *  @param name 需要移除的通知名
 */
- (void)xw_removeNotificationForName:(NSString *)name;

/**
 *  提前移除所有通知
 */
- (void)xw_removeAllNotification;

/**
 *  发送一个通知
 *
 *  @param name     通知名
 *  @param userInfo 数据字典
 */
- (void)xw_postNotificationWithName:(NSString *)name userInfo:(nullable NSDictionary *)userInfo;

@end

NS_ASSUME_NONNULL_END