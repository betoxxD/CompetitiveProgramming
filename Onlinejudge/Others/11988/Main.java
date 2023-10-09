import java.io.*;


public class Main {

    static class Node {
        String content;
        Node next;

        Node() {
            content = "";
            next = null;
        }
    }

    static String input;
    static BufferedReader sc;
    static BufferedWriter bw;
    static Node head;
    static Node finish;
    static Node currentNode;
    static Node aux;
    static boolean isHome;
    static String nextWord;

    static void printResult() {
        while (head != null) {
            try {
                bw.write(head.content);
            } catch (IOException e) {
            }
            head = head.next;
        }
        try {
            bw.write("\n");
            bw.flush();
        } catch (IOException e) {
        }
    }

    static void makePhrase() {
        head = new Node();
        finish = new Node();
        head.next = finish;
        nextWord = "";
        aux = head;
        for (int i = 0; i < input.length(); i++) {
            if (input.charAt(i) == '[' || input.charAt(i) == ']') {
                currentNode = new Node();
                if (isHome) {
                    currentNode.content = nextWord;
                    currentNode.next = head;
                    head = currentNode;
                    nextWord = "";
                } else {
                    currentNode.content = nextWord;
                    finish.next = currentNode;
                    finish = currentNode;
                    nextWord = "";
                }
                if (input.charAt(i) == '[') {
                    isHome = true;
                } else {
                    isHome = false;
                }
            } else {
                nextWord += input.charAt(i);
            }
        }
        currentNode = new Node();
        if (!isHome) {
            currentNode.content = nextWord;
            finish.next = currentNode;
            finish = currentNode;
        } else {
            currentNode.content = nextWord;
            currentNode.next = head;
            head = currentNode;
        }
    }

    static void readData() {

        sc = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        while (true) {
            try {
                if (!((input = sc.readLine()) != null && input.length() != 0)) break;
            } catch (IOException e) {

            }
            makePhrase();
            printResult();
        }
    }

    public static void main(String[] args) {
        readData();
    }
}