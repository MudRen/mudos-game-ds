/* 
 * ���ѽu�W���a�����ݩ��`�M�C��
 *
 *
 */
#include <ansi.h>
inherit NPC;
int sort_atts(int at1, int at2);
void create()
{
//=========================�򥻳]�w==========================

        set_name( "�s�@", ({ "ryu ichi","ryu","ichi"}));
        set("long", @LONG
�M�J��î���O�@��L�D�����~�k�l�A�ˤ����������z�ۤ@�ѷF�m
�������P�C�~���ɪ��L�O�@��i�����_�I�ӤH�A�b�@���X�G��R����
�󤤳Q�����g�L���_�I�̩ҷf�ϡA����K�n�u�b���a���U�_�I�̸̭�
�M�@�Ǻ������g�C

     checkclub	< ���|�W�� >	�ɵo���|�H�� [�K�O]
     checkuser	< ���a��id >	�լd�u�W�Y�쪱�a�ݩʱj�� [200��/��]
          (PS. �Ův�i�ϥ�userdata���O���o�u�W���a�ݩ��`�M�C��)

LONG
        );
        set("level",50);
        set("title","[1;33m���u[m");
        set("gender", "�k��");
        set("race", "�H��");
        set("age", 42);
        set("exp",10);		//���a�����|�o��exp/10 (�i�K)
        				//��ĳ���n�ۤv�]exp. �Ѩt�ΨM�w
        				//�H�K���Pwiz�g��mob �|�X�{�Ӥj���t��
        				
        set("str",73);			//�]�w�ݩ�(�i�K)
        set("dex",54);			//�]�i�H�u�]�w level
        set("con",67);			//��L�S�]�w���ݩʨt�δN�|�۰ʲ���,
        set("int",58);			//�Y�ϬO�ۦP��level�]�|�����P�ݩ�.
        
        set("evil",-20);			//���c�� 20 (�������c, �t���})

//========================�A�����O=================================
//   set("attitude", "friendly");   //�͵��� NPC�C
   set("attitude", "peaceful");   //�ũM�� NPC�C
//   set("attitude", "heroism");    //�^���D�q�� NPC�C
//   set("attitude", "aggressive"); //�D�ʧ���,�ͩʦn������ NPC�C
//   set("attitude", "killer");     //�ݱ����ʪ� NPC�C


//===========================���D�^��==================================
set("inquiry", ([
"name":"�b�U�s�@�A�Цh�h���СC\n",
"club":"�ڧکҪ��A�ثe���|�j���|�A���O�O�y���ڡz�y�g�s�z�y��ڡz�٦��y�Ѧa�z�C\n",

// add by alickyuen
"marry" : "�A�̪񪺱B�åͬ��p���H\n",
]));
       setup();

//==========================�˳ƹD��=============================
//      add_money("coin", 200);		//�a����
//      carry_object(__DIR__"item/bag");
//      carry_object(__DIR__"wp/kaisan_b")->wield();
//      carry_object(__DIR__"eq/blackjacket")->wear();
}
/*
int talk_action(object me)	//talk �ɷ|���榹�禡.
{
 command("say �A�p�G���F���|�H���N�ӧ�ڥӽ�(checkclub)�a!");
 return 1;
}
*/
void init()
{
	::init();
	add_action("do_checkclub","checkclub");
	add_action("do_checkuser","checkuser");
	add_action("do_checkmarry","checkmarry");
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
int do_checkuser(string arg)
{
	object me,target;
	string msg="",target_name="";
	int *atts;
	me=this_player();
// if(!arg || arg=="") return notify_fail("checkclub < ^@^P^W|^FW^Z^Y > ^H^R^Fp: checkclub moon ^AC\n");
 if(!arg || arg=="") return notify_fail("checkuser < ���aid > �Ҧp: checkuser luky \n");
	
	if(!target=find_player(arg)) return notify_fail("�ثe�u�W�䤣��o�쪱�a�C\n");
	if(wizardp(target) && !me->visible(target)) return notify_fail("�ثe�u�W�䤣��o�쪱�a�C\n");
	if(!me->can_afford(200))
		return notify_fail("�o���A�Ȼݭn200���A�ӧA���W���������C\n");
	 me->receive_money(-200);
	atts = ({ target->query("con"), target->query("int"), target->query("str"), target->query("dex") });
	atts = sort_array(atts, -1);
	target_name=target->query("name")+"(" + capitalize(target->query("id")) + ")";
        
    msg = sprintf("�s�@���X�@�����֤p�U�l½�F�@�U�A�M�ỡ:\n\n"+
    	"\t%s �ثe�����ŬO %d �šA�~�֬O %d ���A\n\t�ݩ��`�M�� %d �I�A�䤤�̰����ݩʬO %d �I�C\n",
	target_name,target->query("level"),target->query("age"),target->query_total_gift(),atts[0]);
//    msg+=sprintf("%d,%d,%d,%d\n",atts[0],atts[1],atts[2],atts[3]);
    me->start_more(msg);
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
        say( "�s�@���R�h���o�M���z���_�I�@�����Q�C\n");

        return 1;
}
/*	add by alickyuen	*/
int do_checkmarry()
{
}
