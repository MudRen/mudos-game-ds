// ���Ƚd�ҤH�� 
// by Luky 19993.20
#include <ansi.h>
inherit NPC;
void create()
{
//=========================�򥻳]�w==========================

        set_name( "�p��", ({ "boy"}));
        set("long", "�@�Ӥp�k��, �L�ݰ_�ӫܷW�i, �A�i�H�ոլݩM�L������(talk with boy)�C\n"
        );
        set("level",2);
        set("gender", "�k��");
        set("race", "�H��");
        set("age", 6);
        set("exp",300);			//���a�����|�o��exp/10 (�i�K)
        				//��ĳ���n�ۤv�]exp. �Ѩt�ΨM�w
        				//�H�K���Pwiz�g��mob �|�X�{�Ӥj���t��
        				
        set("str",5);			//�]�w�ݩ�(�i�K)
        set("dex",6);			//�]�i�H�u�]�w level
        set("con",5);			//��L�S�]�w���ݩʨt�δN�|�۰ʲ���,
        set("int",6);			//�Y�ϬO�ۦP��level�]�|�����P�ݩ�.
        
        set("combat_exp",200);		//�Լ�(���bmob level��100�����k���y)
        set("env/wimpy", 10);		//�k�]wimpy (10%)
        set("evil",-30);		//���c�� 20 (�������c, �t���})

	set_skill("blade",20);		// �ޯ�(�۩w)
	set_skill("parry",20);		//
	set_skill("dodge",20);		//

   set("attitude", "peaceful");   //�ũM�� NPC�C
set("inquiry/name", @LONG
  [1;36m �ڥs���p��.. �Цh����!![m
LONG );
set("inquiry/base", "[1;36m ���K��a�N�b���䨺�Ӧa�}(hole)��..���I�h�ϥL�a!![m\n");
set("inquiry/hole", "�a�}? �N�b�A�᭱��..�� go hole �N�i�H�i�h�F!!\n");
set("talk_reply","����!?�ڤ��p�ߧ�p����b���K��a(base)�F.. �A�i�H���ڱϱϥL��?");
      setup();
      add_money("coin", 20);		//�a����
      carry_object("/u/l/luky/npc/item/dump");
}


