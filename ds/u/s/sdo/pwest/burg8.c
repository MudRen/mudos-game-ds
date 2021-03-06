inherit ROOM;

void create()
{
	set("short", "迷霧森林之徑");
	set("long", @LONG
走到此處，你有點感覺到為什麼要叫做『迷霧森林』了。因為在
這裡的樹木讓你感覺到一種奇異的感覺，好像他們都是會動的，而且
居高臨下的看著你。這裡有塊材質堅硬的大石頭，不像是天然的，看
起來像是有人特意把它搬過來，而且上面還有一些文字。
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "forest");
	set("exits", ([ /* sizeof() == 2 */
  		"east" : __DIR__"burg9",
  		"south" : __DIR__"burg7",
	]));
	set("item_desc",([
        "文字":	"上面寫著『界碑』的兩個銀色字跡的大字，底下還有幾行銀色小字：\n\n"
        	"	在諸神的見證之下，幽遮蘭與妖精國度定界\n"
        	"	於此，兩國以迷霧森林為邊境，互不侵犯。\n"
        ]));

	setup();
	replace_program(ROOM);
}
