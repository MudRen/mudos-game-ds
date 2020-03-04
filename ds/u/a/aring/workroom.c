
#define WALLDATA        "/u/a/aring/note.txt"
#include <ansi.h> 
inherit ROOM;
string base_long;
void load_wall_data();
void create() 
{ 
     set("short", HIW"�C�L"BLK"�۸O"NOR);

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
                message_vision(HIW"$N"HIW"��Q�g���ΤO����W�h�F�C\n", me);
                load_wall_data();
                return 1;
        }
        else
                return notify_fail("�z�Q�褰��r�W�h?\n");
}

void load_wall_data() {
        string appendlong;

        if(file_size(WALLDATA) == -1) {
                appendlong = "\n    Aring�ȮɨS���d����C"NOR;
        }
        else {
              appendlong = ""HIC"�ϥΤ�k�� write xxx�A�Ч������Q�Φ��d�����C"NOR"\n---------------------------------------------------------------------------------\n"NOR + read_file(WALLDATA);
        }
        set("long", base_long + appendlong + "\n");

}

