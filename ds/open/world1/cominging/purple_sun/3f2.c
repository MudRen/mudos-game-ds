// 紫陽山第三層

inherit ROOM;

void create()
{
	set("short", "紫陽山");
	set("long", @LONG
你走在山路上，不停的往前走，走向山上，路旁邊還不時的冒出幾
株生命力旺盛的小草，路上的塵沙經過強風的吹打，使得路上有些模糊
不清。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"3f1.c",
  "northwest" : __DIR__"3f3.c",
]));
	set("world", "past");
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}
