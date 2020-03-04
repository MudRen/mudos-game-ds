#include <ansi2.h>
inherit ROOM;
int out_here(object me,object ob);
int out_here1(object me,object ob);

void create()
{
	set("short", "迷霧森林內");
	set("long", @LONG
你走著走著，開始覺得有點累了。你坐在石頭上沉思：一直找不
到路也不是辦法，難道就要這樣空手而回嗎？還是說要使用什麼特殊
的方式才能通過這裡？
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("no_map",1);
	set("no_recall",1);
	set("exits", ([ /* sizeof() == 4 */
  		"east" : __DIR__"wforest3",
  		"west" : __DIR__"wforest2",
  		"south" : __DIR__"wforest1",
  		"north" : __DIR__"wforest4",
	]));
	set("outdoors","forest");

	setup();
}
void init()
{
	call_out("out_here1",1,this_player());
	call_out("out_here",2,this_player());
}
int out_here1(object me,object ob)
{
	string str,str1;
	me=this_player();
	
	if(!me) return 0;
	if(me->query_temp("outhere2") >= 10)
	{
		message_vision(
		HIW"$N似乎發現了出口，朝那邊走了出去。\n"NOR,me);
		me->start_busy(3);
		me->delete_temp("outhere");
		me->delete_temp("outhere1");
		me->delete_temp("outhere2");
		me->delete_temp("outhere3");
		me->move(__DIR__"forestout.c");
		return 1;
	}
	switch(random(6)){
		case 0:{
			str="看見白楊樹在你身邊聳立著，充滿威嚴的樣子。";
			str1="north";
			break;}
		case 1:{
			str="認為路旁蒼老的柏樹是智慧與長壽的象徵。";
			str1="east";
			break;}
		case 2:{
			str="看著楓樹漸漸轉紅的樹葉，讓你的思緒頓時陷入一陣感傷。";
			str1="south";
			break;}
		case 3:{
			str="聞到遠方傳來一陣幽幽的桂花香。";
			str1="west";
			break;}
		default :{
			str="發現沒什麼特別的。";
			str1="";
			break;}
	}
	write("你"+str+"\n");
	me->set_temp("outhere3",str1);
	return 1;
}		
int out_here(object me,object ob)
{
	string dir1,dire;
	me=this_player();
		
	if(!ob=present("elf's tear",me))return 0;
	if(me->query_temp("outhere") >= 10)
	{
		message_vision(
		HIW"$N轉眼被白霧淹沒，失去了蹤影！\n"NOR,me);
		me->delete_temp("outhere");
		me->delete_temp("outhere1");
		me->delete_temp("outhere2");
		me->delete_temp("outhere3");
		me->move(__DIR__"tree");
		return 1;
	}
	else{
	switch(random(4)) {
		case 0:{
			dir1="north";
			dire="北方";
			break;}
		case 1:{
			dir1="east";
			dire="東方";
			break;}
		case 2:{
			dir1="south";
			dire="南方";
			break;}
		case 3:{
			dir1="west";
			dire="西方";
			break;}
	}
	write(
	HIW"你看到妖精之淚\向"+dire+"射出一道光芒。\n"NOR);
	me->set_temp("outhere1",dir1);
	}
	return 1;
}
int valid_leave(object me, string dir)
{
	int col,col1;
	col=me->query_temp("outhere");
	col1=me->query_temp("outhere2");
	
	if(dir==me->query_temp("outhere3"))
	{
		me->set_temp("outhere2",col1+1);
	}
        if(dir==me->query_temp("outhere1")){
        	me->set_temp("outhere",col+1);
        }
        else{
        	me->set_temp("outhere",col-1);
        }
        return 1;
}