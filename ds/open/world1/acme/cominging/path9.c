inherit ROOM;

void create()
{
	set("short", "走道");
	set("long", @LONG
在這裡有一個特殊的房間，似乎就是四維之中的”禮房”，裡面不
知道住的是什麼人，好像很神秘的樣子，北邊還有一些房間，不知道又
是做什麼用的了。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
//  "east" : __DIR__"house4",
  "west" : __DIR__"path1",
  "north" : __DIR__"path8",
]));
        set("light",1);

	setup();
	replace_program(ROOM);
}
