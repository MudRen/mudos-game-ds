// Room: /u/a/acme/area/hall.c

inherit ROOM;

void create()
{
	set("short", "武廳");
     set("light",1);
	set("long", @LONG
這裡是神武教的練武廳，這是讓剛入教的弟子在此習劍，一對一的攻
防，攻者凌厲，防者堅固。大廳門口上有幅匾額，上頭寫著四個大字「劍
氣沖霄」，筆法雄渾豪邁，似是練武之人所書。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"corridor",
]));
     set("objects",([
        __DIR__"npc/apprentice" : 3,
        __DIR__"npc/woodman" : 4,
     ]) );
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
