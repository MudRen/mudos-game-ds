// �̥D�n�O�� long ���ܤ�   wilfred@DS

inherit ITEM;
void create()
{
  set_name("�Ȧ���U",({"traveler sack","sack"}));
  set_weight(500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("basic_long","�o�O�F�z�Ȧ�̪����ݫ~�A���U�H�����_�s�Ӧ��A�Q���@�ΡC\n�ϥΤ�k: drink sack\n");
    set("value",400);
  }
  setup();

  set("fill_water",10);
}

void init()
{
  add_action("do_drink","drink");
}

int do_drink(string str)
{
  object ob = this_object(), me = this_player();
  if(!str || str != "sack") return 0;
  if(ob->query("fill_water") == 1) return notify_fail("���U�̤v�g�S�����F��I\n");
  if(me->query("hp") >= me->query("max_hp")) return notify_fail("�A���{�ּ֧��}�F�I\n");

  ob->add("fill_water",-1);
  me->add("hp", random(20)+1 );
  if( ob->query("fill_water") > 1 )
    message_vision("$N���_���U�ܤF�X�f�C\n",me);
  else message_vision("$N�N���U�̳̫�X�f���ܥ��C\n",me);
  return 1;
}

string long()
{
  int index = this_object()->query("fill_water");
  string msg = this_object()->query("basic_long");

  if(index == 10) return msg + "\n�o���U�O�������C\n";
  if(index > 7)   return msg + "\n�o���U���C�����C\n";
  if(index > 4)   return msg + "\n�o���U���b���C\n";
  if(index > 1)   return msg + "\n�o���U�֨����F�C\n";
  return msg + "\n�o���U�O�Ū��C\n";
}

