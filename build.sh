LD_LIBRARY_PATH=/usr/lib/jvm/java-7-oracle/jre/lib/amd64/server
JAVA_HOME=/usr/lib/jvm/java-7-oracle

javac HelloSwing.java
javac HelloSwing2.java
javac HelloCPP.java

g++ -I$JAVA_HOME/include -I$JAVA_HOME/include/linux -L$JAVA_HOME/jre/lib/amd64/server jvm.cpp -ljvm

