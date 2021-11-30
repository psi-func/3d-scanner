//
// Created by User on 25.11.2021.
//

#ifndef INC_3D_SCANNING_THREADSAFEPRINT_H
#define INC_3D_SCANNING_THREADSAFEPRINT_H

#include <iostream>
#include <mutex>
#include <sstream>

namespace we {
    std::mutex _cerr_mutex;

    template<typename T>
    void safeCerr(const T& msg) {
        std::lock_guard<std::mutex> lock(_cerr_mutex);
        std::cerr << msg << std::endl;
    }
}


#endif //INC_3D_SCANNING_THREADSAFEPRINT_H
