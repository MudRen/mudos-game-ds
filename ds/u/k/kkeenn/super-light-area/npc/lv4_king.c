inherit NPC;
#include <ansi.h>
void create()
{
           set_name("�Ʀ�����H",({"0101010 robot","robot"}) );
set("long","�W�����ۤ@�ǵP�l�g�ۡy�����q�q�~�īȮa�ڥ��~���ʤ�����I�z\n");
        set("race","human");
   set("age",0);
               set("level",45);
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
        write( name() + "�N�A�d�F�U�ӡC\n");
   command("no");
            say("�Ʀ�����H���G"HIY"�ڪ����ȴN�O�����_�I�̡I\n"NOR);
        return 1;
} 
void die()
{
         message_vision("$N���e���G��...��...�_..., �D�H�A��..�S...�k...����..�A��...����...",this_object());
            ::die();
}
