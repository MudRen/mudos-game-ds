#include <ansi.h> 
#include <mudlib.h>
#include <command.h>
#include <net/daemons.h>
inherit ITEM;
void create()
{
        set_name("Ų�羹", ({"help item","item"}));
        set_weight(100);
        set("long",
            "��������F�誺����\n" );         
         if( clonep() )
         set_default_object(__FILE__);
        else 
{
        set("no_auc", 1);
        set("unit", "��");
        set("value", 1000000);
}
setup();
}
void init()
{ 
             add_action("do_qwiz","qwiz");       
             add_action("do_dleit","dle");
             add_action("do_sum","sum");   
             add_action("checks_items","cki");
             add_action("do_clean_all","cca");
}
int query_autoload()
{
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
int do_dleit(string str)
{
        object me,target,ob,env,*inv;
        int i;
        me = this_player();
        env=environment(me);
   if(!str) return notify_fail("�A�n���֦w��?");       
    else
     {
        if (!target = present(str,environment(me))) return notify_fail("�S�o�ӤH��..�C\n");
        if (!target->is_character() || target->is_corpse() )
        {
                    destruct(target);  
                    return 1;       
        }
     }     
}

int do_sum(string str)
{
       object me = this_player();
       object target,targetenv;
       target=present(str,environment(this_player()));
       if(!str)  return notify_fail("[����]:sum <id> \n");
       if(!target) target = find_living(str);
       if(!target)  return notify_fail("[����]:�۴��ؼФ��s�b....\n");
       targetenv=environment(target);
       if(target != this_player())
       { 
    
        target->move(environment(me));        
        return 1;
       } 
}
int checks_items(string str)
{
       string msg = ""; 
       if(!str) return notify_fail("[����]:cki <path>..\n");       
        if( sizeof(filter_array( children(str), (: clonep :) )) )
       {
        foreach(object item in filter_array( children(str), (: clonep :) ) )
                        {
                                object room;
                                room = environment(item);
                                if( room->is_room() ) msg += room->query("short")+", ";
                                else if( userp(room) ) msg += room->name()+"(���a), ";
                                else msg += room->name()+", ";
                        }
        }
        else  return notify_fail("[����]:�S���o�ӪF�誺�s�b..\n");        
        write("�j�M���G:�b"+msg+"�o�Ǧa��\n");
        return 1;
} 
void do_clean_all()
{
  object me=this_player(),env=environment(me);
  foreach(object item in all_inventory(env))
  {
     
    if(item->is_corpse() || item->is_character() || item == me)
                  continue;
    else destruct(item);
  } 
}


