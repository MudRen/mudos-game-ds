#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("��Ũ�m",({"white shirts","shirts"}) );
	set("long",@LONG
�o�O�@��զ⪺Ũ�m�A�q�`�Φb�����������X�C
LONG);
	set_weight(770);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "��");
        }
        set("armor_prop/armor",5);
        setup();
        set("value",455);
        set("volume", 4);
}
int query_autoload() { return 1; }
