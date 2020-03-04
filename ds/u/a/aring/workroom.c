
#define WALLDATA        "/u/a/aring/note.txt"
#include <ansi.h> 
inherit ROOM;
string base_long;
void load_wall_data();
void create() 
{ 
     set("short", HIW"劍林"BLK"石碑"NOR);

        base_long = @LONG

LONG;
        set("long", base_long);
;


         set("exits", ([
        "wiz" : "/d/wiz/hall1.c", 
]) );
        set("light",1);
        set("no_clean_up", 0);
        set("valid_startroom", 1);
        setup();  
        load_wall_data();
        load_object("/obj/board/aring_b");
}

void init()
{
      add_action("to_write","write");
}

int to_write(string arg) {

        object me;
        int  current;
        me = this_player();
        current = time();  
        if(arg) {
        write_file(WALLDATA, ctime(current)+" : "+ me->query("name") +NOR":"HIW + arg + NOR +"\n");
                message_vision(HIW"$N"HIW"把想寫的用力的刻上去了。\n", me);
                load_wall_data();
                return 1;
        }
        else
                return notify_fail("您想刻什麼字上去?\n");
}

void load_wall_data() {
        string appendlong;

        if(file_size(WALLDATA) == -1) {
                appendlong = "\n    Aring暫時沒有留言喔。"NOR;
        }
        else {
              appendlong = ""HIC"使用方法為 write xxx，請妥善的利用此留言版。"NOR"\n---------------------------------------------------------------------------------\n"NOR + read_file(WALLDATA);
        }
        set("long", base_long + appendlong + "\n");

}

