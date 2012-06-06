/*
 ============================================================================
 Name        : base.h
 Author      : Qiniu Developers
 Version     : 1.0.0.0
 Copyright   : 2012(c) Shanghai Qiniu Information Technologies Co., Ltd.
 Description : 
 ============================================================================
 */

#ifndef QBOX_BASE_H
#define QBOX_BASE_H

#include <stdlib.h>
#include <string.h>

/*============================================================================*/
/* func QBox_Zero */

#define QBox_Zero(v)		memset(&v, 0, sizeof(v))

/*============================================================================*/
/* func QBox_snprintf */

#if defined(_MSC_VER)
#define QBox_snprintf		_snprintf
#else
#define QBox_snprintf		snprintf
#endif

/*============================================================================*/
/* type QBox_Int64 */

#ifdef WIN32
typedef _int64 QBox_Int64;
#else
typedef long long QBox_Int64;
#endif

/*============================================================================*/
/* type QBox_Bool */

typedef int QBox_Bool;

enum {
	QBox_False = 0,
	QBox_True = 1
};

/*============================================================================*/
/* type QBox_Error */

typedef struct _QBox_Error {
	int code;
	const char* message;
} QBox_Error;

/*============================================================================*/
/* type QBox_Count */

typedef long QBox_Count;

QBox_Count QBox_Count_Inc(QBox_Count* self);
QBox_Count QBox_Count_Dec(QBox_Count* self);

/*============================================================================*/
/* func QBox_String_Concat */

char* QBox_String_Concat2(const char* s1, const char* s2);
char* QBox_String_Concat3(const char* s1, const char* s2, const char* s3);
char* QBox_String_Concat(const char* s1, ...);

/*============================================================================*/
/* func QBox_String_Encode */

char* QBox_String_Encode(const char* s);

/*============================================================================*/
/* func QBox_QueryEscape */

char* QBox_QueryEscape(const char* s, QBox_Bool* fesc);

/*============================================================================*/
/* func QBox_Seconds */

QBox_Int64 QBox_Seconds();

/*============================================================================*/
/* type QBox_Buffer */

typedef struct _QBox_Buffer {
	char* buf;
	char* curr;
	char* bufEnd;
} QBox_Buffer;

void QBox_Buffer_Init(QBox_Buffer* self, size_t initSize);
void QBox_Buffer_Reset(QBox_Buffer* self);
void QBox_Buffer_Cleanup(QBox_Buffer* self);

const char* QBox_Buffer_CStr(QBox_Buffer* self);

size_t QBox_Buffer_Len(QBox_Buffer* self);
size_t QBox_Buffer_Write(QBox_Buffer* self, const void* buf, size_t n);
size_t QBox_Buffer_Fwrite(void *buf, size_t size, size_t nmemb, void *self);

/*============================================================================*/
/* func QBox_Null_Fwrite */

size_t QBox_Null_Fwrite(void *buf, size_t size, size_t nmemb, void *self);

/*============================================================================*/

#endif /* QBOX_BASE_H */

