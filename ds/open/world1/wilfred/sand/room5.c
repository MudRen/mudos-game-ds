#include <ansi.h>
inherit ROOM;
void create()
{
  set ("short", HIC"�p�e��"NOR);
  set ("long", @LONG
�o�̬O�Ӥp�p��w�A�@�l�u���A�Φ��F�@�D�Ȧ⪺�p�˦V�F�y�h
�A�e��}�����X�ʾ�A���ѤF�M�D���Ƚ��A����F�D���ż���Ԥ�_
�ӡA�o�̦��p�M�D�@�ɡA�O�Ӧw�R�Ĺ窺�a��C
LONG
);

  set("exits", ([
  "east" : __DIR__"room6",
  "south" : __DIR__"room4",
]));
  set("objects",([
  __DIR__"npc/npc15" : 2,
]));
  set("item_desc", ([
  "�u��" : "�q�a���۵M��X���u�A�ݨӲM�D�Ѵ��A�]�\\�A�i�H�����U�Ӹˤ�(fill)�C\n",
]));
  set("outdoors", "land");
  setup();
}

void init()
{
  add_action("do_fill","fill");
}

int do_fill()
{
  int i,index = 0;
  object me = this_player();
  object *inv;
  if(me->query("level") > 25) return notify_fail("���u���Ȩѵ��ŤG�Q�����������a�ϥ�\n");
  if(me->is_busy()) return notify_fail("�A���b���I\n");
  if(query("fill") > 500) return notify_fail("�u���N�n���U�F�A�٬O�����^�_�ɦA���a�I\n");
  inv = all_inventory(me);
  if( !( present("traveler sack",me )) ) return notify_fail("�A���W�S���i�H�ˤ����F��C\n");
  for(i=0; i<sizeof(inv); i++)
  {
    if( inv[i]->query("id") == "traveler sack" )
    {
      if(inv[i]->query("fill_water") < 5)
      {
        inv[i]->add("fill_water",1);
        message_vision("$N�Τ��U�ˤF�@�Ǭu���C\n",me);
       add("fill",1);
        index++;
        break;
      }
      else continue;
    }
  }
  if(!index) return notify_fail("�A���W���Ҧ����U�����F�C\n");
  return 1;
}

void reset()
{
  set("fill",0);
  ::reset();
}
