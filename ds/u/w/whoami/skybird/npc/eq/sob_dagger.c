#include <weapon.h>
#include <ansi.h>
inherit DAGGER;
void create()
{
        set_name(HIR"泣心"NOR, ({ "sob dagger","dagger" }) );
        set_weight(1800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把"); 
                set("long", "傳說中這是絕命雙煞的成名武器之一，據說此匕原為一位女俠所有，似\n"
                            "乎和天梟有一段難解的緣份•這把匕首到了每月二十二日的夜晚，都會\n"
                            "發出哭泣之聲，且從匕鞘發出安慰之聲撫慰•不過傳說歸傳說，這一把\n"
                            "匕首刀身微泛暗紅，似乎有一股血光之氣附在其上•\n");
                set("value", 3300);
                set("material", "steel");
                set("volume",1);
        }
        init_dagger(39);
        set("wield_msg", "$N單手握住$n, 霎時一陣熱氣直衝百里穴！\n");
        set("unwield_msg", "$N將手中的$n藏入懷中。\n");
        setup(); 
        call_out("sob", 60);
}

void sob()
{
        object me = environment(this_object());

        if( !this_object() || !me ) return;
        if( interactive(me) && me->query_temp("weapon") == this_object())
        {
        message_vision(CYN"$N突然發出一陣淒厲的哭號之聲，聞者皆不寒而慄……\n"NOR, this_object());
        }
        call_out("sob", 120);
}

