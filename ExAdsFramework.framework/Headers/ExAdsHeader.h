//
//  ExAdsHeader.h
//  NobodySDK
//
//  Created by NobodySDK on 2025/9/10.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AdjustSdk/AdjustSdk.h>
NS_ASSUME_NONNULL_BEGIN

@interface ExAdsHeader : NSObject

@property(nonatomic,assign)BOOL isWebview;

+ (instancetype)shareHeader;
/**
 *  Log 输出开关 (默认开启)
 *  @param flag 是否开启 YES:显示；NO:不显示
 */
- (void)ExAdsNSLogEnable:(BOOL)flag;

/**
 *  获取所有收集的日志内容
 *  @return 格式化的日志字符串
 */
- (NSString *)getAllLogs;

/**
 *  清空所有收集的日志
 */
- (void)clearLogs;
//初始化和加载广告
- (void)ExAdsATT;

//去除splash ad
- (void)ExAdsRemoveAd;
//获取去除广告状态，1:代表去除广告
- (NSString *)ExAdsGetRemoveAdStats;
//展示RewardedVideo
- (void)ExAdsShowRewardedVideo;
//展示Interstitial
- (void)ExAdsShowInterstitial;
//展示Banner
- (void)ExAdsShowBanner;
//关闭Banner
- (void)ExAdsCloseBanner;

//显示广告测试面板
- (void)ExAdsShowTestAD;
//系统分享 title:分享标题 url:分享链接
- (void)ExAdsSysShareWithTitle:(NSString *)title url:(NSString *)url;
//系统的app评分
- (void)ExAdsSysScore;
//震动 repeat是否重复
- (void)ExAdsSysVibrate:(BOOL)repeat;
//取消震动
- (void)ExAdsSysCancelVibrate;
//屏幕旋转相关
- (UIInterfaceOrientationMask)ExAdsDeviceSupportedInterfaceOrientationsForWindow:(UIWindow *)window;

- (void)ExAdsApplication:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;

- (void)ExAdsApplication:(UIApplication *)application
            openURL:(NSURL *)url
                options:(nonnull NSDictionary<UIApplicationOpenURLOptionsKey, id> *)options;
//adjust配置，handler回调
- (void)ExAdsAdjustCallBackHandler:(void (^)(BOOL isSuccess))handler;
//获取AdjustCampaign
- (NSString *)ExAdsGetAdjustCampaign;
//获取AdjustCreative
- (NSString *)ExAdsGetAdjustCreative;
//adjust事件
- (void)ExAdsAdjustEvent:(NSString *)eventString;

//设置用户属性 json:json可为json字符串或者字典
- (void)ExAdsTrackUserProperty:(id)json;

/**
 自定义事件埋点

 @param key         事件名称
 @param jsonStr 事件属性，json字符串
 */
- (void)ExAdsThinkingTrackEventWithKey:(NSString *)key jsonStr:(NSString *)jsonStr;
- (void)ExAdsThinkingSetSuperPropertiesJsonStr:(NSString *)jsonStr;
//th游戏通用关卡埋点
- (void)ExAdsThinkingTrackLevelEnter:(NSInteger)level;
- (void)ExAdsThinkingTrackLevelStart:(NSInteger)level;
- (void)ExAdsThinkingTrackLevelWin:(NSInteger)level;
- (void)ExAdsThinkingTrackLevelFail:(NSInteger)level;
- (void)ExAdsThinkingTrackLevelRevive:(NSInteger)level;
- (void)ExAdsThinkingTrackLevelRetry:(NSInteger)level;
- (void)ExAdsThinkingTrackLevelProp:(NSInteger)level;

//firebase获取推送token
- (void)ExAdsRequestFCMToken;

- (void)ExAdsFirebaseApnsToken:(NSDate *)token;

//开始内购 productId：商品ID
- (void)ExAdsLaunchInAppPurchase:(NSString *)productId;
//恢复内购 productId：商品ID
- (void)ExAdsRestoreInAppPurchase:(NSString *)productId;
//请求内购列表
- (void)ExAdsRequestProductLists;
//获取uuid
- (NSString *)ExAdsGetUUID;
//banner方向，topDir--YES为顶部，NO为底部，需在调用ExAdsShowBanner之前调用
- (void)ExAdsBannerDirectionWithTop:(BOOL)topDir;

/**
 * 显示日志界面
 * @param parentViewController 父视图控制器
 */
+ (void)showLogViewControllerFromParent:(UIViewController *)parentViewController;

@end

NS_ASSUME_NONNULL_END
