#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIC"�j���[���"HIY"���D���C"NOR);
        set("long", @long

�æ{���]�����D�A�½�ӥճ��AĲ���ɦ��A�H�j�H�A�L�m���̡C
�M�o���K���H����A�i�H�w�j���B�˵áB�b�B�~�A�h���١A���T�ΡC
��l����H���R�E���A�����G�C�Ҧ��ஷ���̡A��䯲�J�C�ä��H���b���j�C

long    );
        set("exits", ([
  "baal": "/u/b/baal/workroom.c",
  "wiz": "/d/wiz/hall1.c",
  "c_hotel": "/open/world1/tmr/area/hotel.c",
  "q": "/u/u/uchimaha/workroom.c",
  "luky": "/u/l/luky/workroom.c",
  "alick": "/u/a/alickyuen/workroom.c",
]));
  set("objects", ([ __DIR__"coming_b.c": 1, ]));
        setup();
//        call_other("/obj/board/coming_b.c", "???");
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

void w(string a)
{ write_file(__DIR__"translate_log", a); }

