#include <ansi.h>
inherit ROOM;

void create()
{
set("short", HIY"�P��"NOR);
        set("long",

     HIB"�L���j�L�A���m���ɡE�E�Ө�o�̡A���b��o�o����a�W�A
���Y����o�����R�S���䪺�P�šA�����d�W�U�Ƥ������P�P����
�A�w�۲��C���@�䪺�ѪšA�S���@�s���R���y�P�B�A�µۧA�ĹL
�ӡC�o�˪��������A�ΪA���εۤF�E�E�E\n"
HIY" �E           .             .                    .               �E
   �E          �E            .               �E         �E               .
.     .       �E                     .                .         .\n"

        NOR);
        set("exits", ([
"out": "/d/wiz/hall1",
"start": "/open/world1/tmr/area/hotel",
        ]));
        set("light",1);
          set("objects",([
        ]));
        setup();
}

