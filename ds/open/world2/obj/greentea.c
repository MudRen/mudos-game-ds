inherit ITEM;
inherit F_WATER;
void create()
{
	function f;
	set_name("綠茶", ({ "green tea","tea" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",@LONG
  一罐統一公司生產的純喫茶。喝(drink) 了可以提神醒腦而且常
喝綠茶亦有防癌的效果。
LONG);
		set("unit", "瓶");
		set("material","water");
	}
	set("value", 50);    
	set("heal_mp",25);
	set("water_remaining", 1);
	setup();

}
