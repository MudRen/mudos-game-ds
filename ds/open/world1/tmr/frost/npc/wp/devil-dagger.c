#include <ansi.h>
#include <weapon.h>

inherit DAGGER;

void create()
{
        set_name(HIR "邪靈匕首" NOR,({"devil dagger","dagger"}) );
        set("long",@LONG
    這是一把血紅的匕首，匕鋒就算在漆黑的夜晚也能散發出足以照明的
紅光，握柄上刻著數種妖魔的模樣，其刻工精細而使得每尊妖魔的造型栩
栩如生，似乎隨時會衝出來傷害你一樣。
LONG
);
         set_weight(2500);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","把");
                set("value",5000);
        }
        set("light",1);
        set("weapon_prop/dex",1);
        set("weapon_prop/bio",1);
        set("weapon_prop/sou",1);
        set("limit_level",25);
        set("limit_dex",50);
        init_dagger(38);
        set("backstab_bonus",40); //百分比
        setup();        
}

void init()
{
        if(!this_object()->query_light()) this_object()->start_light(1);
}

