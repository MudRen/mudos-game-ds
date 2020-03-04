//bug char jail 
//editor-jangshow
#include <ansi.h>
#include <room.h>

inherit ROOM;
inherit F_SAVE; 
void create()
{
        set("short",HIM"�}���T����"NOR);
        set("long",
HIR"\n�o�̬O���æ� BUG CHAR ���T���ǡA�b�j���٥��d�X�ӫe�A�b\n"
"�o�̭��w�ߪ����a�C\n\n"NOR
HIC"\t�����F Arch-Jangshow ���~�A��l���Ův�ФŶé�\n\n"NOR
);

        set("light",1); 
        set("no_kill",1); 
        set("no_quit",1);
        set("valid_startroom", 1); 
        set("no_recall",1); 
        setup();
        call_out("help_reborn",1);
}

void init()
{
        int time;
        object me;

        me = this_player();

        if( !me ) return;
        
        if( me->query("out_of_power") )
        {
                add_action("do_action", "", 1);
                return;
        }

}
int do_action()
{
        if ( (string)query_verb() == "help" )
        { return 0; }
        if ( (string)query_verb() == "say" )
        { return 0; }
        if ( (string)query_verb() == "look" )
        { return 0; }
        if ( (string)query_verb() == "save" )
        { return 0; }
        if ( (string)query_verb() == "inactive" )
        { return 0; }
        if ( (string)query_verb() == "wiz_help" )
        {
                call_out("help_me",1,this_player());
                return 1;
        }

        write("Sorry, �b�c���٬O�w���I�n�C"NOR""WHT"�`�N: �b�o�̯�Ϊ����O�u��:\n   l, say,inactive,save,wiz_help\n"NOR);
        return 1;
}

int help_me(object me)
{
        object *obs = users();
        object ob = this_object();
        int i;

        if(!ob || !me) return 1;

        if(!ob->query_temp("help_ok"))
        {
                write(HIR"Sorry, �o�ӫ��O�٭n�A���ǮɭԤ~��A�ΡC\n"NOR);
                return 1;
        }

        for(i=0;i<sizeof(obs);i++)
                if( wiz_level(obs[i]) > 2 ) tell_object(obs[i],BEEP""HIW"\n"+
                        me->query("name")+"("+me->query("id")+")[���bbug char jail] �V�A�o�X�D�U�T���I�A���Ū��ܴN�L�h�ݬݬO���^�Ƨa�I\n\n"NOR);

                write(HIC"�D�U�T���v�g�o�X�h�F�A�ܩ�Ův�|���|�ӡA�N�n�ݧA���y�ƤF�C\n"NOR);
                ob->delete_temp("help_ok");
        return 1;
}
void help_reborn()
{
        this_object()->set_temp("help_ok",1);
        remove_call_out("help_reborn");
        if(this_object()) call_out("help_reborn",300);
}

