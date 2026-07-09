//
//  ExAdsHeader.h
//  NobodySDK
//
//  Created by NobodySDK on 2025/9/10.
//

#import <AdjustSdk/AdjustSdk.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@class ExAdsGameConfig;

// 广告聚合类型枚举
typedef NS_ENUM(NSInteger, ExAdsAggregationType) {
  ExAdsAggregationTypeIronSource = 0,  // Ir/onSource 聚合
  ExAdsAggregationTypeMAX        = 1,  // AppLovin MAX 聚合
};
NS_ASSUME_NONNULL_BEGIN

// 免广告类型
typedef NS_ENUM(NSInteger, ExAdsRemoveType) {
  ExAdsRemoveTypeReward = 0,   // 激励视频
  ExAdsRemoveTypeInsert = 1,   // 插屏广告
  ExAdsRemoveTypeBanner = 2,   // Banner 广告
  ExAdsRemoveTypeSplash = 3,   // 开屏广告
  ExAdsRemoveTypeAll = 4,      // 所有广告
  ExAdsRemoveTypeNative = 5,   // 原生广告
  ExAdsRemoveTypeUnknown = -1, // 未知
};

@interface ExAdsHeader : NSObject

@property(nonatomic, assign) BOOL isWebview;

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
// 初始化和加载广告
- (void)ExAdsATT;

// 去除splash ad
- (void)ExAdsRemoveAd;
// 获取去除广告状态，1:代表去除广告
- (NSString *)ExAdsGetRemoveAdStats;
// 展示RewardedVideo
- (void)ExAdsShowRewardedVideo;
// 展示Interstitial
- (void)ExAdsShowInterstitial;
// 展示Banner
- (void)ExAdsShowBanner;
// 关闭Banner
- (void)ExAdsCloseBanner;

// 显示广告测试面板
- (void)ExAdsShowTestAD;
// 系统分享 title:分享标题 url:分享链接
- (void)ExAdsSysShareWithTitle:(NSString *)title url:(NSString *)url;
// 系统的app评分
- (void)ExAdsSysScore;
// 震动 repeat是否重复
- (void)ExAdsSysVibrate:(BOOL)repeat;
// 取消震动
- (void)ExAdsSysCancelVibrate;
// 屏幕旋转相关
- (UIInterfaceOrientationMask)
    ExAdsDeviceSupportedInterfaceOrientationsForWindow:(UIWindow *)window;

- (void)ExAdsApplication:(UIApplication *)application
    didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;

- (void)ExAdsApplication:(UIApplication *)application
                 openURL:(NSURL *)url
                 options:(nonnull NSDictionary<UIApplicationOpenURLOptionsKey,
                                               id> *)options;
// adjust配置，handler回调
- (void)ExAdsAdjustCallBackHandler:(void (^)(BOOL isSuccess))handler;
// 获取AdjustCampaign
- (NSString *)ExAdsGetAdjustCampaign;
// 获取AdjustCreative
- (NSString *)ExAdsGetAdjustCreative;
// adjust事件
- (void)ExAdsAdjustEvent:(NSString *)eventString;

// 主动请求 Adjust 归因信息（内部8秒超时，失败则回调 isSuccess=NO）
- (void)ExAdsRequestAdjustInfo;
// Adjust 归因结果回调（isSuccess, network, campaign, adGroup, creative）
- (void)ExAdsOnAdjustCallBack:(void (^)(BOOL isSuccess, NSString *network,
                                        NSString *campaign, NSString *adGroup,
                                        NSString *creative))handler;

// 设置分析用户属性，`json` 可为 JSON 字符串或者字典
- (void)ExAdsTrackUserProperty:(id)json;

/**
 分析 SDK 自定义事件埋点（当前由 Solar Engine 承载，对外保留原接口名）

 @param key         事件名称
 @param jsonStr 事件属性，json字符串
 */
- (void)ExAdsThinkingTrackEventWithKey:(NSString *)key
                               jsonStr:(NSString *)jsonStr;
