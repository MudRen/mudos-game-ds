inherit ROOM;
void create()
{
	set("short", "�۪O��");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_7_12",
	"south" : __DIR__"map_8_11",
	"north" : __DIR__"map_6_11",
	"west" : __DIR__"map_7_10",
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

