// syy bluemountain = tvtv test deaon (expect: ccr watch )

#include <ansi.h>
#define NAME "������"
#define ID "basic"
inherit ITEM;

mapping skills = ([ ]);
string string_back();

void create()
{
        set_name("������" ,({ "basic"}));
        setup();
        save_object(__DIR__"querier.o", 1);
}

void init()
{
        add_action("do_query", "query");
        add_action("do_ret", "ret");
}

int do_query(string arg)
{
        object me = this_player();
        string str = "";

        if( !arg )
        {
                if( query("level") ) write( string_back() + "\n");
                else return 0;
        }
                        
        if( file_size("/data/user/" + arg[0..0] + "/" + arg + ".o") == -1 )
                return notify_fail("�S���o�Ӫ��a�Ϊ̤w�g�Q�R���F�I\n");
        if( restore_object("/data/user/" + arg[0..0] + "/" + arg + ".o", 1) == 0 )
                return notify_fail("'restore' ����. \n");

        write(string_back() +"\n");
        return 1;
}

int do_ret()
{
        return restore_object(__DIR__"querier.o",1 );
}

string string_back()
{
        return sprintf( HIY"\n UsER: "HIG"%s(%s) \n"NOR+
        "ATTR: str:%d | con:%d | int:%d | dex:%d | Combat_exp:%d | MKS:%d | popularity:%d \n"+
                        "SK: combat:%d | parry:%d | dodge:%d | block:%d \n Dayz: %s | Level: %d\n",
                        query("name"),
                        query("id"),
                        query("str"),
                        query("con"),
                        query("int"),
                        query("dex"),
                        query("combat_exp"),
                        query("MKS"),
                        query("popularity"),
                        skills["combat"],
                        skills["parry"],
                        skills["dodge"],
                        skills["block"],
                        FINGER_D->age_string((int)query("mud_age")),
                        (int)query("level"), );
}
