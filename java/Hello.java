public class Hello {
    public static void main(String[] args) {
        String s = "";
        for (int i = 0; i < 6000; i++) {
            s += "Hello, world!";
            System.out.println(s);
        }
    }
}