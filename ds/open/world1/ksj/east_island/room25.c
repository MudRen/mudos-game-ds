#include <room.h>
inherit ROOM;

void create()
{
 set("short","�A��");
 set("long",@LONG
�غ��_�l���A�СA�Ф����L�L�����A�`�񪺽_�l�H�۷L���j�L�
곧@�T�A�Ф����X���е�b�_�O���X�S�C
LONG);
   set("exits",([ 
       "east":__DIR__"room20",
       "west":__DIR__"room30",
       "south":__DIR__"room24",
   ]));

   set("no_clean_up",0);
   set("outdoors","land");
   set("objects",([
      __DIR__"npc/frog":3,
     ]) );
   setup();
}            
