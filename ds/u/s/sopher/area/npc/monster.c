#include <ansi.h>
inherit NPC;
void create()
{
        set_name(YEL"�h�A�Ǫ�"NOR, ({ "monster" }) );
        set("long", "�@�ӥ����G�����ΩM�I�����ߥͪ��C\n");
        set("race", "���~");
        set("gender","����");   // 1999.2.28 �W�[������
        set("age", 1000);
        set("level",20);
        set("str", 20);
        set("dex", 20);
        set("con",10);
        set("limbs", ({ "�Y��", "����", "�e��", "���"  }) ); //���𳡦�
        set("verbs", ({ "bite", "claw" }) );
        set_skill("unarmed",20);               
        set_temp("apply/damage", 10);   //���[�ˮ`�O
        set_temp("apply/hit", 20);      //���[�R���v
        set_temp("apply/armor", 10);     //���[���m�O 
        set("chat_chance",20);
set("chat_msg", ({HIW"�h�A�Ǫ��R�X�@�ί��~~~\n"NOR,
        (:command("bite hunter"):),
         }));
        setup();
}
