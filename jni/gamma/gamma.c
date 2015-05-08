#include <jni.h>
#include <gamma.h>
#include <android/bitmap.h>

#define LOG_GAMMA_TAG "GAMMA======: "

JNIEXPORT void JNICALL
Java_com_github_kkspeed_n2kit_Gamma_changeGammaArray(JNIEnv *env,
                                                   jobject jthis,
                                                   jintArray color,
                                                   int gamma_level) {

    jsize len = (*env)->GetArrayLength(env, color);
    jint *body = (*env)->GetIntArrayElements(env, color, 0);

    int i;
    unsigned char r, g, b, a; 

    if(gamma_level < 0 || gamma_level > 8) gamma_level = 8;
    /* ARGB_8888 */
    for(i=0; i<len; i++) {
        b = body[i] & 0xff;
        g = (body[i] >> 8) & 0xff;
        r = (body[i] >> 16) & 0xff;
        a = (body[i] >> 24) & 0xff;

        b = gamma_map[gamma_level][b];
        g = gamma_map[gamma_level][g];
        r = gamma_map[gamma_level][r];

        body[i] = (a << 24) | (r << 16) | (g << 8) | b;
    }

    (*env)->ReleaseIntArrayElements(env, color, body, 0);
}

JNIEXPORT void JNICALL
Java_com_github_kkspeed_n2kit_Gamma_changeGammaARGB8888(JNIEnv *env,
                                                       jobject jthis,
                                                       jobject jbitmap,
                                                       int gamma_level) {

    uint32_t *pixels;
    AndroidBitmapInfo info;
    AndroidBitmap_getInfo(env, jbitmap, &info);
    
    AndroidBitmap_lockPixels(env, jbitmap, (void **)&pixels);

    int length = info.height * info.width;
    int i;
    unsigned char r, g, b, a; 

    if(gamma_level < 0 || gamma_level > 8) gamma_level = 8;
    for (i=0; i<length; i++) {
        b = pixels[i] & 0xff;
        g = (pixels[i] >> 8) & 0xff;
        r = (pixels[i] >> 16) & 0xff;
        a = (pixels[i] >> 24) & 0xff;

        b = gamma_map[gamma_level][b];
        g = gamma_map[gamma_level][g];
        r = gamma_map[gamma_level][r];

        pixels[i] = (a << 24) | (r << 16) | (g << 8) | b;
    }
    AndroidBitmap_unlockPixels(env, jbitmap);
}


JNIEXPORT void JNICALL
Java_com_github_kkspeed_n2kit_Gamma_changeGamma(JNIEnv *env,
                                               jobject jthis,
                                               jobject jbitmap,
                                               int gamma_level) {

    uint16_t *pixels;
    AndroidBitmapInfo info;
    AndroidBitmap_getInfo(env, jbitmap, &info);
    
    AndroidBitmap_lockPixels(env, jbitmap, (void **)&pixels);

    int length = info.height * info.width;
    int i;
    unsigned char r, g, b; 

    /* RGB565 */
    if(gamma_level < 0 || gamma_level > 8) gamma_level = 8;
    for (i=0; i<length; i++) {
        if (pixels[i] == 65535) {
            continue;
        } 

        r = (pixels[i] & 31) << 3;
        g = ((pixels[i] >> 5) & 63) << 2;
        b = ((pixels[i] >> 11) & 31) << 3;


        r = gamma_map[gamma_level][r];
        g = gamma_map[gamma_level][g] & 0xfc;
        b = gamma_map[gamma_level][b] & 0xf8;

        pixels[i] = (b << 8) | (g << 3) |(r >> 3);
    }
    AndroidBitmap_unlockPixels(env, jbitmap);
}
