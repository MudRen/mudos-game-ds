// Room: /u/t/tmr/area/woodhouse.c

#include <room.h>
inherit ROOM;
inherit DOOR;

void create()
{
	set("short", "���");
	set("long", @LONG
���u�ί��л\�ۡA�o���n�e���A������G�C�󤤱��@�T�L�W�p�e�A�]
�@�i�դ�׺f�C�๹���C���b�C�աA����ټƶ��A�׫Ǧb���C�V���]
�⮰����A���~�@���ˮ|�A���䳣���f�i�B�@�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"lake-road3",
]));
	set("item_desc", ([ /* sizeof() == 1 */
//  "out" : (: look_door,     "out" :),
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/chiou" : 1,
]));
	set("light",1);
	set("no_clean_up", 0);

	setup();
      create_door("out", "���", "enter", DOOR_CLOSED);
}
