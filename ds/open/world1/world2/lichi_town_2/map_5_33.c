inherit MOBROOM;
void create()
{
	set("short", "倉庫");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_6_33",
	"north" : __DIR__"map_4_33",
	"west" : __DIR__"map_5_32",
	]));
	set("objects", ([
	__DIR__"../npc/beast_cat_4" : 1,
	]) );
	set("chance",33);	
	set("mob_amount",4);	
	set("mob_object",({	
	__DIR__"../npc/beast_mosquito_1",
	__DIR__"../npc/beast_roach_2",
	__DIR__"../npc/beast_spider_5",
	}) );
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

