// dog.c
#include <ansi.h>

inherit NPC;

void create()
{
         set_name( YEL "��˪����ت�" NOR , ({ "slency's dog","dog" }) );
        set("race", "���~");
        set("age", 1);
        set("long", "�e�O��˪����ت�, �]���O���ت�, �ҥH�e���ʮ𤣤j�n��C\n");

        set("str", 20);
        set("cor", 26);

        set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("chat_chance", 8);
        set("chat_msg", ({

                "��˪����ت��Ϋ�L��F��ۤv���զ��C\n" }) );

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
        if(me->query("name") != "���")
        {
say("��˪����ت��Q�F�Q�A���}���D�G" HIW "HI!�o��ȤH�A�n��, ������˪����ت�, ���n75����C\n" NOR );
                command("bite" + me->query("id"));
        }else
         {
                say( HIG "��˪����ت��λ�l�D�F�D�A���}�C \n" NOR );
                say( HIG "��˪����ت��b��˪��}������������M�Q�Q�F��Y�C\n" NOR );
                say( HIG "��˪����ت���۫�˷n�F�n���ڡC\n" NOR );
      }   
}
