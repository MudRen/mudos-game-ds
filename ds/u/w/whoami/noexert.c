inherit ITEM;
void create()
{
  set_name("�ʩ�",({"noexert"}));
  set_weight(1);
  set("no_sac", 1);
  set("no_get", 1);
  set("no_drop", 1);
  set("no_give", 1);
  setup();
  set_temp("invis",1);
}

void init()
{
        object room = environment(this_object());
        add_action("no_exert","exert");

        if( !room) return;
        if( userp(room) ) return;
        call_out("destruct", 1, this_object());

        return;
}

int no_exert()
{
  write("�A�����g�߮��f��A�@���I�i�~�\\�K�|���ͩR���M�I�E\n");
  return 1;
}

void destruct(object obj)
{
        remove_call_out("gone");
        destruct(obj);
        return;
}

