#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("�B�ʭm",({"sport clothes","clothes"}) );
	set("long",@LONG
�o�O�@��R�}�F�Ͳ����B�ʥ𶢭m�C
LONG
);
	set_weight(2100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "��");
        }
	set("auto_set",2);
        setup();
}

// int query_autoload() { return 1; }
