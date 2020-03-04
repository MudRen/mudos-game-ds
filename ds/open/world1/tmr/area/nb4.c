// Room: /u/t/tmr/area/nb4.c

inherit ROOM;

void create()
{
	set("short", "鶴子橋端");
	set("long", @LONG
鶴子橋到了這裡就已到底，往北可看到五間竹房，離此尚有一大段距
離，就是當今輕功最高的人也難一蹴而及。在你西邊停著一艘小船在橋邊
，看來可以上去瞧瞧。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"nb3",
  "enter" : __DIR__"bship",
]));
	set("outdoors","land");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
