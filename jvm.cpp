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

  //jclass cls = env->FindClass("HelloCPP");
  //jmethodID mid = env->GetStaticMethodID(cls, "sayHello", "(I)V");
  jclass cls = env->FindClass("HelloSwing");
  std::cout << "jclass:" << cls << endl;
  jmethodID mid = env->GetStaticMethodID(cls, "main", "()V");  
  std::cout << "jmethodID" << mid << std::endl;

  int  val = 0;
  env->CallStaticVoidMethod(cls, mid, 100);


  jclass cls2 = env->FindClass("HelloSwing2");
  std::cout << "jclass2:" << cls2 << endl;
  jmethodID mid2 = env->GetStaticMethodID(cls2, "main", "()V");  
  std::cout << "jmethodID2" << mid2 << std::endl;
  env->CallStaticVoidMethod(cls2, mid2, 100);




    /* We are done. */
  cout << "Unesi 9 za izlazak" << std::endl;

  cin >> val;
  cout << "before destroyJVM" << endl;

  //jvm->DestroyJavaVM();

  cout << "kraj" << endl;
 
  return 0;
}
