// Room: /u/l/luky/room/pearl_24.c
#include <ansi.h>
inherit ROOM;
void create()
{
set("short", HIM"����j�D"NOR);
set("long", @LONG

����                                                   ����
�� :��    �o��������Ǫ����F�C���C�⪺�U������A�A   ��: ��
�� : :�j���Q�K�@��^�a������A�i�O�S�ȳQ�O�H�ݨ�A �y: : ��
�� : :�j�u�n�����F�o�ө��Y�C��_�観�y���R���ؿv�� �y: : ��
�� :��  �A�n���ƨӰ}�}�������C                       ��: ��
����                                                   ����

LONG
);
set("exits", ([ /* sizeof() == 2 */
"north" : __DIR__"pearl_23",
"south" : __DIR__"pearl_6",
]));
set("no_clean_up", 0);
set("light",1);
setup();
replace_program(ROOM);
}
