#include <ansi.h>
inherit NPC;
void goto_1();
void goto_2();
void goto_3();
void create()
{
//=========================�򥻳]�w==========================

        set_name( "�j�L", ({ "bigmouth" }));
        set("long", "�@��ܥΥ\\���s��Ův�M���b��B�ݤ峹�ǪF��C\n");
        set("level",20);
        set("title","[1;32m���ߧŮv[m");
        set("gender", "�k��");
        set("race", "human");
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
  set("chat_chance", 1 );  //�ʧ@���v
  set("chat_msg", ({       //�ʧ@���e
"�Aı�o���I���ӹ�l�C\n",
(:command("look board"):),
(:command("say can you help me?"):),
(:command("hmm"):),
(:command("lick"):),
}) );

//===========================���D�^��==================================
set("inquiry/name", @LONG
  [1;36m�ڥs���d�ͥ|...�A�n!![m
LONG );


//=========================�԰��T��===========================
     set("chat_chance_combat", 17);
     set("chat_msg_combat", ({
(:command("kick "+this_player()->query("id")):),
 HIR"�j�L�ܤ��n���� : �u�i�c���å��TPK�NPK, �֩Ƚ֡T�v\n"NOR,
     }) );


// �Ƶ{�ʧ@

set("schedule",
([
	"00" : (: command("say �{�b�O�C������0�I��F��!!") :),
	"01" : (: command("say �{�b�O�C������1�I��F��!!") :),
	"02" : (: command("go up") :),
	"02" : (: command("say �{�b�O�C������3�I��F��!!") :),
	"04" : (: command("go down") :),
	"05" : (: command("say �{�b�O�C������5�I��F��!!") :),
	"06" : (: command("say �{�b�O�C������6�I��F��!!") :),
	"07" : (: command("say �{�b�O�C������7�I��F��!!") :),
	"08" : (: command("say �{�b�O�C������8�I��F��!!") :),
	"09" : (: command("say �{�b�O�C������9�I��F��!!") :),
	"10" : (: command("say �{�b�O�C������10�I��F��!!") :),
	"11" : (: command("say �{�b�O�C������11�I��F��!!") :),
	"12" : (: command("say �{�b�O�C������12�I��F��!!") :),
	"13" : (: goto_1 :),
	"14" : (: command("say �{�b�O�C������14�I��F��!!") :),
	"15" : (: command("say �{�b�O�C������15�I��F��!!") :),
	"16" : (: command("say �{�b�O�C������16�I��F��!!") :),
	"17" : (: goto_2 :),
	"18" : (: command("say �{�b�O�C������18�I��F��!!") :),
	"19" : (: command("say �{�b�O�C������19�I��F��!!") :),
	"20" : (: command("say �{�b�O�C������20�I��F��!!") :),
	"21" : (: command("say �{�b�O�C������21�I��F��!!") :),
	"22" : (: command("say �{�b�O�C������22�I��F��!!") :),
	"23" : (: goto_3 :),
]));


        setup();

//==========================�˳ƹD��=============================
      add_money("coin", 200);		//�a����
      carry_object("/u/l/luky/npc/item/bag");
      //carry_object(__DIR__"wp/kaisan_b")->wield();
      //carry_object(__DIR__"eq/blackjacket")->wear();
}

int talk_action(object me)	//talk �ɷ|���榹�禡.
{
 command("smile "+me->query("id") );
 command("say �ڷ|�V�O�ǲߪ�!");
 return 1;
}

void goto_1()
{
	if(!find_object("/u/l/luky/workroom")) return;
 message_vision(HIW" �y�{�H�o~ �z�u��$N"HIW"���ѪŤ@�D�M�ƨ����@���p�����M�԰԰�~�������F�C\n"NOR, this_object());
 this_object()->move("/u/l/luky/workroom");
 message_vision(HIW"�y�F~~�z$N"HIW"��M�X�{�b�@�}���������C\n"NOR, this_object());
}

void goto_2()
{
	if(!find_object("/u/s/shengsan/workroom")) return;
 message_vision(HIW" �y�{�H�o~ �z�u��$N"HIW"���ѪŤ@�D�M�ƨ����@���p�����M�԰԰�~�������F�C\n"NOR, this_object());
 this_object()->move("/u/s/shengsan/workroom");
 message_vision(HIW"�y�F~~�z$N"HIW"��M�X�{�b�@�}���������C\n"NOR, this_object());
}

void goto_3()
{
	if(!find_object("/d/wiz/hall1")) return;
 message_vision(HIW" �y�{�H�o~ �z�u��$N"HIW"���ѪŤ@�D�M�ƨ����@���p�����M�԰԰�~�������F�C\n"NOR, this_object());
 this_object()->move("/d/wiz/hall1");
 message_vision(HIW"�y�F~~�z$N"HIW"��M�X�{�b�@�}���������C\n"NOR, this_object());
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
 message_vision("[1;37m�j�L��$N[1;37m��: �Ф��n�ʲ�, ���Ʀn�Ӷq�C[m\n",this_player());
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
        	+"�j�L(bigmouth)�Q�ѱ���!! �j�L(bigmouth)�O���H����!![m\n");
                command("say �L@#$��, �Ѥl���b�Υ\\�~�M�����!!");
                kill_ob(ob);
                }
                break;
        case "club":
                command("angry "+ob->query("id") );
                if(random(10)>6 && !ob->is_fighting())
        	{
        	shout("[1;31m"+ob->query("name")+"("+ob->query("id")+")�d�G���Y�D�o��: �ϩR��!! �ϩR��!!!\n"
        	+"�j�L(bigmouth)�Q�ѱ���!! �j�L(bigmouth)�O���H����!![m\n");
                command("say �L@#$��, �Ѥl���b�Υ\\�~�M�����!!");
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
