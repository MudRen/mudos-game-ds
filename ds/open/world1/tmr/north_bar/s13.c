#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIY"�d�~�j�}"NOR"��"HIB"�}��-�G�h"NOR);
 set("long",@LONG 
�o�̪��a���٬O����Ʒƪ��A������S���e�����Y���F�A��
�O�o�̪��a�����G�`�`�b�_�ʡA�ӥB�X�G�S����L�C�����|���|
��@�b��M��Ӭ}���U�ӡE�E
LONG
    );

       set("exits",([      
       "north":__DIR__"s16",  
       "east":__DIR__"s6", 
       "west":__DIR__"s12",
           ]));

	set("objects", ([
		  __DIR__"npc/mucus-odd.c" : 2,
           __DIR__"npc/anthropophagi-monster" :1,
           ]));
 set("no_clean_up", 0);
 setup();
}

