// Room: /open/world1/dragoncity/caodi3.c

inherit MOBROOM;

void create()
{
	set("short", "奧特蘭克-草地");
	set("long", @LONG
這兒是奧特蘭克山谷外的大草地，往北可以望見少帥軍
與虎人鐵櫻族終年爭戰的主要戰地－奧特蘭克山谷，雖然這
兒沒有半點戰火，但四週氣氛卻是充滿金屬肅殺之氣。
LONG
	);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"caodi1",
  "south" : __DIR__"caodi5",
]));
	set("current_light", 3);
	set("no_clean_up", 0);
        set("chance", 60); 
        set("mob_amount",3);     
           set("mob_object",({  
                  __DIR__"npc/tiger1",
                   __DIR__"npc/tiger2",
                   __DIR__"npc/tiger3",
        }));


	setup();
}
