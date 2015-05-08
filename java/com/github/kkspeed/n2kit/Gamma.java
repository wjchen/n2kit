package com.github.kkspeed.n2kit;

import android.graphics.Bitmap;

public class Gamma {
	
	static {
        System.loadLibrary("gamma");
	}

	synchronized public static void changeGammaWrapper(Bitmap bitmap, int gamma_level) {
        if(bitmap == null) return;
        if(bitmap.getConfig() == Bitmap.Config.RGB_565) {
            changeGamma(bitmap, gamma_level);
        } else if(bitmap.getConfig() == Bitmap.Config.ARGB_8888) {
            changeGammaARGB8888(bitmap, gamma_level);
        }
    }

	synchronized public static native void changeGamma(Bitmap bitmap, int gamma_level);
	synchronized public static native void changeGammaARGB8888(Bitmap bitmap, int gamma_level);
	synchronized public static native void changeGammaArray(int[] color, int gamma_level);
}

