inherit ITEM;
inherit F_FOOD;
void create()
{
    set_name("回元丹", ({ "recover pill","pill" }));
    set("long","回元丹是專門調理內力和真氣的藥丹，很好用。\n");
	set("weight", 300);
	if( clonep() ) 
		set_default_object(__FILE__);
	else {
		set("unit", "粒");
		set("value",200);
        set("heal_ap",40);
        set("food_remaining", 1);
	}
	setup();
}
