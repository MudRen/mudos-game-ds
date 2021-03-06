#include <weapon.h>
#include <ansi.h>
inherit SSERVER;
inherit FORK;

void create()
{
        set_name( HIC "悲嚎槍" NOR,({"sadness howl pike", "pike"}) );
        set("long",@LONG
東武林祭乾坤五大神器之一，為司馬吟風與其餘五兄弟於古洞中所獲
，後傳與其小兒子驚虹留恨手中。悲嚎槍一出動，會發出泣天動地的
悲嚎魔音，影響人之心智。此槍後來不知流落何處。
LONG
        );
        set_weight(4000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","把");
                set("value",8000);
                set("volume",3);
                set("limit_level",40);
                set("limit_skill",70);
        }
        set("weapon_prop/shield",10);
        set("weapon_prop/armor",10);
        set("weapon_prop/bar", -1);
        set("weapon_prop/sou", 1);
        init_fork(60);
        setup();        
}

void attack(object me, object victim)
{
    ::attack();
    if(!me) return;
    if(!victim) return;

    if( me->query_skill("sword") < 80 ) return;
    if( me->query_dex() < 50 ) return;
    if( random(100) < 80 ) return;      /* 20% 的特攻發動率 */

        message_vision(HIB"悲嚎槍出泣天動地的悲嚎魔音，$n"HIB"的心智大受影響！！\n" NOR, me, victim);
//        victim->receive_damage("hp", 10 + random(40), me);      /* 10~49 */
        victim->start_busy(1);
}

