public class Robot extends Citizen {
    public Robot(String nome, String endereco, int CEP) {
        super(nome, endereco, CEP);
    }

    public void greet(Citizen c) {
        if (c.getCEP() == this.getCEP())
            System.out.println("Olá! └[∵┌]└[ ∵ ]┘[┐∵]┘");
    }
}