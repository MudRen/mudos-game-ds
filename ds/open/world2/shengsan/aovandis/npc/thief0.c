#include <ansi.h>
inherit NPC;
void create()
{
//=========================�򥻳]�w==========================

        set_name( "���a", ({ "chen tuay","chen","tuay"}));
        set("long", "�@�Ӱ����N�N������M�����b�o�̦������F��C\n"
        );
        set("level",7);
        set("gender", "�k��");
        set("race", "�H��");
        set("age", 16);

        set("str",7);			//�]�w�ݩ�(�i�K)
        set("dex",24);			//�]�i�H�u�]�w level
        set("con",13);			//��L�S�]�w���ݩʨt�δN�|�۰ʲ���,

        set("evil",15);			//���c�� 20 (�������c, �t���})

   set("attitude", "peaceful");   //�ũM�� NPC�C


  set("chat_chance", 1 );  //�ʧ@���v
  set("chat_msg", ({       //�ʧ@���e
"�Aı�o�o�̦��G���H�b���s�A..\n",
"",
"",
}) );

//===========================���D�^��==================================
set("inquiry/name", @LONG
  �A..�A���ݪ����????
LONG );

//set("talk_reply","�A�ֺ޶���....");
//=========================�԰��T��===========================
     set("chat_chance_combat", 10);
     set("chat_msg_combat", ({
 "���a�Υx�y�j�| : �u�F���Q��T�n�x��y�T�v\n",
     }) );
	
	set_temp("hide",1);
        setup();

//==========================�˳ƹD��=============================
      add_money("dollar", 110);		//�a����
      carry_object(__DIR__"obj/ironkey");
      carry_object(__DIR__"wp/fork0")->wield();
      carry_object(__DIR__"eq/cloth2")->wear();
}
