#include <ansi.h>
inherit NPC; 
void combat_ai(); 
void heal();
void create()
{
 set_name("小隊長",({"guard captain","captain"}));
 set("long",@LONG 
負責看守天梟聖泉的守衛，他的武功顯然已有小成，沒事盡
量別跟他起衝突•

LONG);
 set("title",HIC"天梟聖泉護衛"NOR);
 set("attitude","peaceful"); 
 set("age",28+random(3));
 set("gender","男性");
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
                 (:command,"say 看什麼看！還不快滾！":), 
                 (:command,"say 那邊那個！別在那鬼鬼祟祟的，小心我揍你•":),
                 }));
 set("chat_chance_combat",200);
 set("chat_msg_combat",({(:command,"exert sky-dagger":),
                         (:command,"say 兄弟們，死也要守住這！":),
                         (:command,"say 大家別怕！後援馬上就來了！":),
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
     HIM"\t天梟聖泉護衛小隊長奮戰到最後一刻，仍然不敵"+ob->query("name")+"，不由得敗下陣來……\n"NOR
     ,users() );
        tell_object(ob,HIW"\n(因為你殺死了小隊長，所以得到了 1 點聲望。)\n"NOR); 
     
        if( !this_object()->query("protect") ){  
             message_vision("李鎮遠來到此地•\n",ob); 
             npc=new(__DIR__"lee_jenn_yeuan");
             npc->move(env);  
            for (x=0;x<5;x++)
            {
             message_vision("小隊長來到此地•\n",ob);
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

        /* 武器被打掉，則裝回去 */
        if( !this_object()->query_temp("weapon") ) 
                command("wield stabber"); 
                command("wield stabber 2");

        /* 受傷時會自我醫療  */
        if( this_object()->query("hp") < (this_object()->query("max_hp")/3) )
                heal();

        /* 敵人->attack */

        command("exert sky-dagger");
        this_object()->add_busy(-2);

        return;
}

void heal()
{
    object me=this_object();
    message_vision(HIC"$N從懷中掏出一瓶小瓶子，將瓶中液體塗抹在傷口處，傷口便神奇的癒合了•\n"NOR, me);              
    me->receive_heal("hp",random(400));
    me->receive_heal("mp",random(400));
    me->receive_heal("ap",random(500));
    return;
}

