inherit ITEM;
inherit F_FOOD;
void create()
{
	set_name("���[�ޱ�",({ "garlic pork chop","chop" }) );
	set_weight(800);
	if( clonep() )
	set_default_object(__FILE__);
	else {
	set("long",@LONG
�o�O�@���ѽި��W���U���סC
LONG);
	set("unit", "��");
	set("material","food2");
	}
	set("value",180);
	set("food_remaining",5);
	set("heal_hp",40);
	setup();
}
