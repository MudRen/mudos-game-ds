/* include 檔 write by -Acme-
*/

#include <ansi.h>

void do_attack(object who);

void do_attack(object who)
{
    int attack, damage;
    string skill_type;
    object weapon, target, *targets;

    if( !objectp(who) || who->is_busy() ) return;
    if( sizeof( targets = who->query_enemy() ) < 1 ) return;
    if( !objectp(target = targets[random(sizeof(targets))] ) ) return;
    if( who->query("hp") < who->query("max_hp")/2 ) return;
    if( environment(who) != environment(target) ) return;

    /* 使用武器 */
    if( objectp(weapon = who->query_temp("weapon")) ) 
        skill_type = weapon->query("skill_type");
    else skill_type = "unarmed";

    /* 攻擊命中 */
    attack = COMBAT_D->attack_factor(who ,skill_type)*10/15;
    attack -= COMBAT_D->dodge_factor(target, "dodge")*10/15;
    if( attack > 95 ) attack = 95;
    if( attack < 20 ) attack = 20;

    if( objectp(weapon) )
        message_vision(YEL"$N眼光乍紅，周身懸浮白霧，"+weapon->query("name")+YEL"隨著氣勁攻向$n。"NOR, who, target);
    else message_vision(YEL"$N眼光乍紅，周身懸浮白霧，伴著氣勁揮拳攻向$n。"NOR, who, target);

    if( attack > random(100) ) {
        damage = who->query_skill(skill_type)+random(who->query_damage()) - random(target->query_armor());
        if( damage > 0 ) {
            message_vision("結果一擊命中！\n", who);
            target->receive_damage("hp", damage, who); 
            if( target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                tell_object(target,HIR"( 傷害: "+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
            COMBAT_D->report_status(target);
        } else message_vision("結果似乎沒有$N任何造成傷害。\n", target);
    } else message_vision("結果被$N閃了過去。\n", target);
    return;
}
