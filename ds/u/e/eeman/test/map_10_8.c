inherit ROOM;
void create()
{
	set("short", "���");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_10_9",
	"south" : __DIR__"map_11_8",
	"north" : __DIR__"map_9_8",
	"west" : __DIR__"map_10_7",
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

