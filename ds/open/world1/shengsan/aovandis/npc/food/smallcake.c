
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("�p�J�|",({ "small cake","small","cake" }) );
	set_weight(50);
	if( clonep() )
	set_default_object(__FILE__);
	else {
	set("long","�o�Ӥp�J�|���o�Z��o���C\n");
	set("unit", "��");
	set("value",50);
	set("food_remaining",2);
	}
}
