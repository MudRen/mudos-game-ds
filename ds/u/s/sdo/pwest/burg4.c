inherit ROOM;

void create()
{
	set("short", "村子裡小路");
	set("long", @LONG
這條小路附近也有著許多的農田，可是有幾塊農田裡有被破壞過
的痕跡，看來那些被破壞過的農田裡的作物都不能收成了。小路的北
邊有著一戶人家，房屋的旁邊有著一個倉庫，看來這些農田的主人就
是那戶人家了。
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 3 */
  		"north" : __DIR__"house4",
  		"east" : __DIR__"burg3",
  		"west" : __DIR__"burg5",
	]));
	set("item_desc",([
        "痕跡":	"看起來好像是被一群野蠻的生物肆虐過的樣子。\n",
        "倉庫":	"一個專門存放作物地方。\n",
        ]));

	setup();
	replace_program(ROOM);
}
