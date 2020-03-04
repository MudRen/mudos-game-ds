// Room: /u/a/acme/area/lea7.c

inherit MOBROOM;

void create()
{
	set("short", "大草原");
	set("long", @LONG
你身處在一望無際的大草原，四周的野草略為高大，行走時便覺得有
點困難，你可聽見春蟬在「知了∼知了∼」的叫著，顯得生氣盎然。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"lea9",
  "northeast" : __DIR__"lea8",
  "east" : __DIR__"lea6",
]));
        set("chance",65);
        set("mob_amount",3);
     set("mob_max",8);
        set("mob_object",({   
            __DIR__"npc/orangutan",
        }) );
	set("no_clean_up", 0);
      set("outdoors","land");

	setup();
}
