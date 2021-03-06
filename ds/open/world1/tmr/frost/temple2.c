// Room: /open/world1/tmr/frost/temple2.c

inherit ROOM;

void create()
{
	set("short", "寒澈道觀-內殿");
	set("long", @LONG
這裡是道觀內的正殿，殿內供俸著道教天尊的神像，居中一個偌大的
香爐裡更是香火鼎盛，四週的牆壁也掛著數位歷代得道仙人的畫像，筆鋒
細緻，把每個人物畫得栩栩如生。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"temple1e2",
]));
	set("current_light", 2);
        set("objects", ([
                __DIR__"npc/huang-fei-hu":1,
                __DIR__"npc/taoist2": 2,
        ]) );

	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
