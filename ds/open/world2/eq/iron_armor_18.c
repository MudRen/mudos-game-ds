#include <armor.h>
inherit ARMOR;

void create()
{
	set_name("�j�ƫ��K�@��",({"s-iron chest protector","protector"}) );
	set("long",@LONG
�o�O�@����K�����X�Ӧ����@�ݡA���O���X�B�g�L�F�j�ƳB�z�C
LONG
);
	set_weight(9750);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "iron");
                set("unit", "��");
        }
        set("armor_prop/armor",18);
        setup();
        set("value",2980);
        set("volume", 8);
}

int query_autoload() { return 1; }
