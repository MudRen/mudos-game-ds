#include <room.h>
inherit ROOM;

void create()
{
 set("short","�A��");
 set("long",@LONG
�غ��_�l���A�СA�Ф����L�L�����A�`�񪺽_�l�H�۷L���j�L�
곧@�T�A�Ф����ӥi�H�ݨ�d�ϷȹL�C
LONG);
   set("exits",([ 
       "east":__DIR__"room25",
       "west":__DIR__"room35",
       "south":__DIR__"room29",
   ]));

   set("no_clean_up",0);
   set("outdoors","land");
   set("objects",([
      __DIR__"npc/loach":2,
     ]) );
   setup();
}            
