inherit ITEM;
inherit F_WATER;
void create()
{
	set_name("���A����",({ "fish soup","soup" }) );
	set_weight(500);
	if( clonep() )
	set_default_object(__FILE__);
	else {
	set("long",@LONG
�o�J���Q�Q�������̩�F�n�h���s�A���סA���H�Ԥ������j�ʡC
LONG);
	set("unit", "�J");
	set("material","food2");
	}
	set("value",120);
	set("water_remaining",3);
	set("heal_hp",30);
	setup();
}
