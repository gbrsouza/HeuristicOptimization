package problem;

import lombok.Data;

import java.util.ArrayList;
import java.util.Collections;

@Data
public class TSP {

    private int dimension;
    private int sizeSolution;

    private ArrayList<Integer> bestSolution;
    private ArrayList<ArrayList<Integer>> data;
    private int bestCost;

    public ArrayList<Integer> generateRandomSolution(){
        ArrayList<Integer> solution = new ArrayList<Integer>();
        for (int i=0; i<dimension; i++){
            solution.add(i);
        }
        Collections.shuffle(solution);
        solution.add(solution.get(0));
        return solution;
    }

    public int costOfSolution(ArrayList<Integer> solution){
        int cost = 0;
        for (int i=0; i<solution.size()-1; i++){
            cost += this.data.get(i).get(i+1);
        }
        return cost;
    };
}
