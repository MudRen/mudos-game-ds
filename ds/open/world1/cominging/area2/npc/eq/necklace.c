#include <armor.h>
inherit NECK;
void create()
{
	set_name("�p����" ,({ "necklace" }) );
	set("long","�@���������p����A�W�����@�������p�_�ۡC\n");
	set_weight(1100);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "��" );
		set("value" , 1160);
		set("armor_prop/armor", 5);
		set("armor_prop/shield", 3);
		set("armor_prop/dodge", 3);
	}
	setup();
}
