#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "薦獸", ({ "ghost" }) );
        set("level",33);
        set_skill("dodge",100);
        set_skill("parry",100);
        set_skill("sword",100);
        set("long" ,"這是眾多追隨奇倪遁入黑暗的第二批神獸之一,由於作為神獸的時日稍短,在神獸錄中通稱為薦。\n");
        set("verbs", ({ "bite", "claw" }) );
        set("limbs", ({ "頭部", "身體", "前爪", "後爪", "尾部","雙翼" }) );
        set("title",HIG"魂因階級"NOR);
        set("chat_chance", 50);
        set("gender","雄性");
        set("chat_msg", ({
           (: random_move :),
       (:command("kill meo"):),
        (:command("kill guard"):),
        (:command("kill taoist"):),
        }) );
        setup();
}
void init()
{
        object ob;
        ::init();
        if(!this_object()->visible(this_player())) return;
        if(this_player()->query("level") > 9 && userp(this_player()) )
        {
          this_object()->kill_ob(this_player());
        }
}
void die()
{
        int i;
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        i = random(23);
        ob->set_temp("skycitywar",i+1);
        if(i > 15) 
        {
          ob->add("popularity",1); //聲望
          tell_object(ob,CYN"\n你殺死了薦獸，得到了 1 點聲望。\n"NOR);
        }
        ::die();
        return;
}
