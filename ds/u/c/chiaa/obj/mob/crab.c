//u/c/chiaa/obj/mob/crab.c
#include <ansi.h>
inherit NPC;
void create()
{
set_name("����", ({ "crab" }) );//�W�r
set("race", "���~");//�ر�
set("gender", "����" );//�ʧO
set("age",4 );//�~��
set("long", "�@���b�F�y���Ӫ��h������\n");//�H���ԭz
set("str",1 );//�M�O
set("cor",0 );//�x��
set("int",0 );//����
set("spi",0 );//�F��  
set("cps",1 );//�w�O
set("per",0 );//�e��
set("kar",0 );//�ֽt 
set("con",0 );//�ڰ�
set("limbs", ({ "�Y��", "����", "�e�g", "�ᨬ" }) );//���鳡��
set("verbs", ({ "bite", "claw" }) );//�������A ��hoof��crash�rbite��claw                                                        ��poke
set("combat_exp", 100);//�H���g��
set("potential", 10);//���
set_temp("apply/attack", 4);//�����O
set_temp("apply/armor", 4);//���m�O

set("chat_chance",20 );//�ʤ���ʧ@���v
set("chat_msg",({"���ɱq�L�̦R�X�w�w\n",(: random_move :),//�H���è� 
}) );//�ʧ@�ԭz

add_money("coin",100);//�o�쪺����coin silver gold
set("max_gin", 10);//��̤j��
set("max_kee", 100);//��̤j��
set("max_sen", 10);//���̤j��  


setup();
  
}

