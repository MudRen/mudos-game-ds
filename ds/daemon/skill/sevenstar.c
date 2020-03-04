/*	File : "/daemon/skill/sevenstar-sword.c"	*
 *	Desc : "疾風門自學Skills"			*
 *	Author : "Alickyuen@DS"				*
 *	Last Modify : "2002年10月16日"			*/

#include <ansi2.h>
#define SKILL_NAME "昴七星劍義"

inherit SKILL;
inherit SSERVER;

int check(object me, int ck);
int attack(object me, object target);

void skill_improved(object me)
{
    if( me->query_skill("star-sword") )
    {
        me->set_skill("star-sword", me->query_skill("star-sword")-1 );
        tell_object(me, HIW"你把所體會的昴星劍義轉化成自己的武學－『"+SKILL_NAME+"』了！。\n"NOR);
    }
}

int improve_limite(object me)
{
    return 100;
}

int cast_skill(object me, string skill_name, object target, string arg)
{
    object weapon, sword;
    int num, max, sk, damage;

    if( arg == "off" )
    {
        object air;
        me->map_skill("sword");
        me->reset_action();
        write("你停止使用"+SKILL_NAME+"了。\n");
        check(me, 1);
        if( objectp(air = present("air sword", me)) )
        {
            message_vision("$N慢慢在空氣中消失了....\n", air);
            destruct(air);
        }
        return 1;
    }

    if( !skill_name ) skill_name = "sevenstar-sword";

    sk = me->query_skill(skill_name);

    weapon = me->query_temp("weapon");

    if( !weapon && sk == 100 && !objectp(present("air sword", me)) && me->query("ap") >= 100 )
    {
        object wp;
        wp = new(__DIR__"npc/airsword");
        wp->move(me);
        message_vision(HIW"$N提起內勁，匯氣成劍。\n"NOR, me);
        me->start_busy(2);
        me->receive_damage("ap", 100);
        //                me->skill_active("sevenstar-sword",(: call_other, __FILE__, "delay", me, wp :), 2);
        return 1;
    }

    if( !weapon || weapon->query("skill_type") != "sword" )
        return notify_fail("使用"+SKILL_NAME+"時必須裝備上劍類武器。\n");

    if( me->query_skill_mapped("sword") != skill_name )
        //        if( !me->query_skill_mapped("sword") )
    {
        if( me->query("ap") < 20 )
            return notify_fail("你現在的身體狀態並不能使用"+SKILL_NAME+"。\n");
        me->map_skill("sword", skill_name);
        me->reset_action();
me->skill_active( "sevenstar-sword",(: call_other, __FILE__, "fight_cost", me :), 6);
        message_vision(HIY"$N眼觀四方﹐耳聽八方﹐心凝意在﹐漸漸體會"+SKILL_NAME+"！\n"NOR, me);
        return 1;
    }
    /*
    	if( me->query_skill_mapped("sword") != skill_name )
    		return notify_fail("請你先停用其他有關劍類武學之技能吧。\n");
    */

    if( !weapon->query_durable() )
        return notify_fail(weapon->name()+"已經損壞了，不能夠再使用。\n");

    num = check(me, 0);

    if( me->is_fighting() && num )
    {
        if( !target ) target = offensive_target(me);
        if( !target ) return notify_fail("[攻擊錯誤]：沒有攻擊目標人物。\n");
        attack(me, target);

        return 1;
    }

    if( weapon->query("id") == "air sword" )
        return notify_fail(weapon->name()+"並沒有實體，不能以氣控制。\n");

    switch(sk)
    {
    case 0..10:	max = 1;	break;
    case 11..27:	max = 2;	break;
    case 28..45:	max = 3;	break;
    case 46..63:	max = 4;	break;
    case 64..81:	max = 5;	break;
    case 82..99:	max = 6;	break;
    case 100:	max = 7;	break;
    }

    if( num >= max )
        return notify_fail("以你目前"+SKILL_NAME+"的水平，最多只能夠控制著 "+max+" 把飛劍。\n");

    if( num >= (me->query_Merits("tec")+1) )
        return notify_fail("以你目前科技(tec)的水平，最多只能夠控制著 "+(me->query_Merits("tec")+1)+" 把飛劍。\n");

    //        damage = ( weapon->query("weapon_prop/damage") / 3 * max ) + random(me->query("level")) + (sk * 3 / 2) + me->query_int();
    //        damage = ( weapon->query("weapon_prop/damage") / 3 * max ) + sk;
    damage = (me->query_str()/3) + (weapon->query("weapon_prop/damage")*8/5) + me->query("level");

    //        if( damage < weapon->query("weapon_prop/damage") ) damage = weapon->query("weapon_prop/damage");

    //        damage = damage * weapon->query_durable() / 100;

    message_vision(HIC"\n$N運氣一沉，把$n"HIC"拋上半空，然後運氣控制著。\n\n"NOR, me, weapon);

    sword = new(__DIR__"npc/sword");

    sword->rename(me, weapon, damage);

    sword->set("durable", weapon->query_durable());

    sword->move(environment(me));

    //        me->skill_active("sevenstar-sword",(: call_other, __FILE__, "cost", me :), 15);

    me->start_busy(1);

    return 1;
}

