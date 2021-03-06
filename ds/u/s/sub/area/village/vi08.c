// Room: /u/s/sub/area/village/vi08.c

inherit ROOM;

void create()
{
	set("short", "碎石小路");
	set("long", @LONG
北邊有的小湖，因為潮濕的關係地上都是濕濕黏黏的泥巴，一直向北
邊延伸過去。如果要進入村莊別忘了把鞋子上的泥巴給清除乾淨喔！往北
走可以到一個小湖，南邊是一個小村莊。
LONG
	);
	set("world", "undefine");
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("current_light", 2);
    set("objects", ([
        __DIR__"npc/village_racer1_45" : 1,
        __DIR__"npc/village_racer2_45" : 1,
        __DIR__"npc/village_racer3_45" : 1,
        ]) );
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"map_9_7",
  "south" : __DIR__"vi07",
]));

	setup();
	replace_program(ROOM);
}
