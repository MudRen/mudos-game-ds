#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�n���D"NOR);

 set("long",@LONG
�A�B��ܦ�, ��~���V���n���G���~�b�_�ݮɧ�j�F��,
�A���ճ�ť, �o�{���n�����O���H�H�K���V���۾��Ӧ�,�o�{�F
�o�I, �A�Ϧӧ�Q��X�n�����Ѩ�....
LONG
    );
 set("exits",([ "north":__DIR__"walk2",
            "south":__DIR__"walk6",
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);   
}        
           
