#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
        set_name(HIR"��ù���٢�"NOR, ({ "shu lo ring","ring" }) );
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","�|�j������@���P�D�ۨϥΪ�����C\n");
                set("unit", "�u");
        set("value",3200);
        set_weight(400);
              set("material","jade");
                set("armor_prop/armor", 5);
                 set("armor_prop/con",1);
        }
        setup();
}

