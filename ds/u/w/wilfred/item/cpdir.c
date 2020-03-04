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
                notify_fail("���O�榡: cpdir <�ӷ��ؿ����|> <�ت��ؿ����|> \n");

        src = resolve_path(me->query("cwd"), src);
        dst = resolve_path(me->query("cwd"), dst);


        if(src == dst) return 1;

        if( file_size(src)==-2 && src[strlen(src)-1] != '/' ) src += "/";
        fromfile = get_dir(src+"*.*", -1);
        if( !sizeof(fromfile) )
           {if (file_size(src) == -2) return notify_fail("�ӷ��ؿ��O�Ū��C\n");
               else
                  return notify_fail("�䤣��ӷ��ؿ��C\n");
           }

        if( file_size(dst)==-2 && dst[strlen(dst)-1] != '/' ) dst += "/";
        tofile = get_dir(dst, -1);
        if( !sizeof(tofile) && file_size(dst) != -2)
                  return notify_fail("�䤣��ت��ؿ��C\n");

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
                   write(" �A�S��������Ū�g�v�Q�C\n");
          }
        }
        printf("�@���� %d ���ɮ�\n",counter);
        return 1;
}

int help(object me)
{
  write(@HELP
���O�榡: cpdir <�ӷ��ؿ����|> <�ت��ؿ����|>
�d��: cpdir /test/examples /d/test
      cpdir . ..
      cpdir /test/examples 
�����O�i���A(�p)�������w�ؿ��U���Ҧ��ɮסC
HELP
    );
    return 1;
}


