// syy bluemountain = tvtv test deaon (expect: ccr watch )

#include <ansi.h>
#define NAME "雛型機"
#define ID "basic"
inherit ITEM;

mapping skills = ([ ]);
string string_back();

void create()
{
        set_name("雛型機 v2" ,({ "basic"}));
        setup();
        save_object("/u/c/cominging/test/querier.o", 1);
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
        mixed *files;

        if( !arg ) return notify_fail("請指定一個字母開頭..!\n");;

        files = get_dir("/data/user/" + arg[0..0] + "/");

        if( !arrayp(files) ) return notify_fail("沒有以 "+ arg[0..0] + " 開頭的玩家。\n");

        for(int x=0;x<sizeof(files);x++)
        {
                write("** file["+x+"] :"+ files[x]+ "\n");
                if( file_size("/data/user/" + arg[0..0] + "/" + files[x]) == -1 )
                        write("沒有這個玩家或者已經被刪除了！\n");
                if( restore_object("/data/user/" + arg[0..0] + "/" + files[x], 1) == 0 )
                { write("'restore' 失敗. \n"); continue; }
                write(string_back());
        }
        return 1;
}

int do_ret()
{
        return restore_object(__DIR__"querier.o",1 );
}

string string_back()
{
        return sprintf(HIC"%10s(%11s) ;Combat_exp: %-8d ;popularity: %-3d ;Dayz: %10s ;Level: %-2d ;AwARD: %-3d\n"NOR,
                        query("name"),          query("id"),
                        query("combat_exp"),    query("popularity"),
                        FINGER_D->age_string((int)query("mud_age")),
                        (int)query("level"),    query("award/totalvalue"),      );
}
