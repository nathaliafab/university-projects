public class DataBaseWeasleys implements DataBase {
    public Produto[] produtos;

    public DataBaseWeasleys() {
        produtos = new Produto[50];
    }

    public int procuraProduto(String nome) throws PIException {
        boolean achou = false;
        int index = -1;

        for (int i = 0; !achou && i < 50; i++)
            if (produtos[i] != null)
                if (produtos[i].getNome() == nome) {
                    index = i;
                    achou = true;
                }

        if (!achou)
            throw new PIException(nome);

        return index;
    }

    public void insertProduto(Produto produto) {
        for (int i = 0; i < 50; i++)
            if (produtos[i] == null) {
                produtos[i] = produto;
                break;
            }
    }

    public void deleteProduto(String nome) throws PIException {
        produtos[procuraProduto(nome)] = null;
    }

    public void attEstoque(String nome, int qtd) {
        for (int i = 0; i < 50; i++)
            if (produtos[i].getNome() == nome) {
                int estoque = produtos[i].getQtd() - qtd;
                produtos[i].setQtd(estoque);
                break;
            }
    }

    public int gift() {
        float min = Float.MAX_VALUE;
        int index = -1;

        for (int i = 0; i < 50; i++)
            if (produtos[i] != null)
                if (produtos[i].getPreco() <= min && produtos[i].getQtd() > 0) {
                    min = produtos[i].getPreco();
                    index = i;
                }

        if (min == Float.MAX_VALUE)
            throw new RuntimeException(); //Não tem produtos na loja, portanto, não tem brinde

        return index;
    }
}