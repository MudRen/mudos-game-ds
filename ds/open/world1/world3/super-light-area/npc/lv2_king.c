inherit NPC;
#include <ansi.h>
void create()
{
          set_name("�׽m��",({"practice robot","robot"}) );
set("long","�ѶW�E���l���q�s�@�Ӧ����ͤƤH�A�֦��ʦ~���H�X���Ѥ媺DNA�I�I\n");
        set("race","human");
set("age",60);
              set("level",30);
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
        write( name() + "�N�A�d�F�U�ӡC\n");
      command("sigh");
           say("�׽m�̻��D�G"HIW"���n�h�e�����I\n"NOR);  
        return 1;
} 
void die()
{
         message_vision("$N�����e��: �ڦn���U�A���n�b�e�i�F�I",this_object());
            ::die();
}
