// ask.c

#include <ansi.h>

inherit F_CLEAN_UP;

string *msg_dunno = ({
	"$n搖搖頭﹐說道﹕沒聽說過。\n",
	"$n睜大眼睛望著$N﹐顯然不知道$P在說什麼。\n",
	"$n聳了聳肩﹐很抱歉地說﹕無可奉告。\n",
	"$n說道﹕嗯....這我可不清楚﹐你最好問問別人吧。\n",
	"$n想了一會兒﹐說道﹕對不起﹐你問的事我實在沒有印象。\n"
});

int main(object me, string arg)
{
	string dest, topic, msg;
	object ob;

	seteuid(getuid());

	if( !arg || sscanf(arg, "%s about %s", dest, topic)!=2 )
		return notify_fail("你要問誰什麼事﹖\n");

	if( !objectp(ob = present(dest, environment(me))) )
		return notify_fail("這裡沒有這個人。\n");

	if( !ob->is_character() ) {
		message_vision("$N對著$n自言自語....\n", me, ob);
		return 1;
	}

	if( !ob->query("can_speak") ) {
		message_vision("$N向$n打聽有關『" + topic + "』的消息﹐但是$p顯然聽不懂人話。\n", me, ob);
		return 1;
	}

	if( !INQUIRY_D->parse_inquiry(me, ob, topic) )
		message_vision("$N向$n打聽有關『" + topic + "』的消息。\n", me, ob);

	if( userp(ob) ) return 1;
	if( !living(ob) ) {
		message_vision("但是很顯然的﹐$n現在的狀況沒有辦法給$N任何答覆。\n",
			me, ob);
		return 1;
	}

	if( msg = ob->query("inquiry/" + topic) ) {
		if( stringp(msg) ) {
			message_vision( CYN "$N說道﹕" + msg + "\n" NOR, ob);
			return 1;
		}
	} else
		message_vision(msg_dunno[random(sizeof(msg_dunno))], me, ob);

	return 1;
}

int help(object me)
{
   write( @HELP
指令格式: ask <someone> about <something>

這個指令在解謎時很重要, 通常必須藉由此一指令才能
獲得進一步的資訊。
HELP
   );
   return 1;
}
