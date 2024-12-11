public class Square implements Geometric {
    private double aresta;

    public Square(double aresta) {
        this.aresta = aresta;
    }

    public double calculateArea() {
        return aresta * aresta;
    }

    public double calculatePerimeter() {
        return aresta * 4;
    }

    public double getAresta() {
        return aresta;
    }
}