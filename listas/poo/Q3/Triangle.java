public class Triangle implements Geometric {
    private double base;
    private double altura;

    public Triangle(double base, double altura) {
        this.base = base;
        this.altura = altura;
    }

    public double calculateArea() {
        return (base * altura) / 2;
    }

    public double calculatePerimeter() {
        double lado = getLado();
        return lado * 2 + base;
    }

    public double getLado() {
        return Math.sqrt((base * base / 4) + altura * altura);
    }

    public double getBase() {
        return base;
    }

    public double getAltura() {
        return altura;
    }
}