
inherit NPC;

void create()
{
	set_name("旅館職員", ({"keeper"}) );
	set("long", "他是這間旅館的職員,可以向他詢問一些資料.\n");
	set("race", "機械人");
	set("age", 49);
	set("level", 5);

	setup();

}
