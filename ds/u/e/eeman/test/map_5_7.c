inherit ROOM;
void create()
{
	set("short", "�_��L");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_5_8",
	"south" : __DIR__"map_6_7",
	"north" : __DIR__"map_4_7",
	"west" : __DIR__"map_5_6",
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

