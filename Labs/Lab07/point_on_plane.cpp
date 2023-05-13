/*
* AUTHOR: ASHWIN ABRAHAM
*/
#include <cmath>

double det(double m_11, double m_12, double m_13,
           double m_21, double m_22, double m_23,
           double m_31, double m_32, double m_33){
    double det = 0;
    det+=(m_21*m_32*m_13 + m_11*m_22*m_33 + m_12*m_23*m_31);
    det-=(m_23*m_32*m_11 + m_13*m_22*m_31 + m_12*m_21*m_33);
    return det;
}
double cross_magnitude(double x1, double y1, double z1, double x2, double y2, double z2){
    double v1 = y1*z2 - y2*z1;
    double v2 = x2*z1 - x1*z2;
    double v3 = x1*y2 - x2*y1;
    return sqrt(v1*v1 + v2*v2 + v3*v3);
}
bool point_on_plane(double *p1_x, double *p1_y, double *p1_z,
                    double *p2_x, double *p2_y, double *p2_z,
                    double *p3_x, double *p3_y, double *p3_z,
                    double *q_x, double *q_y, double *q_z,
                    double *dist){
    double determinant = det(*q_x - *p1_x, *q_y - *p1_y, *q_z - *p1_z,
                             *p2_x - *p1_x, *p2_y - *p1_y, *p2_z - *p1_z,
                             *p3_x - *p1_x, *p3_y - *p1_y, *p3_z - *p1_z);
    double cm = cross_magnitude(*p2_x - *p1_x, *p2_y - *p1_y, *p2_z - *p1_z,
                                *p3_x - *p1_x, *p3_y - *p1_y, *p3_z - *p1_z);
    *dist = abs(determinant/cm);
    if(*dist<1e-8){return true;}
    return false;
}
