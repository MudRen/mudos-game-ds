inherit ROOM;
void create()
{
	set("short", "�_��L");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_9_13",
	"south" : __DIR__"map_10_12",
	"north" : __DIR__"map_8_12",
	"west" : __DIR__"map_9_11",
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

