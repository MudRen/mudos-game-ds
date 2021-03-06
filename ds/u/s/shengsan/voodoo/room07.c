inherit ROOM;

void create()
{
	set("short", "廣場");
	set("long", @LONG
廣場的四周都有青翠的竹林包圍著，廣場地板的石材都是相當的好。
也許這裡就是教徒常常來練功的地方。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	    "east" : __DIR__"room05",
            "north": __DIR__"room08",
            ]));

	set("objects", ([ /* sizeof() == 2 */
            __DIR__"mob/master" : 1,
	    __DIR__"mob/disciple" : 2,
            ]));

	set("no_clean_up", 0);
	set("outdoors",1);

	setup();
	replace_program(ROOM);
}
