public abstract class Citizen {
    private String nome;
    private String endereco;
    private int CEP;

    public Citizen(String nome, String endereco, int CEP) {
        this.nome = nome;
        this.endereco = endereco;
        this.CEP = CEP;
    }

    // Método diferente para Robot e Human:
    public abstract void greet(Citizen c);

    public String getNome() {
        return this.nome;
    }

    public String getEndereco() {
        return this.endereco;
    }

    public int getCEP() {
        return this.CEP;
    }
}