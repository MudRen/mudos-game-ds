// Room: /u/k/kenshin/sha-zin-gu/room12.c

inherit ROOM;

void create()
{
	set("short", "武器舖");
	set("long", @LONG
一走進這家武器舖，便聽到一巨大的打鐵聲音和老闆招呼來購買
武器的人，此打鐵舖一直以來，秉持的一項原則，就是童叟無欺，不
知是否真是如此。
LONG
	);
	set("outdoors", "land");
	set("current_light", 2);
	set("light", 1);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/npc/wpboss" : 1,
]));
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"room9",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
