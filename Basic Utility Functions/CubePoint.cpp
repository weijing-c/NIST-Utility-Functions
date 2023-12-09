#include <iostream>




void CubePoint(float cube_x, float cube_y, float cube_z, float cube_r, float point_x, float point_y, float point_z) {

    float cube_max_x = cube_x + cube_r;
    float cube_min_x = cube_x - cube_r;
    float cube_max_y = cube_y + cube_r;
    float cube_min_y = cube_y - cube_r;
    float cube_max_z = cube_z + cube_r;
    float cube_min_z = cube_z - cube_r;

    if (cube_min_x <= point_x && point_x <= cube_max_x && cube_min_y <= point_y && point_y <= cube_max_y && cube_min_z <= point_z && point_z <= cube_max_z) {

        std::cout << 1;


    }

    else {
        std::cout << 0;
    }


}