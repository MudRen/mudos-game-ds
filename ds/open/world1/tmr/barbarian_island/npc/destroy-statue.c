/* 強化系sk：破壞拳
 * -Tmr 2002/05/08
 */
inherit ITEM;
#include <ansi.h>
#include <skill.h>

#define QUEST "barbarian_island/destroy-fist"

void create()
{
        set_name("破壞神石像", ({ "destroy statue", "statue" }));
        set_weight(99999);
        if( !clonep() ) {
                set("unit", "個");
                set("value",100);
                set("no_get",1);
                set("container_unit", "尊");
                set("long",@long
    這是一尊島上野蠻人所祭拜的破壞神石像，不知從什麼時候開始受到
大家的祭拜，似乎它擁有奇特的神力，能賦于人們更強大的破壞力，你瞧
見石像全身上下有著新舊大小不同的血跡，不知是因為在此發生過戰鬥，
還是有人碰撞(collide)它受傷以致血留在上頭的關係。

(本任務為解強化系特殊技「破壞拳」之用，如你不想學習，請勿嘗試解本任務。)
long
        );
        }
        setup();
}
void init()
{
        add_action("do_collide","collide");
}

int do_collide(string arg)
{
        object me=this_player();
        int cost=5+random(5);
        if(!me || !userp(me) ) return 0;
        if(!arg || arg!="statue") return 0;
        if(me->is_busy() || me->is_fighting() )
                return notify_fail("你正忙著，請先停下手邊的工作吧。\n");
        if( me->query("skills_point")+3>SKILL_MAX_POINT )
                return notify_fail("你的技能點數已滿，無法成功解得此任務。\n");
        if( me->query_learn("destroy fist") )
                return notify_fail("你已經學到「破壞拳」了，無法成功解得此任務。\n");
         if( me->query_stat("hp") < 10 )
                return notify_fail("你現在的身體狀態不好，無法用身體衝撞石像。\n");
        switch( random(4) )
        {
                case 0:
                        message_vision(HIR"$N大喊一聲，一頭就往石像上衝去，結果撞得頭破血流....\n"NOR,me);
                break;
                case 1:
                        message_vision(HIR"$N咬緊牙根奮力撞向石像，結果撞出了內傷，吐了幾口鮮血....\n"NOR,me);
                break;
                case 2:
        		message_vision(HIR"$N使出力氣撞向石像，結果「喀喇」一聲，竟然是肩骨撞斷了...\n"NOR,me);
                break;
                case 3:
                        message_vision(HIR"$N狠狠撞向石像，撞得頭昏眼花、久久不能保持清醒..\n"NOR,me);
                break;          
        }
        me->consume_stat("hp",cost);
        me->add_temp(QUEST,1+random(me->query_attr("int")) );
        me->start_busy(1);
        if( me->query_temp(QUEST) > 5000 ) {
                me->delete_temp(QUEST);
                me->improve_skill("destroy fist",100);
                me->add("skills_point",3);
                tell_object(me,
                HIY "你忽然領略到「破壞拳」的精義了！！\n" NOR
                +HIG"(你的技能學習點數花掉三點。)\n" NOR
                );
        }
        return 1;
}

