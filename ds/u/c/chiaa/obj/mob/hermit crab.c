//u/c/chiaa/obj/mob/hermit crab.c

#include <ansi.h>
inherit NPC;
void create()
{
set_name("�H�~��", ({ "hermit crab" }) );//�W�r
set("race", "���~");//�ر�
set("gender", "����" );//�ʧO
set("age", 5 );//�~��
set("long", "�@���b�F�y�W���Ӫ��h���H�~��\n");//�H���ԭz
set("str",1 );//�M�O
set("cor",1 );//�x��
set("int",0 );//����
set("spi",0 );//�F��  
set("cps",0 );//�w�O
set("per",0 );//�e��
set("kar",0 );//�ֽt 
set("con",0 );//�ڰ�
set("limbs", ({ "�Y��", "����", "�e��" }) );//���鳡��
set("verbs", ({ "bite", "crash" }) );
//�������A��hoof��crash�rbite��claw��poke
set("combat_exp", 100);//�H���g��
set("potential", 10);//���
add_money("coin",100);//�o�쪺����
set_temp("apply/attack", 5);//�����O
set_temp("apply/armor", 5);//���m�O
set("chat_chance",10 );//�ʤ���ʧ@���v
set("chat_msg",({"�H�~�ɾ߰_�F�y���F�l�ӦY\n", 
       (: random_move :), //�H���è� 
}) );//�ʧ@�ԭz

set("max_gin", 10);//��̤j��
set("max_kee", 100);//��̤j��
set("max_sen", 10);//���̤j�� 

    setup(); 
}

