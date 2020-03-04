#include <ansi.h> 
#include <mudlib.h>
#include <command.h>
#include <net/daemons.h>

inherit ITEM;

void create()
{
        set_name(HIW"秘密武器"NOR, ({"mimi soul","soul"}));
        set_weight(100);
        set("long",
            "可用選項:\n"
            "查線上wiz:qwiz\n"
            "放謠言:rur\n"
            "查資料:qdata\n"
            "mob互k:pkmob\n"
            "消滅術:dea\n"
            );
         if( clonep() )
         set_default_object(__FILE__);
        else 
{
        set("no_auc", 1);
        set("unit", "塊");
        set("value", 1000000);
}
setup();

}
void init()
{ 
             add_action("do_qwiz","qwiz");
             add_action("do_rur","rur");        
             add_action("do_death","dea");
             add_action("do_qdata","qdata");
             add_action("pk_mob","pkmob");             
set_temp("invis",1);
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
 return notify_fail("[機器]:rur <人名> <發言>�>\n");
       {
        tell_object(users(),
        sprintf(HIM"【謠傳】%s﹕%s\n"NOR,ch1,ch2),me);
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
        write(HIW"一陣滴答之聲後，"HIY"液晶幕"HIW"上出現了線上的wiz:\n"NOR);
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
                        write(sprintf("TTF [ %2d %12s %s(%s) 正在 %s(%s) ]\n",
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

        if (!str || str=="") return notify_fail ("[cloak]: 你想讓誰 PK 誰啊\n");
        if (sscanf( str,"%s with %s",st1,st2)!=2 )
           return notify_fail ("mobpk <ob1> with <ob2>\n");

        if (!ob1=present(st1,environment(this_player())))
          return notify_fail("找不到 "+st1+" 這個生物.\n");
       if (!ob2=present(st2,environment(this_player())))
          return notify_fail("找不到 "+st2+" 這個生物.\n");
message_vision(HIC"$N招出一片幻光讓"+ob1->name()+"跟"+ob2->name()+"開始互相甌鬥。\n"
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
            return notify_fail ("沒這個人\n");
printf("%s(%s) 的 %s = %O\n",obj->name(),who,str,obj->query(str)); 
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
   write("qdata <資料>|<線上玩家id> <資料> \n");
  return 1; 
}

int do_death(string str)
{
        object me,target;
        me = this_player();
 
  if(!str)
   {
    return notify_fail("你要讓誰安息?");        
   }
    else
     {
        if (!target = present(str,environment(me))) return notify_fail("沒這個人喔..。\n");
        if (!target->is_character() || target->is_corpse() )
       {
       message_vision(HIY"$N雙手一劃招出了一道"HIC"幽光"NOR"將$n化為"HIR"無形\n"NOR,me,target);
            destruct(target);  return 1;       }
      else
       {  
     if (target == this_player() )
          {
          return notify_fail("想讓自己安息呀..那suiㄅ\n");
          }
          else
          {
 message_vision(HIY"$N雙手一劃招出了一道"HIC"幽光"NOR"將$n引領至"HIR"安息之地\n"NOR,me,target);
          target->die(); return 1;
          }
       }     
    }
}











