// colormap.h
#ifndef COLORMAP_H
#define COLORMAP_H

#ifdef __cplusplus
extern "C" {
#endif

// Declare global arrays
extern const char* majorColor[];
extern const char* minorColor[];

// Declare function pointer type for printer callback
typedef void (*ColorPrinter)(int, const char*, const char*);

// Expose the core function
int generateColorMap(ColorPrinter printer);

#ifdef __cplusplus
}
#endif

#endif // COLORMAP_H