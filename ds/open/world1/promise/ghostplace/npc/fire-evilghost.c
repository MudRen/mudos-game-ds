#include <ansi.h>
inherit NPC; 
varargs int receive_damage(string type, int damage, object who);
void create() 
{ 
  set_name(HIR"火鬼"NOR+RED"幽"NOR,({"fire ghostevil","fire","ghost","evil"}));
  set("race", "human");
  set("level",60);
  set("max_hp",20000);
  set("max_mp",20000);
  set("max_ap",20000);
  set("age",1020);     
  set("title",HIW"白鬼四"NOR"幽");
  set("nickname",HIR"火靈"NOR);
  set("combat_exp",5000000); 
  set("attitude","aggressive");
  set_skill("sword",100);
  set_skill("blade",100);
  set_skill("block",100);
  set_skill("dodge",100);
  set_skill("blade",100);
  set_skill("whip",100);
  set_skill("axe",100);
  set_skill("force",100);
  set_skill("unarmed",100);
  set_skill("parry",100);
  set_skill("anti_poison",100);
  set_skill("chess",100);
  set_skill("literate",100);
  set_skill("swim",100);
  set_skill("gun",100);
  set_skill("hammer",100);
  set_skill("bow",100);
  set_skill("throwing",100);
  map_skill("blade","left-blade");
  map_skill("dodge","bird-eight");
  set_skill("left-blade",100);
  set_skill("bird-eight",100);
  set("devil",100000); 
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
  (: command("do wield cross,exert left-blade") :),
 (: command("do wield cross,exert left-blade") :),
 (: command("do wield cross,exert left-blade") :),
 (: command("do wield cross,exert left-blade") :),
 (: command("do wield cross,exert left-blade") :),
(: command("do wield cross,exert left-blade") :),
})); 

  set("long",@LONG        
善於操縱火術之術師，當今可排名數一數二，但因為一次的迷失
踏上了不歸路。
LONG); 
  setup(); 
  carry_object(__DIR__"wp/fire-cross")->wield();
  carry_object(__DIR__"eq/dragon-hat")->wear();
    }
varargs int receive_damage(string type, int damage, object who)
{
        int val;

                if(this_object()->is_fighting() ) {

        if( damage < 0 ) error("F_DAMAGE: 傷害值為負值。\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: 傷害種類錯誤( 只能是 hp, mp, ap其中之一 )。\n");
        if( objectp(who) && type=="hp") set_temp("last_damage_from", who);
                if(random(100)<40)
                {
                                damage/=2;
                                message_vision(HIG "\n$N"HIG"招換火靈，使出絕對防禦，硬生生的化解大半部分的傷害！！\n"NOR,this_object());
                }
                }

                if(objectp(who) )
                        ::receive_damage(type,damage,who);
                else
                        ::receive_damage(type,damage);
                return damage;
}
void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
                message("world:world1:vision",
HIR"\n\t火鬼幽大聲咆嘯："HIW+ob->name(1)+HIR"果然有兩把刷子，老夫甘拜下風！！\n\n"
HIR"\n\t火鬼幽死後，本命星消逝不見，"HIW+ob->name(1)+HIR"闖往"HIC"水舞之陣"HIR"！！\n"NOR                
,users());
        ob->add("popularity", 3); //聲望
                ::die();
        //destruct(this_object());
        return;
}

