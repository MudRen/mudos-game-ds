//
// �n�ͫ��O by Wilfred@DS  2000/12/6

#include <ansi.h>

inherit F_CLEAN_UP;

void ft_ob(string str);
void ft_list();
void ft_tune();
void ft_talk(string str);
void ft_clean();
int help(object me);

void create()
{
  seteuid(getuid());
}

int main(object me, string arg)
{
  string str, index;
  if(!arg) arg = "...";
  if(sscanf(arg,"%s %s",index,str) != 2) index = arg;
  switch(index)
  {
    case "-ob"   : ft_ob(str);    break;
    case "-list" : ft_list();     break;
    case "-tune" : ft_tune();     break;
    case "-clean": ft_clean();    break;
	// default      : (str) ? ft_talk(index+" "+str) : ft_talk(index);
	// return 0 ��� channel �ӵo�� by tmr 2007/05/01
    default      : return 0;
  }
  return 1;
}

void ft_ob(string str)
{
  string *ft;
  object ob;

  ft = this_player()->query("friend");
  if( !str )
  {
        help(this_player());
        return;
  }
  if( pointerp(ft) && member_array(str, ft) != -1 )
  {
    ft -= ({ str });
    write(HIC+str+" �v�q�n�ͦW�椤�R��!\n"NOR);
  }
  else
  {
    if( !wizardp(this_player()) && sizeof(ft) > (5 + this_player()->query("level")*2) )

    {
      write("��p, �A�v�]�F�Ӧh�n��, �Х���z�A���n�ͦW��.\n");
      return;
    }
    ob = new(LOGIN_OB);
    ob->set("id", str);
    if( !ob->restore() )
    {
      write("�S���o�Ӫ��a�C\n");
      destruct(ob);
      return;
    }
    destruct(ob);

    if(!ft) ft = ({ str });
      else ft += ({ str });
    write(HIC+str+" �v�[�J�n�ͦW��!\n"NOR);
  }
  this_player()->set("friend", ft);
  this_player()->save();

  return;
}

void ft_list()
{
  string *ft, *t_ft, temp, msg = "";
  int i;
  object ob;

  ft = this_player()->query("friend");

  if(sizeof(ft) < 1) msg = HIR"�A�ثe�|���]�w�n�ͦW��\n"NOR;

  for(i=0 ; i<sizeof(ft) ; i++)
  {
    if( ob = find_player(ft[i]) )
    {
      t_ft = ob->query("friend");
      if( pointerp(t_ft) && member_array(this_player()->query("id"), t_ft) != -1 )
        temp = "* "+ft[i];
      else temp = "? "+ft[i];
      if(wizardp(ob)) temp = ft[i];
    }
    else temp = ft[i];
    msg += sprintf("%-15s%s", temp, ( i % 5 == 4 ) ? "\n" : "");
  }
  msg += "\n";

  write(NOR"�A���n�ͦW�欰: (�P�������b�s�u��, �ݸ��N���H�õL�N�A�]���n��)\n"+
  "--------------------------------------------------------------------------\n"NOR);
  this_player()->start_more(msg);
  (this_player()->query("ft_tune")) ? msg = "����" : msg = "�}��"; 
  write("\n  �A���n�ͤ��}�W�D�O"+msg+"��\n");
  return;
}

void ft_tune()
{
  if(this_player()->query("ft_tune"))
  {
    this_player()->set("ft_tune",0);
    write("�}�Ҧn�ͤ��}�W�D.\n");
  }
  else
  {
    this_player()->set("ft_tune",1);
    write("�����n�ͤ��}�W�D.\n");
  }
  this_player()->save();
  return;
}

/*

void ft_talk(string str)
{
  string *ft, *t_ft;
  object ob;
  int i;

  if(this_player()->query("ft_tune"))
  {
    this_player()->set("ft_tune",0);
    write("�}�Ҧn�ͤ��}�W�D.\n");
  }

  ft = this_player()->query("friend");

  for(i=0 ; i<sizeof(ft) ; i++)
  {
    if( ob = find_player(ft[i]) )
    {
      t_ft = ob->query("friend");
      if( pointerp(t_ft) && member_array(this_player()->query("id"), t_ft) != -1 )
      {
        if(!ob->query("ft_tune"))
          tell_object(ob,HIW"�i�n�͡j"+this_player()->name_id(1)+"�R"+str+"\n"NOR);
      }
    }
  }
  write(HIW"�i�n�͡j"+this_player()->name_id(1)+"�R"+str+"\n"NOR);
  return;
}
*/

void ft_clean()
{
  this_player()->delete("friend");
  write("�n�ͬ����M�����\\. \n");
  return;
}

int help(object me)
{
  write(@HELP
�����O�榡�R
           �W/�R�n��>      ft -ob [id]
           �n�ͦW��>       ft -list
           �n�ͤ��}�W�D>   ft [speaking]
           �}/���n���W�D>  ft -tune
           �M�����>       ft -clean

�A�i�H�Q�γo�ӫ��O�ά����ѼơA��\��ЬݤW�C�C

����:
  A �] B ���n��, �h B ����b A �]�Ťz�Z�����p�U tell A
  A �M B �Ҥ��]���n��, �h A �M B �౵�����Ӧۦn���W�D���T�� 

�A�i�H�]�w 5 + Level*2 �Ӧn�͡C

��L�������O�Rtell, set auto_reply
HELP
);
  return 1;
}

