// Room: /u/s/sub/area/valley/map_1_2.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "����");
	set("long", @LONG

LONG
	);
    set("outdoors", "land");
	set("map_long", 1);
	set("world", "undefine");
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"map_1_3",
  "west" : __DIR__"map_1_1",
  "south" : __DIR__"map_2_2",
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "����" : "�o�O�@�ʥ��j������A�b���[�����U�A�i�H�ݨ�Q����I�k������C
���~�]�i�H�ݥX��F�����]�����ư٭��X�G�ܦ����Ū��C
���G�i�H���F���X�@�Ӭ}(crash)�C
",
]));
	set("current_light", 1);

	setup();
}
void init()
{ 
         add_action("do_crash","crash");
         add_action("do_enter","enter");
}
int do_crash(string arg)
{
          object me;
          me=this_player();
        if(!arg) return notify_fail("�A�n������?\n");
          if(arg != "����")
            return notify_fail("�o�̨S���o�˪F��C\n");
          else {
            message_vision("$N�`�`�l�F�@�f��A�µۯ���ΤO���F�L�h�A���G��F�]���}�F�@�Ӥj�}�C\n\n",me);
            message_vision(HIR"���֪���h���J$N������A�ϱo$N��y�����A�����J�C�C\n"NOR,me);
            set("exits", ([
               "enter" : "/u/s/sub/area/village/tree1",
               "south" : __DIR__"map_2_2",
               "west" : __DIR__"map_1_1",
               "east" : __DIR__"map_1_3",
            ]));
            me->receive_wound("body",10);
            tell_room("/u/s/sub/area/village/tree1",HIG"��F�Q"+me->query("name")+"���X�@�Ӥj�}�C\n"NOR,me);
            return 1;
          }
}
int do_enter()
{
            object me;
            me=this_player();
            set("exits", ([
               "south" : __DIR__"map_2_2",
               "west" : __DIR__"map_1_1",
               "east" : __DIR__"map_1_3",
            ]));
           message_vision(HIG"$N�q�L��֪��}�}��A���쪺�ˤf�S�����_��F�C\n"NOR,me);
            me->move("/u/s/sub/area/village/tree1");
            tell_room(environment(me),HIG+me->query("name")+"�i�ӫ�A��֤S��_�컪�C\n"NOR,me);
            return 1;
}
