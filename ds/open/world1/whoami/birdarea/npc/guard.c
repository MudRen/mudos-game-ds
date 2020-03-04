#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�ѱ��u��" , ({ "guard" }) );
        set("level",20);
        set("race","�H��");
         set("gender","�k��");
        set("age",30);
        set_skill("dagger", 50);
        set_skill("parry", 50);
        set_skill("bird-eight", 70);
        set_skill("sky-dagger", 40);
        set_skill("dodge", 80);
        map_skill("dagger","sky-dagger");
        map_skill("dodge","bird-eight");
        set("long",@LONG�L�O�u�@�ѱ��Ъ��@�áA�ݰ_�Ӹ}�B�Ií�A���\�������ˤl,
���O�L���٦פ��|�ܵ���, �i���~�a�\�ҩ|�i�C
LONG
           );
        set("chat_chance", 200);
        set("chat_msg_combat",({
            "�ѱ��u�óܹD�G�j��W��!���n���o�å�]�F!\n", 
        }) );
        setup();
        carry_object(__DIR__"eq/dagger.c")->wield();
        carry_object(__DIR__"eq/cloth.c")->wear();
        carry_object(__DIR__"eq/boots.c")->wear();
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
 switch( ob->query("class1") ) {
  case "�ѱ���":
   command("talk with "+ob->query("id")+" about �v��, �A�i�n�r�I\n");
  break;

  default:
   say("�ѱ��u�ù�A���D�G�дL�Ȥ�B�I\n");
  break;   
 }
}
