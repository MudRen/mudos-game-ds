#include <ansi2.h>
inherit NPC;
void create()
{
        set_name(HIW"��l"NOR, ({ "lion" }) );
        set("long",@LONG
            ���������    
          ����    �����  
          ��  ���  ��   �o����l�O�]�����]���d���C
          �� �֡C�� �� 
          ���� �� ����   �ͩʷŹ��A�~�a�~�X��۩y�C
       ��   ��������     
     ~ �`�]���������^ 


LONG
);
        set("race", "���~");
        set("gender","����");
        set("level",25);
        set("age",2);
        set_skill("unarmed", 100);
        set_skill("dodge", 100);

	set_temp("apply/armor",600);

	set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("dex", 100);
	set("con", 100);

        set("combat_exp", 30000);

        setup();

}
