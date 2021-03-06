#include <ansi.h>
inherit SSERVER;
inherit SKILL;
int summon_ghost(object me);
int check_ghost(object me);
void delay(object me);

int cast(object me, object target)
{
    int sk,inn,max_ghost;
    sk = me->query_spell("summon_ghost");
    inn = me->query_int();
    if (me->is_ghost()) return notify_fail("你還是鬼吧。\n");
    if (environment(me)->query("no_fight") || environment(me)->query("no_kill"))
        return notify_fail("這裡有股神聖的力量，幽靈無法進入。\n");
    if (me->query("hp")<100 || me->query("mp")<100)
        return notify_fail("你目前的身體狀態無法使用「幽靈召喚」。\n");
    if (me->is_fighting())
        return notify_fail("你現在正忙著，沒有空吧。\n");

    if (sk < 50) max_ghost=1;
    else if (sk < 90) max_ghost=2;
    else max_ghost=3;

    if (me->query_temp("ghost_summoned"))
        return notify_fail("你必須休息一會兒才能再次召喚鬼魂。\n");
    if (check_ghost(me) >= max_ghost)
        return notify_fail("你只能召喚這麼多鬼魂。\n");

    message_vision(HIG
                   "$N默唸「神祝禱篇」之「遊魂」訣：\n\n" NOR
                   +HIM"      「重陰在上，鬼氛浮游。神黯黯，意悠悠。」\n" NOR
                   +HIM"      「若得陰人引，變化魚龍出大淵。」\n" NOR
                   +HIB"\n\n登時$N的四周鬼影重重，陰風陣陣....\n" NOR
                   ,me);

    me->start_busy(3);
    call_out("summon_ghost", 3 , me);
    me->receive_damage("mp", (sk+inn)/2+random(inn/3));
    return 1;
}

object createGhost(object me) {
    int sk,inn;
    object ob;

    sk = me->query_spell("summon_ghost")/4;
    inn = me->query_int();

    ob=new(__DIR__"npc/ghost");
    ob->set("name",me->query("name")+"的孤魂野鬼");
     ob->set("level", 1);
    ob->set("str", sk +(me->query_str()/3)+random(4));
    ob->set("con", sk +(me->query_con()/3)+random(4));
    ob->set("int", sk +(me->query_int()/3)+random(4));
    ob->set("dex", sk +(me->query_dex()/3)+random(4));
    ob->set("max_hp", inn*20 );
    ob->set("max_mp", inn*10 );
    ob->set("max_ap", inn*10 );
    ob->set("hp",ob->query("max_hp"));
    ob->set("ap",ob->query("max_ap"));
    ob->set("mp",ob->query("max_mp"));

    ob->setup();
    ob->set_temp("no_combine",1);       //分開顯示

    ob->set_leader(me);
    ob->set_owner(me); // 標記主人 by -Acme-
    ob->set("creater",me);          //標記主人
    return ob;
}

int summon_ghost(object me)
{
    int sk,inn;
    object ob,env;

    sk = me->query_spell("summon_ghost");
    inn = me->query_int();
    if (!me) return 0;
    if (me->is_ghost()) return 0;
    env=environment(me);
    if (!env) return 0;

    if (me->query_temp("call_ghost")<=2 && (sk+inn ) >random(40) )
    {
        ob = createGhost(me);
        me->add_temp("summon_ghost",( { ob }));
        message_vision(HIW "\n只見$N身旁的煙霧一起，伴雜著鬼嘯魂啼，漸漸凝聚成一股人形.....\n"NOR
                       ,me);
    }
    else
    {
        message_vision(HIW "\n只見$N四周鬼影隱默，又恢復了平常的樣子，看來什麼事也沒有發生。\n"NOR,me);
        return 1;
    }

    me->improve_spell("summon_ghost", 1 + random(inn/2) );
    if ( random(sk + inn) < random(20)) //召喚失敗品
    {
        ob->set("name",HIM+"赤煉邪鬼"+NOR);
        ob->set("attitude", "aggressive");
        ob->delete("creater");
        ob->set("no_creater",1);
        ob->set_leader(0);
    }

    ob->move( env );
    tell_room(env,"你身邊突然出現了一個"+ob->name()+"。\n");
    me->set_temp("ghost_summoned",1);
    call_out("delay", 10,me);
    return 1;
}

void delay(object me)
{
    if (!me) return;
    if (me->query_temp("ghost_summoned"))
        me->delete_temp("ghost_summoned");
    return;
}

int check_ghost(object me)
{
    object *ghost=( {});
    if (!me) return 0;
    if (!ghost = me->query_temp("summon_ghost")) return 0;

    ghost -= ({0});
    if( sizeof(ghost) <= 0)  {
        me->delete_temp("summon_ghost");
        return 0;
    }
    
    return sizeof(ghost);
}

int improve_limite(object ob)
{
    if (!ob) return 0;
    if (ob->query("adv_class")>1) return (ob->query_int()>=80?100:ob->query_int()+20);

    return (int)ob->query_int();
}

