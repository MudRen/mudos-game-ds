// mailbox.c
#include <ansi.h>

inherit ITEM;
inherit F_SAVE;

mapping *mails;

void get_mail_text(mapping mail, string str);

void create()
{
        set_name("�ڤ۫H�c", ({ "mailbox" }) );
        set("long",@LONG

                �A�i�H�ΥH�U���O�ӳB�z�A���l��
                
                mail <�Y�H>               �H�H���O�H�C
                forward <�H��s��> <�Y�H> �N�Y�ʫH��H���O�H�C
                from                      �d�ݫH�c�����H��C
                read <�H��s��>           �\\Ū�@�ʫH��C
                discard <�H��s��>        ���@�ʫH��C

LONG
        );
        set("unit", "��");
        set("no_drop", 1);
//      set_temp("invis");
        setup();
}

int set_owner(string id)
{
        set("owner_id", id);
        return restore();
}

void init()
{
        if( this_player() && environment()==this_player() )
        {
                set_owner( (string)this_player()->query("id") );
                this_player()->delete("new_mail");
                this_player()->set_temp("mbox_ob", this_object());
                add_action("do_mail", "mail");
                add_action("do_forward", "forward");
                add_action("do_from", "from");
                add_action("do_read", "read");
                add_action("do_discard", "discard");
        }
}

string query_save_file()
{
        string id;

        if( !stringp(id = query("owner_id")) ) return 0;

        return DATA_DIR + "mail/" + id[0..0] + "/" + id;
}

void receive_mail(mapping mail)
{
        if( !pointerp(mails) ) mails = ({ mail });
        else mails += ({ mail });
        save();
}

void send_mail(string receiver, mapping mail)
{
        object ppl, mbx;

        // Get the mailbox or make a new one if not found.
        ppl = find_player(receiver);
        if( !mbx ) {
                mbx = new(MAILBOX_OB);
                mbx->set_owner(receiver);
        }

        // Receive the mail and destruct the objects if receiver is off-line.
        mbx->receive_mail(mail);
        if(ppl){
                mbx = ppl->query_temp("mbox_ob");
                write ("�w�q�� " + receiver + " ���H!\n");
                tell_object(ppl, HIC"\n���z���s�H�T\n\n"NOR);
        }
        else MAIL_D->send_mail(receiver);

        destruct(mbx);
}

int do_mail(string arg)
{
        mapping mail;

        if( this_player()!=environment() ) return 0;

        if( !arg || arg=="" )
                return notify_fail("�A�n�H�H���֡S\n");

        mail = ([
                "from": this_player()->name(1) + "(" + this_player()->query("id") + ")",
                "title": "�L�D",
                "to": arg,
                "time": time(),
                "text": ""
        ]);
        write("�H����D�R");
        input_to("get_mail_title", mail);
        return 1;
}

void get_mail_title(string str, mapping mail)
{
        if( str!="" ) mail["title"] = str;
        write("�H�󤺮e�R\n");
        this_player()->edit( (: get_mail_text, mail :) );
}

void get_mail_text(mapping mail, string str)
{
        mail["text"] = str;
        write("�z�ۤv�n�d�@���ƥ���(y/n)�S[n]");
        input_to("confirm_copy", mail);
}

void confirm_copy(string yn, mapping mail)
{
        if( yn[0]=='y' || yn[0]=='Y' ) receive_mail(mail);
        send_mail(mail["to"], mail);
        write ("�а��٦��n�H���ֶ�(y/n) ? [n]");
        input_to ("confirm_other", mail);
}

void get_id (string str, mapping mail)
{
        if( str!="" ) mail["to"] = str;
        send_mail(str, mail);
        write ("�а��٦��n�H���ֶ�(y/n) ? [n]");
        input_to ("confirm_other", mail);
}

void confirm_other(string yn, mapping mail)
{
        if ( yn[0]=='y' || yn[0]=='Y' ) {
          write ("�Ф@���@�ӿ�J�W��, �����ХΥy�I '.'  : ");
          input_to("mail_other", mail);
        }
}

void mail_other(string name, mapping mail)
{
        if (name == ".")
          write ("�H�H�X�h�F.\n");
        else {
          mail["to"] = name;
          send_mail(name, mail);
          write ("�Ф@���@�ӿ�J�W��, �����ХΥy�I '.'  : ");
          input_to("mail_other", mail);
        }
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
                printf("%2d %-40s �H�H�H�R%-25s\n",
                        i+1, mails[i]["title"], mails[i]["from"] );
        write("\n");
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

int do_discard(string arg)
{
        int num;

        if( !arg || !sscanf(arg, "%d", num) )
                return notify_fail("�A�n�����@�ʫH�S\n");

        if( !pointerp(mails) || num > sizeof(mails) )
                return notify_fail("�S���o�ӽs�����H��C\n");

        num --;

        mails = mails[0..num-1] + mails[num+1..sizeof(mails)-1];
        save();
        write("Ok.\n");

        return 1;
}

int do_forward(string arg)
{
        string dest;
        int num;
        mapping m;

        if( !arg || sscanf(arg, "%d %s", num, dest)!=2 )
                return notify_fail("�A�n�N���@�ʫH��H���O�H�S\n");

        if( !pointerp(mails) || num > sizeof(mails) )
                return notify_fail("�S���o�ӽs�����H��C\n");

        num --;

        m = ([]);
        m["title"] = mails[num]["title"];
        m["text"] = mails[num]["text"];
        m["time"] = mails[num]["time"];
        m["from"] = mails[num]["from"] + "/��H��" + this_player()->query("name");
        m["to"] = dest;
        send_mail( dest, m );
        write("Ok.\n");

        return 1;
}

void owner_is_killed() { destruct(this_object()); }
