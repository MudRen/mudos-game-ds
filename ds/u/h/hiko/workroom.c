#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIC"��"HIW"��"HIC"��"HIW"��"HIC"��"NOR);
        set("long",
         "�o���򳣨S���A�u�O�@����ۥ��v�A���A���I�L�k�m�H\n"
         "���L�C�C���A�o�{�A�b�L�ƥ�´����궡�A�ϩ����@�تF��\n"
         "���G���ӤO�q����a�A�b�A�����i���U�A�@����L���ƪ�\n"
         "�]�O�Hı�o���p��ڤ@��C\n" 
         );
        set("light", 1);
        set("exits", ([  /* sizeof() == 3 */            
         "start"  : "/open/world2/anfernee/start/hall", 
            "wiz" : "/d/wiz/hall1",
            "tra" : "/open/world1/tmr/area/hotel",
          "poleg" : "/u/h/hiko/poleg/po0",
          "test"  : "/u/h/hiko/trm1",
       "fongevil" : "/u/h/hiko/fongevil/mu1", 
          ]));                 
        set("valid_startroom", 1);
call_other("/obj/board/hiko_b","???");
        setup();
}


