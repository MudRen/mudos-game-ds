//u/c/chiaa/obj/mob/turtle.c
#include <ansi.h>
inherit NPC;
void create()
{
set_name("���t", ({ "turtle" }) );//�W�r
set("race", "���~");//�ر�
set("gender", "����" );//�ʧO
set("age",3 );//�~��
set("long", "�@���b�F�y�W�ΤӶ������t\n");//�H���ԭz
set("str",2 );//�M�O
set("cor",0 );//�x��
set("int",0 );//����
set("spi",0 );//�F��  
set("cps",0 );//�w�O
set("per",0 );//�e��
set("kar",0 );//�ֽt 
set("con",2 );//�ڰ�
set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );//���鳡��
set("verbs", ({ "bite", "crash","claw"  }) );
//�������A ��hoof��crash�rbite��claw��poke
set("combat_exp", 100);//�H���g��
set("potential", 5);//���
set_temp("apply/attack", 6);//�����O
set_temp("apply/armor", 8);//���m�O
set("chat_chance",15 );//�ʤ���ʧ@���v
set("chat_msg",({"���t�b�F�y�C�C�o����\n",
       (: random_move :), //�H���è� 
}) );//�ʧ@�ԭz

add_money("coin",150);//�o�쪺����coin silver gold
set("max_gin", 10);//��̤j��
set("max_kee", 100);//��̤j��
set("max_sen", 10);//���̤j��  

setup();
  
}
