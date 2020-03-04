// Room: /open/world1/acme/bonze/b4.c

inherit ROOM;

void create()
{
	set("short", "上山小路");
	set("long", @LONG
你走在這荒野的山道間，禿枝落葉，四野蕭棠，一片死寂，偶爾
從不遠處傳來幾聲虎鳴狼吠，顯得格外的淒涼。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"b3",
  "southup" : __DIR__"b5",
  "north" : __DIR__"b18",
]));
    set("objects",([
   __DIR__"npc/old_beggar": 1,
   ]) );
        set("outdoors","land");

	setup();
	replace_program(ROOM);
}
