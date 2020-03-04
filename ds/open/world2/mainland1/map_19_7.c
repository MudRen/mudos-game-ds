inherit MOBROOM;
void create()
{
	set("short", "��L");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_19_6",
	"south" : __DIR__"map_20_7",
	"north" : __DIR__"map_18_7",
	"east" : __DIR__"map_19_8",
	]));
	set("objects", ([
	__DIR__"../npc/beast_pig_7" : 2,
	]) );
        set("outdoors","land");
	set("chance",33);	
	set("mob_amount",3);	
	set("mob_object",({	
	__DIR__"../npc/beast_deer_6",
	__DIR__"../npc/beast_pig_7",
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

