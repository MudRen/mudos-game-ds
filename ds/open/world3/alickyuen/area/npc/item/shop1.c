// updated

inherit ROOM;

void create()
{
	set("short", "EQ放置室");
	set("long", "這是一個放了很多EQ的地方。\n");
	setup();
	set("stroom",1); //這樣就不會清掉這裡的東西.也不會再生 (特殊情況才用)
}
