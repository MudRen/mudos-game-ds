
#include <armor.h>
inherit LEGGING;

void create()
{
	set_name("�@��",({"leggings"}) );
	set("long",@LONG
�o�O�ΨӨ���B�ʶˮ`���@���C
LONG
);
	set_weight(1900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "iron");
		set("unit", "��");
	}
	set("auto_set",2);
	setup();
}

// int query_autoload() { return 1; }
