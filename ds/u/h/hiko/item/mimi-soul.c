#include <ansi.h> 
#include <mudlib.h>
#include <command.h>
#include <net/daemons.h>

inherit ITEM;

void create()
{
        set_name(HIW"���K�Z��"NOR, ({"mimi soul","soul"}));
        set_weight(100);
if( clonep() )
         set_default_object(__FILE__);
        else 
{

        set("no_sell", 1);
        set("no_drop", 1);
        set("no_put", 1);
        set("no_get", 1);
        set("no_auc", 1);
        set("unit", "��");
        set("value", 1000000);
}
setup();

}
void init()
{
             add_action("do_sum","sum"); 
             add_action("do_qwiz","qwiz");
             add_action("do_rur","rur");        
             add_action("do_death","dea");
             add_action("do_qdata","qdata");
             add_action("pk_mob","pkmob");
             add_action("do_snop","snoop");
             
}
int do_sum(string str)
{
       object me = this_player();
       object target,targetenv;
       target=present(str,environment(this_player()));
       if(!target) target = find_living(str);
       if(!target)
      {
       write(HIC+"�j������M�ݲM���ؼЦA�۳�T\n"+NOR);
       return 1;
      }
       targetenv=environment(target);
       if(target != this_player())
     { 
    
        target->move(environment(me));        
        return 1;
      }
}
int query_autoload()
{
      return 1;
}
int do_rur(string arg)
{ 
        object me = this_player();
        string ch1,ch2;        
 if(!arg||sscanf(arg, "%s %s",ch1,ch2)!=2)
 return notify_fail("[����]:rur <�H�W> <�o��>�>\n");
       {
        tell_object(users(),
        sprintf(HIM"�i���ǡj%s�R%s\n"NOR,ch1,ch2),me);
        }
    return 1;
}


int do_qwiz(string arg)
{
        int i,j=0,n,idle;
        object *user_list,where;
        string status1, status2, status3;

        user_list = users();
        n = sizeof(user_list);
        write(HIW"�@�}�w�����n��A"HIY"�G����"HIW"�W�X�{�F�u�W��wiz:\n"NOR);
        for( i=0 ;i<n ;i++)
        {
                if( wizardp(user_list[i])&&user_list[i]->query("id")!="hzx")
                {
                        where = environment(user_list[i]);
                        idle=query_idle(user_list[i]);
                        if (in_input(user_list[i])) status1=HIY"(INPUT)"NOR;
                                else status1="";
                        if ((in_edit(user_list[i])))
                         status2=sprintf(HIY"(EDIT: %s)"NOR,in_edit(user_list[i]));
                                else status2="";
                        if (idle>180) status3=sprintf(HIY"(IDLE %d MIN)"NOR,idle/60);
                                else status3="";
                        write(sprintf("TTF [ %2d %12s %s(%s) ���b %s(%s) ]\n",
                        j,
                        SECURITY_D->get_status(user_list[i]),
                        user_list[i]->query("name"),
                        user_list[i]->query("id"),
                        (string)where->query("short"),
                        (string)file_name(where)));
                        if ((status1!="")||(status2!="")||(status3!=""))
                        write(sprintf("TTF [                STATUS: %s%s%s]\n",
                                      status1,status2,status3));
                        j++;
                }
        }
        return 1;
}


int pk_mob(string str)
{
        object ob1,ob2;
        string st1,st2;

        if (!str || str=="") return notify_fail ("[cloak]: �A�Q���� PK �ְ�\n");
        if (sscanf( str,"%s with %s",st1,st2)!=2 )
           return notify_fail ("mobpk <ob1> with <ob2>\n");

        if (!ob1=present(st1,environment(this_player())))
          return notify_fail("�䤣�� "+st1+" �o�ӥͪ�.\n");
       if (!ob2=present(st2,environment(this_player())))
          return notify_fail("�䤣�� "+st2+" �o�ӥͪ�.\n");
message_vision(HIC"$N�ۥX�@���ۥ���"+ob1->name()+"��"+ob2->name()+"�}�l���ۿ^���C\n"
,this_player());
        ob1->kill_ob(ob2);
        return 1;
}

int do_qdata(string arg)
{   string who,str;
    int j,i;
    object *list,obj;
    mixed data;
    list = users();
    i=1;
    if(arg)
      { 
       if(sscanf(arg,"%s %s",who,str)==2)
       { if(!(obj=find_player(who)) )
          if(!(obj=find_living(who)) )
            if (!(obj = present(who, environment(this_player())) ))
            return notify_fail ("�S�o�ӤH\n");
printf("%s(%s) �� %s = %O\n",obj->name(),who,str,obj->query(str)); 
       }
       else
       {
        j = sizeof(list);
        while( j-- ) 
         {
          if( !environment(list[j]) ) continue;
          if( wizardp(list[j])) continue;
             printf("%8s%8s : ",list[j]->name(),"("+list[j]->query("id")+")"); 
             data=list[j]->query(arg);            
             printf("%O  ",data);
             i=i+1;
             if(i==4)
              {printf("\n");
                i=1;
              }                                         
         } 
       }           
    }
   else 
   write("qdata <���>|<�u�W���aid> <���> \n");
  return 1; 
}

int do_death(string str)
{
        object me,target;
        me = this_player();
 
  if(!str)
   {
    return notify_fail("�A�n���֦w��?");        
   }
    else
     {
        if (!target = present(str,environment(me))) return notify_fail("�S�o�ӤH��..�C\n");
        if (!target->is_character() || target->is_corpse() )
       {
       message_vision(HIY"$N����@���ۥX�F�@�D"HIC"�ե�"NOR"�N$n�Ƭ�"HIR"�L��\n"NOR,me,target);
            destruct(target);  return 1;       }
      else
       {  
     if (target == this_player() )
          {
          return notify_fail("�Q���ۤv�w���r..��sui�t\n");
          }
          else
          {
 message_vision(HIY"$N����@���ۥX�F�@�D"HIC"�ե�"NOR"�N$n�޻��"HIR"�w�����a\n"NOR,me,target);
          target->die(); return 1;
          }
       }     
    }
}

int do_snop(string arg)
{
        object ob,me;
        me=this_player();

        if( !arg ) {
                if( objectp(ob = query_snooping(me)) )
                        write("�A�{�b���b��ť" + ob->query("name") + "�Ҧ��쪺�T���C\n");
                return 1;
        } else if( arg=="none" ) {
                if( objectp(ob = query_snooping(me)))
                snoop(me);
                write("Ok.\n");
                return 1;
        }

        ob = find_player(arg);
        if(!ob) ob = find_living(arg);
        if(!ob || !me->visible(ob)) return notify_fail("�S���o�ӤH�C\n");
        if( me==ob ) return notify_fail("�Х� snoop none �Ѱ���ť�C\n");
                
        snoop(me, ob);
        write("�A�{�b�}�l��ť" + ob->name(1) + "�Ҧ��쪺�T���C\n");
        if( userp(ob) && me->query("id")!="ghoster") log_file("SNOOP_PLAYER",
                sprintf("%s(%s) snoops %s on %s.\n", me->name(1), geteuid(me), ob->name(1),
                        ctime(time()) ) );
}

int help()
{
        write(@TEXT
���O�榡�Rsnoop <�Y�H>|none

��ť��L�ϥΪ̩Ҧ�ť���T���Msnoop none �h������ť�C
TEXT
 );
 return 1;
}





