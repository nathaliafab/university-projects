public class Robot {
    private String nome;
    private int numeroCamisa;
    private float posX;
    private float posY;

    public Robot(String nome, int numeroCamisa, float x, float y) {
        this.nome = nome;
        this.numeroCamisa = numeroCamisa;
        this.posX = x;
        this.posY = y;
    }

    public String getNome() {
        return this.nome;
    }

    public int getNumeroCamisa() {
        return this.numeroCamisa;
    }

    public float getPosX() {
        return this.posX;
    }

    public float getPosY() {
        return this.posY;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setNumeroCamisa(int numeroCamisa) {
        this.numeroCamisa = numeroCamisa;
    }

    public void setPos(float posX, float posY) {
        this.posX = posX;
        this.posY = posY;
    }
}