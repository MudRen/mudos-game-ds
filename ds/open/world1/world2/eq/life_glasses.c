#include <armor.h>
#include <ansi.h>
inherit MASK;
void create()
{
	set_name("�ͩR�P����", ({ "life-detect glasses","glasses" }) );
	set("long",@LONG
�o�Ʋ��褺�t���O�p�P�ū׭p�A�i�H������ϥΪ̪��ͩR���A�P���������C
LONG
);
	set_weight(930);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "glass");
	}
	set("armor_prop/armor",2);
	set("armor_prop/show_damage",1);
	setup();
	set("value",1200);
}

//int query_autoload() { return 1; }
