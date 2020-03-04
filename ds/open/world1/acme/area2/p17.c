// Room: /u/a/acme/area3/p17.c

inherit ROOM;

void create()
{
	set("short", "廚房");
	set("long", @LONG
這是一間廚房，廚房裡鍋碗瓢盆樣樣俱全，這裡的長工，正在燒著準
備下酒的小菜，香氣四溢，令你垂涎三尺。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"p16",
]));
set("objects",([
   __DIR__"npc/general4" : 1,
   __DIR__"npc/ma" : 1,
]) );
       set("light",1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
