#include <ansi.h>
inherit NPC;
void create()
{
        set_name("蓋德拉斯" , ({ "catch man","man" }) );
        set("long",
                  "他是N.Y.T的高級總裁，\n"
                  "財產僅次於皮爾蓋茲\n"

            );
        set("title",HIY"N.Y.T"HIW"最高總裁"NOR );
        set("level",41);
        set("race","人類");
        set("gender","男性");
        set("age",51);
        set_skill("sword", 72);
        set_skill("parry", 77);
        set_skill("dodge", 71);
        set("chat_chance", 5);
        


        setup();
       carry_object("/u/b/basic/wp/sword1")->wield();
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
        {
message("world:world1:vision", HIW"\n 未來時空傳來的電子訊息：N.Y.T"HIY"最高總裁
"NOR"蓋德拉斯

終於敗給了"HIR + ob->name(1) + " "NOR HIW"。 ] \n\n"NOR, users());
        ob->add("popularity", 1); //聲望
 tell_object(ob,HIW"(因為你殺死了老蓋，所以你得到了 1 點聲望。)\n"NOR);
}
        ::die();
        return;
}
