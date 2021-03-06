#include <ansi.h>

void do_fight_issue();        
void do_fight_heal();                   // 補血
void do_fight_help();                   // 求援

string file_path = "/open/world1/tmr/crush_bone/npc/";         // 求援的npc位置
string *mob_file = ({ "orc_follower.c",
                      "orc.c",
                      "orc_hundred_leader.c",
                      "orc_thousand_leader.c",
                      "orc_commander.c",
                      "orc_commander.c",
                      "orc_commander.c",
                      "orc_herald.c",
                      "orc_herald.c",
                      "orc_envoy.c",
//                      "orc_emperor.c"
                   });

// 半獸人特攻
void do_fight_issue()
{
        int dmg;
        object me, target;
        me = this_object();
        if( !me || me->is_busy() ) return;
        if( !me->is_fighting() ) return;
        target = me->select_opponent();
        if( !target ) return;
    if( environment(target) != environment(me) ) return;

        switch(random(4)) {
                case 0:
                        message_vision("$N狂性大發對著$n使出"HIR"魯莽猛擊"NOR"，欺上前來就是一陣亂打！！\n"NOR, me, target);
                        me->attack();
                        me->attack();
                        me->attack();
                break;
                case 1:
                        message_vision("$N對著$n的腳踝處使出"HIG"斷筋"NOR"，$n感到一陣劇痛，行動有些不便！\n"NOR, me, target);
                        target->start_busy(1);
                break;

                case 2:
                    // emperor 會用恐懼術
                    if( !me->id("_ORC_EMPEROR_") ) {
                        message_vision("$N殺的眼紅，不分青紅皂白使出"HIC"旋風斬"NOR"，$n一時之間不知道怎麼應付這雜亂的招法！\n"NOR, me, target);
                        dmg = me->query_damage() - target->query_shield();
                        if(dmg<1) dmg= 10;
                        dmg = COMBAT_D->Merits_damage(me, target, dmg, "bar");
                        target->receive_damage("hp", dmg, me);
                        COMBAT_D->report_status(target);
                    } else {
                        message_vision(HIM"$N雙手泛著紫光，嘴裡唸唸有辭，雙手往前一推打向$n，$n心裡開始覺得「恐懼」。\n"NOR, me, target);
                        target->apply_condition("fear", target->query_condition("fear") + 3 + random(3) );
                        target->start_busy(1);
                    }

                break;
       default:
                        message_vision("$N殺的眼紅，不分青紅皂白使出"HIC"旋風斬"NOR"，$n一時之間不知道怎麼應付這雜亂的招法！\n"NOR, me, target);
                        target->receive_damage("hp", me->query_damage()/3 + random(me->query_damage()/3), me);
                COMBAT_D->report_status(target);
                break;
        }

}

void do_fight_heal()
{
    object me, hurter, target;
        me = this_object();
        if( !me || me->is_busy() ) return;
        if( !me->is_fighting() ) return;

        target = me->select_opponent();
        if( !target ) return;

    // 敵人的敵人(應該是自已人)
        hurter = target->select_opponent();

    if( !hurter || !objectp(hurter) ) {        
        do_fight_issue();                     // 如果沒有找到要補血的人則自已用特功
        return;
    }

    if( hurter->query("hp") > hurter->query("max_hp")*80/100 ) {
                if( target->query("ap") < target->query("max_ap")*70/100) {
                    message_vision(HIW"$N"HIW"放出心靈震爆的法術，瞬間$n"HIW"被"HIM"紫色光芒"HIW"包圍住...\n"NOR, me, target);
                        target->receive_damage("ap", me->query_damage()/3 + random(me->query_damage()/3) ,me);
                        return;
                }
                if( target->query("mp") < target->query("max_mp")*70/100) {
                    message_vision(HIW"$N"HIW"放出心靈腐蝕的法術，瞬間$n"HIW"被"HIR"紅色光芒"HIW"包圍住...\n"NOR, me, target);
                        target->receive_damage("ap", me->query_damage()/3 + random(me->query_damage()/3) ,me);
                        return;
                }
        do_fight_issue();                     // 如果血量還足夠則自已用特功
        return;
    }

    message_vision(HIW"$N"HIW"嘴裡唸唸有辭，瞬間$n"HIW"四周圍散出白色光芒...\n"NOR, me, hurter);
    hurter->receive_heal("hp", 500 );
}

void do_fight_help()
{
    int i;
    string file;
    object *mob_list;
        object me;

        me = this_object();

        if( !me || me->is_busy() ) return;
        if( !me->is_fighting() ) return;

    switch( random(100) ) {
        case 0..40: do_fight_issue(); return;
        case 41..60: break;
        default: return;
    }

    file = file_path + mob_file[random(sizeof(mob_file))];

    if( sizeof(mob_list = children(file)) ) {
        for(i=0; i<sizeof(mob_list); i++) {
            if( !environment(mob_list[i]) ) {
                destruct(mob_list[i]);
                continue;
            }

            if( mob_list[i]->is_busy() || mob_list[i]->is_fighting() ) continue;

            // 同群的MOB必設有設定 set("vendetta_mark", "xxx"); 結仇，這樣MOB移過來後會自動攻擊
            if( mob_list[i]->move(environment(me)) ) {
                message_vision(HIR"$N"HIR"發出刺耳而嘶吼的狂叫聲，引來附近的$n。\n"NOR, me, mob_list[i]);
                return;
            }

            do_fight_issue();               // 救援者無法移過來則自已用特功
            return;
        }
    } else do_fight_issue();                     // 找不到人來幫，自已用特功
}

