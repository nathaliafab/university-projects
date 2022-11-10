class Main {
    public static void main(String[] args) {
        Robot robo1 = new Robot("Robo1", "End1", 111);
        Robot robo2 = new Robot("Robo2", "End2", 111);
        Adult adulto1 = new Adult("Adulto1", "End3", 222, "Engenheiro");
        Child crianca1 = new Child("Crianca1", "End3", 222, "Carrinho");

        System.out.println("--- Greeting robô mesmo CEP ---");
        robo1.greet(robo2);
        System.out.println("\n--- Greeting robô CEP diferente ---");
        robo1.greet(adulto1);

        adulto1.addKid(crianca1);

        System.out.println("\n--- Greeting 1 criança ---");
        crianca1.greet(robo1);
        System.out.println("\n--- Greeting 2 criança ---");
        crianca1.greet(robo2);
        System.out.println("\n--- Amigos criança ---");
        crianca1.showFriends();

        System.out.println("\n--- Brinquedo antigo ---\n" + crianca1.getBrinquedo());
        crianca1.setBrinquedo("Boneco");
        System.out.println("\n--- Brinquedo novo ---\n" + crianca1.getBrinquedo());

        System.out.println("\n--- Greeting 3 criança ---");
        crianca1.greet(adulto1);
        System.out.println("\n--- Greeting 1 adulto ---");
        adulto1.greet(crianca1);
        System.out.println("\n--- Greeting 2 adulto ---");
        adulto1.greet(crianca1);
        System.out.println("\n--- Amigos adulto ---");
        adulto1.showFriends();
        System.out.println("\n--- Amigos criança ---");
        crianca1.showFriends();
    }
}