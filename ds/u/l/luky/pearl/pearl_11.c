// Room: /u/l/luky/room/pearl_11.c
#include <ansi.h>
inherit ROOM;
void create()
{
set("short", HIG"�ï]���"NOR);
set("long", @LONG

����                                                   ����
�� :��    �A�����b�j��W�C���~���[�A���Aı�o���ǯh   ��: ��
�� : :�j�¡A�ݵ۪��񥭱`�H�a���ЫΡA�A�}�l���I�Q�b �y: : ��
�� : :�j�o�̶R���a�w�w�U�ӡC�D���V�n�_�����ӥh�C   �y: : ��
�� :��                                               ��: ��
����                                                   ����

LONG
);
set("objects",([
__DIR__"npc/oceaner":1,
]));
set("exits", ([ /* sizeof() == 2 */
"north" : __DIR__"pearl_12",
"south" : __DIR__"pearl_10",
]));
set("no_clean_up", 0);
set("light",1);
setup();
replace_program(ROOM);
}
