#include <ansi.h>
inherit ROOM;
void create()
{           
  set("short",HIR"�a��"NOR);
        set("long",@LONG
�o�̬O�Y�Ův���a��....�ݨӧA���ΥX�h�F....:P
���L�Y�A�S�ư����ܥi�H�M�H�q�H(mail)...hehe
LONG
        );
        set("hide_exits",([
  "east" : __DIR__"workroom",
]));
        set("light",1);
        set("no_clean_up", 0);
set("room_type","mail");
        setup();
}
void init()
{
        object mail_ob;
        if(userp(this_player()))
        {
                if(!present("mail_ob",this_player()))
                {
                        mail_ob=new(MAILBOX_OB);
                        if(!mail_ob->can_move(this_player()))
                        {
                                write("�A���W�F��Ӧh�F�A�Хᱼ�@�Ǥ~�ॿ�`���o�H�C\n");
                                return;
                        }
                        mail_ob->set_temp("invis",1);
                        mail_ob->move(this_player());
                }
        }
}

int valid_leave(object me, string dir)
{
        object mail_ob;
        if( dir=="east" )
        {
                mail_ob=present("mail_ob",me);
                if(mail_ob)
                {
                        mail_ob->save();
                        destruct(mail_ob);
                }
        }
        return ::valid_leave(me, dir);
}