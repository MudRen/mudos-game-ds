#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(HIC"���Ū��ѱM�Φ�A"NOR,({"blueksy cloth","cloth"}));
	set("long","�o�O�@�����Ū��ѱM�Φ�A�C\n");
	set_weight(420);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "fur");
		set("unit", "��");
//		set("value",4200);
        	set("armor_prop/armor", 10);
		set("armor_prop/dodge", 10);
	}
	setup();
}

int query_autoload() { return 1; }
