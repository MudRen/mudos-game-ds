inherit ROOM;

void create()
{
	set("short", "走道");
	set("long", @LONG
這裡是走道的開端，如果你一直往北走，經過一些路，就會直達了
縣太爺的衙堂，裡面有許多的護衛，這邊的走道似乎大了許多，旁邊也
有許多的房間，地板偶爾出現幾個破洞，可以看的見下面好像埋著些酒
，大概是廚子儲起來以備以後之用。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"path9",
  "west" : __DIR__"path6",
  "north" : __DIR__"path2",
  "south" : __DIR__"yidoor",
]));
        set("light",1);

	setup();
	replace_program(ROOM);
}
