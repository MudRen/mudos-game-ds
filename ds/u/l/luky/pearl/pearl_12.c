// Room: /u/l/luky/room/pearl_12.c
#include <ansi.h>
inherit ROOM;
void create()
{
set("short", HIG"�ï]���"NOR);
set("long", @LONG

����                                                   ����
���y��    �o�̬O�ѹp��������D�C�ǻ��o�̴N�O�l   ��: ��
���y :�j��N���o���a�A�G�����ֶɤߩ��p��W�j�G�N�� �y: : ��
���y :�j�I�k�̳��E���󦹡A��ت��N�O���F�����l��N �y: : ��
���y��  �����K�C                                     ��: ��
����                                                   ����

LONG
);
set("exits", ([ /* sizeof() == 3 */
"west" : __DIR__"pearl_26",
"south" : __DIR__"pearl_11",
"north" : __DIR__"pearl_13",
]));
set("no_clean_up", 0);
set("light",1);
setup();
replace_program(ROOM);
}
