#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�j�U"NOR);

 set("long",@LONG
�o�̤@�ˬO�H�۬W�l�ӫؿv��, ���O�A�o�{�o�ڬW�l���
�èS���伵�Ѫ�O���@��, �]�����W�����G���ۥi�H�e�U�@��
�H���Ż�, �����D�W���O���O������.....
LONG
    );
 set("exits",([ "south":__DIR__"pill4",
		"northeast":__DIR__"pill7",
    ]));
 set("item_desc",([
        "�W�l":"�@�ڤj�j���W�l, �q�o�Ө��׬ݤ��X�����򲧱`.\n"
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);                      
}
