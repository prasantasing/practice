package com.example.doubleLinklist;
public class Link {
  public long dData; // data item

  public Link next; // next link in list

  public Link previous; // previous link in list

  public Link(long d)
  {
    dData = d;
  }

  public void displayLink(){
    System.out.print(dData + " ");
  }

}