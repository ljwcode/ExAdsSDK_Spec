//
//  ExAdsCallBack.h
//  NobodySDK
//
//  Created by NobodySDK on 2025/9/10.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

//share
typedef void(^onShareCallBack) (BOOL isSuccess);

//in-appPurchase
typedef void(^onProductListCallBack) (NSArray *lists);
typedef void(^onInAppPurchaseCallBack) (BOOL isSuccess, NSString *errorMsg, NSString *productId,NSString *transactionID);
typedef void(^onBeginInAppPurchaseCallBack) (NSString *productId);
typedef void(^onRestoreInAppPurchaseCallBack) (BOOL isSuccess, NSString *errorMsg, NSString *productId);
typedef void(^onBeginRestoreInAppPurchaseCallBack) (NSString *productId);
typedef void(^onAcknowledgeInAppPurchaseCallBack) (NSString *productId,NSString *msg);
typedef void(^onFetchUnacknowledgedOrderCallBack)(NSString *productId,NSString *msg);

//firebase
typedef void(^onFCMTokenCallBack) (BOOL isSuccess, NSString *token, NSString *errorMsg);
/// Firebase 推送点击回调（pushId 为通知携带的 n_push_id 值，可能为空字符串）
typedef void(^onFirebaseMessageClick)(NSString *pushId);

//adjust
typedef void(^onAdjustCallBack) (BOOL isSuccess);
typedef void(^ExAdsAdjustAttributionCallback)(NSDictionary *payload);
// 新增：带详细归因信息的回调（isSuccess, network, campaign, adGroup, creative）
typedef void(^onAdjustCallBackWithInfo)(BOOL isSuccess, NSString *network, NSString *campaign, NSString *adGroup, NSString *creative);

//banner
typedef void(^onBannerShowFail) (NSString *msg, int actualAdType);
typedef void(^onBannerRemoved) (int actualAdType);
typedef void(^onBannerShow) (int actualAdType);

//Interstitial
typedef void(^onInterstitialShowFail) (NSString *msg, int actualAdType);
typedef void(^onInterstitialClose) (int actualAdType);
typedef void(^onInterstitialShow) (int actualAdType);

//RewardVideo
typedef void(^onRewardVideoShowFail) (NSString *msg, int actualAdType);
typedef void(^onRewardVideoFinish) (int actualAdType);
typedef void(^onRewardVideoClose) (int actualAdType);
typedef void(^onRewardVideoShow) (int actualAdType);
typedef void(^onRewardVideoHas) (BOOL has);

//splash
typedef void(^onSplashShowFail) (NSString *msg, int actualAdType);
typedef void(^onSplashFinish) (int actualAdType);
typedef void(^onSplashShow) (int actualAdType);

//facebook callback
typedef void(^onFbSuccess) (NSString *userId);
typedef void(^onFbHeadImage) (UIImage *image);
typedef void(^onFbError) (NSString *msg);
typedef void(^onFbCancel) (void);
@interface ExAdsCallBack : NSObject

+ (instancetype)shareCallBack;

//fackbook
@property (nonatomic,copy)onFbHeadImage __nullable onFbHeadImage;
@property (nonatomic,copy)onFbSuccess __nullable onFbSuccess;
@property (nonatomic,copy)onFbError __nullable onFbError;
@property (nonatomic,copy)onFbCancel __nullable onFbCancel;

//RewardVideo
@property (nonatomic,copy)onRewardVideoShowFail __nullable onRewardVideoShowFail;
@property (nonatomic,copy)onRewardVideoFinish __nullable onRewardVideoFinish;
@property (nonatomic,copy)onRewardVideoClose __nullable onRewardVideoClose;
@property (nonatomic,copy)onRewardVideoShow __nullable onRewardVideoShow;
@property (nonatomic,copy)onRewardVideoHas __nullable onRewardVideoHas;

//Interstitial
@property (nonatomic,copy)onInterstitialShowFail __nullable onInterstitialShowFail;
@property (nonatomic,copy)onInterstitialClose __nullable onInterstitialClose;
@property (nonatomic,copy)onInterstitialShow __nullable onInterstitialShow;


//Splash
@property (nonatomic,copy)onSplashShowFail __nullable onSplashShowFail;
@property (nonatomic,copy)onSplashFinish __nullable onSplashFinish;
@property (nonatomic,copy)onSplashShow __nullable onSplashShow;

//banner
@property (nonatomic,copy)onBannerShowFail __nullable onBannerShowFail;
@property (nonatomic,copy)onBannerRemoved __nullable onBannerRemoved;
@property (nonatomic,copy)onBannerShow __nullable onBannerShow;

//adjust
@property (nonatomic,copy)onAdjustCallBack __nullable onAdjustCallBack;
@property (nonatomic, copy) ExAdsAdjustAttributionCallback attributionCallback;
// 新增：带详细归因信息的回调属性
@property (nonatomic, copy) onAdjustCallBackWithInfo __nullable onAdjustCallBackWithInfo;

//firebase
@property (nonatomic,copy)onFCMTokenCallBack __nullable onFCMTokenCallBack;
@property (nonatomic,copy)onFirebaseMessageClick __nullable onFirebaseMessageClick;

//inAppPurchase
@property (nonatomic,copy)onProductListCallBack __nullable onProductListCallBack;
@property (nonatomic,copy)onInAppPurchaseCallBack __nullable onInAppPurchaseCallBack;
@property (nonatomic,copy)onBeginInAppPurchaseCallBack __nullable onBeginInAppPurchaseCallBack;
@property (nonatomic,copy)onRestoreInAppPurchaseCallBack __nullable onRestoreInAppPurchaseCallBack;
@property (nonatomic,copy)onBeginRestoreInAppPurchaseCallBack __nullable onBeginRestoreInAppPurchaseCallBack;

//share
@property (nonatomic,copy)onShareCallBack __nullable onShareCallBack;

@end

NS_ASSUME_NONNULL_END
