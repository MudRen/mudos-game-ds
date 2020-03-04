#include <path.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set ("short", HIC"秘密花園"NOR);
        set ("long", @LONG
                           ���� 
                            ��  ����   
                        �����矙�����            
 ┌──────┐       �矙����矙矙�   
 │ 秘密花園   │         �� ■ ��           ︿   
 │  清涼走廊  │            ■             /  \︿            
 └──────┘    ^^^^^^^^■^^^^^^^^^^^^^^^^^^^^^^^^^
你一走進這片花園，就深深被他的芳香和溫暖所迷。
豔中帶棘的玫瑰，芬芳滿盈的水仙花，小巧可人的菊
花....這一切都是那麼的美好，你打從心底希望這一
刻能永遠停止.........
LONG);   
        set("light",1);
        set("exits", ([
        "west": __DIR__"dragon5",
        "north": __DIR__"flower_room",
                  ]) );
       
        setup();
        replace_program(ROOM);
}

