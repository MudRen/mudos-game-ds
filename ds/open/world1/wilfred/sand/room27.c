#include <ansi.h>
inherit MOBROOM;
void create()
{
  set ("short", YEL"���F����"NOR);
  set ("long", @LONG
�A�o�{�A�v�������h��V�P�F�A���ޫ�򨫳��n���b�P�@�a�襴
��A�V�|�P��h�A�Ҩ��̶ȯE�E���F�A���T�O�H�߫�A�n�O�A�����X
�o�F�z�A�i��n�G���b�o�̤F�A�t�~ť�ǻD��F�ߤW�o�̱N�r�D�r�~
�ɥX�A�O�H�D�����ܡC
LONG
);

  set("exits", ([
  "east" : __DIR__"room27",
  "west" : __DIR__"room28",
  "north" : __DIR__"room26",
  "south" : __DIR__"room26",
]));
  set("objects",([
  __DIR__"npc/npc34" : 1,
  __DIR__"npc/obj/obj18" : 1,
])); 
        set("item_desc", ([
                "�j�|" : "�@�Ӷ¶ª��}�A�i�H�i�h(enter)�C\n",
                ]));
  set("chance",40);
  set("mob_amount",4);
  set("mob_object",({
  __DIR__"npc/npc1",
  __DIR__"npc/npc2",
  __DIR__"npc/npc7",
  __DIR__"npc/npc8",
}) );

  set("no_map",1);
  set("outdoors", "land");
  set("no_clean_up", 0);
  set("valid_startroom", 1);
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
          if(arg != "�j�|")
            return 0;
          else {
            message_vision("$N���j�|�����F�i�h�C\n",me);
            me->move("/open/world1/jangshow/flame_area/dig-room");
            return 1;
          }
}

