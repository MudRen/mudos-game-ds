#include <ansi.h>
inherit ROOM;

void can_down(int index);

void create()
{
  set ("short", "��");
  set ("long", @LONG

�g�L�F�����I���A�A�ר�F�F�o�̡A�o�ӥ۫Ǹ���L���j�A�u��
���W��ۼƭӤj�r�G
�@�@�@�@�@�@�@�@�@�@�o�Ѯɪ̡A�ܤ�����
�@�@�@�@�@�@�@�@�@�@�o�a�Q�̡A�ܤ����[
�@�@�@�@�@�@�@�@�@�@�o�H�M�̡A�ܤ����L��

�b�j�r�U��ߵۤ@���۸O�A�W�Y��F�Ǧr�C

LONG
);
  set("exits", ([
  "north" : __DIR__"room66",
]));
  set("no_clean_up", 0);
  set("no_recall",1);
  setup();
}

void can_down(int index)
{
  string temp;
  mapping exits = query("exits");

  if(!index)
  {
    set("exits", ([
  "north" : __DIR__"room66",
]));
    tell_room(this_object(),HIB"\n�ӱ�C�C�����W�F ...... \n\n"NOR);
    return;
  }

  temp = __DIR__"room75";
  if(mapp(exits)) set("exits", (mapping)exits + ([ "down" : temp, ]) );
    else set("exits", ([ "down" : temp, ]));

  tell_room(this_object(),HIW"\n�F���@�n�A��M�X�{�F�@�ө��U���ӱ�I�I\n\n"NOR);
  return;
}

void reset()
{
  can_down(0);
  ::reset();
}
