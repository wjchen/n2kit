LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_CFLAGS := -O3

LOCAL_LDLIBS := -lz -ljnigraphics
LOCAL_MODULE    := gamma
LOCAL_SRC_FILES := gamma.c

include $(BUILD_SHARED_LIBRARY)
