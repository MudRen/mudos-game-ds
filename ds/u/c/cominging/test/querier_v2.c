// syy bluemountain = tvtv test deaon (expect: ccr watch )

#include <ansi.h>
#define NAME "������"
#define ID "basic"
inherit ITEM;

mapping skills = ([ ]);
string string_back();

void create()
{
        set_name("������ v2" ,({ "basic"}));
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

        if( !arg ) return notify_fail("�Ы��w�@�Ӧr���}�Y..!\n");;

        files = get_dir("/data/user/" + arg[0..0] + "/");

        if( !arrayp(files) ) return notify_fail("�S���H "+ arg[0..0] + " �}�Y�����a�C\n");

        for(int x=0;x<sizeof(files);x++)
        {
                write("** file["+x+"] :"+ files[x]+ "\n");
                if( file_size("/data/user/" + arg[0..0] + "/" + files[x]) == -1 )
                        write("�S���o�Ӫ��a�Ϊ̤w�g�Q�R���F�I\n");
                if( restore_object("/data/user/" + arg[0..0] + "/" + files[x], 1) == 0 )
                { write("'restore' ����. \n"); continue; }
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
