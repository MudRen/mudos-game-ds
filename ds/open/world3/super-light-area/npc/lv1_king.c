inherit NPC;
#include <ansi.h>
void create()
{
         set_name("檢定師",({"master guard","guard"}) );
         set("title","百歲高人");
 set("long","由超•光子公司製作而成的生化人，擁有百年高人—游機子的DNA！\n");
        set("race","human");
set("age",60);
         set("level",25);
         set_skill("gun",100);
set("chat_chance",10);
        set("chat_msg",({
                         (:command,"reload clip":)}));
                set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (:command("shoot"):),
                (:command("reload clip"):), 
 }) ); 
	setup();
carry_object(__DIR__"obj/light-clip.c");
carry_object(__DIR__"obj/light-clip.c");
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
        write( name() + "將你攔了下來。\n");
      command("hehe");
           say("檢定師說道："HIB"要往進階之路邁進，先通過我這關吧！\n"NOR);
        return 1;
} 
