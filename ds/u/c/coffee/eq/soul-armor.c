#include <armor.h>
#include <ansi.h>
inherit ARMOR;

void create()
{
        set_name(HIC"��"HIY"��"HIR"�ԥ�"NOR, ({ "soul armor","armor" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
          set("long","�@����餣�w���Z�ҡA���O���m�O�Q���A���G�����_���O�q�C");
                set("unit", "��");
                set("value",10000);
        }
       set("wear_msg","$N��$n��_�ӫ�A�ݰ_�ӧ�[���c�F�I\n");

   set("unwear_msg","$N�q��W��$n��F�U�ӤF�A�y���P�F�@�f��C\n"NOR);
                  set("armor_prop/armor", 20);
        set("armor_prop/bar", 1);
        set("armor_prop/tec", -1);
        set("armor_prop/wit", -1);
        set("armor_prop/con", 3);
        set("armor_prop/str", 2);
        set("armor_prop/int", -1);
        setup();
}
