public class teste {
    public static void main(String[] args) {
        Circulo c1 = new Circulo();
        Circulo c2 = new Circulo();

        c1.setNome("Circulo 1");
        c2.setNome("Circulo 2");
        c1.setRaio(3);
        c2.setRaio(2);
        c1.calcular();
        c2.calcular();
        c1.exibeDados();
        c2.exibeDados();

    }
}
