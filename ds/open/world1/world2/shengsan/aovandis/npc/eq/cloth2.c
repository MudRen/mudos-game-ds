
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("��Ũ�m",({"color shirts","shirts"}) );
	set("long","�o�O�@��ܫU�𪺪�Ũ�m�A�̤W�������l�ٳQ��F�C\n");
	set_weight(870);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "��");
        }
        set("value",370);
        set("armor_prop/armor",4);
        setup();
}

