//u/c/chiaa/obj/mob/eye brute.c
#include <ansi.h>
inherit NPC;
void create()
{
set_name("�W���~", ({ "eye brute" }) );//�W�r
set("race", "���~");//�ر�
set("gender", "����" );//�ʧO
set("age",20 );//�~��
set("long", "�@���u���@�Ӳ��������~\n");//�H���ԭz
set("str",10 );//�M�O
set("cor",5 );//�x��
set("int",0 );//����
set("spi",0 );//�F��  
set("cps",0 );//�w�O
set("per",0 );//�e��
set("kar",0 );//�ֽt 
set("con",8 );//�ڰ�
set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );//���鳡��
set("verbs", ({ "hoof", "crash" }) );
//�������A ��hoof��crash�rbite��claw��poke
set("combat_exp", 600);//�H���g��
set("potential", 20);//���
set_temp("apply/attack", 30);//�����O
set_temp("apply/armor", 30);//���m�O
add_money("silver",2);//�o�쪺����coin silver gold
set("max_gin", 35);//��̤j��
set("max_kee", 360);//��̤j��
set("max_sen", 35);//���̤j��  

setup();
  
}

