#include <room.h>
inherit ROOM;

void create()
{
 set("short","�p�u�l");
 set("long",@LONG
�o���\�F�@�Ӥp�u�l�A�u�l�̦��ӦѱC�C���b���۶��{�A�u�l��
���O�@���}�ª��p��ΡA�q�Τl�ϧw�_�X�}�}�շϡC
LONG);
   set("exits",([ 
       "west":__DIR__"room13",
   ]));

   set("no_clean_up",0);
   set("outdoors","land");
   set("objects",([
      __DIR__"npc/old-woman":1,
     ]));
   setup();
}            
