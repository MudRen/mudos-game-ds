#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
        set_name(HIC"���Ф��O��"NOR,({"hiko-board","board"}));
        set("location","/u/h/hiko/workroom");
        set("board_id","hiko_workroom_b");
        set("long",
        "�o�O�����Q��"HIC"����"HIW"�p���H�Ϋ��Ъ��p�a��A\n"NOR
        "�p�G������N���]�Цb����ĳ�A"HIC"����"HIW"�|�ɳt\n"NOR
        "�^�ШýЦh�h����o^^b�C\n"
          );
        setup();
        set("capacity",100);
  set("master",({ "hiko"}));
 
        replace_program(BULLETIN_BOARD);
}


