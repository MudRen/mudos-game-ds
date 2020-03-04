// 不平衡的武器 update by Tmr 2006/06/07
// fixed bug update by whoami 2007/03/22
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void sword_check();
void create()
{
    set_name(HIC"陰"HIR"陽"HIW"長劍"NOR,({"yin-yang longsword","sword","longsword"}));
    set("power", 1);
    set("long","這是一把由獨臂老人所打造出來的最佳傑作，劍刃的地方有著絲\n"
            "絲的寒氣，寒氣的外圍卻又包圍了一層暖氣，入手之後，令人為\n"
            "之一震。\n");
    set("wield_msg","$N從背後抽出一把$n，只見$N身旁圍繞著一股陰陽調和之氣。\n");
    set("unwield_msg","$N放下手中的$n，將$n插入背後的劍鞘中。\n");

    set_weight(17000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "把");
        set("value",5000);
        set("material","blacksteel");
    }
        set("limit_str",40);
        set("limit_int",40);
        set("limit_dex",60);
        set("limit_level",47);
        set("weapon_prop/bar", -1);
        set("weapon_prop/bio", -1);
        set("weapon_prop/wit", 1);
        set("weapon_prop/int", 2 );
        set("weapon_prop/dex", -2);
        set("weapon_prop/hit",15);
    init_sword(40);
    setup();
}

void attack(object me,object victim)
{
        object ob =this_object();
    int ap;

    ::attack();
    if(!me) return;
    if(!victim) return;
    if( me->is_busy() ) return;
    if( random(100) > 10 ) return;


        ap = random(me->query("max_ap")*11/50);
    message_vision(HIG"\n$N"HIG"手中的$n"HIG"發出一股溫暖的氣息，讓$N"HIG"的內勁在惡鬥之中不降反升。\n\n"NOR,me,ob);
    me->receive_heal("ap",ap);

    return;
}

