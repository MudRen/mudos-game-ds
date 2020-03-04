inherit MOBROOM;
void create()
{
	set("short", "�s�u�s��");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_10_22",
	"south" : __DIR__"map_11_21",
	"north" : __DIR__"map_9_21",
	"west" : __DIR__"map_10_20",
	]));
	set("objects", ([
	__DIR__"../npc/beast_ladybug_2" : 1,
	]) );
        set("light",1);
        set("outdoors","land");
	set("chance",53);	
	set("mob_amount",3);	
	set("mob_object",({	
	__DIR__"../npc/beast_ladybug_2",
	__DIR__"../npc/beast_butterfly_1",
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

