inherit ITEM;
inherit F_FOOD;
void create()
{
	set_name("紅燒鹿排",({ "soy deer steak","steak" }) );
	set_weight(600);
	if( clonep() )
	set_default_object(__FILE__);
	else {
	set("long",@LONG
這是由新鮮鹿肉放入醬油慢火熬煮而成的鹿排。
LONG);
	set("unit", "塊");
	set("material","food2");
	}
	set("value",210);
	set("food_remaining",5);
	set("heal_hp",50);
	setup();
}
