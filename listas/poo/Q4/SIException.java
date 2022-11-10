public class SIException extends Exception {
    public SIException(String nome) {
        super("O cliente " + nome + " tem saldo insuficiente. A compra foi interrompida.");
    }
}