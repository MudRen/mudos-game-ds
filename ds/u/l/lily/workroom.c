#include <ansi.h>
inherit ROOM;
string query_long();
void create()
{
        set("short", "�������a");
       set("long",(:query_long :)       );
        set("valid_startroom", 1);
    setup();
        set("exits", ([ 
  "out" : "/d/wiz/entrance",
  "luky" : "/u/l/luky/workroom",
  "hall" :"/d/wiz/hall_guild",
 ]));

        set("no_clean_up", 0);

        setup();
}


int sort_user(object ob1, object ob2)
{
                return (int)SECURITY_D->get_wiz_level(ob1)
                        - (int)SECURITY_D->get_wiz_level(ob2);
}

int member_wiz(object obj){
	if(wizardp(obj)) return 1;
	return 0;
}

string query_long(){

object *list;
        string str;
        int  j;
 
         list = users();
         list = filter_array(list,"member_wiz",this_object());
         list = sort_array(list, "sort_user", this_object());
         j = sizeof(list);
	     str = "\n+++++++++++++++++++++�u�W�o�b���Ův��++++++++++++++++++++++++\n";
	     
	     while( j-- ) {
                         str = sprintf("%s%12s%s",
                                str,
                                RANK_D->query_rank(list[j]),
                                list[j]->short(1)
                        );
                         str += "\n";
        }
        
        str +="+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

	return str;
}
