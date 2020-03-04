#include <ansi.h>
inherit ROOM;
void create()
{
  set ("short", "����");
  set ("long", @LONG

�o�̬O�@�����򳣨S�����p�p�۫ǡA���U�|�g�A�o�Sı�o�|�P��
�۾����Ǥ��۵M....�C

LONG
);
  set("exits", ([
  "up" : __DIR__"room86",
]));

  set("item_desc", ([
"�۾�" : "�|�g�۾��E�ݤ��Uı�o�õL�����A�oı�o���Ʀ۵M�A�{�b\n"+
         "�u���N�N (touch) �ݡA�άO�J�Ӫ��j (search) �L�@���A\n"+
         "�~���i��o�{�ݭ١C\n",
]));
  set("no_recall",1);
  set("no_clean_up", 0);
  setup();
}

void init()
{
  this_player()->delete_temp("no_more_search");
  add_action("do_touch","touch");
  add_action("do_search","search");
}

int do_touch(string str)
{
  tell_object(this_object(),"����Ƴ��S�o��.... \n");
  return 1;
}

int do_search(string str)
{
  object me = this_player();
  if(str != "�۾�") return 0;

        if( me->is_busy() )
                return notify_fail("�A�٦b���L���C\n");
          message_vision(NOR"$N�J�Ӫ��ˬd�۾�......",me);
  if(query_temp("item_get"))
  {
    message_vision("���G���򳣨S�o�{\n",me);
    add_temp("no_more_search",1);
  }
  else
  {
    message_vision("���G$N�b���_���o�{�@��Ȧ⪺�_�͡I�I\n",me);
    new(__DIR__"npc/obj/obj28")->move(environment(me));
    set_temp("item_get",1);
  }
  return 1;
}
// Add By Tmr
// �����w��key ��mark
void reset()
{
        delete_temp("item_get");
        ::reset();
}

