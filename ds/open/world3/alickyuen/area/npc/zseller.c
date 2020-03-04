// 27/12
inherit SELLMAN;
inherit NPC;
void create()
{
	set_name("推銷員", ({"seller"}) );
	set("long", "在動物園任職的推銷員，正在努力推銷一些動物園的特產。\n");
	set("race", "人類");
	set("age", 40);
	set("level", 5);
        set("sell_list",([
__DIR__"obj/food" : 10,
        ]) );
	setup();
}
void init()
{
        add_action("do_list","list");
        add_action("do_buy","buy");
}
