#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name(HIY"�s�Ϯy�����t��"NOR, ({ "Capricorn armor","armor" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�o��N�O���D�Q�G�c���ĤQ�c���s�Ϯy�t��\n");
                set("unit", "��");
                set("material", "steel");
                set("value",20000);
                set("armor_prop/con",5);
                set("armor_prop/dex",5);
                set("armor_prop/str",1);
                set("armor_prop/int",1);
                set("armor_prop/dodge",10);
                set("armor_prop/shield",5);
                set("armor_prop/armor", 45);
                set("armor_prop/bar",-1);
                set("armor_prop/bio",-1);
                set("wear_msg","$N��W$n,$N�P�즳�@�ѯ��O�]���$N!");
                set("remove_msg","$N���U�F$n,�A�����O�����F");
        }
        setup();
}
