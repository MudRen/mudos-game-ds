#include <armor.h>
inherit SURCOAT;
void create()
{
        set_name("�w�֥Ҥ潴" ,({ "sky cloak","cloak" }) );
        set("long","�o��潴�����O�Τ@���@�����w�֥ҩ������Ӧ����A\n"
                   "�Q����@�ΩʡA�����������O�L���F�C\n");
        set_weight(10000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "leather");
	set("volume",3);
        set("unit", "��" );
        set("value",1500);
        set("limit_lv",15);
	}
        set("armor_prop/armor",11);
        set("armor_prop/dodge",-15);
        setup();
}
