#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name(HIY"�B�k�y�����t��"NOR, ({ "Virgo armor","armor" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�o��N�O���D�Q�G�c���Ĥ��c���B�k�y�t��\n");
                set("unit", "��");
                set("material", "steel");
                set("value",20000);
                set("armor_prop/con",7);
                set("armor_prop/dex",5);
                set("armor_prop/int",10);
                set("armor_prop/str",1);
                set("armor_prop/dodge",5);
                set("armor_prop/shield",10);
                set("armor_prop/armor", 45);
                set("armor_prop/wit",10);
                set("armor_prop/sou",6);
                set("armor_prop/spell",6);
                set("armor_prop/bar",-10);
                set("armor_prop/bio",-10);
                set("wear_msg","$N��W$n,$N�P�즳�@�ѯ��O�]���$N!");
                set("remove_msg","$N���U�F$n,�A�����O�����F");
        }
        setup();
}
