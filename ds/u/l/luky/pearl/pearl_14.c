// Room: /u/l/luky/room/pearl_14.c
#include <ansi.h>
inherit ROOM;
void create()
{
set("short", HIG"�ï]���ਤ"NOR);
set("long", @LONG

[1;33m                           �y[31m��[m
  �A�ݨ��_�観�y�Ȧ�[1;33m ��[43m������������[40;37m��[m  �ӧA�����h�O�@���j
�Ŧa�C�A�V�F��h[1;33m     [43m�m�ХХХХХ� [40;37m�m[m �O�����ӫ~��������
�ߡC            [1;33m���e�i[43m�e�i�e�i�e�i�e[40m�i�e[37m��[m
�ġġġġġġġ�[1;33;43m�i     ��   ��   ��     [37m�i[m�ġġġġġġġġ�
"  .   -         :[43;30m��  ��[1;37m �����Ȧ�[0;30;43m ��  ��[m:  -       -  '    "
:      -         :�y[43;30m       ����       [m�j:  -       -    "  :
= ."   -       - :�y[1;43;33m  �� ��[0;30m�p�i[1;33;43m�� ��  [m�j:  -       -       =
==-  " -       - :�y[1;43;32m �ݡ�  [0;30m�p�i[1;43;32m  �ݡ� [m�j:  -       - .   -==
�ááááááááááááá�  �áááááááááááááá�
LONG
);
set("objects",([
__DIR__"npc/sightseer":1,
]));
set("exits", ([ /* sizeof() == 4 */
//"north" : __DIR__"pearl_30",      
"west" : __DIR__"pearl_31",
"south" : __DIR__"pearl_13",
"east" : __DIR__"pearl_15",
]));
set("no_clean_up", 0);
set("light",1);
setup();
replace_program(ROOM);
}
