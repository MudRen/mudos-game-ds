#include <ansi.h>;
inherit ROOM;
void create()
{
        set("short", HIC"������������"NOR);
        set("long", @LONG
�o�̬O��������������A�o�̦p�P����A�\�]�\�h�_�Ყ��A���o�X
�}�}�g�H���M���A�j�����e���@�����l�A�����l���ƨӰ}�}�e�ȭ��A���
���󭻷ϸ͸ͪ��A�p�ڦp�ۡC
LONG
        );
        set("exits", ([ 
  "east"  : __DIR__"room27",
  ]));
        set("no_recall",1);
        set("objects", ([
 __DIR__"npc/left" : 1,
]));
        set("light",1);
        setup();
        replace_program(ROOM);
}
