public interface DataBase {
    void insertProduto(Produto produto);
    void deleteProduto(String nome) throws PIException;
    void attEstoque(String nome, int qtd);
}