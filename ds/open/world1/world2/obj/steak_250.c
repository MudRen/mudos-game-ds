inherit ITEM;
inherit F_FOOD;
void create()
{
	set_name("�K�O����",({ "iron-board steak","steak" }) );
	set_weight(700);
	if( clonep() )
	set_default_object(__FILE__);
	else {
	set("long",@LONG
�@�ȭ��Q�Q���K�O���ơC
LONG);
	set("unit", "��");
	set("material","food2");
	}
	set("value",250);
	set("food_remaining",5);
	set("heal_hp",60);
	setup();
}
