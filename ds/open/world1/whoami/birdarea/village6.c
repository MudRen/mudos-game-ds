#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�y����"NOR"��"HIW"��Q"NOR);
 set("long",@LONG
�b�A���e�O�@�a�y������Q, ���@����Y�j��, �p��p����
�ӤH, ���b���u�u���ݵۧA, �o�̪��\�], ���M�٤��W�ܵ��R, 
���L�F��o����.
LONG
    );
 
 set("exits",(["west":__DIR__"village5",
               ]));
 set("objects",([__DIR__"npc/shopman" : 1,
     ]));
 set("room_type","shop");
 set("light",1);
 set("no_clean_up", 0);
 setup();
}        

