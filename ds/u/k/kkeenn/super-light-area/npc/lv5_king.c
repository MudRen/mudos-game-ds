inherit NPC;
#include <ansi.h>
void create()
{
           set_name(HIR"�԰�"HIC"�Ѩ�"NOR,({"fight angel","angel"}) );
set("long","�������ǤH, ť����q�����D�z�ӵn�W���Ӧu�@��?\n");
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
        write( name() + "�B�Ω��O�N�A����C\n");
   command("nomatch");
            say(HIR"�԰�"HIC"�Ѩ�"NOR"���G"HIC"���I�Q�@�B�n�ѣ�?\n"NOR);
        return 1;
} 
void die()
{
         message_vision("$N���e���G�n!�n!�n! �ש󦳤H��q�L�ڳo���F^^",this_object());
            ::die();
}
