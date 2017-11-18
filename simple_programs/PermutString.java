import java.io.*;
import java.util.*;

public class PermutString{

 public static void main(String args[])
 {
   Scanner in  = new Scanner(System.in);
   String str = in.next();
	ArrayList<String> all = permutAll(str);
	for(String a:all)
		System.out.println(" "+a+" ");
 }

 public static ArrayList<String> permutAll(String str)
 {
  ArrayList<String> permutations = new ArrayList<String> (); 
  if(str == null)
  {
   return null;
  } 
  else if(str.length() == 0)
  {
   permutations.add("");
   return permutations;  
  }

  char first = str.charAt(0);
  String remainder = str.substring(1);
  ArrayList<String> words = permutAll(remainder);
  for(String word:words)
  {
    for(int i=0;i<=word.length();i++)
    {
   	permutations.add(insertCharAt(word,first,i)); 
    }
  }
	 return permutations;
 }

 public static String insertCharAt(String word, char first, int i)
 {
   String start = word.substring(0,i);
   String end  =  word.substring(i);
   return start + first +end; 
 }

}