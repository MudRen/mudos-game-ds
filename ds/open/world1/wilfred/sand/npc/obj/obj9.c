// �̥D�n�O�� long ���ܤƥH�Υi�H���ƨϥ�   wilfred@DS

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
    set("value",300);
  }
  set("no_put",1);
  setup();

  set("fill_water",5);
}

void init()
{
  add_action("do_drink","drink");
  set("value",0);
}

int do_drink(string str)
{
  object ob = this_object(), me = this_player();
  if(!str || str != "sack") return 0;
  if(me->query("level") > 25) return notify_fail("���Ȧ���U�Ȩѵ��ŤG�Q�����������a�ϥ�\n");
  if(ob->query("fill_water") == 1) return notify_fail("���U�̤v�g�S�����F��I\n");
  if(me->query("hp") >= me->query("max_hp")) return notify_fail("�A���{�ּ֧��}�F�I\n");
  if(me->query("hp") < 5) return notify_fail("�A�˭����U�A�A�]�L�O�ܤ��F�I\n");

  ob->add("fill_water",-1);
  me->add("hp", random(15)+15 );
  me->start_busy(2);
  if( ob->query("fill_water") > 1 )
    message_vision("$N���_���U�ܤF�X�f�C\n",me);
  else message_vision("$N�N���U�̳̫�X�f���ܥ��C\n",me);
  return 1;
}

string long()
{
  int index = this_object()->query("fill_water");
  string msg = this_object()->query("basic_long");

  if(index == 5) return msg + "\n�o���U�O�������C\n";
  if(index > 4)   return msg + "\n�o���U���C�����C\n";
  if(index > 3)   return msg + "\n�o���U���b���C\n";
  if(index > 2)   return msg + "\n�o���U�֨����F�C\n";
  return msg + "\n�o���U�O�Ū��C\n";
}

