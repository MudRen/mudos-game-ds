#include <room.h>
inherit ROOM;

void create()
{
 set("short","�p��");
 set("long",@LONG
����o��O�����򺮧������D���A���������@�q�Z���A�����L�L
�a�j�ӡA��Ǫ������L�W�Ϯ��۴X�����O��A������F�\�h�@����
��������C
                �~�w��              �~�w��
                �x  �x              �x  �x                     
�w�w�w�w�w�w�w�w��  �x              �x  ���w�w�w�w�w�w�w�w�w
                    �x              �x
                    �x              �x
�w�w�w�w�w�w�w�w�w�w��              ���w�w�w�w�w�w�w�w�w�w�w
LONG
    );
   set("exits",([ 
       "enter":__DIR__"room7",
       "northeast":__DIR__"room5",
   ]));

   set("no_clean_up",0);
   set("outdoors","land");

   setup();
}            
