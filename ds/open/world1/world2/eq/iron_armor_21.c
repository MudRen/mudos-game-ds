#include <armor.h>
inherit ARMOR;

void create()
{
	set_name("�K�@��",({"iron armor","armor"}) );
	set("long",@LONG
�o�O�@��ѯ��K���y�Ӧ����p���@�ҡC
LONG
);
	set_weight(12250);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "iron");
                set("unit", "��");
        }
        set("armor_prop/armor",21);
        setup();
        set("value",3880);
        set("volume", 10);
}

int query_autoload() { return 1; }
