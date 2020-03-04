#include <ansi.h>
inherit NPC; 
void combat_ai();  
void create()
{
 set_name("小嘍囉",({"bandit's lackey","lackey","bandit"}));
 set("long",@LONG  
在你眼前的就是隨處打劫十萬山山道中旅人錢財的土匪, 傳
聞道十萬山中的土匪各各兇悍無比, 但卻都是女人. 看來這
個傳聞絕非空穴來風. 
LONG);

 set("title",YEL"十萬山山寨"NOR);
 set("age",23+random(15));
 set("gender","女性");
 set("level",25);  
 set("max_hp",8000+random(3000)); 
 set("max_ap",8000); 
 set("str",75+random(18)); 
 set("dex",75);  
 set("Merits/bar",5+random(3));  
 set("Merits/wit",5+random(3)); 
 set_temp("apply/damage",85+random(30)); 
 set_temp("apply/hit",15+random(30));
 set_skill("sword",80+random(15)); 
 set_skill("blade",80+random(15));
 set_skill("whip",80+random(15));
 set_skill("dagger",80+random(15));
 set_skill("hammer",80+random(15));
 set_skill("fork",80+random(15));
 set_skill("throwing",80+random(15));
 set_skill("dodge",70+random(15)); 
 set_skill("parry",70+random(15)); 
 set_skill("block",70+random(15));
 set("chat_chance", 8);
 set("chat_msg", ({
    (: random_move :),
    }));
 setup(); 
 set_living_name("Ten-mount_bandit");
/* 
 carry_object(__DIR__"silk_cloth")->wear();
 carry_object(__DIR__"eq/large_blade")->wield();
 carry_object("/open/world1/eq/moon_skirt")->wear();
*/
}

void init()
{
  object me=this_player(),ob=this_object();
 
  ::init(); 
  if ( !me->query("class1") ) return;
  if ( me->query_temp("invis") ) return;
  ob->kill_ob(me);
  me->kill_ob(ob);

} 
 
void die()
{
        int i;
        object ob,env,npc;

        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        } 
        switch( random(10) ){
        case 0:
        tell_object(ob,HIW"\n(因為你殺死了"+this_object()->query("name")+HIW"，所以得到了 1 點聲望。)\n"NOR); 
        ob->add("popularity",1); 
        break;
        }

        ::die();
        return;
}

