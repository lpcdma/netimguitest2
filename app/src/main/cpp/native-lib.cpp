#include <jni.h>
#include <string>

#include <thread>

extern "C" void* dll_main(void*);

extern "C" JNIEXPORT jstring JNICALL
Java_com_tencent_tmgp_netimguitest2_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    pthread_t tid;
    pthread_create(&tid, NULL, dll_main, nullptr);
    return env->NewStringUTF(hello.c_str());
}