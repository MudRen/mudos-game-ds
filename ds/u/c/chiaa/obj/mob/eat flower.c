//u/c/chiaa/obj/mob/eat flower.c
#include <ansi.h>
inherit NPC;
void create()
{
set_name("���H��", ({ "eat flower" }) );//�W�r
set("race", "���~");//�ر�
set("age",1 );//�~��
set("long", "�@���ݰ_�Ӧ��I���ƪ���\n");//�H���ԭz
set("str",1 );//�M�O
set("cor",3 );//�x��
set("int",0 );//����
set("spi",0 );//�F��  
set("cps",0 );//�w�O
set("per",0 );//�e��
set("kar",0 );//�ֽt 
set("con",0 );//�ڰ�
set("limbs", ({ "�Y��", "����","���l" }) );//���鳡��
set("verbs", ({ "bite", "claw" }) );
//�������A ��hoof��crash�rbite��claw��poke
set("combat_exp", 500);//�H���g��
set("potential", 10);//���
set_temp("apply/attack", 15);//�����O
set_temp("apply/armor", 15);//���m�O
set("attitude", "aggressive");//�۰ʧ���
add_money("coin",500);//�o�쪺����coin silver gold
set("max_gin", 20);//��̤j��
set("max_kee", 300);//��̤j��
set("max_sen", 20);//���̤j��  

setup();
  
}

