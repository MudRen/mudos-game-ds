#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�p�{��" , ({ "little fighter", "fighter" }) );
        set("level",12);
        set("race","�H��");
        set("gender","�k��");
        set("age",20);
        set_skill("dagger",25);
        set_skill("parry", 25);
        set_skill("dodge", 45);
        set_skill("bird-eight", 20);
        map_skill("dodge","bird-eight");
        set("long","�L�O�ѱ��Ъ��p�{��, �ݰ_�ӻ��\����, ���O�Z�\�o�����ˡC\n"
           );
        set("chat_chance", 200);
        set("chat_msg_combat",({
            "�p�̳ܹD�G�ڭn���A���D�p�{�̤]�O���n�S��!!\n", 
        }) );
        setup();
        carry_object(__DIR__"eq/dagger2.c")->wield();
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
        add_action("do_vendor_list", "list");
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
           case 0:
               say("�p�{�̹�A���D�G�A�O���W���Ѯv���{�̶�??\n");
               break;
        }
}
