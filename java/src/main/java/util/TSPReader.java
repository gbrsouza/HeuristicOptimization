package util;

import lombok.extern.slf4j.Slf4j;
import problem.TSP;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;

@Slf4j
public class TSPReader {
    public static TSP readInstance(String path){
        TSP tsp = new TSP();

        try{
            File file = new File(path);
            FileReader reader = new FileReader(file);
            BufferedReader bf = new BufferedReader(reader);
            String line;

            while ((line = bf.readLine()) != null){
                if (line.contains("DIMENSION")){
                    int dimension = Integer.parseInt(line.split(" ")[1]);
                    tsp.setDimension(dimension);
                }

                if (line.contains("NODE_COORD_SECTION")){
                    ArrayList<ArrayList<Integer>> data = new ArrayList<ArrayList<Integer>>();
                    for (int i=0; i<tsp.getDimension(); i++){
                        data.add(i, new ArrayList<Integer>(Collections.nCopies(tsp.getDimension(), 0)));
                        data.get(i).set(i, 0);
                    }

                    ArrayList<EuclidianNode> euclidianNodes = new ArrayList<EuclidianNode>();
                    for (int i=0; i<tsp.getDimension(); i++){
                        line = bf.readLine();
                        String[] values = line.split(" ");
                        euclidianNodes.add(new EuclidianNode(Float.valueOf(values[1]), Float.valueOf(values[2])));
                    }

                    for (int i=0; i<tsp.getDimension(); i++){
                        for (int j=0; j<tsp.getDimension(); j++){
                            if (i!=j){
                                data.get(i).set(j, EuclidianNode.calcCostEdge(euclidianNodes.get(i), euclidianNodes.get(j)));
                            }
                        }
                    }

                    tsp.setData(data);
                }

                if (line.contains("EDGE_WEIGHT_SECTION")){
                    ArrayList<ArrayList<Integer>> data = new ArrayList<ArrayList<Integer>>();
                    for (int i=0; i<tsp.getDimension(); i++){
                        data.add(i, new ArrayList<Integer>(Collections.nCopies(tsp.getDimension(), 0)));
                        data.get(i).set(i, 0);
                    }

                    for (int i=0; i<tsp.getDimension(); i++){
                        line = bf.readLine();
                        String[] values = line.split(" ");

                        for (int j=tsp.getDimension()-1; j>i; j--){
                            int value = Integer.parseInt(values[(tsp.getDimension()-i-1)-(j-i)]);
                            data.get(j).set(i, value);
                            data.get(i).set(j, value);
                        }
                    }

                    tsp.setData(data);
                }
                reader.close();
            }

        }catch (IOException e){
            log.error("Não foi possível ler o arquivo "+path);
        }

        return tsp;
    }

}
