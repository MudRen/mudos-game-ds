/**
 *	Shadow's mob - �~���H(�����H��)
 */
 
#include <ansi.h>
inherit NPC;

int quest();

void create()
{
	/* �H���򥻳]�w */
	set_name( "�~���H", ({ "young man", "man" }) );
	set("long", @LONG
    �L�Ⲵ�Ŭ}�A�u�O�b�b����۴�ߡA���o�@�y�A�⤤�򴤵�
�@���եɡA���ɧC�Y�����A�@�y���s�T���G�O���L�����ߨơA�]�\
�A�i�H�i�H�M�L�ͽ͡C(talk with young man)
LONG
	);
	set("level", 20);	
	set("age", 21);
	set("no_fight", 1);
  set("chat_chance", 20);
  set("chat_msg", ({
		(: quest :),
	}));

	/* ������Ȫ��T�� */
	set("talk_reply", "........ �n��(say)�ƻ�O�H���h���F��A�]�^���ӤF...");
		
	setup();

	call_out("re_quest", 900);
}

int quest()
{
	object ob = this_object();
	if(ob->query_temp("pass_quest"))	message_vision("�w�g�S���ƻ�Ʊ��A��дo�ڤF�I\n",ob);
	else command("sigh");
	return 1;
}

int re_quest()
{
  this_object()->delete_temp("pass_quest");
  this_object()->delete_temp("pass_quest_who");
  this_object()->delete_temp("item_give");
  this_object()->delete_temp("item_give_who");
  call_out("re_quest", 900);
  return 1;
}

void relay_say(object me, string str)
{
	object ob = this_object(), obj;
	string game_index = "no";
  if( !userp(me) ) return;
  if (ob->query_temp("pass_quest"))	{
  	write("�h�³o��"+RANK_D->query_respect(me)+"���n�N�I�w�g�S���ƻ�Ʊ��A��дo�ڤF�I\n");
  	return;
  }	
  if(strsrch(str,"���h���F��") !=-1)	{
		command("say ...................");
		message_vision(YEL"�~���H�Y�]���^�A�u�O�b��۴򭱤��o�@�y�C\n"NOR, me);
		message_vision(YEL"�A���G�ڸ��g���a�C�ݧA�T�e�������A�ݨӤ@�ƤߨƤߨƭ������ˤl�A��աA�̪񳽨ण�W�İ�!?\n"NOR, me);
		message_vision(YEL"�~���H�L�`���q�q�ӫj�j�W���F�@�U�A���H�Y�S�������ĤF�@�f��C\n"NOR, me);
		message_vision(YEL"�o�@�W�٦��֯����ڪ����O�H�C\n"NOR, me);
		command("sigh");
  } else if (strsrch(str,"��") !=-1 || strsrch(str,"����") !=-1)	{
		command("say ��...���§A���n�N�A�o�i���O���q�H�i�H���ڪ�..�C");
		message_vision(YEL"�~���H�ਭ���ǳƦ^�˫Τ��ɡA�����h���F�A�@�����Y�C������M�����@�G�A�榣�@����F�A������C\n"NOR, me);
		command("say �ݱz�@���u�����˳ơA�@�w�O�樫���򪺤j�L�A����Q�����Z�C");
		command("say �i�H..�i�H�ЧA���ڤ@�Ӧ����A�A..�@�w�n����..�@�w�n���ڡC");
		me->command("nod");  	
  } else if ( strsrch(str,"�i�H") !=-1 || strsrch(str,"�n") !=-1 || strsrch(str,"�S���D")!=-1 )	{
		message_vision(YEL"�~���H�}�l�z����ӨƱ������s�h�ߵ��Ať�C\n"NOR, me);
		message_vision(YEL"......\n"NOR, me);
		message_vision(YEL"�o�s�u�[�v�A�ڧ�Ʊ泣�U�I���A�F�A�Ʀ�����ڤ@�w�n�n�����A�C\n"NOR, me);
  	message_vision(YEL"�y���A�~���H�N��⤤���եɻ����A�C\n"NOR, me);
		new(__DIR__"key")->move(me); /* �N�եɥ浹���a */
		//command("give " + me->query("id") + " key");
		set_temp("item_give", 1);
		set_temp("item_give_who", me->name(1));
		message_vision(YEL"�~���H�G�q�o�ӯB���i�H���U�h(jump down)�A�@�������U�A�F�C\n"NOR, me);
  	message_vision(YEL"�~���H�§A���F����C\n"NOR, me);  	
  }
  return;
}

