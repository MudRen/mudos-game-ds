// �ӤH�d��(1) 
// by Luky 19993.20
#include <ansi.h>
inherit NPC;
inherit BANKMAN;
void create()
{
//=========================�򥻳]�w==========================

        set_name("�Ȧ�U�z", ({ "bank assistant","assistant"}));
        set("long",@LONG
        �@�ӲM�q���~���p�j�M�o�b�o�̴����U�Ȧs��ڪ��A�ȡC
        	
        	�l�B�d��	<balance> 
        	�s��		<deposit ���B> 
        	����		<withdraw ���B> 
LONG);
        set("level",15);
        set("title","[1;32m���[m");
        set("gender", "�k��");
        set("race", "human");
        set("age", 26);
        
        //�s���ץ�: �`�N!! (wimpy)
        set("wimpy", 20);		//�k�]wimpy (20%)
	set("evil",-20);		//���c�� 20 (�������c, �t���})

	set("attitude", "peaceful");   //�ũM�� NPC�C
	set("talk_reply","�Q�s��(deposit)��? �`�`�s�ڥi�H�קK�򥢳�!!");
	set("no_kill",1);

//===========================���D�^��==================================
set("inquiry/name", @LONG
  [1;36m �ڥs�����m��.. �Цh����!![0m
LONG );

        setup();
      add_money("dollar", 1670);		//�a����(coin�j�N,dollar�{�N,���ӨS��)
	carry_object(__DIR__"../eq/leather_boots_f_5")->wear();
	carry_object(__DIR__"../eq/cloth_clothes_f_5")->wear();
}

void init()
{
 ::init();
 add_action("do_deposit","deposit");
 add_action("do_withdraw","withdraw");
}
