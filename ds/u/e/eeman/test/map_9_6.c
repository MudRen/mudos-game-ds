inherit ROOM;
void create()
{
	set("short", "�۪O��");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_9_7",
	"south" : __DIR__"map_10_6",
	"north" : __DIR__"map_8_6",
	"west" : __DIR__"map_9_5",
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

