#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIR"龍戰士"NOR, ({ "dragon knight","knight","dragon" }) );
        set("level", 40); 
        set("title",HIW"東"HIY"龍"HIC"守衛 II"NOR);  
        set("race","人類");
        set("gender","男性");
        set("age",430);
        set_skill("parry", 70);
        set_skill("unarmed", 70);
        set_skill("dodge", 70); 
        add("addition_armor",210);
        add("addition_damage",190);  
        set("long","它是磐龍城禁地的守衛，保護著傳說中的寶物。\n");      
        setup(); 
        carry_object(__DIR__"obj/sword")->wield();
}
void init()
{
        object ob;
        ::init();
        add_action("do_guard", "go");
        if(!this_object()->visible(this_player())) return;
        call_out("greeting", 1, ob);
}
int do_guard(string arg)
{
       if( (arg!= "east") || !this_player()->visible(this_object()) ) return 0;
       write( name() + "張開手臂將你擋了下來。\n");
       command("peer");
       command("say 想過的話 . . . 先過了我這關吧 !");
       return 1;
}
void die()
{
        int i;
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        LOGIN_D->set_reboot(0);
        if( !ob ) 
        {
                ::die();
                return;
        }  
message("world:world1:vision",
    HIR"\n【 磐 龍 城 】"+ob->name(1)+"突破了西方神龍大十字了。\n\n"+NOR     
       ,users());
        ob->add("popularity",1); 
              ::die();
        return;
}

