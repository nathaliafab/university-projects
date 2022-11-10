public class Client extends Wizard {
    private float saldo;
    private int pontuacao;

    public Client(String nome, String varinha, float saldo) {
        super(nome, varinha);
        this.saldo = saldo;
        this.pontuacao = 0;
    }

    public void attSaldo(float preco) {
        saldo -= preco;
    }

    public void attPontuacao(double pontos) {
        pontuacao += pontos;
    }

    public float getSaldo() {
        return saldo;
    }

    public int getPontuacao() {
        return pontuacao;
    }

    public boolean canReceiveGift() {
        boolean resposta = pontuacao >= 500;
        return resposta;
    }

    public void getGift(Store loja) {
        if (canReceiveGift()) {
            pontuacao -= 500;
            int index = loja.bancoW.gift();
            loja.bancoW.attEstoque(loja.bancoW.produtos[index].getNome(), 1);

            System.out.println("Recebeu 1x " + loja.bancoW.produtos[index].getNome() + " de brinde!");
        } else
            System.out.println("Pontuação insuficiente. Junte mais " + (500 - pontuacao) + " pontos para resgatar um brinde.");
    }
}