#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
    set_name(HIC"�C"NOR+CYN"�L�O"NOR,({"aring's board","board"}));
    set("location","/u/a/aring/workroom");
    set("board_id", "aring_b");
    set("master",({"acme"}) );
    set("long",
      "[36m�����@�Ǥj�p�Ʊ����ѡC[0m\n");
    setup();
    set("capacity",100);

}



