#include <armor.h>
inherit ARMOR;

void create()
{
	set_name("�զ���T",({"white cloth robe","robe","white robe"}) );
	set("long",@LONG
�o�O�@��զ⪺���T�A���T�W���o�ۤ@�ѲH�H���ȭ����C
LONG
);
	set_weight(3250);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "��");
        }
        set("armor_prop/armor",12);
        set("armor_prop/shield",6);
        set("armor_prop/int",1);
        setup();
        set("value",1160);
        set("volume", 6);
}

int query_autoload() { return 1; }
