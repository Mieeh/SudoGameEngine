#pragma once

namespace sudo {

/* ===================================================== */
/* ===================================================== */

typedef unsigned int uint;
typedef unsigned int uint16;
typedef unsigned char uint8;

typedef char GLchar;
typedef unsigned int GLenum;
typedef unsigned int GLbitfield;
typedef unsigned int GLuint;
typedef int GLint;
typedef int GLsizei;
typedef unsigned char GLboolean;
typedef signed char GLbyte;
typedef short GLshort;
typedef unsigned char GLubyte;
typedef unsigned short GLushort;
typedef unsigned long GLulong;
typedef float GLfloat;
typedef float GLclampf;
typedef double GLdouble;
typedef double GLclampd;

// OPENAL

/** Sound samples: format specifier. */
#define AL_FORMAT_MONO8                           0x1100
#define AL_FORMAT_MONO16                          0x1101
#define AL_FORMAT_STEREO8                         0x1102
#define AL_FORMAT_STEREO16                        0x1103

/* ===================================================== */
/* ===================================================== */

enum SudoBufferType {
	VERTEX_ONLY,
	VERTEX_COLOR,
	VERTEX_COLOR_TEXTURE
};

/* ===================================================== */
/* ===================================================== */

#define SUDO_BEHAVIOUR override

// System macros
#define SYSTEM_API

// Graphics macros
#define GRAPHICS_API
#define MAX_PIXEL_SIZE_X 6000
#define MIN_PIXEL_SIZE_X 0
#define MAX_PIXEL_SIZE_Y 6000
#define MIN_PIXEL_SIZE_Y 0

// Window macros
#define WINDOW_API 

// Time macros
#define TIME_API
#define DEFAULT_FPS_CAP 60
#define FIXED_UPDATE_MS 1000 / DEFAULT_FPS_CAP // ~0.16~

// Particle macros
#define PARTICLE_GRAVITY_Y 0.001f

// Batch Renderer
#define NEAR -1
#define FAR 1000

}