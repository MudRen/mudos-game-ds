inherit ROOM;
void create()
{
	set("short", "血跡");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_25_26",
	"west" : __DIR__"map_26_25",
	"east" : __DIR__"map_26_27",
	]));
	set("outdoors","land");
				set("objects",([
			__DIR__"npc/fetish" : 2, 
			__DIR__"npc/fetish_wizard" : 2, 		
		]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

