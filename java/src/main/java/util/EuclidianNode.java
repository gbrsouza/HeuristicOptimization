package util;


import lombok.AllArgsConstructor;
import lombok.Data;

@Data
@AllArgsConstructor
public class EuclidianNode {

    private Float x;
    private Float y;

    public static int calcCostEdge (EuclidianNode a, EuclidianNode b){
        float xd = a.getX() - b.getX();
        float yd = a.getY() - b.getY();
        int dij = (int) Math.round(Math.sqrt(xd*xd + yd*yd));
        return dij;
    }
}
