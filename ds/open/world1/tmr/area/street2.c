// Room: /u/street2.c

inherit ROOM;

void create()
{
	set("short", "街道");
	set("long", @LONG
一條廣大的街道，過往的人群大都是有錢子弟或是富家公子，左右兩邊
不時傳來年輕姑娘的嘻笑聲，細看之下道路兩旁的房宇樓閣，都掛著「怡紅
院」、「飄香院」之類的招牌，難道....。往東是條道路，往西則是個熱鬧
的市集。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"street1",
		"east" : __DIR__"street3",
]));
	set("outdoors","land");

set("light",1);
	setup();
	replace_program(ROOM);
}
