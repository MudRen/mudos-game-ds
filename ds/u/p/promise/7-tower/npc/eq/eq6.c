#include <armor.h>
#include <ansi.h>
inherit HANDS; void create()
{
        set_name(HIM"����"HIC"��M"NOR, ({ "greedy gloves","gloves" }) );
        set_weight(200);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long",HIC"\n����M���m�O��ΡA�O�j�ɥN���]�j�ԯd�U�Ӫ������C\n"NOR);
                set("unit", "��");
                set("value",7000);
                set("material","silk");
                set("armor_prop/str",1);
                set("armor_prop/int",4);
                set("armor_prop/wit",-2);
                set("armor_prop/sou",-2);
                set("armor_prop/tec",-2);
                set("armor_prop/bar",1);
                set("armor_prop/armor", 10);
                set("limit_lv",40);
                set("limit_str",50);
                set("limit_con",50); 
                set("limit_int",30);
                set("limit_dex",35);
        }
        setup(); 
}

