// by Luky 19993.20
#include <ansi.h>
inherit NPC;
void create()
{
//=========================�򥻳]�w==========================

        set_name("������", ({"lee charn fan","lee","fan"}));
        set("long",@LONG
�@�Ӻ��Y�յ����ѤH�A���b�o�̱��a�A�ʧ@�ݨ����M��w�A���O
�o���@�ѻ����X���y�Z�P�C�|�����d���A�R�������ǡA�ݨӤ��O�@��
���Z�����Y��C

LONG
        );
        set("gender", "�k��");
        set("title","���a�ѭ�");
        set("race", "human");
 	set("level",22);
        set("age", 76);
        //set("exp",300);		//���a�����|�o��exp/10 (�i�K)
        				//��ĳ���n�ۤv�]exp. �Ѩt�ΨM�w
        				//�H�K���Pwiz�g��mob �|�X�{�Ӥj���t��
			
//        set("env/wimpy", 10);		//�k�]wimpy (10%)
        set("evil",-20);		//���c�� -20 (�������c, �t���})

	set_skill("unarmed",99);	// �ޯ�(�۩w)
	set_skill("combat",90);		//
	set_skill("fork",70);		//
	set_skill("bagi_fist",30);
	set_skill("horse-steps",20);
	set_skill("staff",90);
	set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (:command("exert hurrycan_staff"):),
         }) );

	
   set("attitude", "peaceful");   //�ũM�� NPC�C
set("inquiry",([
  "bagi":"�K�����j���N�b�p��(house)�̭��A�i�h(enter)���L�a�C",
  "�K����":"�K�����j���N�b�p��(house)�̭��A�i�h(enter)���L�a�C",
 ]));
set("talk_reply","...");
      setup();
      //set_element("metal");  //�V��: none,metal,plant,wind,ground,water,fire
      add_money("coin", 820);		//�a���� �j�N:coin �{�N:dollar ���ӫh��set("bank/future",�ƶq);
      carry_object("/open/world1/eq/clothes_8")->wear();
      carry_object("/open/world1/wp/ironbroom_21")->wield();
}


