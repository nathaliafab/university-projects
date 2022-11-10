class Main {
    public static void main(String[] args) {
        DataBaseWeasleys banco = new DataBaseWeasleys();
        Produto p1 = new Produto("Mouse", 15, 50);
        Produto p2 = new Produto("Teclado 1", 100, 95000);
        Produto p3 = new Produto("Teclado 2", 3, 130);
        Produto p4 = new Produto("PC 1", 35, 4500);
        Produto p5 = new Produto("PC 2", 150, 1500);
        Store loja = new Store(banco);
        Client cliente1 = new Client("Lari", "V", 90000);

        loja.insertProduto(p1);
        loja.insertProduto(p2);
        loja.insertProduto(p3);
        loja.insertProduto(p4);
        loja.insertProduto(p5);

        System.out.println("1) Compra sem pontuação para brinde:");

        try {
            loja.venda(cliente1, "PC 1", 1);
            System.out.println("Saldo do cliente1 após compra 1: " + cliente1.getSaldo());
            System.out.println("Pontuação do cliente1 após compra 1: " + cliente1.getPontuacao());

        } catch (SIException e) {
            System.out.println(e.getMessage());
        } catch (PIException e) {
            System.out.println(e.getMessage());
        }

        System.out.println("\n2) Compra com pontuação para brinde:");

        try {
            loja.venda(cliente1, "PC 2", 2);
            System.out.println("Saldo do cliente1 após compra 2: " + cliente1.getSaldo());
            System.out.println("Pontuação do cliente1 após compra 2: " + cliente1.getPontuacao());

        } catch (SIException e) {
            System.out.println(e.getMessage());
        } catch (PIException e) {
            System.out.println(e.getMessage());
        }

        System.out.println("\n3) Recebimento do brinde:");
        cliente1.getGift(loja);

        System.out.println("\n3.5) Tentativa de receber brinde:");
        cliente1.getGift(loja);

        System.out.println("\n4) Compra com saldo insuficiente:");

        try {
            loja.venda(cliente1, "Teclado 1", 1);
            System.out.println("Saldo do cliente1 após compra 3: " + cliente1.getSaldo());
            System.out.println("Pontuação do cliente1 após compra 3: " + cliente1.getPontuacao());

        } catch (SIException e) {
            System.out.println(e.getMessage());
        } catch (PIException e) {
            System.out.println(e.getMessage());
        }

        try {
            loja.deleteProduto("Teclado 2");

        } catch (PIException e) {
            System.out.println(e.getMessage());
        }

        System.out.println("\n5) Compra de produto inexistente:");

        try {
            loja.venda(cliente1, "Teclado 2", 1);
            System.out.println("Saldo do cliente1 após compra 3: " + cliente1.getSaldo());
            System.out.println("Pontuação do cliente1 após compra 3: " + cliente1.getPontuacao());

        } catch (SIException e) {
            System.out.println(e.getMessage());
        } catch (PIException e) {
            System.out.println(e.getMessage());
        }
    }
}