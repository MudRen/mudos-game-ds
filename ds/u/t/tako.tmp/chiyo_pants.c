#include <ansi.h>
#include <armor.h>
inherit PANTS;
void create()
{
        set_name(WHT"��ӽ�"NOR ,({ "kneel pants","pants" }) );
        set("long",
"�@���𽯩ұ������u��,�u�콥�\,�ڻ��O�E�תF���ɴ��Ҧۻs���C\n"
);
        set_weight(400);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��" );
                set("value" ,50);
                set("material","linen");
        }
        set("armor_prop/armor", 2);
        set("armor_prop/str", 1); 
        set("armor_prop/int",2);        
setup();
}


