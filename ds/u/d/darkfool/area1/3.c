// Room: /u/d/darkfool/area1/3.c

inherit ROOM;

void create()
{
	set("short", "街道");
	set("long", @LONG
這裡平坦的路面讓人走在上面非常的舒服，你帶著激賞的眼光低
頭望了望腳下平直俊爽的街道；你可以感受到當初這個鎮的創建者們
所投入的那股熱誠。北邊有一間木造小屋，東方不遠處便是鎮上的廣
場。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"4",
  "north" : __DIR__"5",
  "west" : __DIR__"2",
]));

	setup();
	replace_program(ROOM);
}
