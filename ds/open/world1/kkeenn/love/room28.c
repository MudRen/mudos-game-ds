#include <ansi.h>;
inherit ROOM;
void create()
{
        set("short", HIC"�������k����"NOR);
        set("long", @LONG
�o�̬O���������k����A�o�̦p�P����A�\�]�\�h�_�Ყ��A���o�X
�}�}�g�H���M���A�j�����e���@�Ȭ��l�A�Ȭ��l���ƨӰ}�}���᭻�A���
���󭻷ϸ͸ͪ��A�p�ڦp�ۡC
LONG
        );
        set("exits", ([ 
  "west"  : __DIR__"room27",
  ]));
        set("no_recall",1);
        set("objects", ([
 __DIR__"npc/right" : 1,
]));
        set("light",1);
        setup();
        replace_program(ROOM);
}
