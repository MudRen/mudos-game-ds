inherit ROOM;

void create()
{
	set("short", "村子小廣場");
	set("long", @LONG
這裡是幾間房子圍出來的空地。應該也是村人集會的場所，因為
地上可以看見有火堆燒過的痕跡。北邊的房屋是這個村莊最高的房子
，看來可以進去打探打探情報。
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 4 */
  		"north" : __DIR__"house1",
  		"east" : __DIR__"house2",
  		"west" : __DIR__"house3",
  		"south" : __DIR__"burg1",
	]));

	setup();
	replace_program(ROOM);
}
