#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�j�U"NOR);

 set("long",@LONG
�o�̴N�O�ѱ��w�b�@�����j�U�F, �A�o�{�o�̬O�`�o�@��
�j�j���W�l�ؿv, �A���T�Q�n�լd�լd�W�l���s�b�Ҭ�����? 
�P�ɧA�]�o�{�@�ǹC�H�]�b�ݵ۬W�l.
LONG
    );
 set("exits",([ "north":__DIR__"pill5",
                "south":__DIR__"pill6",
                "west":__DIR__"pill2",
    ]));
 set("item_desc",([
        "�W�l":"�@�ڤj�j���W�l, �q�o�Ө��׬ݤ��X�����򲧱`.\n"
    ]));
// set("objects", ([__DIR__"npc/traveller" : 2,
//    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);                      
}
