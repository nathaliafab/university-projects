public class Circle implements Geometric {
    private double raio;
    private static final double PI = 3.14159265358979323846;

    public Circle(double raio) {
        this.raio = raio;
    }

    public double calculateArea() {
        return PI * raio * raio;
    }

    public double calculatePerimeter() {
        return 2 * PI * raio;
    }

    public double getRaio() {
        return raio;
    }
}