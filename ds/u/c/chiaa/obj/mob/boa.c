//u/c/chiaa/obj/mob/boa.c
#include <ansi.h>
inherit NPC;
void create()
{
set_name("���D", ({ "boa" }) );//�W�r
set("race", "���~");//�ر�
set("gender", "�۩�" );//�ʧO
set("age",3 );//�~��
set("long", "�@�����ߪ����D\n");//�H���ԭz
set("str",2 );//�M�O
set("cor",0 );//�x��
set("int",0 );//����
set("spi",0 );//�F��  
set("cps",0 );//�w�O
set("per",0 );//�e��
set("kar",0 );//�ֽt 
set("con",3 );//�ڰ�
set("limbs", ({ "�Y��", "����", "����" }) );//���鳡��
set("verbs", ({ "bite", "crash" }) );
//�������A ��hoof��crash�rbite��claw��poke
set("combat_exp", 300);//�H���g��
set("potential", 9);//���
set_temp("apply/attack", 8);//�����O
set_temp("apply/armor", 8);//���m�O
set("attitude", "aggressive");//�۰ʧ���
add_money("coin",250);//�o�쪺����coin silver gold
set("max_gin", 10);//��̤j��
set("max_kee", 200);//��̤j��
set("max_sen", 10);//���̤j��  

setup();
  
}

