#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","����");

 set("long",@LONG
�A�~�򩹲`�B���U�h, �S�J��F�@�s���~�٭n
�j�����W, �A�߷Q�J�M�A�w�g��o�F, ���藍��N�b
�o�Q���ˤF, �]���A�ĤO���V���W���F�L�h.
LONG
    );
 
 set("exits",(["northeast":__DIR__"en17",
               "southwest":__DIR__"en15",
           ]));
 set("objects",([__DIR__"npc/fox5" : 3,
     ]));
 
 set("no_clean_up", 0);
 setup();
}           
