
inherit ROOM;

void create()
{
	set("short", "倉庫");
	set("long", @LONG
這個地方有點陰暗，不過看得見裡面的情形。你看到有很多用木板
做成的箱子堆放在裡面，有點亂又不會太亂，箱子上的灰塵已經事厚厚的
一層了，看來平常這裡並沒有人來打掃整理。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	    "west" : __DIR__"room34",
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}
