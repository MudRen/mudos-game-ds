inherit ITEM;
void create()
{
  set_name("�Ȧ�c�l",({"silver box","box"}));
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long","�����̭��˵ۤ���O�I���I���}�Ӭݧa�I(open box)");
    set("value",3000);
  }
  setup();
}

void init()
{
  add_action("do_open","open");
}

int do_open(string str)
{
  object me = this_player(), ob = this_object();
  string msg;
  int index, i;

  if(str != "box") return 0;

  message_vision("$N�����Ϋݪ����}�c�l�@�@�s��.....\n",me);
  switch(random(15))
  {
    case 1 : msg = "���@�i����";
             new(__DIR__"obj24")->move(environment(me));
             break;
    case 7 : index = random(50)+1;
             msg = "��"+chinese_number(index)+"�J�|����";
             for(i=0;i<index;i++)
               new("/open/world1/acme/area/npc/obj/soup")->move(environment(me));
             break;
/*
    case 14 : msg = "���@�Ӷ¦����";
              new("/open/always/time-q/black_crystal")->move(environment(me));
              break;
*/
    default : if(random(3)) msg = "���򳣨S��";
                else
                {
                  msg = "�Q�X�@�άr��";
                  me->apply_condition("poison", me->query_condition("poison")+15);
                }
              break;
  }
  message_vision("\n�z.... �c�l�̳��M"+msg+"�A�u�O�ӴΤF�I\n\n",me);
  destruct(ob);
  return 1;
}
