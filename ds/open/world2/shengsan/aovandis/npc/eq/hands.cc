#include <armor.h>
inherit HANDS;

void create()
{
	set_name("���M",({"typical gloves","gloves"}));
	set("long",@LONG
�o�O���Z�}���u�éҸ˳ƪ���M�C
LONG
);
	set_weight(1900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "��");
		set("material", "cloth");
        }
        set("auto_set",2);
        setup();
}

//int query_autoload() { return 1; }
