inherit ROOM;
void create()
{
	set("short", "骨龍遺洞");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_4_30",
	"east" : __DIR__"map_4_32",
	]));
	
	set("objects", ([
		__DIR__"npc/ents" : 1, 
		__DIR__"npc/wendigo.c" : 2, 
		__DIR__"npc/wild_toast.c" : 2, 
	]) );
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

