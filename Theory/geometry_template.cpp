#include<bits/stdc++.h>

using namespace std;
const long double PI = acos(-1);
class Point{
public:
    long double x, y;
    Point(long double x, long double y){
        this->x = x;
        this->y = y;
    }

    bool operator<(const Point& p) {
        if (x == p.x) {
            return y < p.y;
        } else {
            return x < p.x;
        }
    }
};

class Vector{
public:
    long double x, y;
    Vector(Point p1, Point p2)
            : x(p2.x - p1.x)
            , y(p2.y - p1.y){}
    Vector(double long x, double long y)
            : x(x)
            , y(y){}
    long double operator*(const Vector& other){ // dot product
        return x * other.x  + y * other.y;
    }
    long double operator^(const Vector& other){ // cross product
        return x * other.y - y* other.x;
    }
    long double len2() { // квадрат длины
        return x*x + y*y;
    }
    long double len(){ // длина
        return sqrtl(len2());
    }
    Vector normalize(){
        long double l = len();
        Vector norm = Vector(x / l, y / l);
        return norm;
    }
    Vector operator+(const Vector& other){
        return Vector(x + other.x, y+other.y);
    }
};
class Triangle {
public:
    Point a, b ,c;

    Triangle(Point point, Point point1, Point point2)
            : a(point)
            , b(point1)
            , c(point2)
    {}

    long double signed_square(){
        Vector ab = Vector(a, b);
        Vector ac = Vector(a, c);
        return 0.5 * (ab^ac);
    }
    long double square(){
        return abs(signed_square());
    }
};

class Line{
public:
    double long a, b, c;
    Line(Point p1, Point p2)
            : a(p2.y - p1.y)
            , b(p1.x - p2.x)
            , c(-((p2.y - p1.y)*p1.x + (p1.x - p2.x)*p1.y))
    {}
    Line(long double a, long double b, long double c)
            : a(a)
            , b(b)
            , c(c){}

};


long double angle_between_vectors(Vector v1, Vector v2){ // angle = [-pi, pi]
    return atan2(v1^v2, v1*v2);
}

long double square_of_any_shape(int n /* количество точек фигуры */, vector<Point> p /* вектор из точек */){
    long double res = 0;
    for(int i = 1; i < n-1; i++){
        Triangle tr = Triangle(p[0], p[i], p[i+1]);
        res += tr.signed_square();
    }
    return abs(res);
}
long double distance_between_point_and_line(Point p, Line l){
    long double n = Vector(l.a, l.b).len();
    return abs((l.a/n)*p.x + (l.b/n)*p.y + l.c/n);
}
bool is_point_in_segment(Point p, /* координата точки */ Point start, Point end /* координаты начала и конца отрезков */){
    Vector ab = Vector(start, end);
    Vector ca = Vector(p, start);
    Vector cb = Vector(p, end);
    if(ca * cb <= 0 and (ab ^ cb) == 0){
        return true;
    }else{
        return false;
    }

}

bool is_point_on_the_line(Point p, Line l){
    if(l.a*p.x + l.b*p.y + l.c == 0){
        return true;
    }
    else{
        return false;
    }
}
bool are_lines_parallel(Line l1, Line l2){
    if(l1.a*l2.b - l2.a*l1.b == 0){
        return true;
    }else{
        return false;
    }
}
Point lines_intersection(Line l1, Line l2){
    if(!are_lines_parallel(l1, l2)) {
        long double x = ((-l1.c * l2.b) - (-l2.c * l1.b)) / ((l1.a * l2.b) - (l1.b * l2.a));
        long double y = ((l1.a * (-l2.c)) - (l2.a * (-l1.c))) / ((l1.a * l2.b) - (l1.b * l2.a));
        return Point(x, y);
    }
}

Point segments_intersection(Point a1, Point a2, Point b1, Point b2){
    Line l1 = Line(a1, a2);
    Line l2 = Line(b1, b2);
    if(!are_lines_parallel(l1, l2)) {
        Point p = lines_intersection(l1, l2);
        if(is_point_in_segment(p, a1, a2) and is_point_in_segment(p, b1, b2)){
            return p;
        }
    }
}


int main(){
    Point p1 = Point(6, 1);
    Point p2 = Point(6, 5);

    cout << (p1 < p2); 
}

