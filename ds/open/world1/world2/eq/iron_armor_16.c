#include <armor.h>
inherit ARMOR;

void create()
{
	set_name("�K�@��",({"iron chest protector","protector"}) );
	set("long",@LONG
�o�O�@����K�����X�Ӧ����@�ݡC
LONG
);
	set_weight(8850);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "iron");
                set("unit", "��");
        }
        set("armor_prop/armor",16);
        setup();
        set("value",2330);
        set("volume", 8);
}

int query_autoload() { return 1; }
