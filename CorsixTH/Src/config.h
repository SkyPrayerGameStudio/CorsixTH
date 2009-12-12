/*
Copyright (c) 2009 Peter "Corsix" Cawley

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef CORSIX_TH_CONFIG_H_
#define CORSIX_TH_CONFIG_H_

/** Rendering engine choice **/
// SDL - Multiplatform, but suboptimal on some platforms
// DirectX 9 - Windows only, but always has HW accellerated (alpha) blitting
// OpenGL - Faster than SDL on supported platforms, but DX9 may still be
//          preferable on Windows (not yet finished, but should work).
#ifndef CORSIX_TH_RENDERING_ENGINE_DEFINED
#ifdef _WIN32
#define CORSIX_TH_USE_DX9_RENDERER
//#define CORSIX_TH_USE_OGL_RENDERER
//#define CORSIX_TH_USE_SDL_RENDERER
#else
//#define CORSIX_TH_USE_OGL_RENDERER
#define CORSIX_TH_USE_SDL_RENDERER
#endif
#endif //CORSIX_TH_RENDERING_ENGINE_DEFINED

/** Windows Platform SDK usage **/
// When compiling on Windows, the platform SDK should be used. However, when
// using the SDL rendering engine, the platform SDK is not used for anything
// critical, and so its use can be avoided if necessary.
#ifdef _WIN32
#define CORSIX_TH_USE_WIN32_SDK
#endif

/** SDL options **/
// On Windows, the default is to use the copy of SDLmain which is included with
// CorsixTH (SDL_main_win32.c), but a prebuilt SDLmain library can be used
// instead.
#ifdef CORSIX_TH_USE_WIN32_SDK
#define CORSIX_TH_USE_INCLUDED_SDL_MAIN
#endif

/** Audio options **/
// SDL_mixer is used for ingame audio. If this library is not present on your
// system, then you can comment out the next line and the game will not have
// any music.
#define CORSIX_TH_USE_SDL_MIXER

/** Environment detection **/
#if defined(__amd64__) || defined(__IA64__) || defined(__x86_64__) || \
    defined(_M_IA64) ||  defined(_IA64) || defined(_M_X64) || defined(_WIN64) \
    || defined(__x86_64) || defined(__ia64__) || defined(__amd64)
#define CORSIX_TH_64BIT
#endif

/** Standard includes **/
#include <stddef.h>
#ifdef _MSC_VER
// MSVC doesn't have stdint.h, so define the types we want
typedef signed __int8 int8_t;
typedef signed __int16 int16_t;
typedef signed __int32 int32_t;
typedef unsigned __int8 uint8_t;
typedef unsigned __int16 uint16_t;
typedef unsigned __int32 uint32_t;
#else
#include <stdint.h>
#endif // _MSC_VER

#endif // CORSIX_TH_CONFIG_H_
