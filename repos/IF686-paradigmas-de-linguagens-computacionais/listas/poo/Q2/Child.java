public class Child extends Human {
    private String brinquedo;

    public Child(String nome, String endereco, int CEP, String brinquedo) {
        super(nome, endereco, CEP);
        this.brinquedo = brinquedo;
    }

    @Override
    public void greet(Citizen c) {
        super.greet(c);
        System.out.println("Quer brincar com meu " + this.brinquedo + "?");
    }

    public void setBrinquedo(String brinquedo) {
        this.brinquedo = brinquedo;
    }

    public String getBrinquedo() {
        return brinquedo;
    }
}