int check(object me, int ck)
{
    int num;

if( !sizeof(filter_array( children(__DIR__"npc/sword"), (: clonep :) ) ) )
        return 0;

foreach(object sword in filter_array( children(__DIR__"npc/sword"), (: clonep :) ) )
    {
        if( sword->query_leader() == me )
        {
            num +=1;
            if( ck ) sword->end();
        }
    }
    return num;
}

mapping query_action(object me, object weapon)
{
    return SKILL_D("star-sword")->query_action(me, weapon);
}

void cost(object me)
{
    int num;

    if( !me ) return;

    num = check(me, 0);

    if( !num ) return;

    if( me->query("ap") < 5*num )
    {
        me->map_skill("sword");
        me->reset_action();
if( !sizeof(filter_array( children(__DIR__"npc/sword"), (: clonep :) ) ) )
            return 0;
foreach(object sword in filter_array( children(__DIR__"npc/sword"), (: clonep :) ) )
        {
            if( sword->query_leader() == me ) sword->gone();
        }
        tell_object(me, "你的體力無法再支撐著控制飛劍了。\n");
        return;
    }
    me->receive_damage("ap", 5*num);
    tell_object(me, RED"你的力量逐漸被飛劍吸走了。\n"NOR);
me->skill_active("sevenstar-sword",(: call_other, __FILE__, "cost", me :), 15);
    return;
}

void delay(object me, object wp)
{
    if( !wp || !me ) return;
    if( me->query("ap") < 10 )
    {
        message_vision(HIG"$N的體力不夠，身上的$n隨之消失了。\n"NOR, me, wp);
        destruct(wp);
        return;
    }
    me->receive_damage("ap", 10);
me->skill_active("sevenstar-sword",(: call_other, __FILE__, "delay", me, wp :), 2);
    return;
}

int attack(object me, object target)
{
    int num = check(me, 0);
    int dex = (120-me->query_dex());
    int time, max;

if( !sizeof(filter_array( children(__DIR__"npc/sword"), (: clonep :) ) ) )
        return 0;

    if( 10*(num+1) > me->query("ap") )
    {
        tell_object(me, "你的內勁不足以一次過控制這麼多把飛劍。\n");
        return 1;
    }

    if( me->query_temp("wind_skill/sevenstar") )
    {
        tell_object(me, "你短時間內不能再次使用飛劍攻擊。\n");
        return 1;
    }

    switch(me->query_skill("sevenstar-sword"))
    {
    case 0..10:     max = 1;        break;
    case 11..27:    max = 2;        break;
    case 28..45:    max = 3;        break;
    case 46..63:    max = 4;        break;
    case 64..81:    max = 5;        break;
    case 82..99:    max = 6;        break;
    case 100:       max = 7;        break;
    }

    message_vision(HIC"$N嘗試控制其飛劍去攻擊$n....\n"NOR, this_player(), target);

    me->receive_damage("ap", 10*(num+1));

    me->set_temp("wind_skill/sevenstar", 1);

    if( dex < 32 ) dex = 32;


    time = dex*dex*dex/30000*num;

    time -= max;

    if( find_player("alickyuen") && find_player("alickyuen")->query("testing") ) tell_object(find_player("alickyuen"), me->query("id")+" attack time : "+time+"..\n");

    if( time < 10 ) time = 10;

    if( time > 40 ) time = 40;

    call_out("stop", time, me);

    me->set_temp("wind_skill/num", num);

foreach(object sword in filter_array( children(__DIR__"npc/sword"), (: clonep :) ) )
    {
        if( sword->query_leader() == me ) sword->pk(target);
    }

    me->start_busy(2);

    return 1;
}

void stop(object me)
{
    me->delete_temp("wind_skill/sevenstar");
    me->delete_temp("wind_skill/num");
    return;
}
void fight_cost(object me)
{
    object me_weapon;
    if( !me ) return;

    me_weapon=me->query_temp( "weapon" );

    if( !me_weapon || me_weapon->query("skill_type") != "sword" )
    {
        me->map_skill("sword");
        me->reset_action();
        return;
    }

    if( me->query_skill_mapped("sword")!="sevenstar-sword" ) return;

    if( me->query("ap") < 10 )
    {
        me->map_skill("sword");
        me->reset_action();
        tell_object(me, "你的體力不夠繼續使"+SKILL_NAME+"了！\n");
        return ;
    }

    if( me->is_fighting() ) me->receive_damage("ap", 7);

me->skill_active( "sevenstar-sword",(: call_other, __FILE__, "fight_cost", me :), 6);
}
