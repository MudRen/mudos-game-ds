// cpdir.c
inherit ITEM;
void create()
{ set_name("CPDIR",({"cpdir"}));
  setup(); }
void init()
{ add_action("cpdir","cpdir"); }
int cpdir(string arg)
{
        string src, dst;//, *dirs;
        mixed *fromfile,*tofile;
        int i,counter;
        object me = this_player();

        seteuid(geteuid(me));
        if (!arg || sscanf(arg, "%s %s", src, dst)!=2 ) return
                notify_fail("指令格式: cpdir <來源目錄路徑> <目的目錄路徑> \n");

        src = resolve_path(me->query("cwd"), src);
        dst = resolve_path(me->query("cwd"), dst);


        if(src == dst) return 1;

        if( file_size(src)==-2 && src[strlen(src)-1] != '/' ) src += "/";
        fromfile = get_dir(src+"*.*", -1);
        if( !sizeof(fromfile) )
           {if (file_size(src) == -2) return notify_fail("來源目錄是空的。\n");
               else
                  return notify_fail("找不到來源目錄。\n");
           }

        if( file_size(dst)==-2 && dst[strlen(dst)-1] != '/' ) dst += "/";
        tofile = get_dir(dst, -1);
        if( !sizeof(tofile) && file_size(dst) != -2)
                  return notify_fail("找不到目的目錄。\n");

        for( i =0; i<sizeof(fromfile);i++)
        {
          if(fromfile[i][0] != "." && fromfile[i][0] != "..")
          {
              printf("cp %s => %s",src+fromfile[i][0],dst+fromfile[i][0]);

              if( cp(src+fromfile[i][0], dst+fromfile[i][0]) )
              {
                   write(" Ok.\n");
                   counter++;
              }
              else
                   write(" 你沒有足夠的讀寫權利。\n");
          }
        }
        printf("共拷貝 %d 個檔案\n",counter);
        return 1;
}

int help(object me)
{
  write(@HELP
指令格式: cpdir <來源目錄路徑> <目的目錄路徑>
範例: cpdir /test/examples /d/test
      cpdir . ..
      cpdir /test/examples 
此指令可讓你(妳)拷貝指定目錄下的所有檔案。
HELP
    );
    return 1;
}


