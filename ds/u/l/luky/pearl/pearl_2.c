// Room: /u/l/luky/room/pearl_2.c
#include <path.h>
inherit ROOM;
void create()
{
set("short","[1;32m�ï]��[m");
set("long", @LONG

����                                                   ����
�� :��    ��i��î���O�@���c�ؼ��x�����H�A�u���H��   �Ģj��
�� : :�j�H�۫H�o�O�b�����U�T�U�h���ت��a��C���䪺 �y: �j��
�� : :�j����{ģ�ۤC�m�����~�A�A�o�{�o�ǳ���~�M�� �y: �j��
�� :��  �άï]���Ӧ����I�F��O�����j���C         �âj��
����                                                   ����

LONG
);
set("exits", ([ /* sizeof() == 3 */
"north" : __DIR__"pearl_21",
"south" : __DIR__"pearl_3",
"east" : __DIR__"pearl_1",
]));
set("objects",([
__DIR__"npc/swimmaster": 1,
]));

set("no_clean_up", 0);
set("light",1);
setup();
}
