#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name(HIR "��ù������" NOR,({ "shu lo helmet","helmet"}) );
        set("long","�|�j������@���P�D�ۨϥΪ�����C\n");
        set_weight(2400);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cold");
                set("unit","��");
        }
        set("value",4000);
        set("armor_prop/armor",15);
        set("armor_prop/con",1);
             setup();
        set("volume",3);
}

