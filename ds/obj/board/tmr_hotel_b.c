#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
        set_name(HIG"�¤ѯd����"NOR,({"board"}));
          set("location","/open/world1/tmr/area/hotel");
        set("board_id", "tmr_hotel_b");
        set("long",
        "�@�i��s���d���O�A����H���Ƴ���b�W���d�����C\n");
        setup();
          set("capacity",1000);
  set("master",({ "tmr","acme","cominging","luky", "alickyuen"}));
 
}

