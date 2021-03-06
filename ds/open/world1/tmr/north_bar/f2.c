// Room: /open/world1/tmr/north_bar/f2.c

inherit ROOM;

void create()
{
	set("short", "千年古洞-洞穴");
	set("long", @LONG
這裡的地上十分凹凸不平，而且天花板又十分狹窄，一不小
心就會撞到頭。在這裡，你開始遇到了一些看起來十分弱小的野
獸，一不注意，牠就會衝過來偷襲你，請務必小心！
LONG
	);
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/dinosaur.c" : 5,
  __DIR__"npc/dinosaur2.c" : 5,
  __DIR__"npc/dinosaur3.c" : 5,
  __DIR__"npc/mucus-odd.c" : 5,
]));

	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"f1",
  "southeast" : __DIR__"f4",
]));
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
