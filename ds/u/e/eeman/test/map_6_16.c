inherit ROOM;
void create()
{
	set("short", "���");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_6_17",
	"south" : __DIR__"map_7_16",
	"north" : __DIR__"map_5_16",
	"west" : __DIR__"map_6_15",
	]));
        setup();
}

string query_long(int raw)
{
	string out;
	out=ROOM_D->showmap(this_object());
	out+=query("long");
	return out;
}

