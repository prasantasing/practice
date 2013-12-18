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
#include <stdio.h>
#include <jni.h>
#include "FieldAccess.h" 

JNIEXPORT void JNICALL Java_FieldAccess_accessFields(JNIEnv *env, jobject obj)
{
  jclass cls = (*env)->GetObjectClass(env, obj);
  jfieldID fid;
  jstring jstr;
  const char *str;
  jint  ji;

  printf("In C:\n");

  fid = (*env)->GetStaticFieldID(env, cls, "si", "I");
  if (fid == 0)
    return;
  ji = (*env)->GetStaticIntField(env, cls, fid);
  printf("  FieldAccess.si = %d\n", ji);
  (*env)->SetStaticIntField(env, cls, fid, 200);
  
  fid = (*env)->GetFieldID(env, cls, "s", "Ljava/lang/String;");
  if (fid == 0)
    return;
  jstr = (*env)->GetObjectField(env, obj, fid);
  str = (*env)->GetStringUTFChars(env, jstr, 0);
  printf("  c.s = \"%s\"\n", str);
  (*env)->ReleaseStringUTFChars(env, jstr, str);

  jstr = (*env)->NewStringUTF(env, "123");
  (*env)->SetObjectField(env, obj, fid, jstr);
}
