inherit ITEM;
inherit F_WATER;
void create()
{
	function f;
	set_name("強效蠻牛", ({ "cow potion","potion" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",@LONG
  這種飲料藥效快速並且十分強烈。喝(drink) 了之後可以大幅改善
飲用者的精神狀況。
LONG);
		set("unit", "瓶");
		set("material","water");
	}
	set("value", 320);    
	set("heal_mp",180);
	set("water_remaining", 1);
	setup();
}
