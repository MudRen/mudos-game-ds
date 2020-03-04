// Room: /u/a/acme/area3/p20.c

inherit ROOM;

void create()
{
	set("short", "客房");
	set("long", @LONG
這裡是施府的客房，裡頭清新樸實，並不像是大戶人家的作風，這裡
的擺設相當簡單，並無特別之處。
LONG
	);
        set("light",1);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"p18",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
