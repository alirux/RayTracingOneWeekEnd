//
//  RayPlane.cpp
//  RayPlane
//
//  Created by Alberto Lirussi on 26/12/2018.
//  Copyright © 2018 Alberto Lirussi. All rights reserved.
//

#include <stdio.h>
#include "vec3.h"
#include "ray.h"

vec3 color(const ray& r) {
    vec3 unit_direction = unit_vector(r.direction());
    float t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - t)*vec3(1.0, 1.0, 1.0) + t*vec3(0.5, 0.7, 1.0);
}

int main(int argc, const char * argv[]) {
    int nx = 200;   // Number of columns
    int ny = 100;   // Number of rows
    std::cout << "P3\n" << nx << " " << ny << "\n255\n"; // Header: P3, #cols #rows, max color (255)
    
    vec3 lower_left_corner(-2.0, -1.0, -1.0);
    vec3 horizontal(4.0, 0.0, 0.0);
    vec3 vertical(0.0, 2.0, 0.0);
    vec3 origin(0.0, 0.0, 0.0);
    
    for (int j = ny - 1; j >= 0; j--) { // Cycle through rows
        for (int i = 0; i < nx; i++) {  // Cycle through cols
            float u = float(i) / float(nx-1);
            float v = float(j) / float(ny-1);
            // Vector from origin to the plane
            // Starting: u=0, v=1 => r=lower_left_corner+vertical=(-2, 1, -1)
            // Ending: u=1, v=1 => r=lower_left_corner+horizontal+vertical=(2, 1, -1)
            // => upper margin from left to right
            // The same with other values of v (external for)
            ray r(origin, lower_left_corner + u*horizontal + v*vertical);
            vec3 col = color(r);
            int ir = int(255.0*col[0]);
            int ig = int(255.0*col[1]);
            int ib = int(255.0*col[2]);
            std::cout << ir << " " << ig << " " << ib << "   ";
        }
        std::cout << "\n";  // Next row
    }
}
