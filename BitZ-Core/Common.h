#pragma once

#include <cmath>
#include <float.h>
#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <thread>
#include <string>
#include <stdint.h>
#include <vector>
#include <queue>
#include <mutex>
#include <cstddef>
#include <memory>

//OpenGL Includes
#ifdef __ANDROID__

#define __FASTCALL

#define GLEW_NO_GLU true
#define GLEW_STATIC true
#include "Libs/Glew/glew.h"

typedef float float_t;
typedef double double_t;

#include <jni.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>
#include <android/log.h>
#include <GLES/gl.h>
#include <jni.h>
#include <errno.h>
#include <EGL/egl.h>

#elif __APPLE__

#include <OpenGLES/ES1/gl.h>

#elif WIN32

#define __FASTCALL __fastcall

#define GLEW_STATIC true
#include "Libs/Glew/glew.h"
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <tchar.h>

#endif

//GLM Include
#include "../Support Libraries/glm/glm/glm.hpp"
#include "../Support Libraries/glm/glm/gtc/matrix_transform.hpp"
#include "../Support Libraries/glm/glm/gtc/type_ptr.hpp"

//Cpp Format Includes
#include "Libs/CppFormat/format.h"

//Utility Functions
#include "Utility.h"