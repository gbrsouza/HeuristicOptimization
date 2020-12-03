import problem.TSP;
import util.TSPReader;

public class Application {
    public static void main(String[] args){
        String path = "C:\\Users\\gabri\\Documents\\codigos\\HeuristicOptimization\\java\\src\\main\\resources\\instances\\berlin52.tsp";
        TSP tsp = TSPReader.readInstance(path);
        System.out.println(tsp.getDimension());
    }
}
