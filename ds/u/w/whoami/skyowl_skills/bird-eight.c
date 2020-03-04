#include <ansi.h>
inherit SKILL;
inherit SSERVER;

string *dodge_msg = ({
                         HIR"\n突然$n血紅的雙眼放出殺氣，像老鷹一般，嚇的$N不敢靠近$n。\n"NOR,
                         "\n$n突然像背後插了雙翅膀一樣的活動迅速，讓$N無從攻擊起。\n",
                         "\n$n突然像鴕鳥般的急衝起來，讓$N出手的時間大亂，因此避過此招。\n",
                         "\n$n閉上雙眼，腦中想著踩石樁陣的情形，腳也踩起石樁陣式，讓$N無從下手。\n",
                         "\n$n雙腳一蹬，直衝上天，一式"+HIC+"【驚弓之鳥】"+NOR+"漂亮的落在$N身後。\n",
                         "\n突然$n腳步變輕，一招"+HIM+"【返樸歸真】"+NOR+"，在$N的攻勢中遊走四方。\n",
                         "\n突然$n放慢了腳步，忽進忽退，使$N完全摸不著頭腦。\n",
                         "\n煞那間，$n的雙眼發出異樣的光芒，動作比平常要快上數倍，使$N完全碰不到$n一根寒毛。\n",
                     });

void sp_1(object me, object target)
{
    int sk = me->query_skill("bird-eight"), lv = me->query("level"), consume_ap = 50, BusyTime, tint=target->query_int(), myint=me->query_int();
    if( lv > 25 )
        consume_ap = (4*sk) / lv;
    if( consume_ap > 50 )
        consume_ap = 50;
    BusyTime = sk/33;
    if( !me->is_busy() && !target->is_busy() && (tint) <  (1+random(3))*(myint) && !me->query_temp("bird/sp_hint") )
    {
        message_vision(HIC"$N的動作雖然緩慢，然而他的身影卻幻化萬千，一如有形無質的幽靈，令$n無法揣摩。\n"NOR,me,target);
        target -> start_busy(BusyTime);
        me -> receive_damage("ap",consume_ap);
        me -> add_temp("bird/sp_hint", 1);
    }
}

void sp_2(object me, object target)
{
    object *s_target, target_1;
    int x;
    s_target = all_inventory(environment(me));
    if( !me->query_temp("bird/sp_hint") && me->query("quest/bird-eight") && random(150) < (me->query("level")) )
    {
        for(x=0;x<sizeof(s_target);x++)
        {
            if(!s_target[x]->is_fighting(me))
                continue;
            target_1 = s_target[x];
            message_vision(HIC"$N的身子依著靈翼八步的心法高高升起，整個身子鬼魅一般向後疾退，$n的殺招轉瞬間落到別人的身上了。\n"NOR,me,target);
            if( target->query_temp("weapon") )
            {
                COMBAT_D->do_attack(target,target_1,4);
                COMBAT_D->report_status(target_1);
            }
            else
            {
                COMBAT_D->do_attack(target,target_1,target->query_temp("weapon"),4);
                COMBAT_D->report_status(target_1);
            }
            me -> add_temp("bird/sp_hint", 1);
            me -> receive_damage("ap", 8);
            break;
        }
    }
}

void sp_3(object me, object target)
{
    object weapon = me->query_temp("weapon");
    int x,y,mydex=me->query_dex(),tdex=target->query_dex();
    y = me->query_tec()/4;
    y = 1+random(y);
    if( y > 3)
        y = 3;

    if( weapon->query("skill_type") == "throwing" && mydex > tdex && !me->query_temp("bird/sp_hint") )
    {
        message_vision(HIW"$N身子化為隨風柳絮，迎著$n斜斜飛起，當到了一個高度的極點，$N深吸一口氣，雙腿一點，縱上了半空，接著身子宛如在空中滑行一般沖向$n！\n"NOR, me, target);
        me -> add_temp("bird/sp_hint", 1);
        for(x=0;x<y;x++)
        {
            COMBAT_D->do_attack(me,target,weapon);
            COMBAT_D->report_status(target);
        }
    }
}


