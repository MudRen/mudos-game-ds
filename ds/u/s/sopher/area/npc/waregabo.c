#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIW "�˺��[��" NOR , ({ "waregabo" }) );
        set("age", 23);
        set("long","
���e�o��­��������M�h�A���O�]�s�M�h�x�Ϊ�
�⤤�������j�Aģ���L��A���W���]�s�Z�ҡA��Ũ
���X�䤣�i�w������O�C�L�����U�Q�A���G�i�ݯ}�@
���C�ѩ�O�j�N�s�کM�]�ڪ��V���A�]����O���
�����Ѥ~�I
");
        set("level",100);
        set("str", 50);
        set("con", 400);
        set("dex",100);
        set("int",250);
        set_temp("apply/attack", 230);
        set_temp("apply/armor", 200);
        set_skill("dodge",100);
        set_skill("parry",100);
        set("chat_chance",20);
        set("chat_msg",({
           (:command("say ť��sopher�ODS�̫Ӫ��H"):),
           (:command("puke"):),
           (:command("snicker"):),
        }));
        set("chat_chance_combat", 17);
        set("chat_msg_combat", ({HIR"�˺��[���j�� : �u�i�c���å��T�����a�T�v\n"NOR,
           (:command("aluba darkfool"):),
            }) );
        set_heart_beat(1);
        setup();
        
}

void init()
{
        call_out("incheck",3,this_player());
}
void incheck(object me)
{
        if(me->query("name") != "�˺��[��")
        {
say("�˺��[�����D�G" HIR"..........�C\n"NOR);
                command("waha" + me->query("id"));
        }else
         {
                say( HIY "�˺��[�������y��I�z�@�n�C \n" NOR );
                                
      } 
}
