// shuinang.c  ���n

inherit ITEM;
inherit F_WATER;

void create()
{
	set_name("���n", ({"water skin", "skin"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "�o�O�˺��M�������n�C\n");
		set("unit", "�u");
		set("value", 350);
        set("heal_mp", 5);
		set("water_remaining", 7);

	}
}
