// drooler.c
//
// This is an example of interactive npc which applied relay_say, relay_emote
// and relay_channel to collect information.
//
// By Annihilator@Celestial.Empire (09/15/95)

#include <ansi.h>

inherit NPC;

string *first_name = ({ "甲","乙","丙","丁","戊","己","庚","辛","壬","癸",
	"臨時","專業" });
string *name_words = ({ "路人","旅客","玩家","瘋子","迷路者","村民","男孩",
	"壯丁","商人" });

string *rnd_id = ({"ra","ma","ta","pu","gu","du","so","po","lo","phi","tri","ne","she"});
string *rnd_id_tail = ({"ng","gh","ss","h","le","d","ck","m","tte"});

string *rnd_say = ({
	"偷偷告訴你，我是這遊戲的主角喔！",
	"最近來了很多其他世界的人ㄚ！",
	"是嗎？不是吧！",
	"你好，我好，大家好。",
	"有空我想到現代或未來看看說。",

});

varargs void drool(string msg, string who);

void create()
{
	string name, id;

	name = first_name[random(sizeof(first_name))];
	name += name_words[random(sizeof(name_words))];

	id = rnd_id[random(sizeof(rnd_id))];
	if( random(10) > 4 ) id += rnd_id[random(sizeof(rnd_id))];
	id += rnd_id_tail[random(sizeof(rnd_id_tail))];

	set_name(name, ({ id, "drooler" }) );
	set("gender", "男性");
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

                                   (: random_move :),
	}) );
	setup();
            carry_object(__DIR__"eq/cloth.c")->wear();
	if( clonep() ) CHANNEL_D->register_relay_channel("chat");
}

int add_phrase(string who, string msg)
{
	msg = replace_string(msg, "?", "");
	msg = replace_string(msg, "？", "");
	msg = replace_string(msg, "﹖", "");
	msg = replace_string(msg, "!", "");
	msg = replace_string(msg, "！", "");
	msg = replace_string(msg, "啊", "");
	msg = replace_string(msg, "嗎", "");
	msg = replace_string(msg, "耶", "");
	msg = replace_string(msg, "吧", "");

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
			command("say 為什麼踢我﹖會痛耶﹗");
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

	if( (strsrch(msg, "為什麼") >= 0) ) {
		if( sscanf(msg, "%*s為什麼%s", msg)==2 ) msg = "為什麼" + msg;
		switch(random(8)) {
		case 0: command("say " + who + "﹐你是在問我嗎﹖"); break;
		case 1: command("say 關於" + msg + " ... "); break;
		case 2: command("say 呃 ... "); drool(); break;
		case 3: command("say 這個問題嘛 ...."); break;
		case 4: command("say " + who + "﹐知道這個問題的答案對你那麼重要嗎﹖"); break;
		case 5: command("say " + msg + "﹖"); break;
		case 6: command("say " + who + "你能不能說清楚一點﹖"); break;
		case 7: command("say " + who + "﹐我不懂你問的問題"); break;
		}
	}
	else if( (strsrch(msg, "你") >= 0)
	||	(strsrch(msg, "妳") >= 0)
	||	(strsrch(msg, "drooler") >= 0)
	||	(strsrch(msg, "Drooler") >= 0)) {
		if( sscanf(msg, "%*s你%s", msg) == 2 ) msg = "你" + msg;
		msg = replace_string(msg, "你", "我");
		msg = replace_string(msg, "妳", "我");
		switch(random(10)) {
		case 0:	command("say " + who + "﹐你是說" + msg + "嗎﹖");	break;
		case 1:	command("say 你確定" + msg + "﹖");	break;
		case 2:	command("say " + msg + "跟你有什麼關係﹖");	break;
		case 3:	command("say 嗯 ... " + who + "說得好"); break;
		case 4:	command("say " + who + "你為什麼對" + msg + "這麼有興趣﹖"); break;
		case 5:	command("say 為什麼你認為" + msg + "﹖"); break;
		case 6:	command("say 換個話題吧"); drool(); break;
		case 7:	command("say 才怪"); break;
		case 8:	command("say 不一定吧﹖"); break;
		case 9:	command("say 有這個可能 ...."); break;
		}
	}
	else if( (strsrch(msg, "我") >= 0)) {
		if( sscanf(msg, "%*s我%s", msg) == 2 ) msg = "我" + msg;
		msg = replace_string(msg, "我", "你");
		msg = replace_string(msg, "?", "");
		switch(random(8)) {
		case 0:	command("say 你是說" + msg + "嗎﹖"); break;
		case 1:	command("say 真的﹖" + msg + "﹖");	break;
		case 2:	command("say 如果" + msg + "﹐我能幫你什麼忙嗎﹖");	break;
		case 3:	command("hmm");	break;
		case 4:	command("say 你認為" + msg + "﹖"); break;
		case 5:	command("say 我有同感"); break;
		case 6:	command("say 你說的「" + msg + "」我不能苟同"); break;
		case 7:	command("say 有關「" + msg + "」的話題到此為止好嗎﹖"); break;
		}
	} else {
		switch(random(20)) {
			case 0: command("say 為什麼說" + msg + "?"); break;
			case 1: command("say 「" + msg + "」是什麼意思﹖"); break;
			case 2: command("say " + msg + "﹖"); break;
			case 3: command("grin"); break;
			case 4: command("smile"); break;
			case 5: command("?"); break;
			case 6: command("say ...."); break;
			case 7: command("hmm"); break;
			case 8: command("say " + rnd_say[random(sizeof(rnd_say))]); break;
			case 9: command("say 你怎麼知道" + msg + "?"); break;
			case 10: command("say 剛剛" + who + "不是說了﹐" + msg); break;
			case 11: command("say 我當然知道﹐" + msg); break;
			case 12: command("say 然後呢﹖"); break;
			case 13: command("say 真的嗎﹖"); break;
			case 14: command("say 我不這麼認為。"); break;
			default:
				break;
		}
	}
}

void reset()
{
	delete("memory");
}
