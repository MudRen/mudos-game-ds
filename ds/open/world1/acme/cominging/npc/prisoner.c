#include <ansi.h>
inherit NPC;
void create()
{
	set_name("���D��", ({ "capital prisoner","prisoner" }) );
	set("long","�L�O�Ӧ��D�ǡA�����ǤF��o�ӳQ�P���D�C\n");
	set("race","�H��");
	set("gender","�k��");

	set("level", 10);
	set("age",45);

	set_skill("parry", 20);
	set_skill("unarmed", 20);
	set_skill("dodge", 20);

	set("talk_reply","����ڮa���d�p�A�٦��C�Q�h�����ѥ��A�p���Q���b���A\n"
	    "       �ٳQ�P�F���o�A����ڬݧA�O�����F�ڪ��I",);

	set("inquiry",([
  "���o" : "�ڥH�e���H����A�L�c���@���j�a�J�A�e�Ǥ�l�b���@\n"
	    "       ��פl�A�����ֳq�����H�A�����Q�x�L�e�ӥ��ۡA�o��\n"
	    "       �w�A�u�n�{�F�C���ڤw�j���j���I�q�������a�ơI�i�O\n"
	    "       ���ɤw�ߡA�����",
  "�פl" : "�A�O���e�}�l�ڷF�U���פl�ڡI���㨺�ɦb�j��W�ݨ�\n"
	    "       �@�Ӥp���A���o�ٮ��нo���A�ҥH�N��K��K��",
  "�p��" : "�A�O�����Ӥp���ڡI���㨺�Ӥp�������۰d�A��ѱߤW\n"
	    "       �N�W�Q�ۺɤF�I�����o�L�I�o�L�I",
  "�|�}" : "�x�I�H�o�O�Ӥ�K�Ϊ��|�}�ڡI�H�������A�n�h��(dig)�I�H"
]));

	setup();
}

void init()
{ 
	 add_action("do_dig","dig");
}

int do_dig(string arg)
{
	int i;
     object me,ob,wine,wine2,wine3;

	me=this_player();
	ob=this_object();
	i = me->query_temp("SKYCITY/hole");

	if( arg != "�|�}" ) return 0;
	if( me->is_busy() ) return notify_fail("�A���ʧ@�٨S�������M���వ�ʧ@�C\n");

	switch(i) {
	case 0: 
		message_vision("$N���⩹�|�}�̫��A�����o���⪺�j�K�I�n���@�I\n",me);
		command("laugh "+me->query("id"));
		me->set_temp("SKYCITY/hole",i+1);
		me->start_busy(2);
	break; 

	case 1: 
		message_vision("$N���⩹�|�}�̫��A�����o���⪺�j�K�I�n���@�I\n",me);
		command("laugh "+me->query("id"));
		me->set_temp("SKYCITY/hole",i+1);
		me->start_busy(2);
	break;

	case 2: 
		message_vision("$N���⩹�|�}�̫��A�����o���⪺�j�K�I�n���@�I\n",me);
		command("laugh "+me->query("id"));
		me->set_temp("SKYCITY/hole",i+1);
		me->start_busy(2);
	break;

	case 3: 
		message_vision("$N���⩹�|�}�̫��A�����o���⪺�j�K�I�n���@�I\n",me);
		command("say �x�I�H�A��|�p��ť�ܡI�H���|�s���|���I�I"); 
		command("say ��I�ڭ�ı�o�o��"+RANK_D->query_respect(ob)+"�x�ѹL�H�C");
		command("say �A�A���@���ոաI�I");
		command("laugh "+me->query("id"));
		me->set_temp("SKYCITY/hole",i+1);
		me->start_busy(2);
	break;

	case 4: 
		message_vision("$N���⩹�|�}�̫��A�����o���⪺�j�K�I�n���@�I\n",me);
		command("say �ܦn�I�ܦn�I�A�u����ť�ܡC");
		command("say �o�˧a�A�ϥ��ڦ��ߤ]�o���A�ڴN��ڱq���������_�����A�C");
		command("slap "+me->query("id"));
		command("say ��I�I�A��ڳo��e�����F�ܡH�o�ڴx�N�O�ڤ��������_���աI�I");
		me->start_busy(2);
		me->set_temp("SKYCITY/hole",i+1);
	break;

	case 5:
		if(ob->query_temp("SKYCITY/hole")==0)
		{
			wine=new(__DIR__"item/wine");
            wine2=new(__DIR__"item/wine");
            wine3=new(__DIR__"item/wine");
			message_vision("$N���⩹�|�}�̫��A�����o���⪺�j�K�I�n���@�I\n",me);
			command("tsk "+me->query("id"));
			command("say ��ӧA�ٮ������𪺡A���ަp�󥴽|�B�կ��A�٬O����F�A���j�K�����ߡC");
			command("say �ڬݧA�]�����ܨ��W�A�ӧa�I�ڳo�~�s���A�A���M�o���O����n�s�A���L�A�٬O���U�a�C");
         message_vision("���D�ǵ��F$N�@�ǿN�M�l�C\n",me);
        wine->move(me);
        wine2->move(me);
        wine3->move(me);
			me->set_temp("SKYCITY/hole", i+1);
			ob->set_temp("SKYCITY/hole", 1);
			me->start_busy(2);
		}
		else {
			message_vision("$N���⩹�|�}�̫��A�����o���⪺�j�K�I�n���@�I\n",me);
			command("say �A�o�H�ٯu�_�ǡI�o�}�p����ż�A�٤������I�ǤH�I");
			command("snort "+me->query("id"));
			me->start_busy(2);
		}
	break;

	case 6:
		message_vision("$N���⩹�|�}�̫��A�����o���⪺�j�K�I�n���@�I\n",me);
		command("say ���Ϋ��F�աA�ڨS�������_�����A�աI");
		me->start_busy(2);
	break;

	}
	return 1;
}
