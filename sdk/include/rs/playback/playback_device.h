// License: Apache 2.0. See LICENSE file in root directory.
// Copyright(c) 2016 Intel Corporation. All Rights Reserved.

#pragma once
#include <librealsense/rs.hpp>

namespace rs
{
    namespace playback
    {
        /**
        This class provides rs::device capabilities with extention of playback capabilities.
        */
        class device : public rs::device
        {
        public:
            /**
            @brief Indicates the played frame rate - with or without real time frame rate delays.
            @return bool     Real time state.
            */
            bool is_real_time();
            /**
            @brief Pause streaming and leave the file read pointer on its current position.
            */
            void pause();
            /**
            @brief Resume streaming from the current file read pointer position.
            */
            void resume();
            /**
            @brief Set the current frames by a given stream type and index. Other streams will be set by the nearst capture time. The file read pointer will be set to the frame with latest capture time.
            @param[in] index  A zero based frame index to set the file read pointer.
            @param[in] stream  The stream type for which the frame is selected.
            */
            bool set_frame_by_index(int index, rs::stream stream);
            /**
            @brief Locate the frame after a given time stamp. Other streams will be set by the nearst capture time. The file read pointer will be set to the frame with latest capture time.
            @param[in] timestamp  The time in milisecond to seek according to.
            */
            bool set_frame_by_timestamp(uint64_t timestamp);
            /**
            @brief Sets the state of the real time flag.
            @param[in] realtime  The requsted state.
            */
            void set_real_time(bool realtime);
            /**
            @brief Gets the index of current frame.
            @param[in] stream  The stream type for which the frame is queried.
            @return int The frame index.
            */
            int get_frame_index(rs::stream stream);
            /**
            @brief Gets the total count of captured frames in the file.
            @param[in] stream  The stream type for which the frame count is queried.
            @return int  Frame count.
            */
            int get_frame_count(rs::stream stream);
            /**
            @brief Gets the total frame count of the stream with the lowest frame count.
            @return int  Frame count.
            */
            int get_frame_count();
        };
    }
}


