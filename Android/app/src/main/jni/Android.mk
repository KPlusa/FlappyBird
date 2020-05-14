LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := sfml-example

LOCAL_SRC_FILES := main.cpp \
    App.cpp \
    Land_and_background.cpp \
    Bird.cpp \
    pipes.cpp
        


LOCAL_SHARED_LIBRARIES := sfml-system-d
LOCAL_SHARED_LIBRARIES += sfml-window-d
LOCAL_SHARED_LIBRARIES += sfml-graphics-d
LOCAL_SHARED_LIBRARIES += sfml-audio-d
LOCAL_SHARED_LIBRARIES += sfml-network-d
LOCAL_SHARED_LIBRARIES += sfml-activity-d
LOCAL_SHARED_LIBRARIES += openal
LOCAL_WHOLE_STATIC_LIBRARIES := sfml-main-d
LOCAL_STATIC_LIBRARIES := box2d_static

include $(BUILD_SHARED_LIBRARY)

$(call import-module,third_party/sfml)
$(call import-module,Box2D)
