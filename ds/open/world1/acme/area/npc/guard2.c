#include <ansi.h>
inherit NPC;
void create()
{
        set_name("���Z�@��" , ({ "guard" }) );
        set("level",12);
        set("race","�H��");
        set("gender","�k��");
        set("age",25);
        set("int",5);
        set("str",20);
        set_skill("godsword",20);
        set_skill("sword", 30);
        set_skill("parry", 18);
        set_skill("mirage-steps",15);
        set_skill("dodge", 20);
        set("long","�L�O�u�@���Z�j�����@�áA�ݨӪZ�\\�ä��z�C\n");
        set("chat_chance_combat",100);
        set("chat_msg_combat",({
            "���Z�@�óܹD�G�S�̡̭I��o�å뵹�_�F�I\n",
            (:command("exert godsword"):),
            (:command("exert mirage-steps"):),
        }) );
        setup();
        carry_object(__DIR__"wp/longsword.c")->wield();
           carry_object(__DIR__"eq/surcoat.c")->wear();
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
               say("���Z�@�ù�A�ܹD�G���}�I���}�I�o�̰Z�O�A��Ӫ��I\n");
               break;
        }
}

