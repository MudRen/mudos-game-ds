#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
	set_name("���s��", ({ "purple-dragon herb", "herb" }));
	set("long","���s��O�@�إ����ܴ��M���Ĥ�A�Ψӫ�_�]�޽m�B�u�@�үӪ���O\n"
		   "���������ĪG�C\n");
	set_weight(650);

	if( clonep() ) 
		set_default_object(__FILE__);
	else
	{
		set("unit", "��" );
        set("value", 800 );
		set("heal_hp", 75 );
		set("food_remaining", 2 );
		set("heal_ap", 10 );
	}
	setup();
}
