#include <ansi.h>
inherit __DIR__"zombiekill";
inherit NPC;

void create()
{
        set_name("戾絕" ,({"zombie le-jit","jit"}) );
        set("long",@LONG
戾絕是屍變很久的殭屍王，由於已經吸收許多陰氣，特別帶有暴戾之氣。
生前亦是武林正道人士，只可惜因為含冤而死，竟然吸收陰氣而屍變，成
為了殭屍王，並且還在亂葬岡中使的其他屍體屍變，而擁有許多的手下，
十幾年前發現封邪遺跡有著大量陰脈，因此來到此地增強其力量....
LONG
);
        set("age",223);
        set("race","人類");
        set("title","殭屍王");
        set("level",50);
        set("attitude", "aggressive");
        set("gender", "男性" );
        set("Merits/bio",8);
        set("Merits/wit",3);
        set("Merits/bar",9);
        set("exp",40000+random(5000));
        set_skill("parry",100);
        set_skill("dodge",100);
        set_skill("unarmed",100);
        set("chat_chance",8);
        set("chat_msg", ({
           (: random_move :),
        }) );
        set("chat_chance_combat",30);
        set("chat_msg_combat",({
                (: zombie_kill,this_object() :),
                (: zombie_heal,this_object() :),         }) );
        setup();
        set_living_name("zombie-war-mob");
         carry_object(__DIR__"../eq/silver-cloth")->wear();
         carry_object(__DIR__"../wp/corpse_fist")->wield();
         set("actions", (: call_other, __FILE__, "query_action" :));
}
mapping query_action()
{
        return s_action[random(sizeof(s_action))];
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
 message("world:world1:vision",HIW"\n    戾絕"+WHT+"死前大吼︰"HIR"今次敗給"+ob->name(1)+"之事，我必會加倍奉還\n\n"NOR,users());       ob->add("popularity",4); //聲望
         tell_object(ob,HIG"你得到四點聲望了。"NOR);
                     ::die();
                     return;
}










