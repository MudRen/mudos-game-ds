#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
	set_name(HIG"�e�l�j"NOR,({ "shea-gei boots","boots","shea-gei" }) );
    set("long","�@���v�ź�߻s�����c�l�A�~�h�٥]�F�ǻȺ�C\n");
	set_weight(2500);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
        set("material", "skin");
set("volume",2);
		set("unit", "��" );
		set("value", 2600);
		set("armor_prop/armor", 9);
		set("armor_prop/shield", 6);
	}
	setup();
}
