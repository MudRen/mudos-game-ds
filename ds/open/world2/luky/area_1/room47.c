// Modify with AreaMaker1.0
// Room47.c

inherit ROOM;

void create()
{
	set("short","池塘邊");
	set("long", @LONG
這裡的路面是由潮濕的泥土所鋪成，道路兩旁的草長得雜亂無章
。地面上的草愈長愈長。你再仔細一瞧，北邊地勢往上斜陡，傾耳細
聽彷彿還可聽到一陣陣鳥鳴聲。
LONG
	);
	set("exits", ([
		"north": __DIR__"room37",
		"east": __DIR__"room48",
		"west": __DIR__"room46",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

