//u/c/chiaa/obj/mob/toad.c
#include <ansi.h>
inherit NPC;
void create()
{
set_name("�����", ({ "toad" }) );//�W�r
set("race", "���~");//�ر�
set("gender", "����" );//�ʧO
set("age",3 );//�~��
set("long", "�@���b�a�W�C�C���۪������\n");//�H���ԭz
set("str",3 );//�M�O
set("cor",3 );//�x��
set("int",0 );//����
set("spi",0 );//�F��  
set("cps",0 );//�w�O
set("per",0 );//�e��
set("kar",0 );//�ֽt 
set("con",3 );//�ڰ�
set("limbs", ({ "�Y��", "����", "�e�}", "��}" }) );//���鳡��
set("verbs", ({ "bite", "claw", "hoof"}) );
//�������A ��hoof��crash�rbite��claw��poke
set("combat_exp", 350);//�H���g��
set("potential", 6);//���
set_temp("apply/attack", 7);//�����O
set_temp("apply/armor", 7);//���m�O
add_money("coin",200);//�o�쪺����coin silver gold
set("max_gin", 15);//��̤j��
set("max_kee", 150);//��̤j��
set("max_sen", 15);//���̤j��  

setup();
  
}

