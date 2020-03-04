// Room: /u/a/acme/area/lea2.c

inherit MOBROOM;

void create()
{
	set("short", "大草原");
	set("long", @LONG
這裡是一望無際的大草原，四周的景緻並無二樣，草原上頭有許多動
物正盡情的奔跑著，微風輕輕的吹拂著你的臉脥，心胸感到一股無限的舒
暢，四周散發著青草的氣息，你只想輕輕的擁抱著大自然。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"lea9",
  "north" : __DIR__"lea3",
  "south" : __DIR__"lea1",
  "east" : __DIR__"lea13",
]));
        set("chance",80);
        set("mob_amount",3);
        set("mob_max",10);
        set("mob_object",({   
           __DIR__"npc/sciurine",
        }) );
	set("no_clean_up", 0);
      set("outdoors","land");

	setup();
}
