public class Adult extends Human {
    private String profissao;
    private Child[] filhos;

    public Adult(String nome, String endereco, int CEP, String profissao) {
        super(nome, endereco, CEP);
        filhos = new Child[4];
        this.profissao = profissao;
    }

    public void addKid(Child c) {
        Boolean added = false;

        for (int i = 0; !added && i < 4; i++)
            if (filhos[i] == null) {
                filhos[i] = c;
                added = true;
            }
    }
}