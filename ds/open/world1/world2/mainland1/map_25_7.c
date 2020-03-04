inherit MOBROOM;
void create()
{
	set("short", "��L");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_25_6",
	"north" : __DIR__"map_24_7",
	"east" : __DIR__"map_25_8",
	]));
	set("objects", ([
	__DIR__"../npc/beast_deer_6" : 1,
	__DIR__"../npc/beast_deer_4" : 1,
	]) );
        set("outdoors","land");
	set("chance",33);	
	set("mob_amount",3);	
	set("mob_object",({	
	__DIR__"../npc/beast_deer_6",
	__DIR__"../npc/beast_deer_4",
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

