#include <ansi2.h>
inherit SKILL;
inherit SSERVER;


void ShowMessage(object me, object target, string msg)
{
    message_vision( msg, me, target);
}

void MoxibustionFail(object me, object target, string msg)
{
    if( target != me )
        msg += HIB "$N"HIB"一個分心，針就插錯了穴位，讓$n"HIB"感到一陣昏厥•\n" NOR;
    else
        msg += HIB "$N"HIB"一個分心，針就插錯了穴位，自己感到一陣昏厥•\n" NOR;

    ShowMessage(me, target, msg);
    me->start_busy(2);
}

void ShowDamage(object me, object target,int damage)
{
    if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
        tell_object(me,HIY"("+damage+")"NOR);
    if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
        tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
    if(wizardp(me) && me->query("env/debug"))
        tell_object(me, HIR"  ("+damage+")\n"NOR);
}

void SkillImporving(object me, int Bonus)
{
    me -> improve_skill("moxibustion", 1+Bonus);
    me -> improve_skill("acupuncture-cognition", random(Bonus));
}

void rekee(object me, object target, int effect, string msg)
{
    tell_object(target, CYN"你臉由蒼白毫無血色，而變成恢復了不少血氣。\n" NOR);
    ShowMessage(me, target, msg);
    me -> receive_damage("ap", effect*4/5);
    target -> receive_heal("hp", effect);
}

void regin(object me, object target, int effect, string msg)
{
    tell_object(target, HIC"你紊亂的內息似乎有所控制，逐漸穩定了下來。\n"NOR );
    ShowMessage(me, target, msg);
    me -> receive_damage("mp", effect*4/5);
    target -> receive_heal("ap", effect);
}

void resen(object me, object target, int effect, string msg)
{
    tell_object(target, HIM"你原本精神萎靡不振，如今頓時容光煥發，精神奕奕。\n"NOR );
    ShowMessage(me, target, msg);
    me -> receive_damage("hp", effect*4/5);
    target -> receive_heal("mp", effect);
}

void advkee(object me, object target, int effect, string msg)
{
    tell_object(target, "你蒼白的臉色，因為血氣的運行，漸漸紅潤了起來。\n"NOR) ;
    me -> receive_damage("mp", effect*4);
    me -> receive_damage("ap", effect*4);

    target -> apply_condition("advkee", 10*me->query_tec());
    target -> set_temp("advkee", effect);
}

void sky(object me, object target, int effect, string msg)
{
    int ppl_cnt = 0;
    object *s_target = all_inventory(environment(me));
    int x,y = sizeof(s_target);

    // 最多8個玩家
    for(x=0;x<y && ppl_cnt < 8 ;x++)
    {
        if( !userp(s_target[x]) || !living(s_target[x]))
            continue;
        if( s_target[x] == me )
            continue;
        if( s_target[x]->is_fighting() )
            continue;   //  戰鬥中的玩家不能治療

        ppl_cnt += 1;   // 實際接受到治療的玩家數
        if( random(me->query_skill("acupuncture-cognition")) > 40 )
        {
            message_vision("$N感覺到一股氣從「命門穴」及「勞宮穴」衝出，頓時血氣的運行及內息都穩定了不少。\n", s_target[x]);
            s_target[x] -> receive_heal("hp", effect );
            s_target[x] -> receive_heal("ap", effect );
        }
        else
        {
            message_vision(HIB"$N"HIB"一個分心，針就插錯了穴位，讓$n感到一陣昏厥•\n"NOR, me, s_target[x]);
            s_target[x] -> receive_damage("mp", 10 + random(20));
            s_target[x] -> receive_damage("ap", 10 + random(20));
        }
    }
    // 一次算要花費mp
    me -> receive_damage("hp", effect*ppl_cnt);
    me -> receive_damage("ap", effect*ppl_cnt);
    me -> receive_damage("mp", effect*ppl_cnt);
    SkillImporving(me, x*(me->query_int()/8));
}

void heal(object me, object target, int effect, string msg)
{
    tell_object(target, HIC"你傷口上的血漸漸止住了，傷口慢慢地瘉合起來。\n"NOR) ;
    ShowMessage(me, target, msg);
    me -> receive_damage("mp", effect*5);
    me -> receive_damage("hp", effect*5);
    target -> receive_curing("all", effect);
}

