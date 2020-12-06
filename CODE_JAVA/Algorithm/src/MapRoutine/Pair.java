package MapRoutine;

public class Pair<A, B> 
{
    public final A x;
    public final B y;

    public Pair(A a, B b)
    {
        x = a;
        y = b;
    }

    public String toString()
    {
        return "(" + x + "," + y + ")";
    }
}