#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
        set_name(HIY"���B"HIW"��"NOR,({"poo ding board","board"}));
          set("location","/u/t/tako/workroom.c");
        set("board_id", "tako_b");
        set("long",
        "�Υ��B���y�����d���O�A����H���Ƴ���b�W���d�����C\n");
        setup();
        set("capacity",50);  
replace_program(BULLETIN_BOARD);
 
}





