#pragma once


// Windows Header Files
#include <windows.h>
#include <Mmsystem.h>
#include <string>
#include <ctime>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <Psapi.h>
#include <timeapi.h>
#include <time.h>

//MinHook and Lib
#include "MinHook.h"
#pragma comment(lib, "libMinHook.x64.lib")


//Natives
#include "natives.h"
#include "enums.h"
#include "main.h"
#include "types.h"

//MainView
#include "core/menu/script.h"


//Core Items
#include "core/controls/controls.h"
#include "core/buttons/buttons.h"
#include "core/ui/gui.h"
#include "core/draw/drawing.h"

//Global
#include "core/math/math.h"
#include "feature/global/entity/entity.h"
#include "feature/global/player/player.h"