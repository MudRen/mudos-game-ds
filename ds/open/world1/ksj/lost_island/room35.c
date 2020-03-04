#include <ansi.h>
inherit ROOM;

void create()
{
  set("short", "��@�q��"HIW"�d�j�۪L"NOR);
  set("long", @LONG
�o�̬O�@�B���a�A��B���O���j���ƥ۾��A�A��誺�۪L�Φ�
�@���ѵM������A�A�^�Y�@��۪L�����ݡA�H�o�ذ��׬ݼˤl�L�k��
�W�h�F�A�Y���������\�γ\�i�H�D�W(jump up)�C
LONG
);
  set("exits", ([ /* sizeof() == 4 */
      "northeast" : __DIR__"room36",
      "northwest" : __DIR__"room38",
     ]));
  set("no_clean_up", 0);
  set("outdoors","forest");
  set("no_auc", 1);
  setup();
}

void init()
{
  add_action("do_jump","jump");
}

int do_jump(string arg)
{
  object me=this_player();        
  if(arg!="up") 
    return notify_fail("�A�Q�n��(jump)����H");
  if(me->is_busy() )
    return notify_fail("�A�����ۡA�L�k�M�����I���ʧ@�C\n");
  if(me->query_skill("dodge",2) <90)
    return notify_fail("�A����O�����H���W�۪L�C\n" );
  if(!me->move(__DIR__"room32") )
    return notify_fail("�A�L�k���W�۪L�C\n");
  tell_room(me,HIW"$N����@�D�ӤW�A�����s�I��K�A�X���ɤO�ᦨ�\\�D�W�۪L�C\n"NOR,me);
  return 1;
}
