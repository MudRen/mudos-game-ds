#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name("�P����u" ,({ "sun shoes","shoes" }) );
        set("long",@LONG
�o�O�@�������⪺���s���u�A�ݰ_�Ӭ۷��T�C
[�i�x�s�˳�]
LONG
);
        set_weight(3200);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("material", "steel");
        set("unit", "��" );
        set("no_sac",1);
	}
	set("value",1780);
	set("armor_prop/fire", 4); //���t����.
	set("armor_prop/shield", 2);
	set("armor_prop/armor", 8);
        setup();
}


int query_autoload() { return 1; }
