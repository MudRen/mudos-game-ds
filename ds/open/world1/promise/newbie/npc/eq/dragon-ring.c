#include <armor.h>
inherit FINGER;

void create()
{
        set_name("�s����",({"dragon ring","ring"}) );
        set("long",@LONG
���s��̰��Ť�����A�s�Z�Ҩرa
LONG
);
        set_weight(300); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_con",20);
                set("unit", "�u");       
                set("value",1200);          
                set("volume", 2);      
                set("limit_lv",10);                 
                set("material", "stone");   
        }
        set("armor_prop/armor",1);       
        set("armor_prop/str",1);

        set("armor_prop/con",1);
        setup();
}



