// Room: /u/t/tmr/area/lake-road3.c
#include <path.h>

#include <room.h>
inherit DOOR;
inherit ROOM;

void create()
{
	set("short", "�˪L�p�|");
	set("long", @LONG
�@���˪L�����p�|�A�|�P���F�A�񮼩ު��[���ˡA���e������ΡA�P
��s�ˬ��X�A�X�W���������B�쭻�B����B�췬�B�����F�X��M�U�����B
��P�B���a�B�....���ƺءA���i�T�|�C���F�n��L����A�����s�D�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"woodhouse",
   "southeast":ACME_PAST"bonze/b1",
  "northwest" : __DIR__"lake-road2",
]));
       create_door("enter", "���", "out", DOOR_CLOSED);
	set("item_desc", ([ /* sizeof() == 1 */
//  "enter" : (: look_door,     "enter" :),
]));
	set("outdoors","forest");
	set("no_clean_up", 0);
	set("no_map",1);
	setup();
//    replace_program(ROOM);
}
