// signature.c
//

inherit F_DBASE;

void create()
{
        seteuid (getuid());
        set ("name", "簽名指令");
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
    write("簽名檔已清除。\n");
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
    write ("簽名檔儲存完畢。\n");
  else
    write ("簽名檔儲存失敗.\n");
}

int help(object me)
{
write(@HELP
指令格式 : signature <none>
指令說明 :  編輯簽名檔，sig none 可以清除簽名檔。

相關指令 : post , followup 。
HELP
    );
    return 1;
}

