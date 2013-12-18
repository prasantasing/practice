/*
 * Copyright (c) 1995-1997 Sun Microsystems, Inc. All Rights Reserved.
 *
 * Permission to use, copy, modify, and distribute this software
 * and its documentation for NON-COMMERCIAL purposes and without
 * fee is hereby granted provided that this copyright notice
 * appears in all copies. Please refer to the file "copyright.html"
 * for further important copyright and licensing information.
 *
 * SUN MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE SUITABILITY OF
 * THE SOFTWARE, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 * TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE, OR NON-INFRINGEMENT. SUN SHALL NOT BE LIABLE FOR
 * ANY DAMAGES SUFFERED BY LICENSEE AS A RESULT OF USING, MODIFYING OR
 * DISTRIBUTING THIS SOFTWARE OR ITS DERIVATIVES.
 */

public class FieldAccess {
  static int si;
  String s;

  private native void accessFields();
  public static void main(String args[]) {
    FieldAccess c = new FieldAccess();
    FieldAccess.si = 100;
    c.s = "abc";
    c.accessFields();
    System.out.println("In Java:");
    System.out.println("  FieldAccess.si = " + FieldAccess.si);
    System.out.println("  c.s = \"" + c.s + "\"");
  }
  static {
    System.loadLibrary("MyImpOfFieldAccess");
  }
}
