#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("�Ǧ�D�T",({"gray robe","robe"}) );
        set("long",@long
�o�O�@��Ǧ⪺�D�T�A�����u�Ъ��A���C
long
);
        set_weight(1200);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("volume",2);
                set("unit", "��");
                 set("value",500);
                set("armor_prop/armor", 5);
        }
        setup();
}


