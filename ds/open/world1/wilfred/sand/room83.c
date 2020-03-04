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
  if(str != "�۾�") return notify_fail("�A�n�N����H\n");
  say(HIW"��M�@�}�j���ӫG�F�۫� .... "+this_player()->name(1)+"�H�۱j�������b���H���e�C\n");
  this_player()->move(__DIR__"room49");
  write(HIG"�@�}�j������A�A�Ө�F�t�@�Ӧa��C\n"NOR);
  say(HIG+this_player()->name(1)+"��M�q�۫Ǫ����ݱ��F�U�ӡC\n"NOR);
  return 1;
}

int do_search(string str)
{
  object me = this_player();
  if(str != "�۾�") return 0;

  message_vision(NOR"$N�J�Ӫ��ˬd�۾�......",me);
  if(query_temp("item_get"))
  {
    message_vision("���G���򳣨S�o�{\n",me);
   }
  else
  {
    message_vision("���G$N�b���_���o�{�@����⪺�_�͡I�I\n",me);
    new(__DIR__"npc/obj/obj27")->move(environment(me));
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


