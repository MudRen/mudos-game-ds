#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�D���F��");
set("long",@LONG
�o�̩��_�N�O���F���x�B�F, �A�o�{�o�̪��ٻP�٤�����
�O���@�د��_��, �����[����, ���S��[���˳z���\�h���F��
�]���A�i�H�ܲM�����ݨ��̭����@�쥿�b�I�Y�W�F���H....
LONG
    );
 set("exits",([ "north":__DIR__"seacoun11",
		"south":__DIR__"seacoun9",
]));
 set("objects", ([__DIR__"npc/bladeguard" : 2,
    ]));

 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}             
