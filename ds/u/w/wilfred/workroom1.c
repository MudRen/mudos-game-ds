#include <ansi2.h>
#include <room.h>
inherit ROOM;

void create ()
{
  set("short",HIG"������"NOR);
  set("long",
"�o�̬O�@�����R���˪L�A���۷�h���p�ͪ��~��b�o�̡A�A�i�H�յ�\n"
WHT"�I�s(co)"NOR"�L�̡A�˪�j�۵M�A�b�p�����Τl�Ǧ��Ӥp�O�ƪO�A�g�F�Ǧr�C\n"
);
  set("exits",([
  "up" : __DIR__"workroom",
  "down" : "/d/wiz/hall1",
  "west" : "/open/world1/tmr/area/hotel",
]));
  set("light",1);
  setup();
}

void init()
{
  add_action("do_co","co");
}

int do_co(string arg)
{
  object ob,me;
  string file, path;
  path = "/u/w/wilfred/npc";
  me = this_player();

  if(!arg)
  { return notify_fail("�A�Q�s�����ʪ��X�өO :>\n"); }
  else
  {
    file = resolve_path(path,arg);
    file +=".c";
  }

  if(sizeof(file)<=0 || !find_object(file))
  {
    return notify_fail(HIR"�@�I���R�]�S��....\n"NOR);
  }
  else
  {
    ob = new(file);
    ob->move(environment(me));
    message_vision(HIW"�˪L���������M�p�X�F�@��"NOR"$N\n",ob);
    return 1;
  }
}

