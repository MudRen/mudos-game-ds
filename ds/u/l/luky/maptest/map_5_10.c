inherit ROOM;
void create()
{
        set("short", "空地");
        set("long", @LONG
這裡是一塊尚未開發的空地。

LONG
);
	set("exits",([
	"west" : __DIR__"map_5_9",
	"south" : __DIR__"map_6_10",
	"north" : __DIR__"map_4_10",
	"east" : __DIR__"map_5_11",
	]));
        set("out_doors","land");
        setup();
}

string query_long(int raw)
{
	string out;
	out=ROOM_D->showmap(this_object());
	out+=query("long");
	return out;
}

