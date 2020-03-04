// Room: /u/a/acme/area/pass4.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
這裡是一條崎嶇不平的山路，走來令人腳底發軟，北邊是一望無際的
大草原，遠遠自東瞧去，隱約可見天城的城門，西南邊可離開天山。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"lea14",
  "east" : __DIR__"pass3",
  "southwest" : __DIR__"pass5",
]));
      set("objects",([
         __DIR__"npc/traveler2.c" : 3,
      ]));
	set("no_clean_up", 0);
    set("outdoors","land");

	setup();
	replace_program(ROOM);
}
