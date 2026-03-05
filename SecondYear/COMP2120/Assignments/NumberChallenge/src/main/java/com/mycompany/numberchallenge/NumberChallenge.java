
package com.mycompany.numberchallenge;

import java.util.Scanner;

public class NumberChallenge {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.println("How many questions do you want?"); 
        
        int nQuestions = input.nextInt();
        
        Game ob = new Game();
        
        long startTime = System.currentTimeMillis();
        
        for(int i=0; i<nQuestions; i++){
            ob.generateAddQuestion(); 
        }
        
        long endTime = System.currentTimeMillis();;
        
        long totalTime = endTime - startTime;
        System.out.println("You have taken: "+totalTime/1000+" seconds");
        ob.summary();
        
    }
}
