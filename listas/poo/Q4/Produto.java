public class Produto {
    private String nome;
    private int qtd;
    private float preco;

    public Produto(String nome, int qtd, float preco) {
        this.nome = nome;
        this.qtd = qtd;
        this.preco = preco;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getNome() {
        return nome;
    }

    public void setQtd(int qtd) {
        this.qtd = qtd;
    }

    public int getQtd() {
        return qtd;
    }

    public void setPreco(float preco) {
        this.preco = preco;
    }

    public float getPreco() {
        return preco;
    }
}