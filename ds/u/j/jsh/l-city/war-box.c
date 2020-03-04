inherit ITEM ;
#include <ansi.h>

void create()
{
        set_name(HIR"戰爭盒"NOR,({"war box","box"})); 
        set("unit","個");
        set("base_unit","個");
        set("needaward",3); 
        set("no_drop",1);
        set("no_give",1);
set("long","發動戰爭所用的盒子[gowar]。\n");
        setup();
}

void init()
{
        add_action("do_gowar","gowar");
}

int do_gowar(string arg)
{
        object  me,np;
        me = this_player(); 
        if(!arg || arg!="now") return notify_fail("要現在發動戰爭?[now]\n"); 
        {
        message_vision(CYN"\n$N向戰爭盒裡點了火，丟到很高很高的空中！\n"NOR,me);
        message_vision(HIR"\n戰爭盒瞬間爆開！。\n"NOR,me);
        message("world:world1:vision",HIR"\n                                /\n"
                                         "                               / \n"
                                         "                              /  \n"
                                         "                             /   \n"
                                     +HIR"                            ★   『咻∼蹦∼』天空泛起閃亮紅光 \n" 
                                     +HIG"\t"+me->name(1)+""+HIB"正式向開羅王宣戰，開啟了開羅長城的戰爭！！\n" 
                                     +HIW"\t開羅士兵點起了狼煙，長城的十二道門全數打開！！\n"
                                     +HIM"\t數以萬計的開羅士兵，從長城南北湧了進來！！\n"+NOR,users());   
        tell_room(me,HIB"你眼神開始恍惚•••原來是狼煙搞的鬼•••\n"NOR);

        me->add_busy(60);
        np=new(__DIR__"npc/sword-soldier"); 
        np->move(environment(this_player()));
        np->kill_ob(this_player());
        np=new(__DIR__"npc/blade-soldier"); 
        np->move(environment(this_player()));
        np->kill_ob(this_player());
        np=new(__DIR__"npc/axe-soldier"); 
        np->move(environment(this_player()));
        np->kill_ob(this_player());
        np=new(__DIR__"npc/fork-soldier");
        np->move(environment(this_player()));
        np->kill_ob(this_player());
        np=new(__DIR__"npc/sword-soldier"); 
        np->move(environment(this_player()));
        np->kill_ob(this_player());
        np=new(__DIR__"npc/blade-soldier"); 
        np->move(environment(this_player()));
        np->kill_ob(this_player());
        np=new(__DIR__"npc/axe-soldier"); 
        np->move(environment(this_player()));
        np->kill_ob(this_player());
        np=new(__DIR__"npc/fork-soldier");
        np->move(environment(this_player()));
        np->kill_ob(this_player());
        destruct(this_object());
        }
    return 1; 
}

