#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("�B�ʪA",({"short clothes","clothes"}) );
	set("long",@LONG
�o�O�@���ťլ۶����B�ʪA�A�Q�����u�ʡC
LONG);
	set_weight(1370);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "��");
        }
        set("armor_prop/armor",7);
        setup();
        set("value",910);
        set("volume", 4);
}
int query_autoload() { return 1; }
