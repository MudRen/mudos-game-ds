#include <ansi.h>
inherit ROOM;
void create()
{
  set ("short", HIG"�˶�"NOR);
  set ("long", @LONG
�o�̺ص۳\�h�C�ˡA�a�A�l�ޡA��M�O���H�S�N�[�H�Ӯƪ��A��
�l���G���K���P�A�L���j�ӡA�˸��F�F�@�T�A�Ϧp�@�~�緽�C
LONG
);

  set("exits", ([
  "west" : __DIR__"room5",
  "north" : __DIR__"room7",
]));

  set("item_desc", ([
  "�C��" : "�o�̪��F�\\�h�C�ˡA�]�\\�i�H��(cut)�U�ӻs�@�F��C\n",
]));
  set("outdoors", "land");
  set("no_clean_up", 0);
  setup();
}

void init()
{
  add_action("do_cut","cut");
}

int do_cut(string str)
{
  object ob = this_object(), me = this_player();
  object axe;

  if(me->is_busy()) return notify_fail("�A�����ۡA�S�ŧ@��L�ơC\n");
  if(!str) return notify_fail("�A�n�夰��r?\n");
  if(str != "�C��" && str != "�ˤl") return notify_fail("�o�̨S��" +str+ "�C\n");
  if(!axe = present("axe",me)) return notify_fail("�A�ݭn�@����Y�Ӭ�ˤl�C\n");
  if(ob->query("no_cut")) return notify_fail("�A�ݨ�ˤl�ֳQ����F�A�n�F�n�Y�A�߷Q�٬O���n�}�a�p�������n�F�C\n");
  
  message_vision("$N�|�_�⤤�����Y�A�ϫl���µۦˤl�d�y��h�C\n",me);
  me->start_busy(2);
  ob->set("no_cut",1);
  call_out("loop",4);
  return 1;
}

int loop()
{
  object me = this_player();
  message_vision("�԰աI�ˤl�q���_������C\n",me);
  message_vision("$N�N�ˤl�d�K�h���A�@���F�@����^���C\n",me);
  new(__DIR__"npc/wp/wp8")->move(environment(me));
  return 1;
}

void reset()
{
  delete("no_cut");
  return ::reset();
}
