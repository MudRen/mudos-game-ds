#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
 set_name("诹ڪ��p����",({"board"}));
  set("location","/u/l/legend/workroom.c");
   set("board_id", "legend_b");
  set("long",
    "�o�O�@��诹ڱM�Ϊ��p�����C\n�A�ݨ�F���ᰨ�W�Q�b�W���d�����p�ڹڡC\n");
setup();
  set("capacity",100);
   replace_program(BULLETIN_BOARD);
}
