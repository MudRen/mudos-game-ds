#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name(WHT"�騸�]��"NOR, ({ "yi-chan armor","yi-chan","armor" }) );
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
              else {
                set("long","�@����񾮻A���w�ҡA�W���Φ�g��\n"
                HIR"���������D�j�̡I\n"NOR);
                set("unit", "�M");
                set("material","steel");
                set("value",40000);
                set("armor_prop/con",10);
                set("armor_prop/dex",-3);
                set("armor_prop/int",5);
                set("armor_prop/str",8);
                set("armor_prop/dodge",-5);
                set("armor_prop/shield",20);
                set("armor_prop/armor", 55);
                set("armor_prop/wit",10);
                set("armor_prop/sou",10);
                set("wear_msg","$N��W$n,$N���W����|���I");
                set("remove_msg","$N���U�F$n,$N���W������b�������C");
        }
        setup();
}
