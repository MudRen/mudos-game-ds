inherit NPC;
#include <ansi.h>
void create()
{
           set_name("�~�īȱ���",({"to di killer","killer"}));
set("long","�W�����ۤ@�ǵP�l�g�ۡy�����q�q�~�īȮa�ڥ��~���ʤ�����I�z\n");
        set("race","human");
set("age",60);
              set("level",35);
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
carry_object(__DIR__"obj/g_plate.c");
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
      command("wahaha");
           say("�~�īȱ��⻡�D�G"HIY"�Q���I�H���ݰݧڪ��j�a�I\n"NOR);
        return 1;
} 
void die()
{
message_vision("$N���e���G����A�u�F�`�A��ǻ����ӥD��@�����U�F�I",this_object()); 
            ::die();
}
