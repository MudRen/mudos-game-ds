// by Luky 19993.20
#include <ansi.h>
inherit NPC;
void create()
{
//=========================�򥻳]�w==========================

        set_name("���~", ({"strong man","man"}));
        set("long",@LONG
�@�ӤQ���j�����k�H�A�ݨӥ~�a�w�\�����������l�A���Ӵ��g��
��W�v���U�C��������|�_���즹��t�ݤf�H�j�۵������M�f�A�ݤF
���P���m�Z�̪��A���I�߻ġC

LONG
        );
        set("gender", "�k��");
        set("race", "human");
 	set("level",15);
        set("age", 30);
        //set("exp",300);		//���a�����|�o��exp/10 (�i�K)
        				//��ĳ���n�ۤv�]exp. �Ѩt�ΨM�w
        				//�H�K���Pwiz�g��mob �|�X�{�Ӥj���t��
			
//        set("env/wimpy", 10);		//�k�]wimpy (10%)
        set("evil",-20);		//���c�� -20 (�������c, �t���})

	set_skill("unarmed",99);	// �ޯ�(�۩w)
	set_skill("combat",90);		//

   set("attitude", "peaceful");   //�ũM�� NPC�C
set("inquiry/name", @NAME
  [1;36m �ڥs���s�ѥ�.. �Цh����!![m
NAME );
set("inquiry/�s�ѥ�", "�o�O�ڪ��W�r, �����D�ܡH");
//set("talk_reply","����!?�ڤ��p�ߧ�p����b���K��a(base)�F.. �A�i�H���ڱϱϥL��?");
      setup();
//      set_element("ground");    //�V��: none,metal,plant,wind,ground,water,fire
      add_money("coin", 320);		//�a���� �j�N:coin �{�N:dollar ���ӫh��set("bank/future",�ƶq);
      carry_object("/open/world1/eq/clothes_8")->wear();
      carry_object("/open/world1/wp/hammer_16")->wield();
}


