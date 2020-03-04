inherit MOBROOM;
void create()
{
	set("short", "��L");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_15_2",
	"north" : __DIR__"map_14_3",
	"east" : __DIR__"map_15_4",
	]));
	set("objects", ([
	__DIR__"../npc/beast_deer_9" : 3,
	]) );
        set("outdoors","land");
	set("chance",33);	
	set("mob_amount",3);	
	set("mob_object",({	
	__DIR__"../npc/beast_deer_15",
	__DIR__"../npc/beast_deer_9",
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

