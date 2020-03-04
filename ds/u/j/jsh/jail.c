//bug char jail 
//editor-jangshow
#include <ansi.h>
#include <room.h>

inherit ROOM;
inherit F_SAVE; 
void create()
{
        set("short",HIM"罷葛禁閉室"NOR);
        set("long",
HIR"\n這裡是關疑似 BUG CHAR 的禁閉室，在大神還未查出來前，在\n"
"這裡面安心的等吧。\n\n"NOR
HIC"\t※除了 Arch-Jangshow 之外，其餘的巫師請勿亂放\n\n"NOR
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

        write("Sorry, 在牢裡還是安份點好。"NOR""WHT"注意: 在這裡能用的指令只有:\n   l, say,inactive,save,wiz_help\n"NOR);
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
                write(HIR"Sorry, 這個指令還要再等些時候才能再用。\n"NOR);
                return 1;
        }

        for(i=0;i<sizeof(obs);i++)
                if( wiz_level(obs[i]) > 2 ) tell_object(obs[i],BEEP""HIW"\n"+
                        me->query("name")+"("+me->query("id")+")[關在bug char jail] 向你發出求助訊號！你有空的話就過去看看是怎麼回事吧！\n\n"NOR);

                write(HIC"求助訊號己經發出去了，至於巫師會不會來，就要看你的造化了。\n"NOR);
                ob->delete_temp("help_ok");
        return 1;
}
void help_reborn()
{
        this_object()->set_temp("help_ok",1);
        remove_call_out("help_reborn");
        if(this_object()) call_out("help_reborn",300);
}

