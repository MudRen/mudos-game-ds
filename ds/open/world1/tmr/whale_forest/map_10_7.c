inherit ROOM;
void create()
{
	set("short", "林中草地");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_11_7",
	"west" : __DIR__"map_10_6",
	"north" : __DIR__"map_9_7",
	]));
                set("objects", ([ /* sizeof() == 1 */
                          __DIR__"npc/white_horse" : 4,
                ]));


	set("outdoors","forest");

        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

