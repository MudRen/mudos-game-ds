inherit MOBROOM;
void create()
{
	set("short", "��W");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_18_6",
	]));
	set("objects", ([
	__DIR__"../npc/beast_spider_8" : 2,
	]) );
        set("outdoors","land");
	set("chance",53);	
	set("mob_amount",3);	
	set("mob_object",({	
	__DIR__"../npc/beast_spider_16",
	__DIR__"../npc/beast_spider_5",
	__DIR__"../npc/beast_spider_8",
	__DIR__"../npc/beast_butterfly_3",
	}) );
        setup();
	set("map_long",1);     //show map as long
}

