#include "FacebookAPI.h"
#include "cocos2d.h"

#if (CC_TARGET_PLATFORM != CC_PLATFORM_ANDROID)

namespace dxco {

// Desktop builds ship without the Facebook SDK: report no session so that
// UserDAO skips every Facebook code path.
bool FacebookAPI::hasFacebookSession() { return false; }

std::string FacebookAPI::getAccessToken() { return ""; }
std::string FacebookAPI::getUserID() { return ""; }
std::string FacebookAPI::getUsername() { return ""; }
std::string FacebookAPI::getFirstName() { return ""; }
std::string FacebookAPI::getLastName() { return ""; }
void FacebookAPI::invite() { }
void FacebookAPI::rate() { }

} /* namespace dxco */

#else

#include "platform/android/jni/JniHelper.h"
#include <jni.h>

namespace dxco {

extern "C" {

std::string FacebookAPI::getAccessToken() {

	std::string resultado = "";

	cocos2d::JniMethodInfo t;

	if (cocos2d::JniHelper::getStaticMethodInfo(t,
			"com/dxco/facebook/FacebookAPI", "getAccessToken",
			"()Ljava/lang/String;")) {

		jstring ret = (jstring) t.env->CallObjectMethod(t.classID, t.methodID);
		t.env->DeleteLocalRef(t.classID);
		jboolean is_copy = 0;
		const char* str = t.env->GetStringUTFChars(ret, &is_copy);

		if (str) {
			resultado = str;
		}

		if (is_copy) {
			t.env->ReleaseStringUTFChars(ret, str);
		}

		t.env->DeleteLocalRef(ret);

	}

	return resultado;
}

std::string FacebookAPI::getUserID() {
	std::string resultado = "";

	cocos2d::JniMethodInfo t;

	if (cocos2d::JniHelper::getStaticMethodInfo(t,
			"com/dxco/facebook/FacebookAPI", "getUserID",
			"()Ljava/lang/String;")) {

		jstring ret = (jstring) t.env->CallObjectMethod(t.classID, t.methodID);
		t.env->DeleteLocalRef(t.classID);
		jboolean is_copy = 0;
		const char* str = t.env->GetStringUTFChars(ret, &is_copy);

		if (str) {
			resultado = str;
		}

		if (is_copy) {
			t.env->ReleaseStringUTFChars(ret, str);
		}

		t.env->DeleteLocalRef(ret);

	}

	return resultado;
}

std::string FacebookAPI::getUsername() {
	std::string resultado = "";

	cocos2d::JniMethodInfo t;

	if (cocos2d::JniHelper::getStaticMethodInfo(t,
			"com/dxco/facebook/FacebookAPI", "getUsername",
			"()Ljava/lang/String;")) {

		jstring ret = (jstring) t.env->CallObjectMethod(t.classID, t.methodID);
		t.env->DeleteLocalRef(t.classID);
		jboolean is_copy = 0;
		const char* str = t.env->GetStringUTFChars(ret, &is_copy);

		if (str) {
			resultado = str;
		}

		if (is_copy) {
			t.env->ReleaseStringUTFChars(ret, str);
		}

		t.env->DeleteLocalRef(ret);

	}

	return resultado;
}

std::string FacebookAPI::getLastName() {
	std::string resultado = "";

	cocos2d::JniMethodInfo t;

	if (cocos2d::JniHelper::getStaticMethodInfo(t,
			"com/dxco/facebook/FacebookAPI", "getLastName",
			"()Ljava/lang/String;")) {

		jstring ret = (jstring) t.env->CallObjectMethod(t.classID, t.methodID);
		t.env->DeleteLocalRef(t.classID);
		jboolean is_copy = 0;
		const char* str = t.env->GetStringUTFChars(ret, &is_copy);

		if (str) {
			resultado = str;
		}

		if (is_copy) {
			t.env->ReleaseStringUTFChars(ret, str);
		}

		t.env->DeleteLocalRef(ret);

	}

	return resultado;
}

std::string FacebookAPI::getFirstName() {
	std::string resultado = "";

	cocos2d::JniMethodInfo t;

	if (cocos2d::JniHelper::getStaticMethodInfo(t,
			"com/dxco/facebook/FacebookAPI", "getFirstName",
			"()Ljava/lang/String;")) {

		jstring ret = (jstring) t.env->CallObjectMethod(t.classID, t.methodID);
		t.env->DeleteLocalRef(t.classID);
		jboolean is_copy = 0;
		const char* str = t.env->GetStringUTFChars(ret, &is_copy);

		if (str) {
			resultado = str;
		}

		if (is_copy) {
			t.env->ReleaseStringUTFChars(ret, str);
		}

		t.env->DeleteLocalRef(ret);

	}

	return resultado;
}


void FacebookAPI::rate() {
	cocos2d::JniMethodInfo t;

	if (cocos2d::JniHelper::getStaticMethodInfo(t, "com/dxco/SocialUtil",
			"startRateAppIntentFromMenu", "()I")) {

		t.env->CallStaticIntMethod(t.classID, t.methodID);
	}
}


void FacebookAPI::invite() {
	cocos2d::JniMethodInfo t;

	if (cocos2d::JniHelper::getStaticMethodInfo(t, "com/dxco/facebook/FacebookAPI", "invite",
			"()I")) {
		t.env->CallStaticIntMethod(t.classID, t.methodID);
	}
}

bool FacebookAPI::hasFacebookSession() {
	bool result = false;

	cocos2d::JniMethodInfo t;

	if (cocos2d::JniHelper::getStaticMethodInfo(t,
				"com/dxco/facebook/FacebookAPI", "hasSession",
				"()I")) {

		int ret = (int) t.env->CallStaticIntMethod(t.classID, t.methodID);

		if (ret) {
			result = true;
		}
	}

	return result;
}

}
} /* namespace dxco */

#endif
