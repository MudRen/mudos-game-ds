inherit MOBROOM;
void create()
{
	set("short", "��������");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_17_18",
	"south" : __DIR__"map_18_17",
	"west" : __DIR__"map_17_16",
	]));
	set("objects", ([
	__DIR__"../npc/beast_ladybug_2" : 1,
	]) );
        set("light",1);
        set("outdoors","land");
	set("chance",53);	
	set("mob_amount",3);	
	set("mob_object",({	
	__DIR__"../npc/beast_mosquito_1",
	__DIR__"../npc/beast_ladybug_2",
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

