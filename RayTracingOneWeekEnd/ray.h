//
//  ray.h
//  RayTracingOneWeekEnd
//
//  Created by Alberto Lirussi on 26/12/2018.
//  Copyright © 2018 Alberto Lirussi. All rights reserved.
//

#ifndef ray_h
#define ray_h

#include "vec3.h"

class ray {
public:
    vec3 A;
    vec3 B;
    
    ray() {}
    ray(const vec3& a, const vec3& b) { A = a; B = b; }
    vec3 origin() const { return A; }
    vec3 direction() const { return B; }
    vec3 point_at_parameter(float t) const { return A + t*B; }
    
};

#endif /* ray_h */
