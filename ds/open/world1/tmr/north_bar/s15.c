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
       "west":__DIR__"s14", 
           ]));
	set("objects", ([
      __DIR__"npc/anthropophagi-monster" : 3,
      __DIR__"npc/horn-monster" : 3,
    __DIR__"npc/predator-monster" : 3,
    __DIR__"npc/rough-monster" : 3,
    __DIR__"npc/single-monster" : 3,

 ]));
 set("no_clean_up", 0);
 setup();
}

