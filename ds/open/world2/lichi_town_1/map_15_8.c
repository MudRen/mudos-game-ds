inherit MOBROOM;
void create()
{
	set("short", "��������");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_16_8",
	"north" : __DIR__"map_14_8",
	"west" : __DIR__"map_15_7",
	]));
	set("objects", ([
	__DIR__"../npc/beast_cat_4" : 1,
	]) );
        set("light",1);
        set("outdoors","land");
	set("chance",53);	
	set("mob_amount",3);	
	set("mob_object",({	
	__DIR__"../npc/beast_butterfly_1",
	__DIR__"../npc/beast_cat_4",
	__DIR__"../npc/beast_swallow_2",
	__DIR__"../npc/beast_cat_2",
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

