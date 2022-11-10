public class Human extends Citizen {
    private Citizen[] amigos;

    public Human(String nome, String endereco, int CEP) {
        super(nome, endereco, CEP);
        amigos = new Citizen[5];
    }

    public void greet(Citizen c) {
        System.out.println("Olá, " + c.getNome() + "! ♪┏(・o･)┛♪┗ ( ･o･) ┓♪");

        if (!this.isFriend(c))
            this.addFriend(c);
    }

    public Boolean isFriend(Citizen c) {
        Boolean achou = false;

        for (int i = 0; !achou && i < 5; i++)
            if (c == amigos[i])
                achou = true;

        return achou;
    }

    public void addFriend(Citizen c) {
        Boolean added = false;

        for (int i = 0; !added && i < 5; i++)
            if (amigos[i] == null) {
                amigos[i] = c;
                added = true;
            }
    }

    public void showFriends() {
        for (int i = 0;
            (amigos[i] != null) && i < 5; i++)
            System.out.println(amigos[i].getNome());
    }
}