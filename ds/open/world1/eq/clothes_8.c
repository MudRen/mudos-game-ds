#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("�ʥ��­m",({"grass clothes","clothes"}) );
	set("long",@LONG
�o�O�@��¥��s´�Ӧ����B�ʭm�A�i�H����B�ʮɤ@�ǻ��L����
�ˡC
[SAVE-EQ]

LONG
);
	set_weight(2100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "��");
        }
	set("value",240);
    set("armor_prop/armor",4);
        setup();
}

int query_autoload() { return 1; }
