#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "�����]��", ({ "ghost face","ghost","face", "__GUARD__" }) );
        set("level",30);
           set("combat_exp",3000);
set("exp",2000);
        set("long","�L�O�@���������ۤj�j�p�p�����Y�b�ݫe�B�I��A���ФH���b�C\n");
        set("age",50);
        set("evil",60);
     set("title",CYN"���X���S"NOR);
        set("gender","�k��");
        set("attitude","killer");
             set_skill("unarmed",60);
        set_skill("dodge",60);
                  set_skill("parry",60);
        set("Merits/wit",2);
        setup();
}
void init()
{   
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() && this_object()->visible(this_player())) 
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
            command("pk");
            say("�����]�ؤj�ܡG�c��I�I�h���a�I�I\n");
            message_vision("�����]�ضX$N���`�N�ɡA��ŧ�t��$N�A�o�۲r��C\n",me);
            message_vision("�A�ݨ������]�ثe�ݪ��j���Y�A�Q�g�ӥX�A��$N��Ħӥh�C\n",me);
            message_vision(HIR "\n���Y��$N���}�W�r�h�A�ݨ�$N�w���ˤ����C\n"NOR,me);
            me->receive_damage("hp",40);
           me->receive_wound("left_leg",5);
           me->receive_wound("right_leg",5);
            set("attitude","killer");
          }
}
