#include <ansi.h>
#include <armor.h>
inherit PANTS;

void create()
{
        set_name(HIM"��ظ�"NOR,({"moon skirt","skirt"}) );
        set("long",@LONG
�p�����X�M����´�Ȥl�A���o�۰��������C
LONG
);
        set_weight(300); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("female_only",1);
                set("unit", "��");       
                set("value",800);          
                set("volume", 2);                       
                set("material", "silk");   
        }
        set("armor_prop/armor",3);       
        setup();
}


