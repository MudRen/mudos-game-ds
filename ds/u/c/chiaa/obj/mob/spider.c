//u/c/chiaa/obj/mob/spider.c
#include <ansi.h>
inherit NPC;
void create()
{
set_name("�j��", ({ "spider" }) );//�W�r
set("race", "���~");//�ر�
set("gender", "����" );//�ʧO
set("age",5 );//�~��
set("long", "��r\n");//�H���ԭz
set("str",3 );//�M�O
set("cor",3 );//�x��
set("int",0 );//����
set("spi",3 );//�F��  
set("cps",0 );//�w�O
set("per",0 );//�e��
set("kar",0 );//�ֽt 
set("con",3 );//�ڰ�
set("limbs", ({ "�Y��", "����", "�e�}", "��}" }) );//���鳡��
set("verbs", ({ "bite", "crash" }) );
//�������A ��hoof��crash�rbite��claw��poke
set("combat_exp", 400);//�H���g��
set("potential", 12);//���
set_temp("apply/attack", 15);//�����O
set_temp("apply/armor", 10);//���m�O

add_money("coin",500);//�o�쪺����coin silver gold
set("max_gin", 30);//��̤j��
set("max_kee",300);//��̤j��
set("max_sen", 30);//���̤j��  

setup();
  
}
