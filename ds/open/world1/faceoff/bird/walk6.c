#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�I�u�B"NOR);

 set("long",@LONG
�A����o�X�G����, ��ӧA�@���l�M, �ôb���V���n�~�M�O
�n���D�b�I�u���n��, �A���I�u���a��ݤF�X��,�o�{���i��A
�e�i�F...���M�@�}�����ƤF�L��....���a���y�[�d!
LONG
    );
 set("exits",([ "north":__DIR__"walk4",
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);           
}
