// dog.c
inherit NPC;

void create()
{
        set_name("�N�~", ({ "eagle Monster","monster","eagle"}) );
        set("race", "���~");
        set("age", random(10)+8);
        set("level",random(3)+3);
        set("long", "�@���ͪ����I���N���S�Τj�����Y�j�H�C\n");
        set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����","��","�ͻH","���l"}) );
        set("verbs", ({ "bite", "claw" }) );
        set("chat_chance", 6);
        set("chat_msg", ({
                (: this_object(), "random_move" :),
                "�N�~�R�ʵۯͻH�A�@�ƷQ�����k�����_�Ӫ��ˤl�C\n",
                "�N�~�ĤF�f���������������S�n�F�n�Y�C\n",
                "�N�~�i���R���S�X�F�����c�٪��ˤl�C\n" }) );           
        setup();
}




