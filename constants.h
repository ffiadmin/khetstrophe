// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Game Engine constants.h v2.9
// Last modification: Apr-14-2013

#pragma once
#ifndef _CONSTANTS_H            // Prevent multiple definitions if this 
#define _CONSTANTS_H            // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include <windows.h>

//=============================================================================
// Function templates for safely dealing with pointer referenced items.
// The functions defined by these templates may be called using a normal
// function call syntax. The compiler will create a function that replaces T
// with the type of the calling parameter.
//=============================================================================
// Safely release pointer referenced item
template <typename T>
inline void safeRelease(T& ptr)
{
    if (ptr)
    { 
        ptr->Release(); 
        ptr = NULL;
    }
}
#define SAFE_RELEASE safeRelease            // for backward compatiblility

// Safely delete pointer referenced item
template <typename T>
inline void safeDelete(T& ptr)
{
    if (ptr)
    { 
        delete ptr; 
        ptr = NULL;
    }
}
#define SAFE_DELETE safeDelete              // for backward compatiblility

// Safely delete pointer referenced array
template <typename T>
inline void safeDeleteArray(T& ptr)
{
    if (ptr)
    { 
        delete[] ptr; 
        ptr = NULL;
    }
}
#define SAFE_DELETE_ARRAY safeDeleteArray   // for backward compatiblility

// Safely call onLostDevice
template <typename T>
inline void safeOnLostDevice(T& ptr)
{
    if (ptr)
        ptr->onLostDevice(); 
}
#define SAFE_ON_LOST_DEVICE safeOnLostDevice    // for backward compatiblility

// Safely call onResetDevice
template <typename T>
inline void safeOnResetDevice(T& ptr)
{
    if (ptr)
        ptr->onResetDevice(); 
}
#define SAFE_ON_RESET_DEVICE safeOnResetDevice  // for backward compatiblility

//=============================================================================
//                  Constants
//=============================================================================

// window
const char CLASS_NAME[] = "Khetstrophe";
const char GAME_TITLE[] = "Khetstrophe";
const bool FULLSCREEN = false;              // windowed or fullscreen
const UINT GAME_WIDTH =  640;               // width of game in pixels
const UINT GAME_HEIGHT = 640;               // height of game in pixels
 
// game
const double PI = 3.14159265;
const float FRAME_RATE = 240.0f;                // the target frame rate (frames/sec)
const float MIN_FRAME_RATE = 10.0f;             // the minimum frame rate
const float MIN_FRAME_TIME = 1.0f/FRAME_RATE;   // minimum desired time for 1 frame
const float MAX_FRAME_TIME = 1.0f/MIN_FRAME_RATE; // maximum time used in calculations

// graphic images
const char MENU_IMAGE[] =     "pictures\\menu.png";      // menu texture
    
    //board
const char BOARD[] =          "pictures\\GameBoard.png";
    //number grid
const char NUM_GRID[] =       "pictures\\NumberGrid.png";
    //pieces
const char ANUBIS_RED[] =     "pictures\\Anubis_Red.png";
const char ANUBIS_GREY[] =   "pictures\\Anubis_White.png";
const char MIRROR_RED[] =     "pictures\\Mirror_Red.png";
const char MIRROR_GREY[] =   "pictures\\Mirror_White.png";
const char PHAROAH_RED[] =    "pictures\\Pharoah_Red.png";
const char PHAROAH_GREY[] =  "pictures\\Pharoah_White.png";
const char SCARAB_RED[] =     "pictures\\Scarab_Red.png";
const char SCARAB_GREY[] =   "pictures\\Scarab_White.png";
const char SPHINX_RED[] =     "pictures\\Sphinx_Red.png";
const char SPHINX_GREY[] =   "pictures\\Sphinx_White.png";



// audio files required by audio.cpp
// WAVE_BANK must be location of .xwb file.
const char WAVE_BANK[]  = "";
// SOUND_BANK must be location of .xsb file.
const char SOUND_BANK[] = "";

// audio cues

// key mappings
// In this game simple constants are used for key mappings. If variables were used
// it would be possible to save and restore key mappings from a data file.
const UCHAR CONSOLE_KEY  = '`';         // ` key
const UCHAR ESC_KEY      = VK_ESCAPE;   // escape key
const UCHAR ALT_KEY      = VK_MENU;     // Alt key
const UCHAR ENTER_KEY    = VK_RETURN;   // Enter key

#endif
