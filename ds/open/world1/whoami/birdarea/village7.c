#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�y����"NOR"��"HIW"�n����"NOR);
 set("long",@LONG
�A�~�򩹫n��, �Ө�F�n����, �o�̪��H�Өө���, �b�A��
���䦳�@�a�ȴ�, �A�i�H�h���𮧤@�|, �o�����ѥ_��n�����U
�h.
LONG
    );
 
 set("exits",(["north":__DIR__"village5",
               "south":__DIR__"village10",
               "west":__DIR__"village8",
           ]));
  set("objects",([__DIR__"npc/villager" : 1+random(2),
     ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        

