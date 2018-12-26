//
//  main.cpp
//  RayTracingOneWeekEnd
//
//  Created by Alberto Lirussi on 26/12/2018.
//  Copyright © 2018 Alberto Lirussi. All rights reserved.
//

#include <iostream>
#include "vec3.h"

int main(int argc, const char * argv[]) {
    int nx = 200;   // Number of columns
    int ny = 100;   // Number of rows
    std::cout << "P3\n" << nx << " " << ny << "\n255\n"; // Header: P3, #cols #rows, max color (255)
    for (int j = ny - 1; j >= 0; j--) { // Cycle through rows
        for (int i = 0; i < nx; i++) {  // Cycle through cols
            // Red color increase from 0 to 1 (from off to on)
            // Green color decrease from 1 to 0 (from on to off)
            // Blue always zero (off)
            vec3 col(float(i) / float(nx-1), float(j) / float(ny-1), 0.0);
            int ir = int(255.0*col[0]);
            int ig = int(255.0*col[1]);
            int ib = int(255.0*col[2]);
            std::cout << ir << " " << ig << " " << ib << " ";
        }
        std::cout << "\n";  // Next row
    }
}
