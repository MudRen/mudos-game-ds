#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
        set_name("���Z�Яd���O",({"board"}));
        set("location","/u/a/acme/workroom.c");
        set("board_id", "acme_b");
   set("master",({"acme"}) );
        set("long",
        "�o�O�@�����Z�бM�Ϊ��d���O�C\n");
        setup();
        set("capacity",100);

}
