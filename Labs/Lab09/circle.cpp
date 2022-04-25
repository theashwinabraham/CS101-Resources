/*
* AUTHOR: ASHWIN ABRAHAM
*/
#include <simplecpp>

double cradius(int x1, int y1, int x2, int y2, int x3, int y3){
    if((x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))==0){return 1e100;}
    double d1 = sqrt((x2-x3)*(x2-x3) + (y2-y3)*(y2-y3));
    double d2 = sqrt((x1-x3)*(x1-x3) + (y1-y3)*(y1-y3));
    double d3 = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    double s = (d1+d2+d3)/2;
    double A = sqrt(s*(s-d1)*(s-d2)*(s-d3));
    return d1*d2*d3/(4*A);
}

double ccentre_x(int x1, int y1, int x2, int y2, int x3, int y3){
    int D = (x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
    if(D==0){return -1;}
    double d = 2.0*D;
    double k = (x1*x1+y1*y1)*(y2-y3)+(x2*x2+y2*y2)*(y3-y1)+(x3*x3+y3*y3)*(y1-y2);
    return k/d;
}

double ccentre_y(int x1, int y1, int x2, int y2, int x3, int y3){
    int D = (x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
    if(D==0){return -1;}
    double d = 2.0*D;
    double k = (x1*x1+y1*y1)*(x2-x3)+(x2*x2+y2*y2)*(x3-x1)+(x3*x3+y3*y3)*(x1-x2);
    return -k/d;
}

bool is_in_ccircle(int x_check, int y_check, int x1, int y1, int x2, int y2, int x3, int y3){
    if((x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))==0){return true;}
    double x = ccentre_x(x1, y1, x2, y2, x3, y3);
    double y = ccentre_y(x1, y1, x2, y2, x3, y3);
    double r = cradius(x1, y1, x2, y2, x3, y3);
    return ((x_check - x)*(x_check -  x) + (y_check - y)*(y_check - y) <= r*r);
}

int main(){
    int n;
    cin >> n;
    int x[n], y[n];
    initCanvas();
    for(int i = 0; i<n; i++){
        int click = getClick();
        x[i] = click/65536;
        y[i] = click%65536;
        Rectangle r(x[i], y[i], 10, 10);
        r.setColor(COLOR("red"));
        r.setFill(true);
        r.imprint();
    }
    double min_radius = 1e100;
    int min_x, min_y;
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            for(int k = j+1; k<n; k++){
                bool contains_all = true;
                for(int p = 0; p<n; p++){
                    if(p!=i&&p!=j&&p!=k){
                        contains_all = contains_all&&is_in_ccircle(x[p], y[p], x[i], y[i], x[j], y[j], x[k], y[k]);
                    }
                }
                if(contains_all&&(cradius(x[i], y[i], x[j], y[j], x[k], y[k])<min_radius)){
                    min_radius = cradius(x[i], y[i], x[j], y[j], x[k], y[k]);
                    min_x = ccentre_x(x[i], y[i], x[j], y[j], x[k], y[k]);
                    min_y = ccentre_y(x[i], y[i], x[j], y[j], x[k], y[k]);
                }
            }
        }
    }
    Circle c(min_x, min_y, min_radius);
    wait(10);
    return 0;
}
