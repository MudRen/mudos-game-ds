#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
	set_name(HIB"�����l"NOR, ({ "sky flying wing","wing","cloak" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�o��ܭ��W�e�F�@�ﵴ�������l, �O�A�Q���۰g,\n"
                           "���ӬO���~���@�C\n");
		set("unit", "��");
		set("material", "cloth");
//		set("no_drop",1);
		set("no_sac",1);
		set("value",40000);
		set("armor_prop/dex",3);
		set("armor_prop/dodge",7);
		set("armor_prop/shield",5);
		set("armor_prop/armor", 5);
	}
	setup();
}

int query_autoload() { return 1; }