- (void)ExAdsThinkingSetSuperPropertiesJsonStr:(NSString *)jsonStr;
// 通用关卡埋点（对外保留原接口名）
- (void)ExAdsThinkingTrackLevelEnter:(NSInteger)level;
- (void)ExAdsThinkingTrackLevelStart:(NSInteger)level;
- (void)ExAdsThinkingTrackLevelWin:(NSInteger)level;
- (void)ExAdsThinkingTrackLevelFail:(NSInteger)level;
- (void)ExAdsThinkingTrackLevelRevive:(NSInteger)level;
- (void)ExAdsThinkingTrackLevelRetry:(NSInteger)level;
- (void)ExAdsThinkingTrackLevelProp:(NSInteger)level;

/// 开始事件计时；不触发上报，后续对同名事件调用
/// `ExAdsThinkingTrackEventWithKey` 时由 SDK 自动附加时长（秒）
- (void)ExAdsThinkingTimeEventWithKey:(NSString *)key;
/// 获取当前事件自计时开始起的已计时时长（秒）；
/// 未开始或已在上报后被清理则返回 0
- (NSTimeInterval)ExAdsThinkingGetDurationWithKey:(NSString *)key;
/// 结束时间事件并返回 duration（秒），同时清理内部状态；
/// 适用于关卡结束等需要获取最终时长并清理计时器的场景
- (NSTimeInterval)ExAdsThinkingEndTimeEventWithKey:(NSString *)key;

// firebase获取推送token
- (void)ExAdsRequestFCMToken;

- (void)ExAdsFirebaseApnsToken:(NSDate *)token;

/// 应用外消息推送注册（会向用户请求通知权限，未使用则无需调用）
/// @param application UIApplication 实例（通常在 AppDelegate 中传入）
- (void)ExAdsInitFirebaseMessageWithApplication:(UIApplication *)application;

/// 消息推送点击跳转回调设置（pushId 为消息中携带的 n_push_id
/// 值，可能为空字符串）
/// @param handler 回调块，参数为 pushId
- (void)ExAdsOnFirebaseMessageClick:(void (^)(NSString *pushId))handler;

// 获取远端 game 配置（返回当前缓存，可能为 nil）
- (nullable ExAdsGameConfig *)ExAdsGetRemoteGameConfig;

// 拉取远端配置，并通过回调返回是否成功以及解析后的 game 配置（可能为 nil）
- (void)ExAdsFetchRemoteGameConfigWithCompletion:
    (void (^)(BOOL success, ExAdsGameConfig *_Nullable gameConfig))completion;
// 开始内购 productId：商品ID
- (void)ExAdsLaunchInAppPurchase:(NSString *)productId;
// 恢复内购 productId：商品ID
- (void)ExAdsRestoreInAppPurchase:(NSString *)productId;
// 请求内购列表
- (void)ExAdsRequestProductLists;
// 获取uuid
- (NSString *)ExAdsGetUUID;
// banner方向，topDir--YES为顶部，NO为底部，需在调用ExAdsShowBanner之前调用
- (void)ExAdsBannerDirectionWithTop:(BOOL)topDir;

/**
 * 显示日志界面
 * @param parentViewController 父视图控制器
 */
+ (void)showLogViewControllerFromParent:
    (UIViewController *)parentViewController;

// ==================== 免广告接口（选接） ====================
/// 设置指定广告类型是否免广告；当 type 为 ExAdsRemoveTypeAll
/// 时，表示对所有广告生效
- (void)ExAdsSetRemoveAdWithType:(ExAdsRemoveType)type enable:(BOOL)enable;
/// 查询指定广告类型是否免广告；当已设置 All 为 YES 时，对所有类型均返回 YES
- (BOOL)ExAdsIsRemoveAdWithType:(ExAdsRemoveType)type;
/// 关闭免广告（清除全局和各分类型免广告状态，含旧版兼容键）
- (void)ExAdsCloseRemoveAd;

// ==================== 聚合类型查询 ====================
/// 获取当前生效的广告聚合类型
- (ExAdsAggregationType)ExAdsGetAggregationType;
/// 获取当前聚合类型字符串（"ironsource" | "max"）
- (NSString *)ExAdsGetAggregationTypeString;

// ==================== 原生广告（MAX 聚合新增） ====================
/// 展示原生广告到指定父视图（仅 MAX 聚合支持）
/// @param parentView 父视图
/// @param topOffset 顶部偏移（pt）
- (void)ExAdsShowNativeAdIn:(UIView *)parentView topOffset:(CGFloat)topOffset;
/// 移除原生广告
- (void)ExAdsCloseNativeAd;

@end

NS_ASSUME_NONNULL_END
