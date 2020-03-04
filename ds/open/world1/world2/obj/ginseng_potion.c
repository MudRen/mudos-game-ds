inherit ITEM;
inherit F_WATER;
void create()
{
	function f;
	set_name("人參藥水", ({ "ginseng potion","potion" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",@LONG
  這罐藥水是由整顆人參精製而成。喝(drink) 了之後可以強筋活血
並聽說有延年益壽之效況。
LONG);
		set("unit", "瓶");
		set("material","water");
	}
	set("value", 620);    
	set("heal_mp",100);
	set("heal_ap",100);
	set("heal_hp",400);
	set("water_remaining", 1);
	setup();
}
