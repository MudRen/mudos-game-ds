#include <armor.h>
inherit ARMOR;

void create()
{
	set_name("�ѯűj���K��",({"c-iron armor","armor"}) );
	set("long",@LONG
�o�O�@��ѯ��K���y�Ӧ����p���@�ҡA�øg�L�ѯűj�ƻ{�ҡC
LONG
);
	set_weight(13050);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "iron");
                set("unit", "��");
        }
        set("armor_prop/armor",23);
        setup();
        set("value",4680);
        set("volume", 10);
}

//int query_autoload() { return 1; }
