#include <ansi.h>
#include <armor.h>
inherit WAIST;

void create()
{
        set_name("�ָy�a",({"leather waist","waist"}) );
        set("long",@LONG
�֭��s���y�a�A�g�L�Ӥ߫O�i��{�{�o�G�C
LONG
);
        set_weight(0); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");       
                set("value",20);          
                set("volume", 1);                       
                set("material", "leather");   
        }
        set("armor_prop/armor",2);       
        setup();
}

