#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name(HIR"��ù���c��"NOR, ({ "shu lo boots","boots" }) );
        set_weight(2800);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","�|�j������@���P�D�ۨϥΪ�����C\n");
                set("unit", "��");
        set("value",4900);
                set("material","cold");
                 set("armor_prop/con",1);
                 set("armor_prop/armor", 15);
        }
        setup();
}

