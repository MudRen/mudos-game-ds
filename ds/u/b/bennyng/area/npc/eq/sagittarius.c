#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name(HIY"�g��y�����t��"NOR, ({ "sagittarius armor","armor" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�o��N�O���D�Q�G�c���ĤE�c���g��y�t��\n");
                set("unit", "��");
                set("material", "steel");
                set("value",20000);
                set("armor_prop/con",10);
                set("armor_prop/dex",15);
                set("armor_prop/str",5);
                set("armor_prop/dodge",15);
                set("armor_prop/shield",10);
                set("armor_prop/armor", 40);
                set("armor_prop/bar",2);
                set("armor_prop/bio",2);
                set("wear_msg","$N��W$n,$N�P�즳�@�ѯ��O�]���$N!");
                set("remove_msg","$N���U�F$n,�A�����O�����F");
        }
        setup();
}
