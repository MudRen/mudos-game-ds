#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�ϸz�D");

 set("long",@LONG
�o�̬O�ϸz�D������, �A�o�{���@�ӫj�j�i�H���i�h���p�}
�ަb�A�����e, �����ӬO����ͪ����a, �p�G�A�x�l���j, ����
�i�h�ݤ@��....
LONG
    );
 set("exits",([	"northup":__DIR__"ten24",
		"south":__DIR__"ten22",
    ]));
 set("objects", ([__DIR__"npc/bagi_ranger" : 2,
    ]));
 set("item_desc",([
        "�}��":"�@�Ӥp�}, �]\�\\�A\�i\�H\�i\�h\(enter)��\��\.\n"
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
      if (arg != "�}��") return 0;
      message_vision("$N�G���i�J�F�}�ޤ�.\n"  ,me);
      me->move(__DIR__ "ten33");   
      }