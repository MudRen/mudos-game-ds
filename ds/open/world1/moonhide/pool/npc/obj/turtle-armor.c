#include <armor.h>
#include <ansi.h> 
inherit F_UNIQUE;   
inherit ARMOR;

void create()
{
        set_name(CYN"��"HIW"��"CYN"�Z"HIW"��"NOR,({ "shang-woo armor","armor" }) );
        set("long","�ѥȪZ���t���ߩҦ������ҡA�Q���­��A�����m�O�Q���C\n");
        set_weight(10000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
                set("material","steel");
                set("unit", "��" );
                set("value",6000+random(1030));
                set("replica_ob",__DIR__"turtle-armor2");
        }
                set("limit_level",40);
                set("limit_con",40);
                set("armor_prop/armor", 45); 
                set("beast_armor_prop/armor", 45);
                set("armor_prop/con",2);
                set("armor_prop/str",2);
                set("armor_prop/dex",-1);
                set("armor_prop/wit",1);  
        setup();
}

