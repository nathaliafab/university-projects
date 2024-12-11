public class Store {
    public DataBaseWeasleys bancoW;

    public Store(DataBaseWeasleys bancoW) {
        this.bancoW = bancoW;
    }

    public void insertProduto(Produto produto) {
        bancoW.insertProduto(produto);
    }

    public void deleteProduto(String nome) throws PIException {
        bancoW.deleteProduto(nome);
    }

    public void venda(Client cliente, String nome, int qtd) throws SIException, PIException {
        int index = bancoW.procuraProduto(nome);
        int estoque = bancoW.produtos[index].getQtd();
        int vendidos = (qtd <= estoque ? qtd : estoque);
        float preco = bancoW.produtos[index].getPreco();

        if (preco * vendidos > cliente.getSaldo())
            throw new SIException(cliente.getNome());

        else {
            bancoW.attEstoque(nome, vendidos);
            cliente.attSaldo(preco * vendidos);
            cliente.attPontuacao(0.1 * preco * vendidos);

            if (cliente.canReceiveGift())
                System.out.println("O cliente pode receber um brinde!");
        }
    }
}