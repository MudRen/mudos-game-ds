#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("= S C O U T =", ({ "scout" }));
        set("long", " It is just a scout. \n");
        set("no_sac", 1);
        set("value", 1);
        setup();
}

void init()
{
        add_action("do_qusr", "qusr");
}

int do_qusr(string arg)
{
        int i,j=0,n,idle;
        int z;
        object *user_list, user_location;
        object *ob, me = this_player();
        string status1, status2, status3, status4; 

        user_list=users();
        n=sizeof(user_list);
        write(sprintf("□ 目前" + MUD_NAME + "的線上共有 %d 名玩家，名單如下﹕\n\n",n));
        for(i=0;i<n;i++)
        {
                if(user_list[i])
                {
                        ob = users();

                        j++;
                        user_location = environment(user_list[i]);

                        if (!user_location) return notify_fail("他在虛無飄藐間。\n");

                        
                        idle=query_idle(user_list[i]);
                        if (in_input(user_list[i])) status1=HIC"(輸入文字中)"NOR;
                                else status1="";
                        if ((in_edit(user_list[i]))) status2=HIY"(編輯檔案中)"NOR;
                                else status2="";
                        if (idle>60) status3=sprintf(NOR WHT"["HIW"發呆 %d 分鐘"NOR WHT"]"NOR,idle/60);
                                else status3="";
//                      if (idle>3600) status4=sprintf(HIY"(發呆了 %d 小時 %d 分鐘)"NOR,idle/3600,(idle-3600)/60);
//                              else status4="";
                        if(user_list[i]->query_temp("invis")) status4=HIB"(隱形中)"NOR;
                                else status4="";
                        if (!user_location)
                        {
                                write(sprintf("%2d. %-12s◎%s(%s) 位於 %s("WHT"In Secret Space"NOR")\n",
                        j,
                        SECURITY_D->get_status(user_list[i]),                   
                        user_list[i]->query("name"),
                        user_list[i]->query("id"),
//                      (string)user_location->query("short"),
                        "進站中或是有BUG出現" ));
                                if ((status1!="")||(status2!="")||(status3!="")||(status4!=""))
write(sprintf("         [ %s ] 來到此處。"HIG"狀態"NOR"  : %s%s%s%s\n\n",query_ip_name(ob[i]),status1,status2,status3,status4));
                                else
write(sprintf("         [ %s ] 來到此處。"HIG"狀態"NOR"  : 無。\n\n",query_ip_name(ob[i])));
                        }
                        else
                        {

                                write(sprintf("%2d. %-12s◎%s(%s) 位於 %s(%s)\n",
                        j,
                        SECURITY_D->get_status(user_list[i]),
        
                        user_list[i]->query("name"),
                        user_list[i]->query("id"),
                        (string)user_location->query("short"),
                        (string)file_name(user_location) ));
if((status1!="")||(status2!="")||(status3!="")||(status4!=""))
write(sprintf("         [ %s ] 來到此處。"HIG"狀態"NOR"  : %s%s%s%s\n\n",query_ip_name(ob[i]),status1,status2,status3,status4));
else
write(sprintf("         [ %s ] 來到此處。"HIG"狀態"NOR"  : 無。\n\n",query_ip_name(ob[i])));
}
                }
        }
        z = j ;
        return 1;
}
 
int help(string arg)
{
        if( arg == "qusr" )
                write(@HELP
指令格式 : qusr
此指令可讓你(妳)直接查詢目前線上所有的玩家(包括玩家)、位置及狀態。
HELP);
        else return 0;
        return 1;
}

