//u/c/chiaa/obj/mob/bat.c
#include <ansi.h>
inherit NPC;
void create()
{
set_name("����", ({ "bat" }) );//�W�r
set("race", "���~");//�ر�
set("gender", "����" );//�ʧO
set("age",2 );//�~��
set("long", "�k���b��W������\n");//�H���ԭz
set("str",1 );//�M�O
set("cor",0 );//�x��
set("int",0 );//����
set("spi",1 );//�F��  
set("cps",2 );//�w�O
set("per",0 );//�e��
set("kar",0 );//�ֽt 
set("con",1 );//�ڰ�
set("limbs", ({ "�Y��", "����", "�e�}", "��}", "�ͻH" }) );//���鳡��
set("verbs", ({ "bite", "claw", "crash" }) );
//�������A ��hoof��crash�rbite��claw��poke
set("combat_exp", 360);//�H���g��
set("potential", 10);//���
set_temp("apply/attack", 14);//�����O
set_temp("apply/armor", 10);//���m�O

add_money("coin",400);//�o�쪺����coin silver gold
set("max_gin", 20);//��̤j��
set("max_kee", 200);//��̤j��
set("max_sen", 20);//���̤j��  

setup();
  
}

