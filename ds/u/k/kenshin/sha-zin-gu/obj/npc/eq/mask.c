#include <armor.h>
#include <ansi.h>
inherit MASK;
void create()
{
        set_name(NOR""YEL"�F�H����"NOR, ({ "desert mask","mask" }) );
        set_weight(700);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","�F�z���H�̾רF�Ъ�����\n");
                set("unit", "��");
                set("value",2400);
                set("material","fur");
                set("armor_prop/con",2);
                set("armor_prop/armor",4);
        }
        setup();
}

