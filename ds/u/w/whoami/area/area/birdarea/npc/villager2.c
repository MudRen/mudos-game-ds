#include <ansi.h>

inherit NPC;
void create()
{
        set_name("村民",({ "villager" }) );
        set("long","一個居住在獵狐村的村民，似乎常常出去獵補狐狸，賣其皮以糊口•\n");
        set("race","人類");
        set("title",HIR"獵狐村"NOR);
        set("age",30+random(5));
        set("level",15+random(5));
        set("attitude","friendly");
        set_skill("dodge",50);
        set_skill("unarmed",50);
        set_skill("parry",50);
        set("chat_chance",20);
        set("chat_msg", ({
                        (: command("say 還不快走！"):),
                        (: command("pk")            :),
        }));
   setup();
add_money("silver",8);           
}
void init()
{     
   object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
 object me = this_player();
 if ( !me || environment(me) != environment() ) return; 
   command("kick "+ me->query("id"));
   command("say 這位" + RANK_D->query_respect(ob) + "你怎麼隨便就闖入別人的家裡呢？\n" ); 
}
