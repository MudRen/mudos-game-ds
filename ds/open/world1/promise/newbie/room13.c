#include <ansi.h>
inherit ROOM;

void create()
{
  set("short", "���s��"HIR" �s���y"NOR);
  set("long", @LONG
�i�J���a��A�oı�������A���ƹD�s���¦�ŧ���ӡA���H�P���
���M�A�������ˡA�Q�������}���a�A��~�I�l�s�A�Ů�C
LONG);
  set("exits", ([
  "north" : __DIR__"room12",
 ])); 
    set("item_desc", ([
                "�ɪ�" : HIC"\n\t�@�D�λɰ������A���G�i�H���}(push)���ˤl�H\n\n"NOR,
]));
  set("no_member",1); 
  set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/dragon-king" : 1,
]));
 set("no_recall",1);
    set("no_clean_up",0);
  set("outdoor",0);
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
          if(arg != "�ɪ�")
            return 0;
          else {
            message_vision("$N"HIW"�ΤO���}���ɪ��A�M�᭸�F�X�h�����H�v�I�I\n"NOR,me);
            me->move("/open/world1/tmr/area/hotel");
            return 1;
          }
}