void addAttribute(object me, object target, int effect, string msg, string type)
{
    string Attr;
    switch( type )
    {
    case "addstr":
        msg += HIY"$n"HIY"的身體變得高大強壯，肌肉糾結百髯交錯！！\n"NOR ;
        Attr = "str";
        break;
    case "addcon":
        msg += HIG"$n"HIG"的體質有了顯著的改善，整個人強健不少。\n"NOR ;
        Attr = "con";
        break;
    case "addint":
        msg += HIC"$n"HIC"腦中的思緒飛快地運轉，靈感湧泉不歇。\n"NOR ;
        Attr = "int";
        break;
    case "adddex":
        msg += HIW"$n"HIW"覺得腳步變的非常輕快，走起路來有輕飄飄的感覺，非常靈敏。\n"NOR ;
        Attr = "dex";
        break;
    }
    ShowMessage(me, target, msg);
    me -> receive_damage("ap", effect*15);
    me -> receive_damage("mp", effect*15);

    target -> start_busy(effect/5);
    target -> set_temp("add"+Attr, effect);

    target -> add_temp("apply/"+Attr, effect);
    target -> apply_condition("add"+Attr, 10*me->query_tec() );
}

void ghost(object me, object target, int effect, string msg)
{
    tell_object(target, CYN"$N"CYN"不僅手勁增強許\多，對外界的攻擊也多了不少抵抗能力。\n"NOR );
    ShowMessage(me, target, msg);
    me -> receive_damage("ap", effect*10);
    me -> receive_damage("mp", effect*10);
    me -> receive_damage("hp", effect*10);

    target -> start_busy(effect/5);
    target -> set_temp("ghost", effect);
    target -> apply_condition("ghost", 10*me->query_tec());

    // effect 最多為100/4 = 25點
    target -> add_temp("apply/damage", effect);
    target -> add_temp("apply/armor", effect);
}

