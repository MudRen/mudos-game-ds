#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"�վB�����w����j���w����"NOR);
        set("long", @LONG
�A�V�����A�N�i�H�i�J�F�վB���������F�A���a�]���@
���˹��A�G�����L�n�u�A�M���ˬd�i�����ͷN���p�c�B�i
�f�������B�i�ê��H�h���A�q�ˬd������j�ƪ��s�����Υi
�H�o�{�ˬd���{�Ǭ۷��c���A���L�ݨӮȫȨèS���b�ˬd
���C�A�A�i�H������ê���i�J�����C
LONG
        );
        set("exits", ([ 
                        "west": __DIR__"wgate2",
            "east": __DIR__"w1st1",
            ]));
        set("outdoors","land");
        set("no_clean_up", 0);
        set("light",1);
        setup();
        replace_program(ROOM);
}

