inherit ROOM;
void create()
{
        set("short", "��s");
        set("long",@LONG
�o�̤w�g���I����s�U�F�A�i�O�U�詥�������~�k�A���A����
���s�U�@������������A�o�̪���췥�����j�A�O���Ӱ����㪺�n
���ơA�ѩ󱵪�s�U�ʪ��]�����ܤ֤F�C
LONG
        );
  
set("exits", ([
  "northup" : __DIR__"mu20", 
]) );
 set("item_desc", ([
  "���" : "�Q����T������A�]�\\�i�H��(chop)�U�ӻs�@�F��C\n",
]));
set("objects",([__DIR__"animal/woodpecker" : 4,]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
}
 
 void init()
{
  add_action("do_chop","chop");
}

int do_chop(string str)
{
  object ob = this_object(), me = this_player();
  object axe;

  if(me->is_busy()) return notify_fail("�A�����ۡA�S�ŧ@��L�ơC\n");
  if(!str) return notify_fail("�A�n�夰��r?\n");
  if(str != "���" || !str) return notify_fail("�A�n�夰��F��?\n");
  if(!axe = present("axe",me)) return notify_fail("�A�ݭn�@����Y�Ӭ�ˤl�C\n");
  if(ob->query("no_chop")) return notify_fail("�o�̪�������G�w�g�Q��L�F�C\n");
  
  message_vision("$N�|�_�⤤�����Y�A�ϫl���µ۰���d�y��h�C\n",me);
  me->start_busy(2);
  ob->set("no_chop",1);
  call_out("loop",4);
  return 1;
}

int loop()
{
  object me = this_player();
  message_vision("�԰աI���Q�A�q���_����I�C\n",me);
  new(__DIR__"../item/wood")->move(environment(me));
  new(__DIR__"../item/wood")->move(environment(me));
  return 1;
}
void reset()
{
  delete("no_chop");
  return ::reset();
}





