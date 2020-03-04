inherit MOBROOM;
void create()
{
	set("short", "��������");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_14_3",
	"south" : __DIR__"map_15_2",
	"north" : __DIR__"map_13_2",
	"west" : __DIR__"map_14_1",
	]));
	set("objects", ([
	__DIR__"../npc/beast_owl_5" : 1,
	]) );
        set("light",1);
        set("outdoors","land");
	set("chance",53);	
	set("mob_amount",3);	
	set("mob_object",({	
	__DIR__"../npc/beast_butterfly_1",
	__DIR__"../npc/beast_dove_1",
	__DIR__"../npc/beast_swallow_2",
	__DIR__"../npc/beast_butterfly_3",
	}) );
        setup();
}

string query_long(int raw)
{
	string out;
	out=ROOM_D->showmap(this_object());
	out+=query("long");
	return out;
}

