#include <ansi.h>
#include <dbase.h>
//award eq list
string *file=({"bestaxe","bestfork","bestneck","bestsword","doll",
              "moonshade","lightwaist","fairsword","fairring","fairfist",
              "poorboots","poorcloth","poordagger","superpill"});

inherit F_VENDOR;
inherit NPC;
void gotoinn();
void create()
{
//=========================�򥻳]�w==========================

        set_name( "�ڹҤۼv", ({ "dream illusion","illusion" }));
        set("long", "���O�@�Ө���v���Y���Y�L, �ܤƸU�d���ۼv...�ݰ_�Ӭ۷����C\n");
        set("level",60);
        set("title","�C�줧�v");
        set("gender", "�k��");
        set("race","human");
        set("age",777);
//        set("exp",1000);		//���a�����|�o��exp/10 (�i�K)
        				//��ĳ���n�ۤv�]exp. �Ѩt�ΨM�w
        				//�H�K���Pwiz�g��mob �|�X�{�Ӥj���t��
        				
//        set("str",100);			//�]�w�ݩ�(�i�K)
//        set("dex",80);			//�]�i�H�u�]�w level
//        set("con",80);			//��L�S�]�w���ݩʨt�δN�|�۰ʲ���,
//        set("int",80);			//�Y�ϬO�ۦP��level�]�|�����P�ݩ�.
        
//        set("combat_exp",2000);		//�Լ�(���bmob level��100�����k���y)
//        set("evil",20);			//���c�� 20 (�������c, �t���})

	set_skill("unarmed",100);		// �ޯ�(�۩w)

//========================�A�����O=================================
   set("attitude", "friendly");   //�͵��� NPC�C
//   set("attitude", "peaceful");   //�ũM�� NPC�C
//   set("attitude", "heroism");    //�^���D�q�� NPC�C
//   set("attitude", "aggressive"); //�D�ʧ���,�ͩʦn������ NPC�C
//   set("attitude", "killer");     //�ݱ����ʪ� NPC�C


//=============================�۰ʰʧ@=================================
  set("chat_chance",10);  //�ʧ@���v
  set("chat_msg", ({       //�ʧ@���e
(:command("hmm"):),
(:command("say �����D����, �i�H�ݧ�(talk with me)��!"):),
}) );

//===========================���D�^��==================================
//set("inquiry/name","�ڥs���d�ͥ|...�A�n");


//=========================�԰��T��===========================
//     set("chat_chance_combat", 17);
//     set("chat_msg_combat", ({
//(:command("kick "+this_player()->query("id")):),
// HIR"�j�L�ܤ��n���� : �u�i�c���å��TPK�NPK, �֩Ƚ֡T�v\n"NOR,
//     }) );


// �Ƶ{�ʧ@

set("schedule",
([
	"00" : (: gotoinn :),
	"06" : (: gotoinn :),
	"12" : (: gotoinn :),
	"18" : (: gotoinn :)
]));
        setup();

//==========================�˳ƹD��=============================
//      add_money("coin",200);		//�a����
//      carry_object("/u/l/luky/npc/item/bag");
      //carry_object(__DIR__"wp/kaisan_b")->wield();
      //carry_object(__DIR__"eq/blackjacket")->wear();
}

int talk_action(object me)	//talk �ɷ|���榹�禡.
{
 command("hmm "+me->query("id") );
 command("say ����Q�F? �@, �j���O�Q�����y�~���a.");
 command("say ��. �i�D�ڧA�n���h�ְ^�m�ȥX�Ӵ�, �ڴN�|���A�@�ǪF��.");
 command("say ���ت�ۤv�� glist �ݬݧa.");
 return 1;
}

void gotoinn()
{
 int a=random(4);
	if(!find_object("/open/world1/tmr/area/hotel")) return;
	if(!find_object("/open/world1/cominging/area/hotel")) return;
	if(!find_object("/open/world1/acme/area/hotel")) return;
	if(!find_object("/open/world2/shengsan/aovandis/room079")) return;
 message_vision("�������ۼv�@�Ӱ{��, ��M�����b���H���e�C\n", this_object());
 if( a == 0 ) {
   if( file_name(environment(this_object())) == "/open/world2/shengsan/aovandis/room079" ) a++;
   else this_object()->move("/open/world2/shengsan/aovandis/room079"); 
 }
 if( a == 1 ) {
   if( file_name(environment(this_object())) == "/open/world1/cominging/area/hotel" ) a++;
   else this_object()->move("/open/world1/cominging/area/hotel");
 } 
 if( a == 2 ) {
   if( file_name(environment(this_object())) == "/open/world1/acme/area/hotel" ) a++;
   else this_object()->move("/open/world1/acme/area/hotel");
 }
 if( a == 3 ) {
   if( file_name(environment(this_object())) == "/open/world1/tmr/area/hotel" ) a=0; 
   else this_object()->move("/open/world1/tmr/area/hotel");
 }
 message_vision("��M�@�ӯ������ۼv���b�A���e, �A�ڥ������D���O��ɥX�{���C\n", this_object());
}

void init()
{
	::init();
        add_action("do_glist","glist");
	add_action("do_change","change");
}
string item_desc(object ob)
{
	if(ob->query("skill_type")) return HIG+"�Z��"+NOR;
	else if(ob->query("armor_type")) return HIY+"����"+NOR;
	else if(ob->query("heal_hp") || ob->query("heal_mp") || ob->query("heal_ap")) return HIC+"�^�_"+NOR;
	else return "�D��";
}
int do_glist(string arg)
{
  string dir,list;
  object awardeq;
  int i,a,awardcost;
  dir = "/open/world1/award/";
  i = sizeof(file);
  list = "\n\n�z�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�{\n";
  list +="�x �һݰ^�m��        ����   �ثe�i�H�I�������~          �x\n";   
  list +="�|�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�}\n";
  for(a=0;a<i;a++) {
    if(load_object(dir+file[a])) {
      awardeq = load_object(dir+file[a]);
      awardcost = awardeq->query("needaward");
      list += sprintf("%6d ------------- %4s  %-30s",awardcost,item_desc(awardeq),awardeq->short()); }
    else break;
    list += "\n";
  }
  list +="\n";
  list +=" �`�N�ƶ�: �I�����᪺���~�򥢰��D, �b�U�����t�d. �Ӧ��B�I����\n";
  list +="           ���~, ���F�i�H�ä[�O�s���~, �һP�@�몫�~�L��, �ȥ�\n";
  list +="           �p�ߦ���! �n�I���Х� change ���O(�|������).\n";
  this_player()->start_more(list);
  return 1;
}
int do_change(string arg)
{
  return 0;
}

//======================�ʧ@����======================================
/*void relay_emote(object ob, string verb)
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
} */

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
        say("�ڹҤۼv���D�R�h�³o��" + RANK_D->query_respect(who)
                + "�M�����@�w�|�O���A���C\n");

        return 1;
}

void reset()
{
        // delete("memory");
}
