
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("�F��",({"salad"}) );
	set_weight(10);
	if( clonep() )
	set_default_object(__FILE__);
	else {
	set("long","�A�ݤ��X������S�O���a��,�]�\\�u�O�@�L���q���F�ԡC\n");
	set("unit", "�L");
	set("value",30);
	set("food_remaining",1);
	}
}
