inherit ROOM;
void create()
{
	set("short", "���");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_4_14",
	"south" : __DIR__"map_5_13",
	"north" : __DIR__"map_3_13",
	"west" : __DIR__"map_4_12",
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

