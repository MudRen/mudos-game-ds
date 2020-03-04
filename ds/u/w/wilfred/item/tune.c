inherit ITEM;
void create()
{
  set_name("�u�㶰",({"tools"}));
  setup();
}

void init()
{
  add_action("do_add","atune");
}

int do_add(string target)
{
  object me;
  string p,arg;
  string *tuned_ch;

  if( !target )
    return notify_fail("���O�榡: atune �Y�H [�ؼ��W�D]\n");

  if(sscanf(target,"%s %s",p,arg) == 2 )
  {
    me = find_player(p);
    if(!me) return notify_fail("�䤣�즹�H\n");

    tuned_ch = me->query("channels");
    if( pointerp(tuned_ch) && member_array(arg, tuned_ch) != -1 )
    {
      write(me->query("name")+"���� " + arg + " �W�D�C\n");
      tuned_ch -= ({ arg });
      me->set("channels", tuned_ch);
      return 1;
    }
    else
    {
      if(CHANNEL_D->can_tune(arg,me))
      {
        tuned_ch += ({ arg });
        me->set("channels", tuned_ch);
        write(me->query("name")+"�}�� " + arg + " �W�D�C\n");
      }
      else write(me->query("name")+"�L�k�}�ҳo���W�D�C\n");
      return 1;
    }
  }

  me = find_player(target);
  if(!me) return notify_fail("�䤣�즹�H\n");
  tuned_ch = me->query("channels");

  if( !pointerp(tuned_ch) || !sizeof(tuned_ch) )
    write(me->query("name")+"�{�b�èS����ť�����W�D�C\n");
  else
    write(me->query("name")+"�{�b��ť���W�D�R" + implode(tuned_ch, ", ") + "�C\n");
  return 1;
}

