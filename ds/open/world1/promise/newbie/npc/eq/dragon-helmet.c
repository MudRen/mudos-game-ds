#include <armor.h>
inherit HEAD;

void create()
{
        set_name("�s����",({"dragon helmet","helmet"}) );
        set("long",@LONG
���s��̰��Ť�����A�s���Ҩرa
LONG
);
        set_weight(300); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_con",20);
                set("unit", "��");       
                set("value",2000);          
                set("volume",4);      
                set("limit_lv",10);                 
                set("material", "stone");   
        }
        set("armor_prop/armor",3);       
        set("armor_prop/int",1);

        set("armor_prop/dex",1);
        setup();
}

