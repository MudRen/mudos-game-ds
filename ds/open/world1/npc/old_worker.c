#include <ansi.h>

inherit NPC;

void create()
{
        set_name("���q�u", ({ "old worker","worker" }) );
        set("race","human");
        set("gender", "�k��");
        set("level",10);
        set("age",65);
        set("evil",-10);
        set("long",@LONG
�w�g�֭n�h�𪺦��q�u�A���L�ݥL�����N�N�a�A�����D�b��
�Ǥ��򨣤��o�H���ķ�C
LONG
);
        set("chat_chance",30); 
        set("chat_msg",({
                (:command("hehe"):),
                "���q�u�p�n�a���G�u�X�{�b�h�ä@�Ǫ��q��ڪ����_�U......�v\n",
                "���q�u������A���G�u�������F�N�֨��A�o�̤w�g����A�G�F......�v\n",
                "���q�u������A���G�u�o�̮ڥ����O�q�|�A�U���O�i�Ȫ��a��A�O�A�U�h�F......�v\n",
        }) );
        setup();
        carry_object(__DIR__"../obj/ts_bag");
}
