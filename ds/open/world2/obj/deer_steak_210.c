inherit ITEM;
inherit F_FOOD;
void create()
{
	set_name("���N����",({ "soy deer steak","steak" }) );
	set_weight(600);
	if( clonep() )
	set_default_object(__FILE__);
	else {
	set("long",@LONG
�o�O�ѷs�A���ש�J��o�C�����N�Ӧ������ơC
LONG);
	set("unit", "��");
	set("material","food2");
	}
	set("value",210);
	set("food_remaining",5);
	set("heal_hp",50);
	setup();
}
