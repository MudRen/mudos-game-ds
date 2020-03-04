#include <ansi.h>
inherit NPC;
void create()
{
//=========================�򥻳]�w==========================

        set_name( "�ȫ�", ({ "passenger","�ȫ�","passenger",}));
        set("long", "�@�Ӻ��y��ת��ȫȡM���b�Q�w��ĵ�ýL�ݵۡC\n"
        );
        set("level",20);
        set("title","[1;33m�~�a�H[m");
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
//        set("env/wimpy", 20);		//�k�]wimpy (20%)
        set("evil",20);			//���c�� 20 (�������c, �t���})

	set_skill("blade",40);		// �ޯ�(�۩w)
	set_skill("parry",20);		//
	set_skill("dodge",30);		//

//========================�A�����O=================================
//   set("attitude", "friendly");   //�͵��� NPC�C
   set("attitude", "peaceful");   //�ũM�� NPC�C
//   set("attitude", "heroism");    //�^���D�q�� NPC�C
//   set("attitude", "aggressive"); //�D�ʧ���,�ͩʦn������ NPC�C
//   set("attitude", "killer");     //�ݱ����ʪ� NPC�C


//=============================�۰ʰʧ@=================================
  set("chat_chance", 0 );  //�ʧ@���v
  set("chat_msg", ({       //�ʧ@���e
"�ȫȥΤO����F����@�}!! ���G�D�`�ͮ�..\n",
(:command("say �z�a!! �o�O����A�ȺA�׹�!!!"):),
(:command("say �쩳�n�ڻ��X����~~ �o��}�s�M�O�ڭ��ߨ쪺.."):),
(:command("sigh"):),
(:command("shrug"):),
}) );

//===========================���D�^��==================================
set("inquiry/name", @LONG
  [1;36m�ڥs�����L...�A�ݳo�ӷF����?? �L��!![m
LONG );


//=========================�԰��T��===========================
     set("chat_chance_combat", 17);
     set("chat_msg_combat", ({
(:command("kick "+this_player()->query("id")):),
 HIR"�ȫȯ}�f�j�| : �u�i�c���å��T�ڥ����A�T�v\n"NOR,
     }) );

        setup();

//==========================�˳ƹD��=============================
      add_money("coin", 200);		//�a����
      carry_object(__DIR__"item/bag");
      carry_object(__DIR__"wp/kaisan_b")->wield();
      carry_object(__DIR__"eq/blackjacket")->wear();
}

int talk_action(object me)	//talk �ɷ|���榹�禡.
{
 command("smile "+me->query("id") );
 return 1;
}

void init()
{
	::init();
add_action("do_kill","kill");
}

int do_kill(string arg)
{
 if(arg=="passenger")
 {
 message_vision("[1;37m�w��ĵ�ð��W���X�ӹ�$N[1;37m��: �Ф��n�ʤ�, �浹�ڭ̳B�z�N�n�F�C[m\n",this_player());
 return 1;
 }
return 0;
}

//======================�ʧ@����======================================
void relay_emote(object ob, string verb)
{
        if( !userp(ob) ) return;
        switch(verb) {
        case "kick":
                command("angry "+ob->query("id") );
		if(random(10)>7 && !ob->is_fighting())
        	{
        	shout("[1;31m"+ob->query("name")+"("+ob->query("id")+")�d�G���Y�D�o��: �ϩR��!! �ϩR��!!!\n"
        	+"�ȫ�(passenger)�Q�ѱ���!! �ȫ�(passenger)�O���H����!![m\n");
                command("say �L@#$��, �Ѥl���b���Y�W�~�M�����!!");
                kill_ob(ob);
                }
                break;
        case "club":
                command("angry "+ob->query("id") );
                if(random(10)>6 && !ob->is_fighting())
        	{
        	shout("[1;31m"+ob->query("name")+"("+ob->query("id")+")�d�G���Y�D�o��: �ϩR��!! �ϩR��!!!\n"
        	+"�ȫ�(passenger)�Q�ѱ���!! �ȫ�(passenger)�O���H����!![m\n");
                command("say �L@#$��, �Ѥl���b���Y�W�~�M��������!!");
                kill_ob(ob);
                }
                break;
        default:
                command("say �u���@�I!!�O�Ч�!!");
                break;
        }
}

//======================��������======================================
int accept_object(object who, object ob)
{
        int val;

        val = ob->value();
        if( !val )
                return notify_fail("�L���Q���A���F��C\n");
        else if( val > 100 ) {
                if( (who->query("evil") > 0)
                &&      (random(val/10) > (int)who->query("level")) )
                        who->add("evil", - (random((int)who->query("level")) + val/1000) );
        }
        say( "�ȫȻ��D�R�h�³o��" + RANK_D->query_respect(who)
                + "�M�����@�w�|�O���A���C\n");

        return 1;
}

void reset()
{
        // delete("memory");
}
