inherit ROOM;
void create()
{
	set("short", "�۪O��");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_3_13",
	"south" : __DIR__"map_4_12",
	"north" : __DIR__"map_2_12",
	"west" : __DIR__"map_3_11",
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

