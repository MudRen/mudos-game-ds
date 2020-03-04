// Room: /u/s/slency/area/ugelan/innroom1.c

inherit ROOM;

void create()
{
	set("short", "客房");
	set("long", @LONG
這裡是一間普通的客房，桌上有一壺水及一些小點心供房客們食用
，裡面還有一個大床舖，看起來柔軟又舒服，你不禁有點羨慕住在這裡
的旅客們可以有如此的享受。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"inn",
]));
	set("no_clean_up", 0);
        set("light",1);
	setup();
	replace_program(ROOM);
}
