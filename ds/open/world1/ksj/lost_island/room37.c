// 2003.4.13 MOBROOM->ROOM  by ksj
#include <ansi.h>
inherit ROOM;

void create()
{
  set("short", "��@�q��"HIW"�d�j�۪L"NOR);
  set("long", @LONG
�o�̬O�@�B���a�A��B���O���j���ƥ۾��A����b���t���۪L
�����A���خ��߷P�A�����D�|������Ǫ��]�X�ӡA�a���O�p�p���ۦ�
�A�L�k���X����Ӫ��A���r�r����o�I��C
LONG);
  set("exits", ([
      "southwest" : __DIR__"room36",
      "northwest" : __DIR__"room40",
     ]));
  set("no_clean_up", 0);
  set("outdoors","forest");
  set("no_auc", 1);
  setup();
}

void reset()
{
  if( this_object()->query_temp("give_armor") )
  {
    set("objects",([
        __DIR__"npc/chimera":2,
       ]));
  }
  else
  {
    set("objects",([
        __DIR__"npc/chimera":2,
        __DIR__"npc/eq/apollo-stele":1,
       ]));
  }
  ::reset();
}
