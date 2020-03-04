// signature.c
//

inherit F_DBASE;

void create()
{
        seteuid (getuid());
        set ("name", "ñ�W���O");
        set ("id", "signature");
}

int main(object me, string arg)
{
  string        id, fn;

  if (me != previous_object()) return 0;

  id = me->query("id");
  fn = sprintf ("%ssignature/%s/%s.sig", DATA_DIR, id[0..0], id);
  assure_file (fn);

  if (arg == "none")
  {
    rm (fn);
    write("ñ�W�ɤw�M���C\n");
  }
  else {
   // me->edit( (: this_object(), ({ "do_plan", me}) :) );
   me->edit( (: call_other, __FILE__, "do_plan", me :) );
  }
  return 1;
}

void do_plan(object me, string text)
{
  string fn, id;
  //object link_ob;

  id = me->query("id");
  fn = sprintf ("%ssignature/%s/%s.sig", DATA_DIR, id[0..0], id);

  if (write_file (fn, text, 1 ) == 1)
    write ("ñ�W���x�s�����C\n");
  else
    write ("ñ�W���x�s����.\n");
}

int help(object me)
{
write(@HELP
���O�榡 : signature <none>
���O���� :  �s��ñ�W�ɡAsig none �i�H�M��ñ�W�ɡC

�������O : post , followup �C
HELP
    );
    return 1;
}

