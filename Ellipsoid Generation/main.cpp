#include <iostream>
#include <cmath>
#include <vector>
#include <random>

std::vector<double> calculate_center(std::vector<double> F1, std::vector<double> F2) {
    double center_x = (F1[0] + F2[0]) / 2;
    double center_y = (F1[1] + F2[1]) / 2;
    double center_z = (F1[2] + F2[2]) / 2;
    return {center_x, center_y, center_z};
}

std::pair<double, double> calculate_major_minor_axes(std::vector<double> F1, std::vector<double> F2, std::vector<double> P) {
    double PF1 = sqrt(pow(P[0] - F1[0], 2) + pow(P[1] - F1[1], 2) + pow(P[2] - F1[2], 2));
    double PF2 = sqrt(pow(P[0] - F2[0], 2) + pow(P[1] - F2[1], 2) + pow(P[2] - F2[2], 2));
    double major_axis = PF1 + PF2;
    double c = sqrt(pow(F1[0] - F2[0], 2) + pow(F1[1] - F2[1], 2) + pow(F1[2] - F2[2], 2));
    double b_over_2 = sqrt(pow(major_axis / 2, 2) - pow(c, 2) / 4);
    double minor_axis = b_over_2;
    major_axis = major_axis / 2;
    return std::make_pair(major_axis, minor_axis);
}

std::vector<double> generate_random_points_inside_ellipsoid(std::vector<double> semi_axes_lengths, int num_points = 1) {
    std::vector<double> random_points;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<double> distribution(0.0, 1.0);

    for (int i = 0; i < num_points; ++i) {
        double x = distribution(gen);
        double y = distribution(gen);
        double z = distribution(gen);
        double length = sqrt(x * x + y * y + z * z);
        x /= length;
        y /= length;
        z /= length;

        x *= semi_axes_lengths[0];
        y *= semi_axes_lengths[1];
        z *= semi_axes_lengths[2];

        random_points.push_back(x);
        random_points.push_back(y);
        random_points.push_back(z);
    }

    return random_points;
}

int main() {

    //test inputs
    std::vector<double> F1 = {3.4641016151377544, 0, 0};
    std::vector<double> F2 = {-3.4641016151377544, 0, 0};
    std::vector<double> P = {3.04, 1.3, 0};

    auto major_minor_axes = calculate_major_minor_axes(F1, F2, P);
    double major_axis = major_minor_axes.first;
    double minor_axis = major_minor_axes.second;

    std::vector<double> center = calculate_center(F1, F2);
    std::vector<double> semi_axes_lengths = {major_axis, minor_axis, minor_axis};
    //how many points you want this to return to you
    int num_points = 500;
    std::vector<double> random_points = generate_random_points_inside_ellipsoid(semi_axes_lengths, num_points);

    // print the generated random points, test code delete

    for (int i = 0; i < num_points; ++i) {
        std::cout << "(" << random_points[i * 3] << ", " << random_points[i * 3 + 1] << ", " << random_points[i * 3 + 2] << ")" << std::endl;
    }

    return 0;
}












