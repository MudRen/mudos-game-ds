#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
	set_name(HIG"�A�ɧ�"NOR, ({ "Jade ring","ring" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�o�O�@�u�ܺ}�q���٫�, ť�������򯫩_���O�q���[�䤤,\n"
                           "�A�i�H�յ۰t�a�ݬݡC\n");
		set("unit", "�u");
		set("material", "jade");
//		set("no_drop",1);
		set("no_sac",1);
		set("value",25000);
		set("armor_prop/wit",1);
		set("armor_prop/int",4);
		set("armor_prop/armor", 5);
		set("wear_msg",HIG"$N���W�F�o�u�A�ɧ�, �y�ɤ@�ѤO����¶$N�P��!"NOR);
		set("remove_msg",GRN"$N���U�F�A�ɧ�, ����O���������h.."NOR);
	}
	setup();
}

int query_autoload() { return 1; }