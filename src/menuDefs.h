/* -*- C++ -*- */
#pragma once

// #include <Arduino.h>
// #define MENU_ASYNC
// #define MENU_FMT_WRAPS
// #define USE_PGM
// #define USE_RAM
// #define MENU_DEBUG

#include "macros.h"
#include "menuBase.h"
#include "shadows.h"

using namespace Menu;

#ifdef MENU_DEBUG
  String& operator<<(String&s,prompt &p);
  Stream& operator<<(Stream&o,prompt& p);
  Print& operator<<(Print&o,prompt& p);
#endif

#if defined(MENU_DEBUG) || defined(MENU_ASYNC)
  #ifndef ios_h
    #ifndef ARDUINO_STREAMING
      //https://github.com/neu-rah/streamFlow
      #include <streamFlow.h>
    #else
      //https://github.com/scottdky/Streaming
      #include <Streaming.h>
    #endif
  #endif
#endif


#if defined(MENU_DEBUG) && defined(TRACE)
  #define trace(x) x
#else
  #define trace(x)
#endif
#ifdef MENU_DEBUG
  #define _trace(x) x
#else
  #define _trace(x)
#endif
#ifndef MENU_RELEASE
  #define __trace(x) x
#else
  #define __trace(x)
#endif

namespace Menu {
  extern const char* numericChars;
  result maxDepthError(menuOut& o,idleEvent e);
}

#include "items.h"
#include "menuIo.h"
#include "nav.h"
