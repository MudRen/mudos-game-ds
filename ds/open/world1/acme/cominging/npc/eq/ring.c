#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
	set_name(HIC"�L������"NOR,({ "wu ji ring","ring" }) );
	set("long","�o�T�٫��ܯS�O�A�O���Ť����J��Ӧ��A\n"
		   "�o�J���@�������Ϊ��F�@���Ť����A�G��\n"
		   "�H�٤����y�Ť����z�C\n"
	   );
    set_weight(1500);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
        set("material","gem");
		set("unit", "��" );
		set("value",1500);
		set("armor_prop/armor", 3);
		set("armor_prop/shield",3);
		set("armor_prop/dodge",3);
	}
	setup();
}
