// Room: /open/world1/dragoncity/northgate2.c

inherit ROOM;

void create()
{
	set("short", "玄武外門");
	set("long", @LONG
這裡是磐龍城的北城門的外城門，只見城門上方是三個大字。

[1;36m                      玄武門
[0m
近年來虎人族屢次侵犯磐龍城，故這兒把守相當嚴密，一些少帥
軍的官兵們正在盤查要離開磐龍城的人。兩邊往北延伸是一望無
際的大草原。
LONG
	);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"caodi4",
  "west" : __DIR__"caodi5",
  "south" : __DIR__"northgate1",
  "north" : __DIR__"caodi1",
]));
	set("no_clean_up", 0);
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}
