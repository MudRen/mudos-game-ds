// Room: /u/t/truewind/Minetown/area/machinefield5.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�}�B�����׼t");
	set("long", @LONG
�o�̬O�U���}�B�����ת��u�t�A�񲴱�h�A�U���U�˪��}�B����
����s�@�˰��A�X�G�n�B���F�A�����u�C�o�����F�ܦh�j�c�l�٦�
�Y�Ѫ��U���A�@�ѿ@�@������q���Ǫ��j�c�l���U�ǥX�ӡA�A���T�h
�óo�̪��޲z���쩳���S���b���Ʊ�??
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 0);
        set("item_desc", ([ /* sizeof() == 1 */
  "�j�c�l" : "�o�̦��@�j��äC�K�V���c�l�A�䤤���X�Ӧn���i�H����(push)�C
",
]));

	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"machinefield4",
  "south" : __DIR__"machinefield6",
  "east" : __DIR__"machinefield2",
  "down" : __DIR__"pool01",
]));
  set("no_clean_up", 0);
  setup();
}

void init()
{
  add_action("do_push","push");
}

int do_push(string arg)
{
          object me;
          me=this_player();
          if(arg != "�j�c�l")
            return 0;
          else {
            message_vision("$N�����k������j�c�l�@�Ӥ@�ӱ���@��h...�C\n\n",me);
            message_vision("$N�b�U���襤�o�{�F�@�ӦV�U���a�D�J�f�C\n",me);
            set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"machinefield4",
  "south" : __DIR__"machinefield6",
  "east" : __DIR__"machinefield2",
  "down" : __DIR__"pool01",
]));
            return 1;
          }
}

void reset()
{
        set("exits", ([
        "north" : __DIR__"machinefield4",
        "south" : __DIR__"machinefield6",
        "east" : __DIR__"machinefield2",
        ]));
        ::reset();
}
