#include <ansi.h>
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
 set("short",HIR"�j�U"NOR);

 set("long",@LONG
�o�̬O�ѱ��M�Ĥ@�����F�䳡��, �q�o�A���n���N�O�ѱ�
�M�Ĥ@�����ħ���, ���_�h�O���U, �q�`�x���H�����]�N�O�b
�����ݫȤH, �ӱq�o�@�˥i�H�ݨ����ڤj�W�l.
LONG
    );
 set("exits",([ "southwest":__DIR__"pill8",
		"north":__DIR__"pill13",
    ]));
 set("item_desc",([
        "�W�l":"�@�ڤj�j���W�l, �A�o�{���G�i�H���W�h....\n"
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();                  
}
void init()
{
        add_action("do_jump","jump");
}

int do_jump(string arg)
{
      object me;
      me=this_player();
      if (arg != "�W�l") return 0;
      message_vision(HIY"$N�̦��, �a���D�W�W�l!\n"NOR  ,me);
      tell_object(me,HIY"�A�ש��D�W�W���F!\n"NOR);
      me->move(__DIR__ "floor1");   
      }
