#include <weapon.h>
#include <ansi.h>

inherit F_UNIQUE;
inherit DAGGER;

void create()
{
        set_name(HIC"入雲龍"NOR, ({ "dragon dagger","dagger" }) );
        set_weight(2200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把"); 
                set("long", "傳說中這是絕命雙煞的成名武器，與泣心合稱雙絕匕，但泣心已不見江\n"
                            "湖多年，剩下的這把入雲龍在匕界之中已可稱王，你仔細一看，刃身微\n"
                            "泛藍色，隱隱帶有寒霜之氣，是一把極為高級的匕首•\n");
                set("value", 23000);
                set("material", "steel");
                set("volume",1);
                set("limit_str",20);
                set("limit_dex",50);
                set("limit_level",40);
                set("limit_skill",60);
        }
        init_dagger(53);
        set("replica_ob", __DIR__"iron_dagger.c");
        set("weapon_prop/int", 3);
        set("weapon_prop/dex", 2);
        set("weapon_prop/str", 2);
        set("wield_msg", "$N單手握住$n，霎時一陣寒氣直衝靈堂穴。\n");
        set("unwield_msg", "$N將手中的$n藏入懷中。\n");
        setup();
}

void attack(object me,object victim)
{
        int i;
        object *enemy;
        ::attack();
        if(!me) return;
        if(!victim) return;
        if(me->is_busy()) return;
        if(random(4)) return; 
        message_vision(HIC"$N手中的入雲龍突噴出一股寒氣，眼前敵人無一悻俛，皆成冰柱•\n"NOR,me);
       
        enemy = me->query_enemy();
        for(i=0;i<sizeof(enemy);i++)
        { 
        enemy[i]->start_busy(random(3)); 
        enemy[i]->receive_damage("ap", 30+random(30), me);
        }
        return;
}


