#include <armor.h>
inherit BOOTS;

void create()
{
	set_name("�֭�����c",({"leather high heels","heels"}) );
	set("long",@LONG
�o�O�@���k�ʱ`�諸�ֻs����c�C
LONG
);
	set_weight(2300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "leather");
		set("unit", "��");
	}
	set("female_only",1);
	set("value",620);
	set("armor_prop/armor", 5);
	setup();
	set("volume", 4);
}

int query_autoload() { return 1; }
