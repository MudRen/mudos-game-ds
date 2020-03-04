// ²�檺���@�޲z��
// �榡: netcoff -a <ip> <name> �W�[ -d <ip> �R�� -l �C�� (-q �d��u�W�ϥΪ� not ok)
// add_ip & delete_ip ��
// reutrn �� :
// 0:���~
// 1:�w���� ip ;name ( add_ip )  or �L�� ip;name ( delete_ip )
// 2:�W�[ or �R�����\
#include <ansi.h>

inherit F_SAVE;
inherit F_DBASE;

int add_ip(string ips, string name);
int delete_ip(string ips);
int save();
string list_ip();
string query_users_online();

mapping ip = ([
        "None Using" : "0.0.0.0"
]);
mapping query_ip();

void create()
{
        seteuid(getuid());
        set("name", "���@�޲z��");
        if( restore() )
                CHANNEL_D->do_channel(this_object(), "sys", " RESTORE Successed. ");
        remove_call_out("save");
        call_out("save", 300);
}

string channel_id() { return "IP_D"; }

string query_save_file() { return DATA_DIR + "ip_d"; }

int add_ip(string ips, string name)
{
        string i1, i2, i3, i4, *keys;

        if( !ips || sscanf(ips, "%s.%s.%s.%s", i1,i2,i3,i4)!=4 )
                return 0;
        keys = keys(ip);

        for(int x=0;x<sizeof(keys);x++) {
                if( keys[x] == name )
                        return 1;
                if( ip[keys[x]] == ips )
                        return 1;
        }
        ip[name] = ips;
        return 2;
}

int delete_ip(string ips)
{
        string i1, i2, i3, i4, *keys;
        int i;

        if( !ips || sscanf(ips, "%s.%s.%s.%s", i1,i2,i3,i4)!=4 )
                return 0;
        keys = keys(ip);

        for(int x=0;x<sizeof(keys);x++)
                if( ip[keys[x]] == ips )
                {
                        i = 1;
                        map_delete(ip, keys[x]);
                        break;
                }
        if( !i ) return 1;
        return 2;
}

string list_ip()
{
        string msg, *keys;
        keys = keys(ip);
        msg = "\n�������������@���U ip ��m�G\n"+HIY
                "         �W            ��     ip ��     �m\n"+
                "        �¡¡¡¡¡¡¡¡�  �¡¡¡¡¡¡¡�\n"NOR;
        
        if( sizeof(keys) < 1 ) return "�|�L������ !";
        for(int x=0;x<sizeof(keys);x++)
                msg += sprintf(" %18s : %15s\n", keys[x], ip[keys[x]]);
        msg += "\n";
        return msg;
}

mapping query_ip() { return ip; }

string query_users_online()
{
}

int save()
{
        remove_call_out("save");
        call_out("save", 300);
        ::save();
}
