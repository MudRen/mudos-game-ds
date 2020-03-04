#include <ansi.h>
#define DRAGON_M "/open/always/dragon_mark"
#define MOON_M "/open/always/moon_mark"
inherit NPC;
void create()
{
//=========================�򥻳]�w==========================

        set_name( "���|�Ϫ�", ({ "club messager","messager"}));
        set("long", "�@�Ӷ¦�H�C\n�A�p�G�򥢤F���|�H��, �i�H��(checkclub)�V�L�ӽФ@�ӷs���H���C\n"
        );
        set("level",1);
        set("title","[1;33m�q�u[m");
        set("gender", "�k��");
        set("race", "�H��");
        set("age", 1);
        set("exp",10);		//���a�����|�o��exp/10 (�i�K)
        				//��ĳ���n�ۤv�]exp. �Ѩt�ΨM�w
        				//�H�K���Pwiz�g��mob �|�X�{�Ӥj���t��
        				
        set("str",1);			//�]�w�ݩ�(�i�K)
        set("dex",1);			//�]�i�H�u�]�w level
        set("con",1);			//��L�S�]�w���ݩʨt�δN�|�۰ʲ���,
        set("int",1);			//�Y�ϬO�ۦP��level�]�|�����P�ݩ�.
        
        set("combat_exp",1);		//�Լ�(���bmob level��100�����k���y)
//        set("env/wimpy", 20);		//�k�]wimpy (20%)
        set("evil",-20);			//���c�� 20 (�������c, �t���})

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
(:command("sigh"):),
(:command("shrug"):),
}) );

//===========================���D�^��==================================
set("inquiry/name", @LONG
�A�ݳo�ӷF����?? �L��!!
LONG );


//=========================�԰��T��===========================
     set("chat_chance_combat", 17);
     set("chat_msg_combat", ({
(:command("kick "+this_player()->query("id")):),
 HIR"�ȫȯ}�f�j�| : �u�i�c���å��T�ڥ����A�T�v\n"NOR,
     }) );

        setup();

//==========================�˳ƹD��=============================
//      add_money("coin", 200);		//�a����
//      carry_object(__DIR__"item/bag");
//      carry_object(__DIR__"wp/kaisan_b")->wield();
//      carry_object(__DIR__"eq/blackjacket")->wear();
}

int talk_action(object me)	//talk �ɷ|���榹�禡.
{
 command("say �A�p�G���F���|�H���N�ӧ�ڥӽ�(checkclub)�a!");
 return 1;
}

void init()
{
	::init();
	add_action("do_checkclub","checkclub");
}

int do_checkclub(string arg)
{
	object me,mark,old_mark;
	string mark_file="";
	me=this_player();
	if(!arg) return notify_fail("checkclub < ���|�W�� > �Ҧp: checkclub moon �C\n");
	if(CLUB_D->check_member(arg,getuid(me)) == 0 ) return notify_fail("���~�����|�W�٩άO�A���b���|�W�椤�C\n");
	mark_file=CLUB_D->query_club_mark(arg);
	if(mark_file=="") return notify_fail("���|�H���ɮש|���n���C\n");
	
	if(!mark=new(mark_file)) return notify_fail("���|�H���ɿ��~�C\n");
	
	if(old_mark=present(mark->query("id"),me)) return notify_fail("�A�w�g�����|�H���F�C\n");
	
	if(!mark->can_move(me))
	{
	 destruct(mark);
	 return notify_fail("�A�n���ᱼ�@�ǪF��~���������|�H���C\n");
	}
	mark->move(me);
	message_vision("$N���F�@"+mark->query("unit")+mark->name()+"��$n�C\n",this_object(),me);
	me->save();
	return 1;

}

int accept_object(object who, object ob)
{
        int val;

        val = ob->value();
        if( !val )
                return notify_fail("�L���Q���A���F��C\n");
        else if( val > 1000 )
        {
                if( (who->query("evil") > 0)
                &&      (random(val/10) > (int)who->query("level")) )
                        who->add("evil", - (random((int)who->query("level")) + val/10000) );
        }
        say( "�Ϫ̻��D�R�h�³o��" + RANK_D->query_respect(who)
                + "�M�����@�w�|�O���A���C\n");

        return 1;
}