int exert(object me, object target, string arg)
{
    object weapon = me->query_temp("weapon");
    string msg = "";
    int effect, sk1, sk2, Bonus;

    if( !target ) return notify_fail("請選定一個目標。\n");

    sk1 = me->query_skill("acupuncture-cognition");
    sk2 = me->query_skill("moxibustion");

    if( arg == "?" || arg == "help" )
        return notify_fail("請參考help moxibustion 技能說明文件。");

    if( !weapon )
        return notify_fail("你手上沒針是不能施展炙穴針灸的。\n");
    if( weapon->query("skill_type") != "needle" )
        return notify_fail("你手上沒針是不能施展炙穴針灸的。\n");
    if( !target )
        return notify_fail("你沒有可以施展的目標。\n");
    /*
        if( me->query("class2") )
        {
            if( target != me && me->query("class2") != "skyowl_med" )
                return notify_fail("你對別人身上的穴道位置的掌控還不熟練，不能對他人施展此招。\n");
        }
    */
    if( me->is_busy() )
        return notify_fail("你現在正在忙，無法使用炙穴針灸！\n");

    switch( arg )
    {
        ///////////////////////////////////////////////////////////////////////////////////
    case "rekee":
    case "regin":
    case "resen":
        if( me->is_fighting() )
            return notify_fail("打鬥中你沒有時間替"+target->query("name")+"針灸。\n");
        if( me->query("level") < 5 )
            return notify_fail("你的經驗不足，不能擅自替他人針炙•\n");
        if( sk2 < 5 )
            return notify_fail("你對炙穴針灸不夠熟練，無法使用這個功\能•\n");

        effect = sk2;

        if(arg == "rekee") {
            if( me->query("ap") < effect )
                return notify_fail("你的內勁不足。\n");
            if( target->query("hp") >= target->query("max_hp") )
                return notify_fail(target->query("name")+"並沒有受傷，似乎不需針灸•\n");
            if(me!=target)
                message_vision(HIW"$N"HIW"輕輕的吟唱著古老的薪傳詩歌-"HIC"療氣訣"HIW"，手中"+weapon->name()+HIW"化成點點寒芒刺入$n"HIW"身體上督脈的「命門穴」。\n"NOR, me, target);
            else
                message_vision(HIW"$N"HIW"輕輕的吟唱著古老的薪傳詩歌-"HIC"療氣訣"HIW"，手中"+weapon->name()+HIW"化成點點寒芒刺入自身督脈的「命門穴」。\n"NOR, me);
        }

        if(arg == "regin") {
            if( me->query("mp") < effect )
                return notify_fail("你的魔力不足。\n");
            if( target->query("ap") >= target->query("max_ap") )
                return notify_fail(target->query("name")+"的內勁充沛，似乎不需針灸•\n");
            if(me!=target)
                message_vision(HIW"$N"HIW"輕輕的吟唱著古老的薪傳詩歌-"HIG"療精訣"HIW"，手中"+weapon->name()+HIW"也化為點點寒芒刺入$n"HIW"手掌上「勞宮穴」。\n"NOR , me, target);
            else
                message_vision(HIW"$N"HIW"輕輕的吟唱著古老的薪傳詩歌-"HIG"療精訣"HIW"，手中"+weapon->name()+HIW"也化為點點寒芒刺入自身手掌上「勞宮穴」。\n"NOR , me);
        }

        if(arg == "resen") {
            if( me->query("hp") < effect )
                return notify_fail("你的生命不足。\n");

            if( target->query("mp") >= target->query("max_mp") )
                return notify_fail(target->query("name")+"仍精神亦亦，似乎不需針灸•\n");
            if(me!=target)
                message_vision(HIW"$N"HIW"輕輕的吟唱著古老的薪傳詩歌-"NOR+MAG"療神訣"HIW"，手中"+weapon->name()+HIW"也化為點點寒芒刺入$n"HIW"身體上任脈的「神闕穴」。\n"NOR, me, target);
            else
                message_vision(HIW"$N"HIW"輕輕的吟唱著古老的薪傳詩歌-"NOR+MAG"療神訣"HIW"，手中"+weapon->name()+HIW"也化為點點寒芒刺入自身任脈的「神闕穴」。\n"NOR, me);
        }

        if( random(sk1) > 15 ) {
            me -> start_busy(1);
            Bonus = me->query_int()/8;
            if(arg=="rekee")
                rekee(me, target, effect, msg);
            else if(arg=="regin")
                regin(me, target, effect, msg);
            else if(arg=="resen")
                resen(me, target, effect, msg);
            SkillImporving(me, Bonus);
        }
        else    // 失敗
            MoxibustionFail(me, target, msg);
        break;

        ///////////////////////////////////////////////////////////////////////////////////
    case "advkee":
        if( me->is_fighting() )
            return notify_fail("打鬥中你沒有時間替"+target->query("name")+"針灸。\n");
        if( me->query("level") < 10 )
            return notify_fail("你角色的等級不夠10級，不能擅自替他人針炙•\n");
        if( sk2 < 15 )
            return notify_fail("你對炙穴針灸不夠熟練，無法使出《"HIC"善世訣"NOR"》•\n");

        // 使用condition 來判斷
        if( target->query_condition("advkee") || target->query_temp("advkee") )
            return notify_fail(target->query("name")+"身體內已經有一股暖暖氣流正在緩緩的流動著。\n");

        effect = sk2/2;
        if(me->query("ap") < effect*4 )
            return notify_fail("你的內勁不夠，無法使用這個功\能。\n");
        if(me->query("mp") < effect*4 )
            return notify_fail("你的魔力不夠，無法使用這個功\能。\n");

        if(me!=target)
            message_vision( HIW"$N"HIW"輕輕的吟唱著古老的薪傳詩歌-"HIC"善世訣"HIW"，手中"+weapon->name()+HIW"也化為點點寒芒刺入$n"HIW"胸腔處的「神道穴」。\n"NOR, me, target);
        else
            message_vision( HIW"$N"HIW"輕輕的吟唱著古老的薪傳詩歌-"HIC"善世訣"HIW"，手中"+weapon->name()+HIW"也化為點點寒芒刺入自身胸腔處的「神道穴」。\n"NOR, me);
        if( random(sk1) > 35 )
        {
            me -> start_busy(2);
            Bonus = me->query_int()/4;
            advkee(me, target, effect, msg);
            SkillImporving(me, Bonus);
        }
        else
            MoxibustionFail(me, target, msg);

        break;

        ///////////////////////////////////////////////////////////////////////////////////
    case "sky":
        if( me->is_fighting() )
            return notify_fail("打鬥中你沒有時間替"+target->query("name")+"針灸。\n");
        if( me->query("level") < 15 )
            return notify_fail("你的經驗不足，不能擅自替他人針炙•\n");
        if( sk2 < 30 )
            return notify_fail("你對炙穴針灸不夠熟練，無法使出《"HIR"開天訣"NOR"》•\n");

        effect = sk2;

        if(me->query("hp") < effect*8 )
            return notify_fail("你的生命不夠，無法使用這個功\能。\n");
        if(me->query("ap") < effect*8 )
            return notify_fail("你的內勁不夠，無法使用這個功\能。\n");
        if(me->query("mp") < effect*8 )
            return notify_fail("你的魔力不夠，無法使用這個功\能。\n");

        message_vision(HIW"$N"HIW"輕輕的吟唱著古老的薪傳詩歌-"HIR"開天訣"HIW"，手中"+weapon->name()+HIW"化成點點寒芒，一一刺入身旁所有人的「命門穴」及「勞宮穴」。\n"NOR, me);
        if( random(sk1) > 45 )
        {
            me -> start_busy(2);
            sky(me, target, effect, msg);
        }
        else    // 失敗
            MoxibustionFail(me, target, msg);
        break;

        ///////////////////////////////////////////////////////////////////////////////////
    case "heal":
        if( me->is_fighting() )
            return notify_fail("打鬥中你沒有時間替"+target->query("name")+"針灸。\n");
        if( me->query("level") < 20 )
            return notify_fail("你的經驗不足，不能擅自替他人針炙•\n");
        if( sk2 < 40 )
            return notify_fail("你對炙穴針灸不夠熟練，無法使出《"HIC"癒民訣"NOR"》•\n");

        effect = sk2/5;

        if(me->query("mp") < effect*5 )
            return notify_fail("你的魔力不夠，無法使用這個功\能。\n");
        if(me->query("hp") < effect*5 )
            return notify_fail("你的生命不夠，無法使用這個功\能。\n");

        msg+= HIW"$N"HIW"輕輕的吟唱著古老的薪傳詩歌-"HIC"癒民訣"HIW"，手中"+weapon->name()+HIW"化成點點寒芒刺入$n"HIW"身上的傷口四周。\n"NOR ;

        if( random(sk1) > 45 )
        {
            me -> start_busy(2);
            Bonus = me->query_int()/4;
            heal(me, target, effect, msg);
            SkillImporving(me, Bonus);
        }
        else
            MoxibustionFail(me, target, msg);
        break;

        ///////////////////////////////////////////////////////////////////////////////////
    case "addstr":
    case "addcon":
    case "addint":
    case "adddex":
        // 必須使用 condition 來判斷
        if( target->query_condition("addcon")
                || target->query_condition("addint")
                || target->query_condition("addstr")
                || target->query_condition("adddex")
                || target->query_temp("addstr")
                || target->query_temp("addint")
                || target->query_temp("adddex")
                || target->query_temp("addcon") )
            return notify_fail(target->query("name")+"的身體暫時無法再接受肉體上的強化了。\n");

        if( me->is_fighting() )
            return notify_fail("你正忙著戰鬥，沒有空針炙。\n");
        if( me->query("level") < 30 )
            return notify_fail("你的經驗不足，不能擅自替他人針炙•\n");
        if( sk2 < 50 )
            return notify_fail("你對炙穴針灸不夠熟練，無法使用這個功\能•\n");

        effect = sk2/10;        // 每十級一點

        if(me->query("hp") < effect*15 )
            return notify_fail("你的生命不夠，無法使用這個功\能。\n");
        if(me->query("ap") < effect*15 )
            return notify_fail("你的內勁不夠，無法使用這個功\能。\n");
        if(me->query("mp") < effect*15 )
            return notify_fail("你的魔力不夠，無法使用這個功\能。\n");

        if( arg == "addstr")
            msg = HIW"$N"HIW"輕輕的吟唱著古老的薪傳詩歌-"HIY"太陽訣"HIW"，手中"+weapon->name()+HIW"化成點點寒芒刺入$n"HIW"背部的「長強穴」。\n"NOR ;
        else if( arg == "addint")
            msg = HIW"$N"HIW"輕輕的吟唱著古老的薪傳詩歌-"HBK"陰心訣"HIW"，手中"+weapon->name()+HIW"化成點點寒芒刺入$n"HIW"頭頂的「百會穴」。\n"NOR ;
        else if( arg == "addcon")
            msg = HIW"$N"HIW"輕輕的吟唱著古老的薪傳詩歌-"HIG"三焦訣"HIW"，手中"+weapon->name()+HIW"化成點點寒芒刺入$n"HIW"身體上中下焦三處。\n"NOR ;
        else if( arg == "adddex")
            msg = HIW"$N"HIW"輕輕的吟唱著古老的薪傳詩歌-"HIC"逸飄訣，手中"+weapon->name()+HIW"化成點點寒芒刺入$n"HIW"腿上的「風市穴」。\n"NOR ;

        if( random(sk1) > 55 ) {
            me -> start_busy(2);
            Bonus = me->query_int();
            addAttribute(me, target, effect, msg, arg);
            SkillImporving(me, Bonus);
        }  else // 失敗
            MoxibustionFail(me, target, msg);
        break;

        ///////////////////////////////////////////////////////////////////////////////////
    case "ghost":
        // 以condition 來判斷
        if( target->query_condition("ghost")  || target->query_temp("ghost") )
            return notify_fail(target->query("name")+"的身體已經無法再接受肉體上的強化了。\n");
        if( me->is_fighting() )
            return notify_fail("打鬥中你沒有時間替"+target->query("name")+"針灸。\n");

        // 最多100/4 = 25點攻擊力及防禦力
        effect = sk2/4;

        if(me->query("hp") < effect*10 )
            return notify_fail("你的生命不夠，無法使用這個功\能。\n");
        if(me->query("mp") < effect*10 )
            return notify_fail("你的魔力不夠，無法使用這個功\能。\n");
        if(me->query("ap") < effect*10 )
            return notify_fail("你的內勁不夠，無法使用這個功\能。\n");

        //        if( me->query("level") < 30 )
        //            return notify_fail("你的經驗不足，不能擅自替他人針炙•\n");
        if( sk2 < 55 )
            return notify_fail("你對炙穴針灸不夠熟練，無法使出《"HBWHT+BLK"鬼陰世精訣"NOR"》•\n");
        msg+= HIW"$N"HIW"輕輕的吟唱著古老的薪傳詩歌-"HBWHT+BLK"鬼陰世精訣"NOR"，手中"+weapon->name()+HIW"也化為點點寒芒刺入$n"HIW"丹田下「中極穴」、頸下「天突穴」、肩頭「肩井穴」等十二處穴道上。\n"NOR ;
        if( random(sk1) > 65 )
        {
            me -> start_busy(2);
            Bonus = me->query_int();
            ghost(me, target, effect, msg);
            SkillImporving(me, Bonus);
        }
        else
        {
            MoxibustionFail(me, target, msg);
        }
        break;
        ///////////////////////////////////////////////////////////////////////////////////
        // skyowl 沒有直接攻擊的技能
        // tmr 2007/01/05
        /*
        case "attack":
        if( target == me )
            return notify_fail("用 suicide 指令會比較快:P。\n");
        if( sk2 < 70 )
            return notify_fail("你對炙穴針灸不夠熟練，無法使出《"HIR"神悲鬼泣訣"NOR"》•\n");
        if(!me->can_fight(target))
            return 0;

        if(!me->is_fighting(target))
            me->kill_ob(target);
        if(!target->is_fighting(me))
            target->kill_ob(me);

        msg+= HIC"$N"HIC"悟出蒼生萬物死傷輪迴的天地循環真理，神色悲淒。" ;
        msg+=    "\n    隨即一陣狂猛的寒氣自$N"HIC"手中的針鋒竄出，向$n"HIC"十二命門直飆而去！！\n" ;
        Bonus = me->query_int()/2;
        attack(me, target, 1, msg);
        SkillImporving(me, Bonus);

        break;
        */
        ///////////////////////////////////////////////////////////////////////////////////
    default:
        return notify_fail("炙穴針灸沒有這個用法，請參考help moxibustion。\n");
    }

    return 1;
}

int valid_learn(object me)
{
    return 1;
}
int practice_skill(object me)
{
    return 1;
}
int improve_limite(object me)
{
    return me->query_int() + 60;
}


