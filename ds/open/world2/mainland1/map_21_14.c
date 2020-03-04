inherit MOBROOM;
void create()
{
	set("short", "��L");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_21_13",
	"south" : __DIR__"map_22_14",
	"north" : __DIR__"map_20_14",
	"east" : __DIR__"map_21_15",
	]));
	set("objects", ([
	__DIR__"../npc/beast_cow_10" : 1,
	__DIR__"../npc/beast_cow_5" : 2,
	]) );
        set("outdoors","land");
	set("chance",33);	
	set("mob_amount",3);	
	set("mob_object",({	
	__DIR__"../npc/beast_cow_5",
	__DIR__"../npc/beast_bolau_3",
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

