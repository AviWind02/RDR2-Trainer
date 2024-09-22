/*
	THIS FILE IS A PART OF RDR 2 SCRIPT HOOK SDK
				http://dev-c.com
			(C) Alexander Blade 2019
*/

#pragma once

#include <windows.h>
#include <cstdint>

typedef DWORD Void;
typedef DWORD Any;
typedef DWORD uint;
typedef DWORD Hash;
typedef int Entity;
typedef int Player;
typedef int FireId;
typedef int Ped;
typedef int Vehicle;
typedef int Cam;
typedef int CarGenerator;
typedef int Group;
typedef int Train;
typedef int Pickup;
typedef int Object;
typedef int Weapon;
typedef int Interior;
typedef int Blip;
typedef int Texture;
typedef int TextureDict;
typedef int CoverPoint;
typedef int Camera;
typedef int TaskSequence;
typedef int ColourIndex;
typedef int Sphere;
typedef int ScrHandle;

#define ALIGN8 __declspec(align(8))


struct Colour {
    float r;
    float g;
    float b;
    float a;

};


struct Vector2 {
    float x;
    float y;

    // Constructor to initialize Vector2 with float values
    Vector2(float x, float y) : x(x), y(y) {}
};

struct Vector3 {
    float x;
    float y;
    float z;

    // Constructor to initialize Vector3 with float values
    Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
};

struct Vector4 {
    float x;
    float y;
    float z;
    float w;

    // Constructor to initialize Vector4 with float values
    Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
};
