public class Team {
    private Robot[] titular;
    private Robot[] reserva;

    //Lista de robôs do time titular de acordo com "idade"; mais antigos primeiro:
    private Robot[] titularByIdade;

    //Controle sobre a qtd. de robôs em cada time:
    private int indiceT;
    private int indiceR;

    //Construtores:
    public Team() {
        titular = new Robot[6];
        reserva = new Robot[6];
        titularByIdade = new Robot[6];
    }

    public Team(Robot titular[], Robot reserva[]) {
        this.titular = new Robot[6];
        this.reserva = new Robot[6];
        this.titularByIdade = new Robot[6];

        for (int i = 0; i < 6; i++) {
            this.addRobotTitular(titular[i]);
            this.addRobotReserva(reserva[i]);
        }
    }

    public void addRobotTitular(Robot t) {
        titular[indiceT] = t;
        titularByIdade[indiceT] = t;
        indiceT++;
    }

    public void addRobotReserva(Robot r) {
        RobotReserva newRobot = new RobotReserva(r.getNome());
        reserva[indiceR] = newRobot;
        indiceR++;
    }

    public void substitui(Robot t, Robot r) {
        int indext = procuraRobot(t.getNome(), titular);
        int indexti = procuraRobot(t.getNome(), titularByIdade);
        int indexr = procuraRobot(r.getNome(), reserva);

        //Atualiza lista dos robôs por idade; o "novo" robô vai p/ o final da fila e os outros vão uma posição a frente, rumo ao início da fila (r->último->...->2->1->0):
        for (int i = indexti; i < (indiceT - 1); i++)
            titularByIdade[i] = titularByIdade[i + 1];

        titularByIdade[indiceT - 1] = r;
        titularByIdade[indiceT - 1].setPos(t.getPosX(), t.getPosY());

        //A posição onde estava o titular que se quer substituir agora recebe o reserva, entretanto, mantendo a posição que estava:
        titular[indext] = r;
        titular[indext].setPos(t.getPosX(), t.getPosY());

        //A posição onde estava reserva agora recebe o titular, entretanto, mantendo a posição padrão de reserva:
        reserva[indexr] = t;
        reserva[indexr].setPos(-1, -1);
    }

    public void substitui(Robot r) {
        Robot temp = titularByIdade[0];
        int indext = procuraRobot(temp.getNome(), titular);
        int indexr = procuraRobot(r.getNome(), reserva);

        titular[indext] = r;
        titular[indext].setPos(temp.getPosX(), temp.getPosY());

        //Note que nesse caso quem vai pro reserva é o robô mais antigo, o primeiro da fila titularByIdade:
        reserva[indexr] = temp;
        reserva[indexr].setPos(-1, -1);

        //Atualiza lista dos robôs por idade:
        for (int i = 0; i < (indiceT - 1); i++)
            titularByIdade[i] = titularByIdade[i + 1];

        titularByIdade[indiceT - 1] = r;
        titularByIdade[indiceT - 1].setPos(temp.getPosX(), temp.getPosY());
    }

    public int procuraRobot(String nome, Robot team[]) {
        boolean achou = false;
        int i = 0;

        for (i = 0; !achou && i < 6; i++) {
            if (team[i].getNome() == nome)
                achou = true;
        }

        if (achou) return i - 1;
        //Se não achar o robô, ele não está cadastrado no time, então lança uma exceção:
        else throw new RuntimeException();
    }

    //Método para receber os nomes de todos os robôs do time:
    public String getNomesRobos() {
        String string = "TIT: ";
        for (int i = 0; i < indiceT; i++)
            string += titular[i].getNome() + (i != indiceT - 1 ? " | " : "");

        string += "\nRES: ";
        for (int i = 0; i < indiceR; i++)
            string += reserva[i].getNome() + (i != indiceR - 1 ? " | " : "");

        return string;
    }
}