#include <ansi.h> 
inherit ROOM;
string query_long();
void create()
{ 
        set("short", HIG"���v����"NOR);
        set("long",(:query_long :)       ); 
        set("valid_startroom", 1); 
        set("light",1);   
      set("no_clean_up", 0);
  set("exits", ([ /* sizeof() == 2 */ 
  "jang" : "/u/j/jangshow/workroom", 
  "wiz" : "/d/wiz/hall1",   ]));
  call_other("/obj/board/kenshin_b", "???");

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
             str = HIR"\n===============�u�W�Ův��================\n"NOR;
             
             while( j-- ) {
                         str = sprintf("%s%12s%s",
                                str,
                                RANK_D->query_rank(list[j]),
                                list[j]->short(1)
                        );
                         str += "\n";
        }
        
        str +=HIR"=========================================
 "HIW"���t�Υ�DS@Jangshow�L�p����\n"NOR;

        return str;
}

