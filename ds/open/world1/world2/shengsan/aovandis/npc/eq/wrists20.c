
#include <armor.h>
inherit WRISTS;

void create()
{
	set_name("�B���@�u",({"sport wrists","wrists"}) );
	set("long",@LONG
�o�O�@��󽦻s���@�u�A�Ψ��קK�B�ʥi��y�������ˡC
LONG
);
	set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "��");
		set("material", "rubber");
	}
	set("auto_set",2);
	setup();
}

//int query_autoload() { return 1; }
