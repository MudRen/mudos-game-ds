// Room: /u/l/luky/room/pearl_13.c
#include <ansi.h>
inherit ROOM;

void create()
{
set("short", HIG"�ï]���"NOR);
set("long", @LONG

[31m                             ��[m
����                    [1;33m��[43m������[1;40;33m��[m                     ����
�� :��    �o�̬O�ï]���C�o����V�n�_�����A�ѩ�o   ��: ��
�� : :�j�̪����𧡬O�ѵo�����ï]�ҫغc�Ӧ����A�ҥH �y: : ��
�� : :�j�Y�ϬO�b�����]��M�����ݨ���V�C�A�ݨ��_�� �y: : ��
�� :��  ���B���Ӥj�ؿv���A�ٳƦ��G�Q�����Y�C         ��: ��
����                                                   ����


LONG
	);
set("objects",([
__DIR__"npc/oceaner":1,
__DIR__"npc/oceaner":1,
]));
set("exits", ([ /* sizeof() == 2 */
"north" : __DIR__"pearl_14",
"south" : __DIR__"pearl_12",
]));
set("no_clean_up", 0);
set("light",1);
setup();
replace_program(ROOM);
}
