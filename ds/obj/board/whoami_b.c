#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
        set_name("�ڬO�֯d����",({"whoami board", "board"}));
        set("location","/u/w/whoami/workroom.c");
        set("board_id", "whoami_b");
        set("long",
        "�@�i�j����O�d�����A�W�����ӭ��Ǥ��̲`�������D�G�uWho am I�H�v�C\n");
        setup();
          set("capacity",500);
      set("master", ({"whoami"}) );

}

