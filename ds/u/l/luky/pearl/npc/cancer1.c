inherit NPC;
void create()
{
set_name("�p����", ({ "little cancer","cancer" }) );
set("age",6);
set("level",13);
set("long", @LONG

�@�����⪺�p���ɥ��b�ΤӶ��C
    ��           ��
     �@  ��  �� �A 
     �o�~�r�w�r���o
     �o�x      �x�o
       ���w�w�w��
LONG
);
set("race","���~");
set_temp("apply/armor",130);
set("coin",260+random(130));
set("chat_chance", 6);
set("chat_msg", ({
"�p���ɩ��a�j�X�F�@�ӳz�����p�w�w...\n",
"�p���ɧֳt�����L�A����U�D�D\n",
}));
set("limbs", ({ "�Y��", "����", "�e�}", "��}","����"})); //���𳡦�
set("verbs", ({ "bite","claw"})); //�������A��hoof��crash�rbite��claw��poke
setup();
}


