#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
 set_name(HIW+"��"+NOR+"���y���O",({"board"}));
set("location","/u/n/nye/workroom.c");
 set("board_id", "nye_b");
  set("long",
    "�A�ݨ죴�����y���O�A�Ԥ���İʰ��W���_���Ӷ��٩١C\n");
setup();
  set("capacity",100);
  set("master",({ "nye" }));
   replace_program(BULLETIN_BOARD);
}
