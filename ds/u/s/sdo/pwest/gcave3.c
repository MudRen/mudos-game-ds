inherit ROOM;

void create()
{
	set("short", "洞窟內叉路");
	set("long", @LONG
這裡是洞窟裡的叉路之一，狹小的通道讓人感覺有點不舒服，但
是不算難走，尤其是地面還頗為平坦，好像有人常常在這裡行走一樣
。地上好像有些奇怪的毛髮散落。
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 2 */
  		"southwest" : __DIR__"gcave1",
  		"north" : __DIR__"gcave5",
	]));

	setup();
	replace_program(ROOM);
}
