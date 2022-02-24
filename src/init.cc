#include <libyuv.h>
#include "convert_argb.h"
#include "convert.h"
#include "cpu_id.h"
#include "init.h"
#include "rotate_argb.h"
#include "rotate.h"
#include "scale_argb.h"
#include "scale.h"
#include "version.h"
#include "config.h"

static Napi::Object Init(Napi::Env env, Napi::Object exports) {
    
    // convert.cc
    exports.Set("I444ToI420", Napi::Function::New(env, I444ToI420));
    exports.Set("I444ToNV12", Napi::Function::New(env, I444ToNV12));
    exports.Set("I444ToNV21", Napi::Function::New(env, I444ToNV21));
    exports.Set("I422ToI420", Napi::Function::New(env, I422ToI420));
    exports.Set("I422ToNV21", Napi::Function::New(env, I422ToNV21));
    exports.Set("I420Copy", Napi::Function::New(env, I420Copy));
    exports.Set("I010Copy", Napi::Function::New(env, I010Copy));
    exports.Set("I010ToI420", Napi::Function::New(env, I010ToI420));
    exports.Set("I400ToI420", Napi::Function::New(env, I400ToI420));
    exports.Set("I400ToNV21", Napi::Function::New(env, I400ToNV21));
    exports.Set("NV12ToI420", Napi::Function::New(env, NV12ToI420));
    exports.Set("NV21ToI420", Napi::Function::New(env, NV21ToI420));
    exports.Set("YUY2ToI420", Napi::Function::New(env, YUY2ToI420));
    exports.Set("UYVYToI420", Napi::Function::New(env, UYVYToI420));
    exports.Set("AYUVToNV12", Napi::Function::New(env, AYUVToNV12));
    exports.Set("AYUVToNV21", Napi::Function::New(env, AYUVToNV21));
    exports.Set("Android420ToI420", Napi::Function::New(env, Android420ToI420));
    exports.Set("ARGBToI420", Napi::Function::New(env, ARGBToI420));
    exports.Set("BGRAToI420", Napi::Function::New(env, BGRAToI420));
    exports.Set("ABGRToI420", Napi::Function::New(env, ABGRToI420));
    exports.Set("RGBAToI420", Napi::Function::New(env, RGBAToI420));
    exports.Set("RGB24ToI420", Napi::Function::New(env, RGB24ToI420));
    exports.Set("ARGBToUYVY", Napi::Function::New(env, ARGBToUYVY));
    exports.Set("RGB24ToJ420", Napi::Function::New(env, RGB24ToJ420));
    exports.Set("RAWToI420", Napi::Function::New(env, RAWToI420));
    exports.Set("RGB565ToI420", Napi::Function::New(env, RGB565ToI420));
    exports.Set("ARGB1555ToI420", Napi::Function::New(env, ARGB1555ToI420));
    exports.Set("ARGB4444ToI420", Napi::Function::New(env, ARGB4444ToI420));
    exports.Set("RGB24ToJ400", Napi::Function::New(env, RGB24ToJ400));
    exports.Set("RAWToJ400", Napi::Function::New(env, RAWToJ400));
    
#ifdef HAVE_JPEG
    exports.Set("MJPGToI420", Napi::Function::New(env, MJPGToI420));
    exports.Set("MJPGToNV21", Napi::Function::New(env, MJPGToNV21));
    exports.Set("MJPGSize", Napi::Function::New(env, MJPGSize));
#endif
    exports.Set("ConvertToI420", Napi::Function::New(env, ConvertToI420));

    // convert_argb.cc
    exports.Set("ARGBCopy", Napi::Function::New(env, ARGBCopy));
    exports.Set("I420ToARGB", Napi::Function::New(env, I420ToARGB));
    exports.Set("I420ToABGR", Napi::Function::New(env, I420ToABGR));
    exports.Set("J420ToARGB", Napi::Function::New(env, J420ToARGB));
    exports.Set("J420ToABGR", Napi::Function::New(env, J420ToABGR));
    exports.Set("H420ToARGB", Napi::Function::New(env, H420ToARGB));
    exports.Set("H420ToABGR", Napi::Function::New(env, H420ToABGR));
    exports.Set("U420ToARGB", Napi::Function::New(env, U420ToARGB));
    exports.Set("U420ToABGR", Napi::Function::New(env, U420ToABGR));
    exports.Set("I422ToARGB", Napi::Function::New(env, I422ToARGB));
    exports.Set("I422ToABGR", Napi::Function::New(env, I422ToABGR));
    exports.Set("J422ToARGB", Napi::Function::New(env, J422ToARGB));
    exports.Set("J422ToABGR", Napi::Function::New(env, J422ToABGR));
    exports.Set("H422ToARGB", Napi::Function::New(env, H422ToARGB));
    exports.Set("H422ToABGR", Napi::Function::New(env, H422ToABGR));
    exports.Set("U422ToARGB", Napi::Function::New(env, U422ToARGB));
    exports.Set("U422ToABGR", Napi::Function::New(env, U422ToABGR));
    exports.Set("I444ToARGB", Napi::Function::New(env, I444ToARGB));
    exports.Set("I444ToABGR", Napi::Function::New(env, I444ToABGR));
    exports.Set("J444ToARGB", Napi::Function::New(env, J444ToARGB));
    exports.Set("J444ToABGR", Napi::Function::New(env, J444ToABGR));
    exports.Set("H444ToARGB", Napi::Function::New(env, H444ToARGB));
    exports.Set("H444ToABGR", Napi::Function::New(env, H444ToABGR));
    exports.Set("U444ToARGB", Napi::Function::New(env, U444ToARGB));
    exports.Set("U444ToABGR", Napi::Function::New(env, U444ToABGR));
    exports.Set("I010ToARGB", Napi::Function::New(env, I010ToARGB));
    exports.Set("I010ToABGR", Napi::Function::New(env, I010ToABGR));
    exports.Set("H010ToARGB", Napi::Function::New(env, H010ToARGB));
    exports.Set("H010ToABGR", Napi::Function::New(env, H010ToABGR));
    exports.Set("U010ToARGB", Napi::Function::New(env, U010ToARGB));
    exports.Set("U010ToABGR", Napi::Function::New(env, U010ToABGR));
    exports.Set("I210ToARGB", Napi::Function::New(env, I210ToARGB));
    exports.Set("I210ToABGR", Napi::Function::New(env, I210ToABGR));
    exports.Set("H210ToARGB", Napi::Function::New(env, H210ToARGB));
    exports.Set("H210ToABGR", Napi::Function::New(env, H210ToABGR));
    exports.Set("U210ToARGB", Napi::Function::New(env, U210ToARGB));
    exports.Set("U210ToABGR", Napi::Function::New(env, U210ToABGR));
    exports.Set("I420AlphaToARGB", Napi::Function::New(env, I420AlphaToARGB));
    exports.Set("I420AlphaToABGR", Napi::Function::New(env, I420AlphaToABGR));
    exports.Set("I400ToARGB", Napi::Function::New(env, I400ToARGB));
    exports.Set("J400ToARGB", Napi::Function::New(env, J400ToARGB));
    exports.Set("NV12ToARGB", Napi::Function::New(env, NV12ToARGB));
    exports.Set("NV21ToARGB", Napi::Function::New(env, NV21ToARGB));
    exports.Set("NV12ToABGR", Napi::Function::New(env, NV12ToABGR));
    exports.Set("NV21ToABGR", Napi::Function::New(env, NV21ToABGR));
    exports.Set("NV12ToRGB24", Napi::Function::New(env, NV12ToRGB24));
    exports.Set("NV21ToRGB24", Napi::Function::New(env, NV21ToRGB24));
    exports.Set("NV21ToYUV24", Napi::Function::New(env, NV21ToYUV24));
    exports.Set("NV12ToRAW", Napi::Function::New(env, NV12ToRAW));
    exports.Set("NV21ToRAW", Napi::Function::New(env, NV21ToRAW));
    exports.Set("YUY2ToARGB", Napi::Function::New(env, YUY2ToARGB));
    exports.Set("UYVYToARGB", Napi::Function::New(env, UYVYToARGB));
    exports.Set("I010ToAR30", Napi::Function::New(env, I010ToAR30));
    exports.Set("I010ToAB30", Napi::Function::New(env, I010ToAB30));
    exports.Set("H010ToAR30", Napi::Function::New(env, H010ToAR30));
    exports.Set("H010ToAB30", Napi::Function::New(env, H010ToAB30));
    exports.Set("U010ToAR30", Napi::Function::New(env, U010ToAR30));
    exports.Set("U010ToAB30", Napi::Function::New(env, U010ToAB30));
    exports.Set("I210ToAR30", Napi::Function::New(env, I210ToAR30));
    exports.Set("I210ToAB30", Napi::Function::New(env, I210ToAB30));
    exports.Set("H210ToAR30", Napi::Function::New(env, H210ToAR30));
    exports.Set("H210ToAB30", Napi::Function::New(env, H210ToAB30));
    exports.Set("U210ToAR30", Napi::Function::New(env, U210ToAR30));
    exports.Set("U210ToAB30", Napi::Function::New(env, U210ToAB30));
    exports.Set("BGRAToARGB", Napi::Function::New(env, BGRAToARGB));
    exports.Set("ABGRToARGB", Napi::Function::New(env, ABGRToARGB));
    exports.Set("RGBAToARGB", Napi::Function::New(env, RGBAToARGB));
    exports.Set("RGB24ToARGB", Napi::Function::New(env, RGB24ToARGB));
    exports.Set("RAWToARGB", Napi::Function::New(env, RAWToARGB));
    exports.Set("RAWToRGBA", Napi::Function::New(env, RAWToRGBA));
    exports.Set("RGB565ToARGB", Napi::Function::New(env, RGB565ToARGB));
    exports.Set("ARGB1555ToARGB", Napi::Function::New(env, ARGB1555ToARGB));
    exports.Set("ARGB4444ToARGB", Napi::Function::New(env, ARGB4444ToARGB));
    exports.Set("AR30ToARGB", Napi::Function::New(env, AR30ToARGB));
    exports.Set("AR30ToABGR", Napi::Function::New(env, AR30ToABGR));
    exports.Set("AR30ToAB30", Napi::Function::New(env, AR30ToAB30));
    
#ifdef HAVE_JPEG
    exports.Set("MJPGToARGB", Napi::Function::New(env, MJPGToARGB));
#endif

    exports.Set("Android420ToARGB", Napi::Function::New(env, Android420ToARGB));
    exports.Set("Android420ToABGR", Napi::Function::New(env, Android420ToABGR));
    exports.Set("NV12ToRGB565", Napi::Function::New(env, NV12ToRGB565));
    exports.Set("I422ToBGRA", Napi::Function::New(env, I422ToBGRA));
    exports.Set("I422ToABGR", Napi::Function::New(env, I422ToABGR));
    exports.Set("I422ToRGBA", Napi::Function::New(env, I422ToRGBA));
    exports.Set("I420ToARGB", Napi::Function::New(env, I420ToARGB));
    exports.Set("I420ToBGRA", Napi::Function::New(env, I420ToBGRA));
    exports.Set("I420ToABGR", Napi::Function::New(env, I420ToABGR));
    exports.Set("I420ToRGBA", Napi::Function::New(env, I420ToRGBA));
    exports.Set("I420ToRGB24", Napi::Function::New(env, I420ToRGB24));
    exports.Set("I420ToRAW", Napi::Function::New(env, I420ToRAW));
    exports.Set("H420ToRGB24", Napi::Function::New(env, H420ToRGB24));
    exports.Set("H420ToRAW", Napi::Function::New(env, H420ToRAW));
    exports.Set("J420ToRGB24", Napi::Function::New(env, J420ToRGB24));
    exports.Set("J420ToRAW", Napi::Function::New(env, J420ToRAW));
    exports.Set("I420ToRGB565", Napi::Function::New(env, I420ToRGB565));
    exports.Set("J420ToRGB565", Napi::Function::New(env, J420ToRGB565));
    exports.Set("H420ToRGB565", Napi::Function::New(env, H420ToRGB565));
    exports.Set("I422ToRGB565", Napi::Function::New(env, I422ToRGB565));
    exports.Set("I420ToRGB565Dither", Napi::Function::New(env, I420ToRGB565Dither));
    exports.Set("I420ToARGB1555", Napi::Function::New(env, I420ToARGB1555));
    exports.Set("I420ToARGB4444", Napi::Function::New(env, I420ToARGB4444));
    exports.Set("I420ToAR30", Napi::Function::New(env, I420ToAR30));
    exports.Set("H420ToAR30", Napi::Function::New(env, H420ToAR30));
    exports.Set("I420ToARGBMatrix", Napi::Function::New(env, I420ToARGBMatrix));
    exports.Set("I422ToARGBMatrix", Napi::Function::New(env, I422ToARGBMatrix));
    exports.Set("I444ToARGBMatrix", Napi::Function::New(env, I444ToARGBMatrix));
    exports.Set("I010ToAR30Matrix", Napi::Function::New(env, I010ToAR30Matrix));
    exports.Set("I210ToAR30Matrix", Napi::Function::New(env, I210ToAR30Matrix));
    exports.Set("I010ToARGBMatrix", Napi::Function::New(env, I010ToARGBMatrix));
    exports.Set("I210ToARGBMatrix", Napi::Function::New(env, I210ToARGBMatrix));
    exports.Set("I420AlphaToARGBMatrix", Napi::Function::New(env, I420AlphaToARGBMatrix));
    exports.Set("NV12ToARGBMatrix", Napi::Function::New(env, NV12ToARGBMatrix));
    exports.Set("NV21ToARGBMatrix", Napi::Function::New(env, NV21ToARGBMatrix));
    exports.Set("NV12ToRGB565Matrix", Napi::Function::New(env, NV12ToRGB565Matrix));
    exports.Set("NV12ToRGB24Matrix", Napi::Function::New(env, NV12ToRGB24Matrix));
    exports.Set("NV21ToRGB24Matrix", Napi::Function::New(env, NV21ToRGB24Matrix));
    exports.Set("Android420ToARGBMatrix", Napi::Function::New(env, Android420ToARGBMatrix));
    exports.Set("I422ToRGBAMatrix", Napi::Function::New(env, I422ToRGBAMatrix));
    exports.Set("I420ToRGBAMatrix", Napi::Function::New(env, I420ToRGBAMatrix));
    exports.Set("I420ToRGB24Matrix", Napi::Function::New(env, I420ToRGB24Matrix));
    exports.Set("I420ToRGB565Matrix", Napi::Function::New(env, I420ToRGB565Matrix));
    exports.Set("I420ToAR30Matrix", Napi::Function::New(env, I420ToAR30Matrix));
    exports.Set("I400ToARGBMatrix", Napi::Function::New(env, I400ToARGBMatrix));
    exports.Set("ConvertToARGB", Napi::Function::New(env, ConvertToARGB));

    // cpu_id

    exports.Set("InitCpuFlags", Napi::Function::New(env, InitCpuFlags));
    exports.Set("TestCpuFlag", Napi::Function::New(env, TestCpuFlag));
    exports.Set("ArmCpuCaps", Napi::Function::New(env, ArmCpuCaps));
    exports.Set("MipsCpuCaps", Napi::Function::New(env, MipsCpuCaps));
    exports.Set("MaskCpuFlags", Napi::Function::New(env, MaskCpuFlags));
    exports.Set("SetCpuFlags", Napi::Function::New(env, SetCpuFlags));
    exports.Set("CpuId", Napi::Function::New(env, CpuId));

    // rotate_argb.h

    exports.Set("ARGBRotate", Napi::Function::New(env, ARGBRotate));

    // rotate.h

    exports.Set("I420Rotate", Napi::Function::New(env, I420Rotate));
    exports.Set("I444Rotate", Napi::Function::New(env, I444Rotate));
    exports.Set("NV12ToI420Rotate", Napi::Function::New(env, NV12ToI420Rotate));
    exports.Set("RotatePlane", Napi::Function::New(env, RotatePlane));
    exports.Set("RotatePlane90", Napi::Function::New(env, RotatePlane90));
    exports.Set("RotatePlane180", Napi::Function::New(env, RotatePlane180));
    exports.Set("RotatePlane270", Napi::Function::New(env, RotatePlane270));
    exports.Set("RotateUV90", Napi::Function::New(env, RotateUV90));
    exports.Set("RotateUV180", Napi::Function::New(env, RotateUV180));
    exports.Set("RotateUV270", Napi::Function::New(env, RotateUV270));
    exports.Set("TransposePlane", Napi::Function::New(env, TransposePlane));
    exports.Set("TransposeUV", Napi::Function::New(env, TransposeUV));

    // scale_argb.h

    exports.Set("ARGBScale", Napi::Function::New(env, ARGBScale));
    exports.Set("ARGBScaleClip", Napi::Function::New(env, ARGBScaleClip));
    exports.Set("YUVToARGBScaleClip", Napi::Function::New(env, YUVToARGBScaleClip));

    // scale.h

    exports.Set("ScalePlane", Napi::Function::New(env, ScalePlane));
    exports.Set("ScalePlane_16", Napi::Function::New(env, ScalePlane_16));
    exports.Set("I420Scale", Napi::Function::New(env, I420Scale));
    exports.Set("I420Scale_16", Napi::Function::New(env, I420Scale_16));
    exports.Set("I444Scale", Napi::Function::New(env, I444Scale));
    exports.Set("I444Scale_16", Napi::Function::New(env, I444Scale_16));
    exports.Set("Scale", Napi::Function::New(env, Scale));

    // version.h

    exports.Set("Version", Napi::Function::New(env, Version));

    return exports;
}

NODE_API_MODULE(libyuv, Init);