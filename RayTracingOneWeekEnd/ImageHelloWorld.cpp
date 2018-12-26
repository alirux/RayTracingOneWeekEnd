//
//  main.cpp
//  RayTracingOneWeekEnd
//
//  Created by Alberto Lirussi on 26/12/2018.
//  Copyright © 2018 Alberto Lirussi. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int nx = 200;   // Number of columns
    int ny = 100;   // Number of rows
    std::cout << "P3\n" << nx << " " << ny << "\n255\n"; // Header: P3, #cols #rows, max color (255)
    for (int j = ny - 1; j >= 0; j--) { // Cycle through rows
        for (int i = 0; i < nx; i++) {  // Cycle through cols
            float r = float(i) / float(nx-1);   // Red color increase from 0 to 1 (from off to on)
            float g = float(j) / float(ny-1);   // Green color decrease from 1 to 0 (from on to off)
            float b = 0.0;  // Blue always zero (off)
            int ir = int(255.0*r);
            int ig = int(255.0*g);
            int ib = int(255.0*b);
            std::cout << ir << " " << ig << " " << ib << " ";
        }
        std::cout << "\n";  // Next row
    }
}
