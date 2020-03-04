#include <ansi.h>
inherit NPC; 
void combat_ai(); 
void heal();
void create()
{
 set_name("�p����",({"guard captain","captain"}));
 set("long",@LONG 
�t�d�ݦu�ѱ��t�u���u�áA�L���Z�\��M�w���p���A�S�ƺ�
�q�O��L�_�Ĭ�E

LONG);
 set("title",HIC"�ѱ��t�u�@��"NOR);
 set("attitude","peaceful"); 
 set("age",28+random(3));
 set("gender","�k��");
 set("level",33+random(5));  
 set("max_hp",14000+random(3000)); 
 set("max_ap",8000); 
 set("str",80+random(30)); 
 set("dex",80+random(30));  
 set("Merits/bar",4+random(2));  
 set("Merits/wit",6+random(3)); 
 set_skill("sky-dagger",85);
 set_skill("dagger",90); 
 set_skill("dodge",90);
 set_skill("parry",90);
 set_skill("block",90); 
 set_skill("jingang-plan",100); 
 map_skill("dagger","sky-dagger");
 set("chat_chance",3);
 set("chat_msg", ({
                 (:command,"say �ݤ���ݡI�٤��ֺu�I":), 
                 (:command,"say ���䨺�ӡI�O�b�������������A�p�ߧڴ~�A�E":),
                 }));
 set("chat_chance_combat",200);
 set("chat_msg_combat",({(:command,"exert sky-dagger":),
                         (:command,"say �S�̡̭A���]�n�u��o�I":),
                         (:command,"say �j�a�O�ȡI�ᴩ���W�N�ӤF�I":),
                         (: combat_ai :),
 }));
 set_temp("TEAM_NPC",1);
 setup(); 
 carry_object(__DIR__"eq/owl_cloth")->wear(); 
 carry_object(__DIR__"eq/owl_pants")->wear();
 carry_object(__DIR__"eq/black_steel_stabber")->wield(); 
 carry_object(__DIR__"eq/black_steel_stabber")->wield();
 carry_object(__DIR__"eq/owl_armor")->wear();
 carry_object(__DIR__"eq/grass_boots")->wear();
 set_living_name("TEAM_NPC");
} 



void init()
{
  object me,ob;
  me=this_player();
  ob=this_object();
  ::init();
  if( me->query_temp("SkyBird/enemy") ) {

    ob->kill_ob(me);
    me->kill_ob(ob);
    }
}

void die()
{
        int x;
        object ob,npc,npc1,env;
        
        env=environment(this_object());
        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        } 
        ob->add("popularity",1); 
        ob->add_temp("SkyBird/enemy",1);
      
     message("world:world1:vision",
     HIM"\t�ѱ��t�u�@�äp�����ľԨ�̫�@��A���M����"+ob->query("name")+"�A���ѱo�ѤU�}�ӡK�K\n"NOR
     ,users() );
        tell_object(ob,HIW"\n(�]���A�����F�p�����A�ҥH�o��F 1 �I�n��C)\n"NOR); 
     
        if( !this_object()->query("protect") ){  
             message_vision("�����Ө즹�a�E\n",ob); 
             npc=new(__DIR__"lee_jenn_yeuan");
             npc->move(env);  
            for (x=0;x<5;x++)
            {
             message_vision("�p�����Ө즹�a�E\n",ob);
             npc1=new(__DIR__"guard_captain");
             npc1->move(env);
             npc1->set("protect",1); 
            }
        }
     
        ::die();
        return;
}

void combat_ai()
{
        int i;
        object *target;

        target = all_inventory(environment(this_object()));

        /* �Z���Q�����A�h�˦^�h */
        if( !this_object()->query_temp("weapon") ) 
                command("wield stabber"); 
                command("wield stabber 2");

        /* ���ˮɷ|�ۧ�����  */
        if( this_object()->query("hp") < (this_object()->query("max_hp")/3) )
                heal();

        /* �ĤH->attack */

        command("exert sky-dagger");
        this_object()->add_busy(-2);

        return;
}

void heal()
{
    object me=this_object();
    message_vision(HIC"$N�q�h���ǥX�@�~�p�~�l�A�N�~���G���٦b�ˤf�B�A�ˤf�K���_��¡�X�F�E\n"NOR, me);              
    me->receive_heal("hp",random(400));
    me->receive_heal("mp",random(400));
    me->receive_heal("ap",random(500));
    return;
}

