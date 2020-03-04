inherit MOBROOM;
void create()
{
	set("short", "��W");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_12_4",
	"west" : __DIR__"map_11_3",
	]));
	set("objects", ([
	__DIR__"../npc/beast_owl_5" : 1,
	]) );
        set("outdoors","land");
	set("chance",53);	
	set("mob_amount",3);	
	set("mob_object",({	
	__DIR__"../npc/beast_squirrel_3",
	__DIR__"../npc/beast_bolau_3",
	__DIR__"../npc/beast_swallow_2",
	__DIR__"../npc/beast_butterfly_3",
	__DIR__"../npc/beast_owl_5",
	}) );
        setup();
	set("map_long",1);     //show map as long
}

