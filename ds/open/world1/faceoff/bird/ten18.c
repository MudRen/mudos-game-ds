#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","����");

 set("long",@LONG
�o�̤w�g�O���𪺺��Y�F, �b�A�����e�O�@�Ƿ���~�k���s
��, �p�G�A�۫H�A�����\����, �i�H�ոլݭ�ò�������\��, ��
�L�N�⻴�\���n, �A�]�o�{���𨤦��@�Ӥp�}, �A�]�i�H���i�h.
LONG
    );
 set("exits",([	"south":__DIR__"ten17",
    ]));
 set("item_desc",([
        "�s��":"�A�o�{�A�����p���~,�N�⻴\�\\�A\���]����L���h!\n",
	"�p�}":"�@�Ӥ����D������s�b���},�A�i�H��(enter)�i�h....\n",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();                    
}

void init()
{
        add_action("do_enter","enter");
}

int do_enter(string arg)
{
      object me;
      me=this_player();
      if (arg != "�p�}") return 0;
      message_vision("$N�q�𨤪��p�}�p�F�i�h....\n"  ,me);
      me->move( __DIR__"ten19");   
      return 1;
      }
