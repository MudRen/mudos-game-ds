#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
set("short",HIR"����������"NOR);
set("long",@LONG
�o�̬O�ɶ��P�Ŷ������_�A�b�o�̤w�g����A�^�Y�A
�ӳq�����Ӫ��D���N�b�e��A�o�̦��ۤ@�Ӥp�p�����F�A
�j�j����Ⲵ���ݵۧA�A�n���Q��A���Ǥ���C

LONG);
set("exits",([
"north":__DIR__"time2",
"west":__DIR__"trans",
]));
set("light",1);
set("objects",([
__DIR__"npc/mili" : 1]));
set("no_clean_up",0);
setup();
replace_program(ROOM);
}
