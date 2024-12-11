public class PIException extends Exception {
    public PIException(String nome) {
        super("O produto " + nome + " não está a venda na loja.");
		}
}