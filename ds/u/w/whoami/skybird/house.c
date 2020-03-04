#include <ansi.h>
#include <room.h>
inherit ROOM;
inherit DOOR;
void create()
{
 set("short","���Ī̤p��");

 set("long",@LONG 
�A�m����o�ɤ@�L�Ҧ����p�Τ���, �o�{�]���h�~�S���ѱ�
���Ī̫e��, �ҥH�o�ɤp�ΰ��F�@�ǯ}�ª��ľS�Τ@��諸����
�H�~, �N�u�ѤU�@�u�p�p���γU�F....�o�̪��}�ªG�M�O�����i
����..........
LONG
    );
 set("exits",([
     "out":__DIR__"tree7",
     ]));
 set("no_clean_up",0);
 set("light",1);
 set("item_desc",([
    "�γU" : "�@�u���s�٨S�H�ιL���γU�A�ݨӮ���(take)�]�S�H�|���D�E\n", 
    "�ľS" : "�@�ӥΨӫ����ħ����u��E\n",                 ]));   
 set_temp("tent",1);
 setup();
 create_door("out","�}�ꪺ���","enter",DOOR_CLOSED,"nokey");
}

void init()
{
        add_action("do_take","take");
}

int do_take(string arg)
{
        object me,tent;

        me=this_player();
        if(arg != "�γU") return notify_fail("�A�n������??\n");
        if( this_object()->query_temp("tent") ){
        message_vision("$N���ݥk�p���A���������������@�ӺγU�E\n",me);
        tent=new("/open/world1/wilfred/sand/npc/obj/obj11");
        tent->move(me);
        this_object()->add_temp("tent",-1); 
        call_out("rb", 300, this_object());        } else {
        tell_object(me,"�ݨӤw�g���H�������n�F��I\n");       
        }
        return 1;       
}

void rb()
{
       this_object()->set_temp("tent",1);       
       return;
}

