// cleaner.c
#include <ansi.h>

inherit NPC;

void create()
{
         set_name( HIG "�M���" NOR , ({ "cleaner" }) );
        set("race", "���~");
        set("age", 3);
        set("long", "���O������ޤ��ߪ��M����C\n");

        set("str", 24);
        set("cor", 26);

        set("limbs", ({ "��y", "����", "�l�L", "����", "�q�ʨ��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("chat_chance", 8);
        set("chat_msg", ({
                (: this_object(), "random_move" :),
                "�M����Χl�о��b�l�ӵߡC\n" }) );
 set_temp("apply/attack", 10);
        set_temp("apply/armor", 3);

        setup();
}

void init()
{
        call_out("incheck",3,this_player());
}
void incheck(object me)
{
        if(me->query("name") != "�M�����")
        {
say("�M������o�X�T�G���n���G" HIR "�ޡI���n�å�U�����I\n" NOR);
                command("kick" + me->query("id"));
        }else
         {
                say( HIG "�ѤU�j�j�A�n���C \n" NOR );
                say( HIG "�ѤU�j�j�A�n�ӡC\n" NOR);
                say( HIG "�ѤU�j�j�A�O�Ѥ~�C\n" NOR );
      }   
}


