// by Luky 19993.20
#include <ansi.h>
inherit NPC;
void create()
{
//=========================�򥻳]�w==========================

        set_name("���Z�F", ({"lee wu da","lee","da"}));
        set("long",@LONG
�@�ӭ���J�K�������~���H�A���b�o�̹�۽_��H�m�ߤj�j�Z�A
�ݰ_�Ӧ��G�٤��Ӽ��m�C

LONG
        );
        set("gender", "�k��");
        set("race", "human");
 	set("level",13);
        set("age", 19);
        //set("exp",300);		//���a�����|�o��exp/10 (�i�K)
        				//��ĳ���n�ۤv�]exp. �Ѩt�ΨM�w
        				//�H�K���Pwiz�g��mob �|�X�{�Ӥj���t��
			
//        set("env/wimpy", 10);		//�k�]wimpy (10%)
        set("evil",-20);		//���c�� -20 (�������c, �t���})

	set_skill("unarmed",99);	// �ޯ�(�۩w)
	set_skill("combat",90);		//
	set_skill("fork",70);		//
	set_skill("da-fork",30);	//
	map_skill("fork","da-fork");
//	set("chat_chance_combat", 50);
//       set("chat_msg_combat", ({
//                (:command("exert da-fork"):),
//         }) );

	
   set("attitude", "peaceful");   //�ũM�� NPC�C
set("inquiry/master", @NAME
  [1;36m �ڪ��v�ů��j���N�b�p��(house)�̭��A�Q���L�N�i�h(enter)�a�C[m
NAME );
//set("talk_reply","����!?�ڤ��p�ߧ�p����b���K��a(base)�F.. �A�i�H���ڱϱϥL��?");
      setup();
//      set_element("fire");  //�V��: none,metal,plant,wind,ground,water,fire
      add_money("coin", 120);		//�a���� �j�N:coin �{�N:dollar ���ӫh��set("bank/future",�ƶq);
      carry_object("/open/world1/eq/clothes_8")->wear();
      carry_object("/open/world1/wp/pike_13")->wield();
}


