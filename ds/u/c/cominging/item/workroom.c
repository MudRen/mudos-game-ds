#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", " -= Use you brain in PROGRAMMING =- ");
        set("long", @long

�o�Ǧ~, �o�Ǥ�l, �Ƽ�, �ܤ֤]�֤T�~�F, �O�o���Q Jack �Զi
DS��, �٬O�@�Ӧ�� LPC ���󪫪��泾.. ��{�b�j�j�j�j��O�@��
.. �ٯ�� Coding �� Wizard, DS ���Ův�s.. �@�ӱ��ۤ@�Ӫ����@
�I���H�f�y��..���O�� new Mud �N�O�Ƿ~�����D, But I still
believe that.. Our DS won't be ruined !
               We're the Best !

long    );
        set("exits", ([
  "baal": "/u/b/baal/workroom.c",
  "wiz": "/d/wiz/hall1.c",
  "c_hotel": "/open/world1/tmr/area/hotel.c",
  "q": "/u/u/uchimaha/workroom.c",
  "luky": "/u/l/luky/workroom.c",
  "alick": "/u/a/alickyuen/workroom.c",
]));
        setup();
        call_other("/obj/board/coming_b.c", "???");
}

void init()
{
        if( userp(this_player()) )
                call_out("delay", 0, this_player());
}

void delay(object me)
{
        string str;
        if( str = read_file(__DIR__"qlist") )
                write(HIG"\t:::: Incoming "HIY"Quest List "HIG"::::\n\n"NOR+
                        str+ NOR +"\n");
}
