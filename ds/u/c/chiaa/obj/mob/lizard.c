//u/c/chiaa/obj/mob/lizard.c
#include <ansi.h>
inherit NPC;
void create()
{
set_name("�h�i", ({ "lizard" }) );//�W�r
set("race", "���~");//�ر�
set("gender", "����" );//�ʧO
set("age",3 );//�~��
set("long", "�@���b��W���۪��h�i\n");//�H���ԭz
set("str",1 );//�M�O
set("cor",0);//�x��
set("int",0 );//����
set("spi",1 );//�F��  
set("cps",0 );//�w�O
set("per",0 );//�e��
set("kar",1 );//�ֽt 
set("con",3 );//�ڰ�
set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );//���鳡��
set("verbs", ({ "bite", "claw","crash" }) );
//�������A ��hoof��crash�rbite��claw��poke
set("combat_exp", 300);//�H���g��
set("potential", 8);//���
set_temp("apply/attack", 8);//�����O
set_temp("apply/armor", 8);//���m�O
set("attitude", "aggressive");//�۰ʧ���
add_money("coin",250);//�o�쪺����coin silver gold
set("max_gin", 15);//��̤j��
set("max_kee", 200);//��̤j��
set("max_sen", 15);//���̤j��  

setup();
  
}

