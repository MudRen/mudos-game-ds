// by Luky 19993.20
#include <ansi.h>
inherit NPC;
void create()
{
//=========================�򥻳]�w==========================

        set_name("���Z�w", ({"lee wu der","lee","der"}));
        set("long",@LONG
�@�ӭ���J�K�������~���H�A���b�o�̽m�ߵۤK�����A�@�ۤ@��
���G���[�աA���Ѧa�W���L���`�׬ݨӡA�䰨�B��¦�٤����Ϲ�C

LONG
        );
        set("gender", "�k��");
        set("race", "human");
 	set("level",12);
        set("age", 19);
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
	set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (:command("exert bagi_fist"):),
         }) );

	
   set("attitude", "peaceful");   //�ũM�� NPC�C
set("inquiry/join", @NAME
  [1;36m �ڪ��v�ů��j���N�b�p��(house)�̭��A�Q���J�K�����N�i�h(enter)���L�a�C[m
NAME );
//set("talk_reply","����!?�ڤ��p�ߧ�p����b���K��a(base)�F.. �A�i�H���ڱϱϥL��?");
      setup();
//      set_element("fire");  //�V��: none,metal,plant,wind,ground,water,fire
      add_money("coin", 220);		//�a���� �j�N:coin �{�N:dollar ���ӫh��set("bank/future",�ƶq);
      carry_object("/open/world1/eq/clothes_8")->wear();
      carry_object("/open/world1/wp/woodfist_8")->wield();
}


