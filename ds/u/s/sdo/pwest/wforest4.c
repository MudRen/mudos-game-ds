#include <ansi2.h>
inherit ROOM;
int out_here(object me,object ob);
int out_here1(object me,object ob);

void create()
{
	set("short", "�g���˪L��");
	set("long", @LONG
�y�@���A�P�@�B¶��骺�Pı��b���O�ܦn�I�z�A�o��i�D�ۤv
�A���O�]�S����k�A�]���L�׫�򨫳��O�b�J�f����¶�A���ǨS����
��H����q�L�g���˪L�C
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("no_map",1);
	set("no_recall",1);
	set("exits", ([ /* sizeof() == 4 */
  		"east" : __DIR__"wforest3",
  		"west" : __DIR__"wforest2",
  		"south" : __DIR__"wforest5",
  		"north" : __DIR__"wforest1",
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
		HIW"$N���G�o�{�F�X�f�A�¨��䨫�F�X�h�C\n"NOR,me);
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
			str="�ݨ��շ���b�A�����q�ߵۡA�R�����Y���ˤl�C";
			str1="north";
			break;}
		case 1:{
			str="�{�����ǻa�Ѫ��f��O���z�P���ت��H�x�C";
			str1="east";
			break;}
		case 2:{
			str="�ݵ۷��𺥺�������𸭡A���A������y�ɳ��J�@�}�P�ˡC";
			str1="south";
			break;}
		case 3:{
			str="�D�컷��ǨӤ@�}�իժ��۪᭻�C";
			str1="west";
			break;}
		default :{
			str="�o�{�S����S�O���C";
			str1="";
			break;}
	}
	write("�A"+str+"\n");
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
		HIW"$N�಴�Q�����T�S�A���h�F�ܼv�I\n"NOR,me);
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
			dire="�_��";
			break;}
		case 1:{
			dir1="east";
			dire="�F��";
			break;}
		case 2:{
			dir1="south";
			dire="�n��";
			break;}
		case 3:{
			dir1="west";
			dire="���";
			break;}
	}
	write(
	HIW"�A�ݨ짯�뤧�\\�V"+dire+"�g�X�@�D���~�C\n"NOR);
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