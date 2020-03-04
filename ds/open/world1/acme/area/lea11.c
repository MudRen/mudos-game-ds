// Room: /u/a/acme/area/lea11.c

inherit ROOM;

void create()
{
	set("short", "大草原");
	set("long", @LONG
你身處在一望無際的大草原，四周的野草略為高大，行走時便覺得有
點困難，你可聽見春蟬在「知了∼知了∼」的叫著，顯得生氣盎然。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"lea10",
  "northwest" : __DIR__"lea12",
  "southwest" : __DIR__"lea13",
]));
	set("no_clean_up", 0);
     set("outdoors","land");
       set("objects", ([
           __DIR__"npc/nor" : 3,
        ]));

	setup();
	replace_program(ROOM);
}
