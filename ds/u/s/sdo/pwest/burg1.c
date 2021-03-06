inherit ROOM;

void create()
{
	set("short", "村子口");
	set("long", @LONG
如果這幾間房屋加起來的聚落可以叫做村子的話，那麼這裡看起
來就是村子口了。因為這裡有著一塊木牌，上面好像有一些文字，也
許是寫著村子的名稱吧。
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("shout", "村子口");
	set("exits", ([ /* sizeof() == 4 */
  		"north" : __DIR__"burg2",
  		"east" : __DIR__"burg6",
  		"west" : __DIR__"burg3",
  		"south" : __DIR__"path5",
	]));
	set("item_desc",([
        "木牌":	"┌───────┐\n"
        	"│ ↑  伏 克 村 │\n"
        	"│ →  迷霧森林 │\n"
        	"└─┬┬─┬┬─┘\n",
        ]));

	setup();
}
