#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name("�t�M�Y��",({ "holy knight helmet","helmet"}) );
        set("long","�o�O�q�L�t�M�h���窺�H�~�֦����F��C\n");
        set_weight(2400);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "crimsonsteel");
                set("unit","��");
        }
        set("value",3300);
        set("limit_lv",20);
        set("armor_prop/armor",15);
        set("armor_prop/con",1);
        set("armor_prop/str",1);
        setup();
}


