inherit MOBROOM;
void create()
{
	set("short", "�ܮw");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_8_33",
	"west" : __DIR__"map_8_31",
	]));
	set("objects", ([
	__DIR__"../npc/beast_rat_3" : 2,
	]) );
	set("chance",33);	
	set("mob_amount",4);	
	set("mob_object",({	
	__DIR__"../npc/beast_spider_5",
	__DIR__"../npc/beast_roach_2",
	__DIR__"../npc/beast_rat_3",
	__DIR__"../npc/beast_spider_8",
	}) );
        setup();
	set("map_long",1);     //show map as long
}

