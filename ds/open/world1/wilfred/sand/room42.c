#include <ansi.h>
inherit ROOM;
void create()
{
  set ("short", HIW"�Y�s�I�y"NOR);
  set ("long", @LONG
�ʷʦ����A½�B�˴�E�_�����զ����A�o�̫K�O�G�~���A�H
���µ¡A���±����n�A���ر�h�A��������@�y�s�A���W��j�����j
�A�L�k�a��ݲM�C
LONG
);

  set("exits", ([
  "east" : __DIR__"room41",
  "south" : __DIR__"room94",
]));

  set("item_desc", ([
  "�s" : "�A���O�Q�ݲM���誺�s�A���W��Z���L���A�L�k�ݱo�u���C�a�g���A�����ݨ즳�ؿv���A�ݨӥu���Q��k�L�e�~��@���s���C\n",
]));
          set("objects", ([ /* sizeof() == 1 */
            ]));

  set("outdoors", "land");
  set("no_clean_up", 0);
  setup();
}

void init()
{
  write(HIW"�n��K�O�ʷʦ����F�A�u������½�B�˴�E�_�����զ����A�n�կE�j�C\n"NOR);
}

int valid_leave(object me, string dir)
{
  object horse, boots;
  horse = present("fierce-wind horse",me);
  boots = present("water boots",me);

  if(environment(me) && dir == "south")
  {
    if(horse)
    if(objectp(horse = me->query_temp("ride")) )
    {
      message_vision("$N��U��$n�@�n���R�A�H�Y�ĤO���¹賓���F�L�h�C\n",me,horse);
      me->move(__DIR__"room46");
      return notify_fail("");
    }
    if(boots)
    if( stringp(boots->query("equipped")) )
    {
      message_vision("$N�}�����c�A��í���b�����W����ӥh�C\n",me);
      me->move(__DIR__"room46");
      return notify_fail("");
    }
    message_vision("$N�����S�ݪ��K�a�����J�F����.....\n",me);
    remove_call_out("check_sk");
    call_out("check_sk",2,me);
    return notify_fail("");
  }
  return ::valid_leave(me,dir);
}

int check_sk(object me)
{
  int index = me->query_skill("swim");
  me->move(__DIR__"room94");
  if( index > 20 )
  {
    message_vision(HIC"$N�ϥX�F�W�����a�ޡA���p���s�멹�賓�C�F�L�h�C\n"NOR,me);
    me->move(__DIR__"room46");
  }
  else
  {
    if( random(index) > 14 )
    {
      message_vision("�u��$N�W�i�W�i���C�V�賓�A����æE�A�٦Y�F�X�f���C\n",me);
      me->move(__DIR__"room46");
      message_vision("$N�T�V�����W���ӡA�^�Y��۷ʷʦ����A�ߦ��l���C\n",me);
    }
    else
    {
      message("world:world1:vision","\t"+ me->name(1)+ "�Y�G���j�s�G �ϩR���I�ϩR���I...�B�P�B�P...\n",users());
      me->start_busy(2);
      call_out("trouble",1,10);
    }
  }
  return 1;
}

int trouble(int index)
{
  object me = this_player();
  me->start_busy(2);
  if(!index)
  {
    me->move(__DIR__"room42");
    message_vision(HIW"$N�ש�S�Q�R�^�F���W....\n"NOR,me);
    return 1;
  }
  switch(random(3))
  {
    case 0 : message_vision("$N�b�W�ä��S�Y�F�X�f��....\n",me);
             break;
    case 1 : message_vision("$N�b�������B���I���A�۷�T�V....\n",me);
             break;
    case 2 : message_vision("$N������ç�A�o�줣�줰��....\n",me);
             break;
  }
  call_out("trouble",1,--index);
  return 1;
}

