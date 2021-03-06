#include <ansi.h>
#define DELAY 20
inherit ITEM;

void create()
{
        set_name("細柴枝",({"thin firewood","wood"}));
        set("long","一根細柴枝，多是被點燃(fire)來圍著(around)丹爐來燒煉丹藥。\n");
        set_weight(500);
        if(clonep() )
                set_default_object(__FILE__);
        else 
        {
        set("value",10);
        set("unit","根");
        set("fire_power", 10); //火力
        }
        setup();
}

void init()
{
        add_action("do_fire","fire");
        add_action("do_around","around");
}

int do_fire(string arg)
{
        object me,ob;
        me=this_player();
        ob=this_object();
        if(query("on_fire") ) 
                return notify_fail("這根柴枝已正在燃燒了。\n");  
        if(me->is_busy() || me->is_fighting() )
                return notify_fail("你正忙著，沒有空點火。\n");
    message_vision("$N點燃了柴枝。\n",me);
        ob->set("on_fire",1);
        ob->set("no_sac",1);
        ob->set("no_sell",1);
        set_name("柴枝["+HIR"燃燒中"+NOR"]",({"firewood","wood"}));
        call_out("deca",DELAY,0,ob);
        return 1;
}

int do_around(string arg)
{
        object me,paper,ob,f;
        ob=this_object();
        me=this_player();

        if(!arg || arg!="furnace") return notify_fail("你得把柴枝圍繞在丹爐旁才有用處。\n");
        if(!ob->query("on_fire") ) return notify_fail("你得先把柴枝點燃才成。\n");
        if(!objectp(f=present("furnace",environment(me) ) ) )
                return notify_fail("這裡沒有丹爐。\n");
        if(!objectp(paper=present("alchemy paper",me ) ) )
                return notify_fail("你不懂煉丹之法，不知如何排法。\n");
        if(ob->query("around") ) return notify_fail("這根柴枝已圍繞在丹爐旁了。\n");
        message_vision("$N把一根點燃的柴枝圍繞在一個丹爐旁。\n",me);
        ob->set("around",1);
        f->set("around",1);
        ob->move(environment(f) );
        return 1;
}


void deca(int flag,object ob)
{
        object *inv;
        int i;
        inv = all_inventory(environment() );
        if( sizeof(inv) )
        {
        for(i=0;i<sizeof(inv);i++)
        {
                if(inv[i]->query("id")=="furnace" && inv[i]->query("setup_down")==1 )
                {
                if(inv[i]->query("around") )
                {
                        inv[i]->fire_pill(ob);
                        inv[i]->set("around",0);
                }
                }
        }

        }
        destruct(ob);
}

