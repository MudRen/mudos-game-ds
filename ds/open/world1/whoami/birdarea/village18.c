#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
 set("short",HIR"�y����"NOR"��"HIW"�p���"NOR);
 set("long",@LONG
�o�̬O�������a, �A�|�P�ݬ�, �o���\�ǧ�������Ϋ~, �A
ť��γ��W���ǳ\�ݮ��n, �L�̹�A���X�{����Y�åB������, 
�A�̦n���I���}�o.
LONG
    );
 
 set("exits",(["west":__DIR__"village15",
              ]));
 set("item_desc",([
        "�γ�":"�A�ݤF�ݫγ��A�oı�S����S�O��..\n
               (�A�J�Ӥ@�Q�A�o�̬O�Ǥ���M���򳣬ݤ���)\n", 
    ]));
 
 set("objects",([__DIR__"npc/child" : 1,
                 __DIR__"npc/villager2" : 1,
               ]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
}
