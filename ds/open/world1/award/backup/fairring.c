#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
	set_name(HIG"�A�ɧ�"NOR, ({ "jade ring","ring" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�o�O�@�u�ܺ}�G���٫�, ť�������򯫩_���O�q���[�䤤,\n"
                           "�A�i�H�յ۰t�a�ݬݡC\n");
		set("unit", "�u");
	set("value",1);
		set("material","jade");
		set("needaward",22);
		set("wear_msg",HIG"$N���W�F�o�u�A�ɧ�, �y�ɤ@�ѤO����¶$N�P��!"NOR);
		set("remove_msg",GRN"$N���U�F�A�ɧ�, ����O���������h.."NOR);
	}
	set("armor_prop/int",4);
	set("armor_prop/armor",1);
	set("armor_prop/shield",10);
	setup();
}

int query_autoload() { return 1; }
