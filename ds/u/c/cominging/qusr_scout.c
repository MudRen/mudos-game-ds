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
        write(sprintf("�� �ثe" + MUD_NAME + "���u�W�@�� %d �W���a�A�W��p�U�R\n\n",n));
        for(i=0;i<n;i++)
        {
                if(user_list[i])
                {
                        ob = users();

                        j++;
                        user_location = environment(user_list[i]);

                        if (!user_location) return notify_fail("�L�b��L���ƶ��C\n");

                        
                        idle=query_idle(user_list[i]);
                        if (in_input(user_list[i])) status1=HIC"(��J��r��)"NOR;
                                else status1="";
                        if ((in_edit(user_list[i]))) status2=HIY"(�s���ɮפ�)"NOR;
                                else status2="";
                        if (idle>60) status3=sprintf(NOR WHT"["HIW"�o�b %d ����"NOR WHT"]"NOR,idle/60);
                                else status3="";
//                      if (idle>3600) status4=sprintf(HIY"(�o�b�F %d �p�� %d ����)"NOR,idle/3600,(idle-3600)/60);
//                              else status4="";
                        if(user_list[i]->query_temp("invis")) status4=HIB"(���Τ�)"NOR;
                                else status4="";
                        if (!user_location)
                        {
                                write(sprintf("%2d. %-12s��%s(%s) ��� %s("WHT"In Secret Space"NOR")\n",
                        j,
                        SECURITY_D->get_status(user_list[i]),                   
                        user_list[i]->query("name"),
                        user_list[i]->query("id"),
//                      (string)user_location->query("short"),
                        "�i�����άO��BUG�X�{" ));
                                if ((status1!="")||(status2!="")||(status3!="")||(status4!=""))
write(sprintf("         [ %s ] �Ө즹�B�C"HIG"���A"NOR"  : %s%s%s%s\n\n",query_ip_name(ob[i]),status1,status2,status3,status4));
                                else
write(sprintf("         [ %s ] �Ө즹�B�C"HIG"���A"NOR"  : �L�C\n\n",query_ip_name(ob[i])));
                        }
                        else
                        {

                                write(sprintf("%2d. %-12s��%s(%s) ��� %s(%s)\n",
                        j,
                        SECURITY_D->get_status(user_list[i]),
        
                        user_list[i]->query("name"),
                        user_list[i]->query("id"),
                        (string)user_location->query("short"),
                        (string)file_name(user_location) ));
if((status1!="")||(status2!="")||(status3!="")||(status4!=""))
write(sprintf("         [ %s ] �Ө즹�B�C"HIG"���A"NOR"  : %s%s%s%s\n\n",query_ip_name(ob[i]),status1,status2,status3,status4));
else
write(sprintf("         [ %s ] �Ө즹�B�C"HIG"���A"NOR"  : �L�C\n\n",query_ip_name(ob[i])));
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
���O�榡 : qusr
�����O�i���A(�p)�����d�ߥثe�u�W�Ҧ������a(�]�A���a)�B��m�Ϊ��A�C
HELP);
        else return 0;
        return 1;
}

