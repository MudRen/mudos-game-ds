#include <ansi.h>
inherit ITEM;
void create()
{
  set_name(HIC"��������"NOR, ({"test"}));
    set("unit", "��");
    set("long",@LONG
    �ΨӪ����@�ӪF��
LONG);

    set_weight(1);
    set("value",1);
  setup();
}

void init()
{
add_action("do_qusr","qusr");
    }
int do_qusr(string str, string arg)
{
        int i,j=0,n,idle;
        int k;
        int z;
        object where, me;
        object *user_list,user_location;
        object *ob;
        string status1, status2, status3, status4; 
        string msg;
        me = this_player();
        user_list=users();
        n=sizeof(user_list);
     write(sprintf("�ثe"+ MUD_NAME +"�u�W�@�� %d �W���a�A�W��p�U�R\n",n));
        for(i=0;i<n;i++)
        {
                if(user_list[i])
                {
                        ob = users();
                        j++;
                        user_location = environment(user_list[i]);
/*
                        if (!user_location) return notify_fail("�L�b��L���ƶ��C\n");
*/

                        idle=query_idle(user_list[i]);
                if (in_input(user_list[i])) status1=HIC"(��J��r��)"NOR;
                        else status1="";
                if ((in_edit(user_list[i]))) status2=HIY"(�s���ɮפ�)"NOR;
                        else status2="";
                if (idle>180) status3=sprintf(HIR"(�o�b�F %d ����)"NOR,idle/60);
                        else status3="";
                if (idle>3600) status4=sprintf(HIB"(�o�b�F %d �p�� %d ����)"NOR,idle/3600,(idle-3600)/60);
                        else status4="";
                if (!user_location)
{
write(sprintf("%2d %12s %s(%s) ��� %s(?????????)\n",
                        j,
                        SECURITY_D->get_status(user_list[i]),
                        user_list[i]->query("name"),
                        user_list[i]->query("id"),
//                        (string)user_location->query("short"),
                        "�L�b��L���ƶ�" ));
                        if ((status1!="")||(status2!="")||(status3!="")||(status4=""))
write(sprintf("                ���A  : %s%s%s\n",status1,status2,status3,status4));
write(sprintf("                �q %s �Ө즹�B�C\n",query_ip_name(ob[i])));
}
                else
{
write(sprintf("%2d %12s %s(%s) ��� %s(%s)\n",
                        j,
                        SECURITY_D->get_status(user_list[i]),
                        user_list[i]->query("name"),
                        user_list[i]->query("id"),
                        (string)user_location->query("short"),
                        (string)file_name(user_location) ));
                        if ((status1!="")||(status2!="")||(status3!="")||(status4!=""))
write(sprintf("                ���A  : %s%s%s\n",status1,status2,status3,status4));
write(sprintf("                �q %s �Ө즹�B�C\n",query_ip_name(ob[i])));
}
                }
        }
        z = j ;
        return 1;
}


