// �ӤH�d��(1) 
// by Luky 19993.20
#include <ansi.h>
inherit NPC;
inherit BANKMAN;
void create()
{
//=========================�򥻳]�w==========================

        set_name( "���p�j", ({ "miss lee","lee"}));
        set("long", "�@�ӲM�q���~���p�j�M�o�b�o�̪��u�@�O���ѮȫȦs��ڪ��A�ȡC\n\n"
        	    +"  �d�߱b��Х� <balance> \n"
        	    +"  �ݦs���Х� <deposit ���B> \n"
                +"  �n���ڽХ� <withdraw ���B> \n\n"
        );
        set("level",20);
        set("title","[1;32m���ĤH��[m");
        set("gender", "�k��");
        set("race", "�H��");
        set("age", 42);
        set("exp",1000);		//���a�����|�o��exp/10 (�i�K)
        				//��ĳ���n�ۤv�]exp. �Ѩt�ΨM�w
        				//�H�K���Pwiz�g��mob �|�X�{�Ӥj���t��
        				
        set("str",31);			//�]�w�ݩ�(�i�K)
        set("dex",21);			//�]�i�H�u�]�w level
        set("con",33);			//��L�S�]�w���ݩʨt�δN�|�۰ʲ���,
        set("int",18);			//�Y�ϬO�ۦP��level�]�|�����P�ݩ�.
        
        set("combat_exp",2000);		//�Լ�(���bmob level��100�����k���y)
        
        //�s���ץ�: �`�N!! (wimpy)
        set("wimpy", 20);		//�k�]wimpy (20%)
        
        set("evil",-20);		//���c�� 20 (�������c, �t���})

	set_skill("blade",40);		// �ޯ�(�۩w)
	set_skill("parry",20);		//
	set_skill("dodge",30);		//

   set("attitude", "peaceful");   //�ũM�� NPC�C
   set("talk_reply","�Q�s��(deposit)��? �`�`�s�ڥi�H�קK�򥢳�!!");

  set("chat_chance", 3 );  //�ʧ@���v
  set("chat_msg", ({       //�ʧ@���e
(:command("smile"):),
}) );

//===========================���D�^��==================================
set("inquiry/name", @LONG
  [1;36m �ڥs�����A��.. �Цh����!![m
LONG );

        setup();

      add_money("dollar", 120);		//�a����(coin�j�N,dollar�{�N,���ӨS��)

}

void init()
{
 add_action("do_deposit","deposit");
 add_action("do_withdraw","withdraw");
}


