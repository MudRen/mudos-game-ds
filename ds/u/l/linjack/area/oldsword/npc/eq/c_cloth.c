#include <armor.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit CLOTH;
void create()
{
	set_name(HIW"���T"NOR, ({ "cloud cloth","cloth" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�o���A�S�s������M�_�s��k, �����ܦ����ӱj��\n"
                           "�������m�O�窫, �ڻ����Ѥ��U�u�����ѵ����W���o�@��.\n");
		set("unit", "��");
		set("value",15000);
		set("material","cloth");
		set("limit_con",10);
		set("limit_int",15);
		set("replica_ob",__DIR__"c_cloth_f");
	}
	set("armor_prop/dex",1);
	set("armor_prop/dodge",5);
	set("armor_prop/armor",18);
	set("armor_prop/show_damage",1);
	setup();
}
