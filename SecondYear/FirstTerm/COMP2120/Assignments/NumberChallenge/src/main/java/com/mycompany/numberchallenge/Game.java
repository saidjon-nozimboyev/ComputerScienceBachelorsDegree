
package com.mycompany.numberchallenge;
import java.util.Scanner;

public class Game {
    int score; 
    Scanner input; 
    String summary=""; //18+20 = 38 : true
    
    public void generateAddQuestion(){
        input = new Scanner(System.in);
        
        int num1 = (int)(Math.random() * 20); 
        int num2 = (int)(Math.random() * 20);
        
        int actualAnswer = num1 + num2;
        
        System.out.println("What is "+num1+" + "+num2+"?");
        int userAnswer = input.nextInt();
        
        summary +="\n"+num1+" + "+num2+" = "+userAnswer+" : "+(actualAnswer == userAnswer);
        
        if(actualAnswer == userAnswer){
            //System.out.println("True");
            score++;
        }else{
            //System.out.println("False");
        }
        
    }
    
    
    public void summary(){
        System.out.println("Your score is: "+score);
        System.out.println("Summary:"+summary);
    
    }
}
