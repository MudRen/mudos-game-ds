#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name("�çL��A",({ "uniform of guard","uniform" }) );
        set("long","�@����Ŭ۶�����A�A��W��@�w�ܯ���I�I\n");
        set_weight(200);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",1);
         set("material","cloth");
                set("unit", "��" );
       set("value",30);
                set("armor_prop/armor", 2);
        }
        setup();
}

