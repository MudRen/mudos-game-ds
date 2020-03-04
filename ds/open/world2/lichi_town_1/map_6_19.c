inherit MOBROOM;
void create()
{
	set("short", "�Q����");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_6_20",
	"south" : __DIR__"map_7_19",
	"north" : __DIR__"map_5_19",
	"west" : __DIR__"map_6_18",
	]));
	set("objects", ([
	__DIR__"../npc/beast_fish_1" : 3,
	]) );
        set("light",1);
        set("outdoors","land");
	set("chance",53);	
	set("mob_amount",3);	
	set("mob_object",({	
	__DIR__"../npc/beast_fish_3",
	__DIR__"../npc/beast_fish_1",
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

