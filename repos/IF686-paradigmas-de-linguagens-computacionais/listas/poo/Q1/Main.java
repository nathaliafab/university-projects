class Main {
    public static void main(String[] args) {
        Robot[] robosT = new Robot[6];
        robosT[0] = new Robot("Tit0", 1, 0, 0);
        robosT[1] = new Robot("Tit1", 2, 10, 5);
        robosT[2] = new Robot("Tit2", 3, 6, 6);
        robosT[3] = new Robot("Tit3", 4, 9, 8);
        robosT[4] = new Robot("Tit4", 5, 16, 12);
        robosT[5] = new Robot("Tit5", 6, 0, 3);

        RobotReserva[] robosR = new RobotReserva[6];
        robosR[0] = new RobotReserva("Res0");
        robosR[1] = new RobotReserva("Res1");
        robosR[2] = new RobotReserva("Res2");
        robosR[3] = new RobotReserva("Res3");
        robosR[4] = new RobotReserva("Res4");
        robosR[5] = new RobotReserva("Res5");

        Team timeA = new Team(robosT, robosR);
        Team timeB = new Team();

        timeB.addRobotTitular(robosT[0]);
        timeB.addRobotTitular(robosT[3]);
        timeB.addRobotReserva(robosR[5]);
        timeB.addRobotReserva(robosR[2]);

        System.out.println("Robôs no time B:");
        System.out.println(timeB.getNomesRobos());

        timeB.substitui(robosT[3], robosR[2]);
        System.out.println("\nRobôs no time B depois da troca:");
        System.out.println(timeB.getNomesRobos());

        System.out.println("\nRobôs no time A:");
        System.out.println(timeA.getNomesRobos());

        timeA.substitui(robosR[3]);
        System.out.println("\nRobôs no time A depois da troca:");
        System.out.println(timeA.getNomesRobos());

        //Essa última é pra testar se ele está removendo de fato o mais antigo
        timeA.substitui(robosR[2]);
        timeA.substitui(robosR[5]);
        timeA.substitui(robosR[4]);
        timeA.substitui(robosT[2]);
        timeA.substitui(robosT[0]);
        timeA.substitui(robosT[1]);
        System.out.println("\nRobôs no time A depois de várias trocas:");
        System.out.println(timeA.getNomesRobos());
    }
}