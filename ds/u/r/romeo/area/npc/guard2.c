#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIR "����u�çL"NOR, ({ "ghost guard","ghost","guard" }) );
        set("level",35);
           set("combat_exp",4000);
         set("exp",3000);
set("long","�o�O�@��Ż�i���Ԫ��çL�A�q�ͮɴN�Q��餣�Ȧ����z���A
�ݥ��̪����Ӫ���ΡA�@����խ�H���ˤl�u�s�H�تA�C\n");
;
        set("age",50);
        set("evil",60);
     set("title",CYN"�ߧL"NOR);
        set("gender","�k��");
        set("attitude","killer");
             set_skill("unarmed",65);
        set_skill("dodge",65);
                  set_skill("parry",65);
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
          object me;
          me=this_player();
          if( !ob || environment(ob) != environment() ) return;
          {
            command("hehe");
            command("pk");
            say("����çL�g�ۡG�x���I�Ǭӳ��A�d�U�R�ӡC\n");
            message_vision("����çL�X$N���`�N�ɡA��ŧ�t��$N�A�o�۲r��C\n",me);
            message_vision("�A�ݨ�����çL�k��@���A�@�D�l���A��$N��Ħӥh�C
\n",me);
            message_vision(HIR "\n�l����$N���}�W���h�A�ݨ�$N�w���ˤ����C\n"NOR,me);
            me->receive_damage("hp",60);
            me->receive_wound("foot",5);
            set("attitude","killer");
          setup();
}
}
