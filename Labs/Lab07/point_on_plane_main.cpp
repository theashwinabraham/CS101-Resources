#include <simplecpp>
bool point_on_plane(
    double *p1_x, double *p1_y, double *p1_z,
    double *p2_x, double *p2_y, double *p2_z,
    double *p3_x, double *p3_y, double *p3_z,
    double *q_x, double *q_y, double *q_z,
    double *dist);
main_program
{
    double p1_x, p1_y, p1_z, p2_x, p2_y, p2_z, p3_x, p3_y, p3_z, q_x, q_y, q_z, d;
    cin >> p1_x >> p1_y >> p1_z >> p2_x >> p2_y >> p2_z >> p3_x >> p3_y >> p3_z >> q_x >> q_y >> q_z;
    bool is_on_plane = point_on_plane(&p1_x, &p1_y, &p1_z, &p2_x, &p2_y, &p2_z, &p3_x, &p3_y, &p3_z, &q_x, &q_y, &q_z, &d);
    int result = 0;
    if (is_on_plane)
    {
        result = 1;
    }
    cout << fixed;
    cout.precision(2);
    cout << result << ' ' << d << endl;
}