#include "AdsAPI.h"

#include "cocos2d.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "platform/android/jni/JniHelper.h"
#include <jni.h>
#endif

namespace dxco {

	void AdsAPI::showAd() {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
		cocos2d::JniMethodInfo t;

		if (cocos2d::JniHelper::getStaticMethodInfo(t, "com/dxco/DxcoCpp", "showInterstitial", "()V")) {
			t.env->CallStaticVoidMethod(t.classID, t.methodID);
		}
#endif
	}

} /* namespace dxco */