int exert(object me, object target, string arg)
{
    string msg;

    int dodge_apply  = me->query_skill("bird-eight"),
                       temp = me->query_temp("bird/temp");

    if(arg=="off" )
    {
        if( me->query_skill_mapped("dodge")!="bird-eight")
            return notify_fail("你並沒有使用『靈翼八步訣』。\n");
        me->map_skill("dodge");
        me->reset_action();
        me->add_temp("apply/dodge",- temp);
        me->delete_temp("bird/dodge_apply");
        message_vision("\n"CYN"$N的眼睛慢慢轉為平常的顏色，而原本輕盈的腳步也逐漸趨緩。\n"NOR,me);
        write("技能『靈翼八步訣』已取消。\n");
        return 1;
    }

    if(me->query_skill("dodge")<20)
        return notify_fail("以你的輕功\基礎無法使用『靈翼八步訣』。\n");

    //錯1. if(me->query_skill_mapped("dodge")=="mirage-steps")
    if(me->query_skill_mapped("dodge")=="bird-eight")  //luky更正
        return notify_fail("你已經在使用『靈翼八步訣』。\n");

    if(me->query("ap")<50 || me->query("hp")<50)
        return notify_fail("你的身體狀無法使用『靈翼八步訣』。\n");

if(!me->skill_active( "bird-eight",(: call_other, __FILE__, "delay", me :), 10))
        return notify_fail("你的靈翼八步訣收招動作還沒完成。\n");

    if(me->query_skill("sky-throwing")>60)
        dodge_apply += me->query_dex()/4;

    if(me->query("class2") == "skyowl_med")
        dodge_apply = dodge_apply/2;

    if(me->query("class2") == "skyowl_military")
        dodge_apply = dodge_apply*85/100;

    if(!me->query("class2") && me->query("class1") == "skyowl")
        dodge_apply = dodge_apply*4/10;

    dodge_apply = dodge_apply - me->query_skill("sky-dagger")/5;
    if( dodge_apply < 0 )
        dodge_apply = 0;

    // 錯2. me->map_skill("dodge", "mirage-steps");
    me->map_skill("dodge", "bird-eight"); //luky 更正
    me->reset_action();
    me->add_temp("apply/dodge",dodge_apply);
    me->set_temp("bird/temp",dodge_apply);

    message_vision("\n"HIR"$N的雙眼突然轉為血紅色，捕捉敵人的一舉一動，準備使出傳說中的『靈翼八步訣』。\n"NOR,me);
    me->receive_damage("ap",15);
    me->start_busy(1);
    //錯3. call_out("delay",10,me);
    return 1;
}

void delay(object me)
{
    int temp = me->query_temp("bird/temp");
    if(!me)
        return;

    if(me->query_skill_mapped("dodge")!="bird-eight")
    {
        //免. remove_call_out("delay");
        return;
    }

    if(me->query("ap")<50)
    {
        me->map_skill("dodge");
        me->reset_action();
        message_vision("\n"HIW"$N的眼光漸漸恢復為正常顏色，而原本輕盈的腳步也逐漸趨緩。\n"NOR,me);
        me->add_temp("apply/dodge",- temp);
        me->delete_temp("bird/temp");
        tell_object(me,"你的體力不足無法繼續使用『靈翼八步訣』。\n");
        //免. remove_call_out("delay");
        return ;
    }
    //    if ( me->is_fighting() ) me->receive_damage("ap",2); //沒加戰鬥判斷
    //錯. call_out("delay",10,me);
me->skill_active( "bird-eight",(: call_other, __FILE__, "delay", me :), 10);
}

int valid_learn(object me)
{
    return 1;
}

string query_dodge_msg(string limb, object me, object target)
{
    int sk = me->query_skill("bird-eight");

    if( sk > 95 && me->query("class2") == "skyowl_step" )
        sp_3(me, target);
    if( sk > 80 && me->query("class2") == "skyowl_step" )
        sp_2(me, target);
    if( sk > 60 && me->query("class2") == "skyowl_step" )
        sp_1(me, target);

    me->receive_damage("ap",2);
    me->delete_temp("bird/sp_hint");
    return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
    return 1;
}

int improve_limite(object me)
{
    int a;
    a=me->query_dex()+me->query_int();
    if(a>100)
        a=100;
    return a;
}


