inherit ROOM;
void create()
{
	set("short", "林中草地");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_12_15",
	]));
	set("outdoors","forest");
                set("objects", ([ /* sizeof() == 1 */
                          __DIR__"npc/mouse" : 4,
                ]));

        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

