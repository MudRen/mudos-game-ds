inherit NPC;
#include <ansi.h>
void create()
{
           set_name(HIR"戰鬥"HIC"天使"NOR,({"fight angel","angel"}) );
set("long","神秘的怪人, 聽說精通念的道理而登上此樓守護者?\n");
        set("race","human");
      set("age",100);
             set("level",50);
              set_skill("doubleshoot",100);
set("chat_chance",10);
        set("chat_msg",({
                         (:command,"reload clip":)}));
                set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (:command("exert doubleshoot"):),
                (:command("reload clip"):), 
 }) ); 
	setup();
carry_object(__DIR__"obj/light-clip.c");
carry_object(__DIR__"obj/light-clip.c");
       carry_object(__DIR__"obj/g_plate.c");
carry_object(__DIR__"obj/light-gun.c")->wield();  
}

void init()
{
       ::init();
        add_action("do_guard", "go");
}
int do_guard(string arg)
{
        if( (arg!= "up") || !this_player()->visible(this_object()) ) return 0;
        write( name() + "運用念力將你堵住。\n");
   command("nomatch");
            say(HIR"戰鬥"HIC"天使"NOR"說："HIC"怎麼！想一步登天ㄚ?\n"NOR);
        return 1;
} 
void die()
{
         message_vision("$N死前說：好!好!好! 終於有人能通過我這關了^^",this_object());
            ::die();
}
