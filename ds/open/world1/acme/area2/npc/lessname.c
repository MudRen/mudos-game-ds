#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�C�L�W" , ({ "the sword less name","name", "__GUARD__" }) );
 set("long", "�L�O�խߦa���̪��j�]�Y�A�өʴݼɤ����A�ݱ����ʡC\n");
        set("level",20);
set("exp",1500);
           set("combat_exp",2000);
        set("gender","�k��");
        set("gender", "�k��");
        set("race", "�H��");
        set("age", 42);
        set("combat_exp",2000);         //�Լ�(���bmob level��100�����k���y)
        set("env/wimpy", 20);           //�k�]wimpy (20%)
       set("evil",50);
           set_skill("sword",40);
          set_skill("parry",40);
           set_skill("dodge",40);
//    set_skill("darksword",40);
        set("chat_chance_combat",70);
        set("chat_msg_combat", ({
           (:command("exert darksword"):),
        }) );
        set("attitude", "aggressive");
        setup();
               carry_object(__DIR__"wp/sword.c")->wield();
            carry_object(__DIR__"eq/helmet.c")->wear();
}

void init()
{   
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() && this_object()->visible(this_player()) ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
          object me;
          me=this_player();
          if( !ob || environment(ob) != environment() ) return;
          {    
            command("hehe");
              say("�C�L�W�j�ܡG����I�I�h���a�I�I\n");
            message_vision("�C�L�W�X$N���`�N�ɡA��ŧ�t��$N�A�o�۲r��C\n",me);
            say("�A�ݨ��C�L�W��W���K�ի歸�ӨӡA�����{�����ΡI�I\n");
 message_vision(HIR "\n$N�Q�K�է�o���⤣�ΡA�K�ը�i�F$N���ݤf�C\n"NOR,me);
              me->receive_wound("body",8);
                  me->receive_damage("hp",20);
               set("attitude","killer");
          }
}
