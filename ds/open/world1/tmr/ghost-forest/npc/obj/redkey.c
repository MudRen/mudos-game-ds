#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIR"�����_��"NOR,({"red key","key"}));
	set("long",@long
�@��a����⪺�_�͡A���@�Ӥ�x���A�ͨ��c�y�ᬰ�����C
long
		);

	set_weight(100);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("door","redkey");
		set("value", 1);
	}
	setup();
}
