#include <room.h>
inherit ROOM;

void create()
{
 set("short","�p��");
 set("long",@LONG
�o�̬O���L�P�˪L�����@�q�u�u���d�ڤp���A���b�o�̨�ı�o
�w�R�\�h�A�ݵ��Y�����Ū��ѪŤ߱��]�νw�h�F�C
LONG);
   set("exits",([ 
       "west":__DIR__"room82",
       "northeast":__DIR__"room78",
   ]));

   set("no_clean_up",0);
   set("outdoors","land");

   setup();
}            
