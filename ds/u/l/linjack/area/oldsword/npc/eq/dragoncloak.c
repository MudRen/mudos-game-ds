#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
inherit F_UNIQUE;
void create()
{
	set_name(HIC"���s�ԳT"NOR, ({ "dragon cloak","cloak" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�o��T�W�õۤT�ե��s, �Q��Q��, ���ӬO�x�a�Y�ر`\n"
                           "�ܱ��W�}���ԳT.\n");
		set("unit", "��");
		set("value",18000);
		set("material","cloth");
		set("limit_con",10);
		set("limit_dex",40);
		set("replica_ob",__DIR__"cloak.c");
	}
	set("armor_prop/armor",12);
	set("armor_prop/shield",10);
	setup();
}
