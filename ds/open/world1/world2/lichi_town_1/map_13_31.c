inherit MOBROOM;
void create()
{
	set("short", "�x�|");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_13_32",
	"south" : __DIR__"map_14_31",
	"north" : __DIR__"map_12_31",
	"west" : __DIR__"map_13_30",
	]));
	set("objects", ([
	__DIR__"../npc/beast_swallow_2" : 2,
	]) );
	set("chance",53);	
	set("mob_amount",3);	
	set("mob_object",({	
	__DIR__"../npc/beast_swallow_2",
	__DIR__"../npc/beast_dove_1",
	}) );
	set("outdoors","land");
	set("light",1);
        setup();
}

string query_long(int raw)
{
	string out;
	out=ROOM_D->showmap(this_object());
	out+=query("long");
	return out;
}

