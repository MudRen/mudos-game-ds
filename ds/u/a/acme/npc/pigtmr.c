#include <ansi.h>
inherit NPC;
string *rnd_say = ({
	"�ڬO�s��M�Чi�D�ڦp�󪱳o�ӹC���C",
	"������ڪ���𯫳����|��_�S",
	"���֥i�H���ڤ@�ǿ��S",
	"�o�̪��H�����z�ڡT",
	"�i���i�H�i�D�ڭ��̥i�H�m�\\�S",
	"hi",
	"hello",
	"hmm",
	"wa...",
	"waley",
	"wait...",
	"hohoho",
	"hehe",
	"ah..",
});

varargs void drool(string msg, string who);

void create()
{
	string name, id;


set_name("�_",({"tmr"}));
	set("title", "���q�ʩm");
	set("gender", "�k��");
	set("age", 14);
	set("attitude", "friendly");
	set("combat_exp", 100);
	set("env/wimpy", 100);
	set("chat_chance", 30);
	set("chat_msg", ({
		(: drool :),
		(: drool :),
		(: drool :),
		(: drool :),
		(: drool :),
	}) );
	setup();
	if( clonep() ) CHANNEL_D->register_relay_channel("chat");
}

int add_phrase(string who, string msg)
{
	msg = replace_string(msg, "?", "");
	msg = replace_string(msg, "�H", "");
	msg = replace_string(msg, "�S", "");
	msg = replace_string(msg, "!", "");
	msg = replace_string(msg, "�I", "");
	msg = replace_string(msg, "��", "");
	msg = replace_string(msg, "��", "");
	msg = replace_string(msg, "�C", "");
	msg = replace_string(msg, "�a", "");

	if( msg!="" ) {
		add("memory/" + who, ({ msg }));
		return 1;
	} else return 0;
}

string make_reply()
{
}

void relay_channel(object ob, string channel, string msg)
{
	string who, phrase;

	if( !userp(ob) || (channel != "chat") ) return;
	who = ob->query("name");

	// Don't process our own speech.
	if( ob==this_object() ) return;

	if( add_phrase(who, msg) &&	random(10) > 4 )
		drool(msg, ob->query("name"));
}

void relay_say(object ob, string msg)
{
	string who, phrase;

	if( !userp(ob) ) return;
	who = ob->query("name");

	// Don't process our own speech.
	if( ob==this_object() ) return;

	if( add_phrase(who, msg) &&	random(10) > 4 )
		drool(msg, ob->query("name"));
}

void relay_emote(object ob, string verb)
{
	if( !userp(ob) ) return;

	switch(verb) {
	case "kick":
		if( random(10)<5 ) {
			command("say �������ڡS�|�h�C�T");
			break;
		}
	default:
		if( random(10)<5 )
			command(verb + " " + ob->query("id"));
		else
			drool();
	}
}

varargs void drool(string msg, string who)
{
	mapping mem;
	string *ob;

	mem = query("memory");
	if( !mapp(mem) ) return;

	if( !msg || !who) {
		ob = keys(mem);
		who = ob[random(sizeof(ob))];
		msg = mem[who][random(sizeof(mem[who]))];
	}

	if( (strsrch(msg, "������") >= 0) ) {
		if( sscanf(msg, "%*s������%s", msg)==2 ) msg = "������" + msg;
		switch(random(8)) {
          case 0: command("tchat " + who + "�M�A�O�b�ݧڶܡS"); break;
          case 1: command("tchat ����" + msg + " ... "); break;
          case 2: command("tchat �c ... "); drool(); break;
          case 3: command("tchat �o�Ӱ��D�� ...."); break;
          case 4: command("tchat " + who + "�M���D�o�Ӱ��D�����׹�A���򭫭n�ܡS"); break;
          case 5: command("tchat " + msg + "�S"); break;
          case 6: command("tchat " + who + "�A�ण�໡�M���@�I�S"); break;
          case 7: command("tchat " + who + "�M�ڤ����A�ݪ����D"); break;

		}
	}
	else if( (strsrch(msg, "�A") >= 0)
	||	(strsrch(msg, "�p") >= 0)
	||	(strsrch(msg, "drooler") >= 0)
	||	(strsrch(msg, "Drooler") >= 0)) {
		if( sscanf(msg, "%*s�A%s", msg) == 2 ) msg = "�A" + msg;
		msg = replace_string(msg, "�A", "��");
		msg = replace_string(msg, "�p", "��");
		switch(random(10)) {
          case 0: command("tchat " + who + "�M�A�O��" + msg + "�ܡS");  break;
          case 1: command("tchat �A�T�w" + msg + "�S"); break;
          case 2: command("tchat " + msg + "��A���������Y�S"); break;
          case 3: command("tchat �� ... " + who + "���o�n"); break;
          case 4: command("tchat " + who + "�A�������" + msg + "�o�򦳿���S"); break;
          case 5: command("tchat ������A�{��" + msg + "�S"); break;
          case 6: command("tchat ���Ӹ��D�a"); drool(); break;
          case 7: command("tchat �~��"); break;
          case 8: command("tchat ���@�w�a�S"); break;
          case 9: command("tchat ���o�ӥi�� ...."); break;
          }
      }
      else if( (strsrch(msg, "��") >= 0)) {
          if( sscanf(msg, "%*s��%s", msg) == 2 ) msg = "��" + msg;
          msg = replace_string(msg, "��", "�A");
          msg = replace_string(msg, "?", "");
          switch(random(8)) {
          case 0: command("tchat �A�O��" + msg + "�ܡS"); break;
          case 1: command("tchat �u���S" + msg + "�S"); break;
          case 2: command("tchat �p�G" + msg + "�M�گ����A���򦣶ܡS"); break;
            case 3: command("tchat* hmm"); break;
            case 4: command("tchat �A�{��" + msg + "�S"); break;
  
           case 5: command("tchat �ڦ��P�P"); break;
           case 6: command("tchat �A�����u" + msg + "�v�ڤ���e�P"); break;
           case 7: command("tchat �����u" + msg + "�v�����D�즹����n�ܡS"); break;
          }
       } else {
          switch(random(20)) {
              case 0: command("tchat ������" + msg + "?"); break;
              case 1: command("tchat �u" + msg + "�v�O����N��S"); break;
              case 2: command("tchat " + msg + "�S"); break;
              case 3: command("tchat* grin"); break;
              case 4: command("thcat* smile"); break;
              case 5: command("tchat* ?"); break;
              case 6: command("tchat ...."); break;
              case 7: command("tchat* hmm"); break;
              case 8: command("tchat " + rnd_say[random(sizeof(rnd_say))]); break;
              case 9: command("tchat �A��򪾹D" + msg + "?"); break;
              case 10: command("tchat ���" + who + "���O���F�M" + msg); break;
              case 11: command("tchat �ڷ�M���D�M" + msg); break;
              case 12: command("tchat �M��O�S"); break;

              case 13: command("tchat* �u���ܡS"); break;
              case 14: command("tchat �ڤ��o��{���C"); break;
			default:
				break;
		}
	}
}

void reset()
{
	delete("memory");
}
