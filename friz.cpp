/*
  ==============================================================================

   This file is part of the JUCE library.
   Copyright (c) 2017 - ROLI Ltd.

   JUCE is an open source library subject to commercial or open-source
   licensing.

   By using JUCE, you agree to the terms of both the JUCE 5 End-User License
   Agreement and JUCE 5 Privacy Policy (both updated and effective as of the
   27th April 2017).

   End User License Agreement: www.juce.com/juce-5-licence
   Privacy Policy: www.juce.com/juce-5-privacy-policy

   Or: You may also use this code under the terms of the GPL v3 (see
   www.gnu.org/licenses).

   JUCE IS PROVIDED "AS IS" WITHOUT ANY WARRANTY, AND ALL WARRANTIES, WHETHER
   EXPRESSED OR IMPLIED, INCLUDING MERCHANTABILITY AND FITNESS FOR PURPOSE, ARE
   DISCLAIMED.

  ==============================================================================
*/

#ifdef JUCE_GUI_BASICS_H_INCLUDED
 /* When you add this cpp file to your project, you mustn't include it in a file where you've
    already included any other headers - just put it inside a file on its own, possibly with your config
    flags preceding it, but don't include anything else. That also includes avoiding any automatic prefix
    header files that the compiler may be using.
 */
 #error "Incorrect use of JUCE cpp file"
#endif

#define JUCE_CORE_INCLUDE_OBJC_HELPERS 1
#define JUCE_CORE_INCLUDE_COM_SMART_PTR 1
#define JUCE_CORE_INCLUDE_JNI_HELPERS 1
#define JUCE_CORE_INCLUDE_NATIVE_HEADERS 1
#define JUCE_EVENTS_INCLUDE_WIN32_MESSAGE_WINDOW 1
#define JUCE_GRAPHICS_INCLUDE_COREGRAPHICS_HELPERS 1

#ifndef JUCE_PUSH_NOTIFICATIONS
 #define JUCE_PUSH_NOTIFICATIONS 0
#endif

#include "friz.h"

//==============================================================================
#if JUCE_MAC
 #import <WebKit/WebKit.h>
 #import <IOKit/IOKitLib.h>
 #import <IOKit/IOCFPlugIn.h>
 #import <IOKit/hid/IOHIDLib.h>
 #import <IOKit/hid/IOHIDKeys.h>
 #import <IOKit/pwr_mgt/IOPMLib.h>

 #if JUCE_PUSH_NOTIFICATIONS
  #import <Foundation/NSUserNotification.h>

  #include "native/juce_mac_PushNotifications.cpp"
 #endif

//==============================================================================
#elif JUCE_IOS
 #if JUCE_PUSH_NOTIFICATIONS
  #if defined (__IPHONE_10_0) && __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_10_0
   #import <UserNotifications/UserNotifications.h>
  #endif

  #include "native/juce_ios_PushNotifications.cpp"
 #endif

//==============================================================================
#elif JUCE_ANDROID
 #if JUCE_PUSH_NOTIFICATIONS
  #include "native/juce_android_PushNotifications.cpp"
 #endif

//==============================================================================
#elif JUCE_WINDOWS
 #include <windowsx.h>
 #include <vfw.h>
 #include <commdlg.h>

 #if JUCE_WEB_BROWSER
  #include <exdisp.h>
  #include <exdispid.h>
 #endif

//==============================================================================
#elif JUCE_LINUX
 #include <X11/Xlib.h>
 #include <X11/Xatom.h>
 #include <X11/Xutil.h>
 #undef SIZEOF
 #undef KeyPress

 #if JUCE_WEB_BROWSER
  #include <unistd.h>
  #include <fcntl.h>
  #include <sys/wait.h>

  #if JUCE_GCC
   #pragma GCC diagnostic push
   #pragma GCC diagnostic ignored "-Wzero-as-null-pointer-constant"
   #if __GNUC__ > 7
    #pragma GCC diagnostic ignored "-Wparentheses"
   #endif
  #endif

  #if JUCE_CLANG
   #if __has_warning("-Wzero-as-null-pointer-constant")
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wzero-as-null-pointer-constant"
   #endif
  #endif

  #include <gtk/gtk.h>

  #if JUCE_GCC
   #pragma GCC diagnostic pop
  #endif

  #if JUCE_CLANG
   #if __has_warning("-Wzero-as-null-pointer-constant")
    #pragma clang diagnostic pop
   #endif
  #endif

  #include <gtk/gtkx.h>
  #include <glib-unix.h>
  #include <webkit2/webkit2.h>
 #endif
#endif

//==============================================================================
#include "animator/friz_AnimatedValue.cpp"
#include "animator/friz_Animation.cpp"
#include "animator/friz_Animator.cpp"
#include "animator/friz_Constant.cpp"
#include "value/friz_Easing.cpp"
#include "value/friz_Linear.cpp"
#include "value/friz_Sequence.cpp"
#include "value/friz_Sinusoid.cpp"
#include "value/friz_Spring.cpp"

//==============================================================================

 #if JUCE_CLANG
  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wundeclared-selector"
 #endif

 #if JUCE_IOS
  #include "native/juce_ios_UIViewComponent.mm"
 #endif

 #if JUCE_CLANG
  #pragma clang diagnostic pop
 #endif
