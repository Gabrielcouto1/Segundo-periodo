public class Circulo {
    private double raio,circunferencia,area;
    private String nome;

    public void setRaio(double r){
        if(r>0)
            raio=r;
    }

    public void setNome(String name){
        nome = name;
    }
    
    public String getNome(){
        return nome;
    }

    public double getRaio(){
        return raio;
    }

    public void calcular(){
        area = (3.1415926)*(raio*raio);
        circunferencia = 2*3.1415926*raio;
    }

    public void exibeDados(){
        //for(int i=0;i<40;i++)
          //  System.out.print("=");
        System.out.println("\n\nDados do circulo "+"'"+nome+"' ");
        System.out.println("Raio : "+raio);
        System.out.println("Diametro : "+raio*2);
        System.out.println("Circunferencia : "+circunferencia);
        System.out.println("Area : "+area+"\n\n");
       // for(int i=0;i<40;i++)
         //   System.out.print("=");
    }
}
