#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "地殘天佬", ({ "di chan tan lu","di","tan","chan","lu" }) );
        set("level",70);
           set("combat_exp",5500);
           set("evil",99);
        set("long",
            "他是數百年前幽冥地窖中的天殘邪佬的師弟，他今年已很老\n"
            "但不知為什麼他到今時今日仍然能生存，實在另有一點不相信....\n",
        );
        set("age",1000);
        set("gender","男性");
        set("title",WHT"【地邪天王】"NOR);
set("attitude", "friendly");
        set_skill("unarmed",100);
           set_skill("dodge",100);
           set_skill("parry",100);
     set("chat_chance_combat",80);
        set("chat_msg_combat", ({
           (:command("say 你這惡賊，接我這一招，受死吧！！！"):),
        }) );
       setup();
}
void init()
{
       ::init();
        add_action("do_guard", "go");
}

int do_guard(string arg)
{

           object me;
           object obj;
           me=this_player();
           obj=this_object();
        if( (arg!= "north") || !this_player()->visible(this_object()) ) return 0;
        write( name() + "將你攔了下來。\n");
        write("地殘天佬突然向著你撲了過來，想吃了你般...");
        obj->kill_ob(me);
        return 1;
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
 message("world:world3:vision",CYN"\n  突然天空中出現了一些奇怪的字句:\n\n\t【地邪天王】終於敗給了"+ob->name(1)+"。\n\n"+NOR,users());
        ob->add("popularity",3); //聲望
        ::die();
        //destruct(this_object());
        return;
}
