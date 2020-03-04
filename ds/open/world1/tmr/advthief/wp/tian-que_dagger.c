#include <ansi.h>
#include <weapon.h>

inherit DAGGER;

void create()
{
        set_name("天缺匕",({"tian-que dagger","dagger"}) );
        set("long",@LONG
這是天下第一盜賊-賊帥慣用的匕首，其造形花巧，直奪天地造化之
工，銀白色的匕鋒帶著一絲紫藍色的水痕。
LONG
);
         set_weight(2500);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","把");
                set("value",5000);
        }
        set("weapon_prop/dex",1);
        set("weapon_prop/str",1);
        set("limit_level",25);
        set("limit_dex",50);
        init_dagger(45);
        set("backstab_bonus",40); //百分比
        setup();        
}

