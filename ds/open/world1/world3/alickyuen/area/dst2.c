// updated 26/12

inherit ROOM;

void create()
{
	set("short", "[1;36mST。Road＠South[2;37;0m");
	set("long", @LONG
看到前面這座巨型的建築物，就知道不是未來世界時建造的。一座宏
偉的教堂，看上去就像有過百年歷史，是受國家保護的古代建築。但是，
你從這間教堂上，完全感覺不到神聖，還有一點陰森恐怖．．．．．．
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"dst3.c",
  "south" : __DIR__"dst1.c",
  "west" : __DIR__"church",
]));
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard.c" : 1,
]));
   set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
