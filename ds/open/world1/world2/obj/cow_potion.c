inherit ITEM;
inherit F_WATER;
void create()
{
	function f;
	set_name("�j���Z��", ({ "cow potion","potion" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",@LONG
  �o�ض����Įħֳt�åB�Q���j�P�C��(drink) �F����i�H�j�T�ﵽ
���Ϊ̪��믫���p�C
LONG);
		set("unit", "�~");
		set("material","water");
	}
	set("value", 320);    
	set("heal_mp",180);
	set("water_remaining", 1);
	setup();
}
