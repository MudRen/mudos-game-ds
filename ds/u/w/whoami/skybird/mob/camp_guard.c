#include <ansi.h>
inherit NPC;

void create()
{
        set_name("巡邏兵", ({"camp guard", "camp", "guard"}) );
        set("long", @LONG
一個正在營區內大搖大擺走來走去的巡囉兵。
LONG);

        set("title","討伐軍");
        set("gender","男姓");
        set("race","人類");
        set("age", 10+random(20));
        set("level",20);
        set_skill("dodge", 60+random(10));
        set_skill("parry", 60+random(20));
        set_skill("unarmed", 60+random(30));
        set_skill("blade", 70+random(21));
        set("chat_chance", 10);
        set("chat_msg", ({
         (: random_move :),
  (: command,"say 看來這次討伐是勢在必得啊。" :),
  YEL"巡邏兵滿意的看著亮晶晶的靴子\n"NOR,
  }));
        set_temp("soldier",1);
        setup(); 
        set_living_name("Ten_Mount_Soldier");        carry_object(__DIR__"wp/blade.c")->wield();
        carry_object(__DIR__"eq/huge_armor.c")->wear();
}


void init()
{ 
        object me=this_player(),ob=this_object(),*target;
        int x;
        target = all_inventory(environment(ob));   
        add_action("do_kill","kill");
        for(x=0;x<sizeof(target);x++){
            if( !target[x]->is_fighting() ) continue; 
            if( target[x]->query_temp("soldier") ) continue;            command("say 不想活了！？竟敢在軍營內打鬥！！");
            ob->kill_ob(target[x]);
            me->kill_ob(ob);
        }            }

int do_kill(string arg)
{
        object *ob,me;
        int i;

        me=this_player();

        if (!arg) return 0;
        if(!objectp(present(arg, environment(me)))) return 0;
        
        if( is_fighting(me) ) return 0;
        command("snort");
        command("say 去死吧！！ \n");

        ob=all_inventory(environment());
        for(i=0;i<sizeof(ob);i++)
        {
                ob[i]->soldier_assist(this_object(), me);
        }
        return 1;
}

void soldier_assist(object alert, object me)
{
          if(
             !living(this_object())
        ||      is_fighting(me) )
                return;

          switch(random(2)) {
        case 0: command("say 大膽！受死吧！\n"); break;
        case 1: command("say 看來你也是山賊一夥的！殺！！\n"); break;
        }
        kill_ob(me);
        me->fight_ob(this_object());
}

