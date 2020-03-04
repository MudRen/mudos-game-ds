#include <ansi.h>
inherit ITEM;
inherit F_SAVE;

mapping *mails;

int last_read_time;
int newest_mail_time;
void get_mail_text(mapping mail, string str);
string sid="";
void create()
{
        set_name("�H�c", ({ "mailbox","mail_ob" }) );
        set("long",@LONG

                �o�O�@�ӥΨӱH�H�B���H���H�c�M�A�i�H�ΥH�U���O�ӳB�z�A���l��R
                from                      �d�ݫH�c�����H��C
                read <�H��s��>           �\Ū�@�ʫH��C
LONG
        );
        set("unit", "��");
        set("no_drop", 1);
        set("no_put", 1);
        set("no_insert", 1);
        seteuid(getuid());

}

int set_owner(string id)
{
        set("owner_id", id);
        return restore();
}

void set_last_read(int time)
{
        if(last_read_time < time)
                last_read_time = time;
        return ;
}

int query_last_read_time()
{
        return last_read_time;
}
int query_newest_mail_time()
{
        return newest_mail_time;
}

int query_mail_flag()
{
        if(last_read_time < newest_mail_time) return 1;
        else return 0;
}
void get_box()
{
        object ob;

        if( this_player() && environment()==this_player() )
        {
                set_owner( getuid(this_player()) );
                this_player()->set_temp("mbox_ob", this_object());
                set_name( this_player()->name(1) + "���H�c", ({ "mailbox","mail_ob" }) );
                add_action("do_from", "from");                add_action("do_read", "read");
        }
}

void init()
{
   add_action("do_set_box","set_box");
}
 
int do_set_box(string ids)
{
   sid=ids;
   get_box();
   return 1;
}


string query_save_file()
{
        return DATA_DIR + "mail/" + sid[0..0] + "/" + sid;
}


int do_from()
{
        int i;

        if( !pointerp(mails) || !sizeof(mails) ) {
                write("�A���H�c���ثe�S������H��C\n");
                return 1;
        }
        write("�A���H�c���{�b�@�� " + sizeof(mails) + " �ʫH��R\n\n");
        for(i=0; i<sizeof(mails); i++)
        {
                printf("%s\n%2d %-50s �H�H�H�R%-20s"NOR,last_read_time<mails[i]["time"]? HIG : "",
                        i+1, mails[i]["title"], mails[i]["from"] );
        }
        write("\n\n");
        return 1;
}

int do_read(string arg)
{
        int num;

        if( !arg || !sscanf(arg, "%d", num) )
                return notify_fail("�A�nŪ���@�ʫH�S\n");

        if( !pointerp(mails) || num < 1 || num > sizeof(mails) )
                return notify_fail("�S���o�ӽs�����H��C\n");

        num --;

        printf("�H����D�R%s\n�H �H �H�R%s\n\n%s\n",
                mails[num]["title"], mails[num]["from"], mails[num]["text"] );
        return 1;
}

void owner_is_killed() { destruct(this_object()); }

