#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIW"聖誕"HIM"小禮物"NOR, ({ "xmas present","present" }));
        if( clonep() )
                set_default_object(__FILE__);
        else
                set("long","聖誕節禮物，不仿打開來看看(open)。\n");
        
        set("no_auc",1);
        set("no_put",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_drop",1);
        setup();
}

void init()
{
  add_action("do_open","open");
}
int do_open(string str,object obj,object me)
{
        int i;
        
        obj = this_object();
        me = this_player();
                
        if(!str || str != "present" || me->query("xmas-gift2")) return 0;
                i = random(1000);
        switch(i)
        {
                case 0..500:
                        me->add("exp", 1000000); 
                        message_vision(HIG"$N打開了"HIR"聖誕小禮物"HIG"後，聖誕老公公給你經驗值一百萬做獎勵！\n"NOR,me,obj); 
                        me->set("xmas-gift2",1);
                        break;
                case 501..980:
                        me->add("popularity", 200);
                        message_vision(HIG"$N打開了"HIR"聖誕禮物"HIG"之後，聖誕老公公給你聲望兩百點做獎勵！\n"NOR,me,obj);
                        me->query("xmas-gift2",1);
                        break;
                case 981..999:
                        new(__DIR__"red_sock")->move(me);
                        message_vision(HIG"$N打開了"HIR"聖誕禮物"HIG"之後，得到超級大獎「聖誕泡泡襪」當作獎勵！\n"NOR,me,obj);
                        me->query("xmas-gift2",1);
                        break;
           
            }
  destruct(obj);
  return 1;
}

