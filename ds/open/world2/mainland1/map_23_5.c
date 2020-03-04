inherit MOBROOM;
void create()
{
	set("short", "��L");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_23_4",
	"south" : __DIR__"map_24_5",
	"north" : __DIR__"map_22_5",
	"east" : __DIR__"map_23_6",
	]));
	set("objects", ([
	__DIR__"../npc/beast_deer_9" : 2,
	__DIR__"../npc/beast_deer_6" : 1,
	]) );
        set("outdoors","land");
	set("chance",33);	
	set("mob_amount",3);	
	set("mob_object",({	
	__DIR__"../npc/beast_deer_6",
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

