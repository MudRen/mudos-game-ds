// entrance.c

#include <login.h>
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "巫師會客室");
	set("long",
		"這裡是巫師和玩家聊天的地方﹐如果你有什麼意見要讓巫師們知道﹐在這裡\n"
	"留言是最快的途徑﹐不過如果是對於遊戲中的問題﹐請您先確定我們提供的說明\n"
	"文件裡沒有說明﹐再提出疑問﹐巫師的主要職責並不是教玩家如何玩。\n"
	"    為了杜絕機器人﹐您可以在這裡檢舉(accuse)某個玩家﹐該名玩家會被抓去\n"
	"做一些小小的測驗﹐目前這項功\能尚未做任何限制﹐請勿利用來騷擾別人。\n");
	set("exits", ([
		"west" : "/d/wiz/hall1",
        "east" : "/open/world2/anfernee/start/bug",
]) );
	set("no_fight", 1);
	set("no_magic", 1);
   set("light",1);

	setup();
	call_other( "/obj/board/query_b", "???" );
}

int valid_leave(object me, string dir)
{
	if( dir=="west" && !wizardp(me) )
		return notify_fail("那裡只有巫師才能進去。\n");
	return ::valid_leave(me, dir);
}

void init()
{
	add_action("do_accuse", "accuse");
}

int do_accuse(string arg)
{
	object ob;
	string s;

	if( (int)this_player()->query("age") < 15 )
		return notify_fail("你年紀太小了﹐沒有檢舉別人的權力。\n");

	if( !arg ) return notify_fail("你要檢舉誰﹖\n");
	if( ob = find_player(arg) ) {
		if( ob==this_player() )
			return notify_fail("你要檢舉自己﹖\n");
		if( ob->is_ghost() )
			return notify_fail( ob->name(1) + "已經死了﹐放他一馬吧。\n");
		if( wizardp(ob) )
			return notify_fail("你不能檢舉巫師。\n");
		if( this_player()->query_temp("accuse")>=1 || this_player()->query("accuse")>10 )
			return notify_fail("你不能一再的檢舉玩家。\n");
		this_player()->set_temp("accuse",1);
		this_player()->add("accuse",1);
		tell_object(ob, HIW + this_player()->name(1) + "檢舉你是個機器人﹐請你接受一個小小的測驗。\n" NOR);
		ROBOT_CHECK->test_me(ob);
		write("Ok. 已經將你檢舉的對象送去做測驗。\n");
		write("為了避免有人用機器人亂檢舉騷擾別人﹐請你也接受相同的測驗。\n");
		ROBOT_CHECK->test_me(this_player());
		log_file("robot_accuse",
			sprintf("%s accused %s on %s.\n", this_player()->query("id"), ob->query("id"), ctime(time())));
		return 1;
	}
	return notify_fail("目前線上並沒有這位玩家。\n");
}

