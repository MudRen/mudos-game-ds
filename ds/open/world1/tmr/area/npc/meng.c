#include <net/dns.h>
inherit NPC;

int WWWW=0;
string arg;
void do_teach();

void create()
{
        set_name("�s��A",({"meng chiou nong","meng"}) );
	set("long",
	"�@�Ӧ~���C�Q���������վv�ѯΡA��۾�ꥭ�`�A�@�y�M���A���w�J\n"
	"�j�}���~�A���믫���]�A���@�����ѺA�C�s��A��Ū�֮ѡA�`�`�оɧ�����\n"
    "Ū���Ѧr�A�L���~���k�M�w���F���p�ѡC�p�A�]�Q�hŪ�I�ѡA�������U�ӡA\n"
	"�M�j�a�@�_Ū�ѡC\n"
        );
        set("title","����");
        set("age",70);
        set("level",10);
        set("gender","�k");
        set("race","�H��");
        set("chat_chance",10);

        set("chat_msg",({
		(:do_teach:),
		(:do_teach:),
		"�s��A���F�ӫ���..�u��..��������̤F?..���ڷQ�Q..�v\n",
		(:do_teach:),
		"�s��A�I�F�I�Y�A�åB���F�X�B�C\n",
		(:do_teach:),
        }) );	

        set_skill("unarmed",20);
        set_skill("parry",20);
        set_skill("dodge",20);
        set_skill("bagi_fist",10);
        map_skill("unarmed","bagi_fist");
        setup();
        add_money("silver",5);
}

void do_teach()
{
	object ob,*s;
	
	int j;
	arg="�Х��ͱл�";
	ob=this_object();

	if(ob->is_fighting() ) return;
	
	switch(WWWW)
	{
	
	case 1:
		command("say ���R���`�A��X�_�o�C");
		arg="���R���`�A��X�_�o�C";
	break;

	case 2:
		command("say ��H���E�A���H�s���A�N���ͨo�C");
		arg="��H���E�A���H�s���A�N���ͨo�C";

	break;

	case 3:
		command("say �b�Ѧ��H�A�b�a���ΡA�ܤƨ��o�C");
		arg="�b�Ѧ��H�A�b�a���ΡA�ܤƨ��o�C";
	break;
	case 4:
		command("say �O�G�A��X�ۼ��A�K���ۿ��C");
		arg="�O�G�A��X�ۼ��A�K���ۿ��C";
	break;
	case 5:
		command("say �����H�p�^�A���H���B�C");
		arg="�����H�p�^�A���H���B�C";
	break;
	case 6:
		command("say ���B��A�@�H�@���A���D���k�A�[�D���k�C");
		arg="���B��A�@�H�@���A���D���k�A�[�D���k�C";
	break;
	case 7:
		command("say �����j�l�A�[�@�U���A���H�����A�[�H²��C");
		arg="�����j�l�A�[�@�U���A���H�����A�[�H²��C";
	break;
	case 8:
		command("say �����h���ˡA���q�h���\\�C");
		arg="�����h���ˡA���q�h���\\�C";
	break;
	case 9:
		command("say ���˫h�i�[�A���\\�h�i�j�C");
		arg="���˫h�i�[�A���\\�h�i�j�C";
	break;
	case 10:
		command("say �ФF�@�q�A�t��ǳդj��`�A���ȧA�̰O����A�ڦA�����@���a�C");
		WWWW=-1;
	break;
	default:
		command("say �ѴL�a���A���[�w�o�C�����H���A�Q���o�C");
		arg="�ѴL�a���A���[�w�o�C�����H���A�Q���o";
		break;
	}

	WWWW++;

	s = all_inventory(environment(this_object()));
	if(sizeof(s)<1) return;
	for(j=0;j<sizeof(s);j++)
	{
		if(userp(s[j]) && s[j]->query_temp("do_sit") && arg)
		{
                if( s[j]->query_temp("netdead") == 1 ) continue;
                // �_�u���H������Ū��...add by -Acme-
			message_vision("$N��۩��D�G"+arg+"\n",s[j] );
          		if (s[j]->query_skill("literate",1) <60)
			s[j]->improve_skill("literate",s[j]->query_int()/10+random(2));
		}
	}
	arg="";
	return;
}


void init()
{
   ::init();
	add_action("do_sit","sit");
	if (this_player()->query_temp("do_sit") ) this_player()->delete_temp("do_sit");
    this_object()->set_heart_beat(1);
//	add_action("do_go","go");
//	add_action("do_recall","recall");
}


int do_sit()
{
	object me;
	me=this_player();

    if(me->query_temp("do_sit")) return notify_fail("�A�w���U�ӱM��ť���F�C\n");
	if (me->is_fighting() ) return notify_fail("�A�����ۥ��[�A�S��ť�ҡI\n");
	if(me->is_ghost()) return notify_fail("�����F�A��Ū�����..:P�I\n");
	if(me->is_busy() ) return notify_fail("�A�����ۡA�S����ť�ҡC\n");

	message_vision("$N�N�a��F�Ӧ�l���U��ť�ҤF�C\n",me);
	me->set_temp("do_sit",1);
	return 1;
}
/*
void do_go(string arg)
{
	if (arg=="north" && this_player()->query_temp("do_sit") ) this_player()->delete_temp("do_sit");
}

int do_recall(string arg)
{
    if (this_player()->query_temp("do_sit") ) 
        this_player()->delete_temp("do_sit");
	return 0;
}
*/
