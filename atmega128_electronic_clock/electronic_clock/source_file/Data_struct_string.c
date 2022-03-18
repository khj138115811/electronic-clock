/*
 * Data_struct_string.c
 *
 * Created: 2021-05-21 오전 11:47:57
 *  Author: khs94
 */ 
#include "Data_struct_string.h"

void DA_string_init(volatile DA_String* user_define)
{
	free(user_define->str);
	user_define->str = (char*)calloc(1,sizeof(char));
	user_define->str[0] = '\0';
	user_define->length = 1;
	user_define->append = DA_String_append; 
	user_define->push = DA_push_string;
	user_define->clear = DA_clear_string;
}

void DA_String_append(volatile DA_String* user_define , char c)
{
	user_define->length += 1;
	user_define->str = (char*)realloc(user_define->str,sizeof(char)*user_define->length);
	user_define->str[user_define->length-2] = c;
	user_define->str[user_define->length-1] = '\0';
}

void DA_push_string(volatile DA_String* user_define, char* s)
{
	uint16_t new_length = user_define->length + 1 + strlen(s);
	user_define->str = (char*)realloc(user_define->str,sizeof(char)*(new_length));
	for(uint16_t i = 0; i <= strlen(s); i++)
	{
		user_define->str[user_define->length-2+i] = s[i];
	}
	user_define->str[new_length-1] = '\0';
	user_define->length = new_length;
}

void DA_clear_string(volatile DA_String* user_define)
{
	free(user_define->str);
}