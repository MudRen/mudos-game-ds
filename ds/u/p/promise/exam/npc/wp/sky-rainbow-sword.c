#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name(HIM"天"HIG"虹"HIW"劍" NOR, ({ "sky rainbow sword","sword" }) );
        set_weight(10000);
        if( clonep() )
                 set_default_object(__FILE__);
        else {
                set("unit", "把");
        set("material","crimsonsteel");
                set("limit_str",40);
                set("limit_con",50);
                set("limit_int",20);
                set("limit_dex",30);
                set("long",
            "此劍成七彩色狀，其攻擊力不在話下。\n");
                set("wield_msg", HIY"$N持起天虹劍後，便顯現了七彩光束環繞在$N身旁。\n"NOR);
                set("unwield_msg", HIW"$N放下了天虹劍，便少了七彩亮光。\n");
        set("value",10000);
        }
        set("weapon_prop/con",2);
        init_sword(69);
        setup();
}
void attack(object me,object victim)
{
        int damage,str,con,random1;
        ::attack();
        if(!me) return;
        if(!victim) return;
        if( random(200)>150)
        {
        str = me->query("str")-random(22);
        con = me->query("con")-random(20);
        random1 = 1+random(2);
        damage = random1*(str+con)/5;
        victim->receive_damage("hp", damage, me );
        message_vision(HIM"天"HIG"虹"HIW"劍"HIM"發出七彩光束，七色光芒直衝向$N"HIR"(-"+damage+")\n"NOR      
                ,victim);
        return;
        } 
        }

