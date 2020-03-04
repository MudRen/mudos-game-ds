/* �벼�c write by whatup 2003/06/26 */
//rewrite by promise@DS
#include <ansi.h>

inherit F_SAVE;
inherit ITEM;

private void enter_vote(string arg,int num,int);
string query_short();
int open_vote(string);
void create()
{
        set_name(HIC"���������~�Ң�Ĥ@���벼����"NOR,({ "vote machine","vote","machine"}));
        set("no_get",1);
        set("no_sac",1);
        set("value",10000000000);
        
        restore();
        set("short",(:query_short:));
}
void init()
{
        if(wiz_level(this_player())>0 )
        {
                add_action("add_vote","add_vote");
                add_action("reset_vote","reset_vote");  
                add_action("open_vote","open_vote");
        }

        if(query("mode")==2 ) return ;
        if(query("vote_data/stop_time") && query("vote_data/stop_time")<time())
        {
                open_vote("");
                return ;
        }
        add_action("vote","vote");
}
int save()
{
        if(!clonep()) ::save();
}
string query_save_file()
{
        return DATA_DIR"votebox";
}
int reset_vote()
{
        delete("vote_data");
        delete("vote_user");
        delete("vote");
        delete("mode");
        write("���m�����I\n");
        save();
        return 1;
}
// �s�W�@�ӷs���벼
int add_vote(string arg)
{
        object me=this_player();
        int num,i,day;
        string long;
        if(wiz_level(me)<6 )
                return 0;
        if(query("vote_data")) 
                return notify_fail("�{�b�벼���b�i�椤�I\n");
        if(!arg || sscanf(arg,"%d %d %s",num,day,long)!=3)
                return notify_fail("add_vote <�ﲼ��> <�Ѽ�> <����>\n");
        if(num < 1 )
                return notify_fail("�ﲼ�Ƴ̤֭n���@�ӡI\n");
        if(day > 7 || day < 1)
            return notify_fail("�Ѽƥu�� 1 - 7�ѡI\n");
        set("vote_data/long",long);
        set("vote_data/start_time",time());
        // �w�]�@�ѴN�}��
        set("vote_data/stop_time",time() + day * 86400);
        set("mode",1);
        i=0;
        write("�п�J�� "+(i+1)+" �i�ﲼ�������G");
        input_to((:enter_vote:),1,num,i);
        return 1;
        
}
void enter_vote(string arg,int num,int i)
{
        if(!arg) {
                write("�@�w�n��J�F��A�ЦA�Ӥ@���G");
                input_to((:enter_vote:),1,num);
                return ;
        }
        set("vote/"+i,arg);
        if(num==1) 
        {
                write("�����F�I\n");
                save();
                return ;
        }
        
        i++;
        num--;
        write("�п�J�� "+(i+1)+" �i�ﲼ�������G");
        input_to((:enter_vote:),1,num,i);
        
}
string extra_long()
{
        string str;

        if(!query("vote")) return "�{�b�S�����󪺧벼�I";
        if(query("mode") == 2)
        {
                return "�벼���G�p�U:\n"+query("vote_data/final");;
        }
         str= sprintf("�벼�����G
        %s
",query("vote_data/long") );
        foreach( string num in sort_array(keys(query("vote")),1))
        {
                if(num == query("vote_user/"+getuid(this_player()))) str += HIW"��"NOR;
                else str += "  ";
                str += sprintf("  [%s] %s\n",num,query("vote/"+num));
        }
        str += "\n\t�٦� "+ FINGER_D->age_string(query("vote_data/stop_time")-time())+ " �N�}���F�A�q�д��ݡI\n";
        return str;
}
string query_short()
{
        object me=this_player();
        if(query("mode")==2)
        {
                return name()+ "(" + capitalize(query("id")) + ")�� �벼�����B�@ "+sizeof(query("vote_user"))+" �H�벼";
        }
        if(query("mode")==1)
        {
                string str;
                str = (query("vote_user/"+me->query("id")))?"�A�w�g�벼�F":HIR"�A�|���벼"NOR;
                return name()+ "(" + capitalize(query("id")) + ")�� "+sizeof(query("vote_user"))+" �H�w�벼 - "+str;
        }
        if(query("mode")==0)
        {
                return name()+ "(" + capitalize(query("id")) + ")���ثe�S������벼";
        }
}
int vote(string arg)
{
        
        if(query("mode")!=1) return 1;
        if(query("vote_user/"+getuid(this_player()))) return notify_fail("�A�w�g��L�F�@�I\n");
        if(!arg) return notify_fail("�A�n�먺�@�ӡH\n");
        if(!query("vote/"+arg)) return notify_fail("�S���o�@�ӿﶵ�@�I\n");
        set("vote_user/"+getuid(this_player()),arg);
        save();
        message_vision("$N��J���t���@���F�I\n",this_player());
        return 1;
}
int open_vote(string arg)
{
        mapping fin;
        string *votes;
        string str;
        
        if(wiz_level(this_player())<6 )
                return 0;       
                
        fin = allocate_mapping(sizeof(query("vote")));
        votes = values(query("vote_user"));
        str = query("vote_data/long")+"\n���G�p�U�G \n";
        
        foreach(arg in keys(query("vote")))
        {
                fin[arg] = sizeof(filter_array(votes,(: $1 == $2:),arg));
        }
        votes = sort_array(keys(fin),1);
        foreach(arg in votes)
        {
                str += sprintf("[%s] %-30s �� %-3d �i��\n",arg,query("vote/"+arg),fin[votes[to_int(arg)]]);
        }
        set("mode",2);
        set("vote_data/final",str);
        write("�}�����\�I\n");          
        write("�̫ᵲ�G��\n"+str);
        save();
        return 1;
}

