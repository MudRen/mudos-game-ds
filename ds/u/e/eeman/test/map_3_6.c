inherit ROOM;
void create()
{
	set("short", "���s");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_3_7",
	"south" : __DIR__"map_4_6",
	"north" : __DIR__"map_2_6",
	"west" : __DIR__"map_3_5",
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

