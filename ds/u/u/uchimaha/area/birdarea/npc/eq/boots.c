#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name(HIC"�оc"NOR, ({ "feather boots","boots" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�o���c�l�W�������F�Ф�, �ݰ_�ӫD�`�ŷx.\n");
                set("unit", "��");
                set("value",300);
                set("material", "silk");
                set("armor_prop/armor", 5);
        }
       setup();
}
