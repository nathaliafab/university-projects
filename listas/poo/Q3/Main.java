class Main {
    public static void main(String[] args) {
        Circle circle = new Circle(3.45);
        Square square = new Square(13);
        Triangle triangle = new Triangle(5, 7);

        System.out.println("--- CIRCLE ---");
        System.out.println("Área: " + circle.calculateArea());
        System.out.println("Perímetro: " + circle.calculatePerimeter());
        System.out.println("Raio: " + circle.getRaio());

        System.out.println("\n--- SQUARE ---");
        System.out.println("Área: " + square.calculateArea());
        System.out.println("Perímetro: " + square.calculatePerimeter());
        System.out.println("Aresta: " + square.getAresta());

        System.out.println("\n--- TRIANGLE ---");
        System.out.println("Área: " + triangle.calculateArea());
        System.out.println("Perímetro: " + triangle.calculatePerimeter());
        System.out.println("Base: " + triangle.getBase());
        System.out.println("Lado: " + triangle.getLado());
        System.out.println("Altura: " + triangle.getAltura());
    }
}