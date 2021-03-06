#include <ansi.h>

inherit NPC;

string *color = ({ HIM, HIW, RED, GRN, YEL, BLU, MAG, CYN,WHT, HIW });

void speak_message(object me, string arg, int flag,string *songs,int);
void speak_end(int flag);

void create()
{
	set_name("老舊的機器人", ({ "dirty robot","robot" }) );
	set("long","一個老舊的機器人，他正站在舞台上演奏著，你也可以點幾首歌來聽(listen)。\n");
	set("level", 23);
	set("age", 20+random(10));
	set("race","機器人");
	setup();
}

void init()
{
	add_action("do_listen","listen");
}

string query_color()
{
	return color[random(sizeof(color))];
}

void speak_end(object me)
{
	CHANNEL_D->do_channel(this_object(),"music","謝謝您的欣賞, 謝謝.");
	this_object()->delete_temp("busy");
	this_object()->delete("no_fight");
}

void speak_message(object me, string arg, int flag,string *songs,int test)
{
	object *user = users();
	if( flag > sizeof(songs) -1 )
	{
		call_out("speak_end", 0,me);
		return;
	}
	if( test==1 )
		CHANNEL_D->do_channel(me,"music",me->name(1)+"點撥了一首歌.....");
	CHANNEL_D->do_channel(this_object(),"music",query_color()+songs[flag]+NOR);
	call_out("speak_message", 4+random(3) , me, arg, flag + 1,songs,2);
}

int do_listen(string arg)
{
	string *songs, file_w,n_s,*a;
	int c;
	object me;

	me = this_player();

	if( query_temp("busy") )
		return notify_fail(" 有人在點了喔 ! \n");
	if( me->query_temp("have_singing" ) )
		return notify_fail(" 你已經點過了了喔！\n");
    if( this_player()->is_fighting() || this_object()->is_fighting() )
        return notify_fail("現在不方便點歌吧！\n");
	if( !arg || sscanf(arg,"no.%d",c)!=1 )
		return notify_fail("你想要點那首歌曲呢？(listen no.<第幾個>)\n");
	if( !read_file(__DIR__"song_info/song_info.s") ) return notify_fail("載入檔案失敗!!\n");
	
	a = explode(read_file(__DIR__"song_info/song_info.s"),":");
	if( c > sizeof(a) ) return notify_fail("沒這首吧？\n");
	
	n_s = a[c];

	write(HIR"點撥歌曲：第 "+c+" 首。\n"NOR);

	if( !read_file(n_s)
	||	!arrayp(songs = explode(read_file(n_s) , "(n)")))
		return notify_fail(HIR"載入失敗！！\n"NOR);

	me->set_temp("have_singing",1);
	this_object()->set_temp("busy",1);
	this_object()->set("no_fight",1);
	call_out("speak_message", 1, me, arg,0,songs,1);
	return 1;
}
