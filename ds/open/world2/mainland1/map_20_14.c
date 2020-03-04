inherit MOBROOM;
void create()
{
	set("short", "��L");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_20_13",
	"south" : __DIR__"map_21_14",
	"north" : __DIR__"map_19_14",
	"east" : __DIR__"map_20_15",
	]));
	set("objects", ([
	__DIR__"../npc/beast_cow_10" : 2,
	__DIR__"../npc/beast_cow_5" : 1,
	]) );
        set("outdoors","land");
	set("chance",33);	
	set("mob_amount",3);	
	set("mob_object",({	
	__DIR__"../npc/beast_cow_5",
	__DIR__"../npc/beast_deer_6",
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

