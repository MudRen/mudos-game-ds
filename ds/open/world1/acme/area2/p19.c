// Room: /u/a/acme/area3/p19.c

inherit ROOM;

void create()
{
	set("short", "施迅臥房");
	set("long", @LONG
這裡就是施迅的臥房了，裡頭清新樸實，並不像是大戶人家，這裡的
擺設相當簡單，一張圓木桌，幾張椅子，和一張床，就無別物了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"p18",
]));
        set("light",1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
