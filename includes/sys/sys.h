/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sys.h
 * Author: haranov
 *
 * Created on 15 janvier 2020, 06:41
 */

#ifndef SYS_KAREE_H
#define SYS_KAREE_H

#ifdef __cplusplus
extern "C" {
#endif
    
    #include "file.h"
    

    #if defined(_WIN32)
        #define PLATFORM_NAME "windows" // Windows
    #elif defined(_WIN64)
        #define PLATFORM_NAME "windows" // Windows
    #elif defined(__CYGWIN__) && !defined(_WIN32)
        #define PLATFORM_NAME "windows" // Windows (Cygwin POSIX under Microsoft Window)
    #elif defined(__ANDROID__)
        #define PLATFORM_NAME "android" // Android (implies Linux, so it must come first)
    #elif defined(__linux__)
        #define PLATFORM_NAME "linux" // Debian, Ubuntu, Gentoo, Fedora, openSUSE, RedHat, Centos and other
    #elif defined(__unix__) || !defined(__APPLE__) && defined(__MACH__)
        #include <sys/param.h>
        #if defined(BSD)
            #define PLATFORM_NAME "bsd" // FreeBSD, NetBSD, OpenBSD, DragonFly BSD
        #endif
    #elif defined(__hpux)
        #define PLATFORM_NAME "hp-ux" // HP-UX
    #elif defined(_AIX)
        #define PLATFORM_NAME "aix" // IBM AIX
    #elif defined(__APPLE__) && defined(__MACH__) // Apple OSX and iOS (Darwin)
        #include <TargetConditionals.h>
        #if TARGET_IPHONE_SIMULATOR == 1
            #define PLATFORM_NAME "ios" // Apple iOS
        #elif TARGET_OS_IPHONE == 1
            #define PLATFORM_NAME "ios" // Apple iOS
        #elif TARGET_OS_MAC == 1
            #define PLATFORM_NAME "osx" // Apple OSX
        #endif
    #elif defined(__sun) && defined(__SVR4)
        #define PLATFORM_NAME "solaris" // Oracle Solaris, Open Indiana
    #else
        #define PLATFORM_NAME NULL
    #endif

    
    const char *getPlatformName();

    int rm(char*);
    
    int makedir(char*);
    
    int mv(char*, char*);
    
    int isDirectory(const char *);
    
    int isRegularFile(const char *);
    
    const char *getPlatformName();
    
    void checkSupportedOs();

#ifdef __cplusplus
}
#endif

#endif /* SYS_KAREE_H */

