#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�H�{" , ({ "believer" }) );
        set("level",8);
        set("race","�H��");
        set("gender","�k��");
        set("age",38);
        set_skill("parry", 20);
        set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set("long","�L�O�ѱ��Ъ�����H�{, �L���b��ѱ������C\n"
           );
        set("chat_chance", 200);
        set("chat_msg_combat",({
            "�H�{�ܹD�G���n�p�ݤF��!\n", 
        }) );
        setup();
     
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
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
           case 0:
               say("�H�{��A���D�G�A���D�ѱ��Ъ��ѨӶ�??\n");
               break;
        }
}
