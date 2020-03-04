#include <ansi.h>
inherit NPC;

void create()
{
        set_name("���ާL", ({"camp guard", "camp", "guard"}) );
        set("long", @LONG
�@�ӥ��b��Ϥ��j�n�j�\���Ө��h�����o�L�C
LONG);

        set("title","�Q��x");
        set("gender","�k�m");
        set("race","�H��");
        set("age", 10+random(20));
        set("level",20);
        set_skill("dodge", 60+random(10));
        set_skill("parry", 60+random(20));
        set_skill("unarmed", 60+random(30));
        set_skill("blade", 70+random(21));
        set("chat_chance", 10);
        set("chat_msg", ({
         (: random_move :),
  (: command,"say �ݨӳo���Q��O�զb���o�ڡC" :),
  YEL"���ާL���N���ݵ۫G�������u�l\n"NOR,
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
            if( target[x]->query_temp("soldier") ) continue;            command("say ���Q���F�I�H�����b�x�示�����I�I");
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
        command("say �h���a�I�I \n");

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
        case 0: command("say �j�x�I�����a�I\n"); break;
        case 1: command("say �ݨӧA�]�O�s��@�٪��I���I�I\n"); break;
        }
        kill_ob(me);
        me->fight_ob(this_object());
}

