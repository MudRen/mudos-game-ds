#include <armor.h>
inherit PANTS;

void create()
{
	set_name("�¦�¥�����",({ "black cloth skirt","black skirt","cloth skirt","skirt" }) );
	set("long",@LONG
�o�O�@��ܾ�����¦�¥����ȡC
LONG
);
	set_weight(1820);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "��");
        }
        set("armor_prop/armor",6);
        set("female_only",1);
        setup();
        set("value",660);
        set("volume", 4);
}

int query_autoload() { return 1; }
