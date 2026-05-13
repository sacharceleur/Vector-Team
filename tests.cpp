void test_circle()
{
    std::cout << "=== TEST CIRCLE ==="<<std::endl;

    Circle c(5, Point(0, 0));

    //1. area()
    double expected_area = 3.1416 * 25;
    double area = c.area();

    if (std::abs(area - expected_area) < 0.01)
        std::cout << "area() OK"<<std::endl;
    else
        std::cout << "area() FAIL"<<std::endl;

    //2. circumference()
    double expected_circ = 2 * 3.1416 * 5;
    double circ = c.circumference();

    if (std::abs(circ - expected_circ) < 0.01)
        std::cout << "circumference() OK"<<std::endl;
    else
        std::cout << "circumference() FAIL"<<std::endl;

    //3. translate()
    Circle c2 = c;
    c2.translate(Point(2, 3));

    if (c2.center.x == 2 && c2.center.y == 3)
        std::cout << "translate() OK"<<std::endl;
    else
        std::cout << "translate() FAIL"<<std::endl;

    //4. resize()
    Circle c3 = c;
    c3.resize(2);

    if (std::abs(c3.radius - 10) < 0.01)
        std::cout << "resize() OK\n";
    else
        std::cout << "resize() FAIL\n";

    //5. equals()
    Circle c4(5, Point(0, 0));
    Circle c5(5, Point(0, 0));

    if (c4.equals(c5))
        std::cout << "equals() OK\n";
    else
        std::cout << "equals() FAIL\n";
} 






void test_triangle()
{
    std::cout << "=== TEST TRIANGLE ==="<<std::endl;
    Triangle t(Point(0,0), Point(4,0), Point(0,3));

    //1. perimeter()

    double p = t.perimeter();

    if (p > 11.9 && p < 12.1)
        std::cout << "perimeter() OK"<<std::endl;
    else
        std::cout << "perimeter() FAIL"<<std::endl;

    //2. area()
    double a = t.area();

    if (std::abs(a - 6.0) < 0.01) // (base*hauteur)/2 = 6
        std::cout << "area() OK"<<std::endl;
    else
        std::cout << "area() FAIL"<<std::endl;

    //3. center()
    Point c = t.center();

    // centre de gravité = (0+4+0)/3 , (0+0+3)/3 = (1.33, 1)
    if (std::abs(c.x - 1.33) < 0.05 && std::abs(c.y - 1.0) < 0.05)
        std::cout << "center() OK"<<std::endl;
    else
        std::cout << "center() FAIL"<<std::endl;

    //4. isRightAngled()

    if (t.isRightAngled())
        std::cout << "isRightAngled() OK"<<std::endl;
    else
        std::cout << "isRightAngled() FAIL"<<std::endl;

    // 5. isIsoceles()

    if (!t.isIsoceles())
        std::cout << "isIsoceles() OK"<<std::endl;
    else
        std::cout << "isIsoceles() FAIL"<<std::endl;

    // 6. equals()
    Triangle t2(Point(0,0), Point(4,0), Point(0,3));

    if (t.equals(t2))
        std::cout << "equals() OK"<<std::endl;
    else
        std::cout << "equals() FAIL"<<std::endl;

    // 7. translate()
    Triangle t3 = t;
    t3.translate(Point(1,1));

    if (std::abs(t3.A.x - 1) < 0.01 && std::abs(t3.A.y - 1) < 0.01)
        std::cout << "translate() OK"<<std::endl;
    else
        std::cout << "translate() FAIL"<<std::endl;

    //8. resize()
	Triangle t4 = t;

	double oldDist = t.center().distance(t.A);

	t4.resize(2);

	double newDist = t4.center().distance(t4.A);

	if (std::abs(newDist - oldDist * 2) < 0.01)
   		 std::cout << "resize() OK" << std::endl;
	else
   		 std::cout << "resize() FAIL" << std::endl;

}


void test_square()
{
    std::cout << "=== TEST SQUARE ===" << std::endl;
    Square s(Point(0,0), Point(2,2));

    //1. side()
    double expectedSide = 2.0;

    if (std::abs(s.side() - expectedSide) < 0.01)
        std::cout << "side() OK" << std::endl;
    else
        std::cout << "side() FAIL" << std::endl;

    //2. perimeter()

    if (std::abs(s.perimeter() - 8.0) < 0.01)
        std::cout << "perimeter() OK" << std::endl;
    else
        std::cout << "perimeter() FAIL" << std::endl;

    //3. area()

    if (std::abs(s.area() - 4.0) < 0.01)
        std::cout << "area() OK" << std::endl;
    else
        std::cout << "area() FAIL" << std::endl;

    //4. center()

    Point c = s.center();

    if (std::abs(c.x - 1.0) < 0.01 &&
        std::abs(c.y - 1.0) < 0.01)
        std::cout << "center() OK" << std::endl;
    else
        std::cout << "center() FAIL" << std::endl;

    //5. translate()

    Square s2 = s;

    s2.translate(Point(2,3));

    Point c2 = s2.center();

    if (std::abs(c2.x - 3.0) < 0.01 &&
        std::abs(c2.y - 4.0) < 0.01)
        std::cout << "translate() OK" << std::endl;
    else
        std::cout << "translate() FAIL" << std::endl;

    //6. resize()

    Square s3 = s;

    double oldSide = s.side();

    s3.resize(2);

    double newSide = s3.side();

    if (std::abs(newSide - oldSide * 2) < 0.01)
        std::cout << "resize() OK" << std::endl;
    else
        std::cout << "resize() FAIL" << std::endl;

    //7. equals()

    Square s4(Point(0,0), Point(2,2));

    if (s.equals(s4))
        std::cout << "equals() OK" << std::endl;
    else
        std::cout << "equals() FAIL" << std::endl;

    //8. inscribedCircle()

    Circle in = s.inscribedCircle();

    if (std::abs(in.radius - 1.0) < 0.01)
        std::cout << "inscribedCircle() OK" << std::endl;
    else
        std::cout << "inscribedCircle() FAIL" << std::endl;

    //9. circumscribedCircle()

    Circle out = s.circumscribedCircle();

    double expectedRadius = std::sqrt(2);

    if (std::abs(out.radius - expectedRadius) < 0.01)
        std::cout << "circumscribedCircle() OK" << std::endl;
    else
        std::cout << "circumscribedCircle() FAIL" << std::endl;
}
