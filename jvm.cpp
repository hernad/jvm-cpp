#include <jni.h>
#include <iostream>

using namespace std;

int main( int args, char** argv ) {
  JavaVM* jvm;
  JNIEnv* env;
  JavaVMInitArgs vmArgs;
  JavaVMOption options[1]; int n = 0;
  options[n++].optionString = "-Djava.class.path=.";

  vmArgs.version = JNI_VERSION_1_6;
  vmArgs.nOptions = n;
  vmArgs.options = options;
  vmArgs.ignoreUnrecognized = false;

  JNI_CreateJavaVM(&jvm, (void**)&env, &vmArgs);


  jclass cls = env->FindClass("HelloCPP");
  jmethodID mid = env->GetStaticMethodID(cls, "sayHello", "(I)V");
  std::cout << cls ;
  std::cout << "," << mid;

  int  val = 0;

 env->CallStaticVoidMethod(cls, mid, 100);
    /* We are done. */
  cin >> val;
  jvm->DestroyJavaVM();

  // here we can use the jvm
  //
  //    jvm->DestroyJavaVM();
  //
  //       return 0;
  //       }
}
