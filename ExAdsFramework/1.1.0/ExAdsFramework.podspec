Pod::Spec.new do |s|
  s.name             = 'ExAdsFramework'
  s.version          = '1.1.0'
  s.summary          = 'ExAdsSDK iOS SDK'
  s.description      = '内部聚合广告 + 数据上报一体化 SDK，仅支持真机 (iOS-arm64)。'
  s.homepage         = 'https://github.com/ljwcode/ExAdsSDK_Spec'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'nba137cbav75@gmail.com.com' => 'nba137cbav75@gmail.com' }

  # 通过 Git Tag 获取源码/二进制，不走 zip
  s.source           = { :git => 'https://github.com/ljwcode/ExAdsSDK_Spec.git',
                         :tag => s.version.to_s }

  s.ios.deployment_target = '15.0'
  s.swift_versions        = ['5.0', '5.9']

# ========= 交付二进制静态库 =========
# ⚠️ 删除 s.source_files，因为不再让集成方编译源码
# ⚠️ 只保留 vendored_frameworks + public_header_files
s.vendored_frameworks = 'ExAdsFramework.framework'

# 明确哪些头文件对外可见（位于 framework/Headers/ 下）
# ↓ 新增两行 ↓
s.source_files         = 'ExAdsFramework.framework/Headers/*.h'
s.public_header_files  = 'ExAdsFramework.framework/Headers/*.h'

# CocoaPods 自动把 framework 内部的 .bundle / .nib 等资源收进来，
# 不需要再额外写 resource_bundles，除非你有独立散落的资源文件
# 若之前写的 bundle 路径已无效，可直接删掉
# 拷贝 framework 根目录里所有 png
  # 仅真机构建；排除模拟器 arm64，避免 lint/集成报错
  # 仅一次性赋值即可
s.pod_target_xcconfig = {
  'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64',
  'OTHER_LDFLAGS'                        => '-ObjC'
}

s.user_target_xcconfig = {
  'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'
}

  # ========== 三方依赖（保持原版，删掉重复） ==========

s.dependency 'IronSourceSDK', '9.4.1.0'
s.dependency 'IronSourceAdQualitySDK', '9.5.1'

s.dependency 'IronSourceAppLovinAdapter', '5.6.0.0'
s.dependency 'IronSourceAdMobAdapter', '5.8.0.0'
s.dependency 'IronSourceVungleAdapter', '5.7.0.0'
s.dependency 'IronSourceMintegralAdapter', '5.13.0.0'
s.dependency 'IronSourcePangleAdapter', '5.22.0.0'
s.dependency 'IronSourceFyberAdapter', '5.8.0.0'
s.dependency 'IronSourceFacebookAdapter', '5.3.0.0'
s.dependency 'Google-Mobile-Ads-SDK', '13.3.0'
s.dependency 'IronSourceChartboostAdapter', '5.4.0.0'
s.dependency 'IronSourceInMobiAdapter', '5.5.0.0'
s.dependency 'IronSourceBigoAdapter', '5.6.0.0'
s.dependency 'IronSourceMolocoAdapter', '5.10.0.0'

s.dependency 'FBSDKCoreKit', '18.0.3'
s.dependency 'FBSDKLoginKit', '18.0.3'
s.dependency 'FBSDKShareKit', '18.0.3'

s.dependency 'FirebaseAnalytics', '12.13.0'
s.dependency 'FirebaseMessaging', '12.13.0'
s.dependency 'FirebaseCrashlytics', '12.13.0'
s.dependency 'FirebaseRemoteConfig', '12.13.0'
s.dependency 'GoogleUserMessagingPlatform', '3.1.0'
s.dependency 'Adjust/AdjustGoogleOdm', '5.6.2'
s.dependency 'GoogleAdsOnDeviceConversion', '3.5.0'

s.dependency 'Adjust', '5.6.2'

s.dependency 'SolarEngineSDKiOSInter', '1.3.1.2'
end
