#include <armor.h>
inherit WAIST;

void create()
{
	set_name("�p�ֱa",({"small belt","belt"}));
	set("long",@LONG
�o���ֱa�ݰ_�Ӧ��G���ӭ@�Ϊ��ˤl�C
LONG
	);
	set_weight(1600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "skin");
		set("unit", "��");
	}
	set("auto_set",2);
	setup();
}
// int query_autoload() { return 1; }

