// Room: /u/m/mulder/area/naboo/jungle/jungle2.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG"�˪L"NOR);
	set("long", @LONG
�o�̪������i��ѪŤ��A�𸭿@�K�A�B�\�F�j�����������C�O��o
�̳����˴ˡC�A�J�Ӥ@�ݡA�oı�a�W�G���j�p���P���}�L�C�A���_�Mı�o
�o�̦s�b�@�ǥͪ��D�D�D�D�D
LONG);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"jungle4",
  "south" : __DIR__"jungle3",
  "west" : __DIR__"jungle",
  "east" : __DIR__"jungle19",
]));
	set("world", "undefine");
	set("outdoors","forest");
	set("no_map",1);
	set("no_recall",1);
	set("no_clean_up", 0);
}	
void init()
{
write(HIG"�A�}�l�i�J�˪L�F\n"NOR);
}	

