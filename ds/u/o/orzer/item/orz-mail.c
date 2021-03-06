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
        set_name("信箱", ({ "mailbox","mail_ob" }) );
        set("long",@LONG

                這是一個用來寄信、收信的信箱﹐你可以用以下指令來處理你的郵件﹕
                from                      查看信箱中的信件。
                read <信件編號>           閱讀一封信件。
LONG
        );
        set("unit", "個");
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
                set_name( this_player()->name(1) + "的信箱", ({ "mailbox","mail_ob" }) );
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
                write("你的信箱中目前沒有任何信件。\n");
                return 1;
        }
        write("你的信箱中現在共有 " + sizeof(mails) + " 封信件﹕\n\n");
        for(i=0; i<sizeof(mails); i++)
        {
                printf("%s\n%2d %-50s 寄信人﹕%-20s"NOR,last_read_time<mails[i]["time"]? HIG : "",
                        i+1, mails[i]["title"], mails[i]["from"] );
        }
        write("\n\n");
        return 1;
}

int do_read(string arg)
{
        int num;

        if( !arg || !sscanf(arg, "%d", num) )
                return notify_fail("你要讀哪一封信﹖\n");

        if( !pointerp(mails) || num < 1 || num > sizeof(mails) )
                return notify_fail("沒有這個編號的信件。\n");

        num --;

        printf("信件標題﹕%s\n寄 信 人﹕%s\n\n%s\n",
                mails[num]["title"], mails[num]["from"], mails[num]["text"] );
        return 1;
}

void owner_is_killed() { destruct(this_object()); }

