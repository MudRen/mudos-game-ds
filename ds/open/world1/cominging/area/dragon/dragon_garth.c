#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�g�s��"HIM"��"HIY"���x"NOR);
	set("long", @LONG
    �A�g�L�g�s�����A��ۥѫC�۾Q�������C�C���i�h�C
�񲴱�h�A�|�P���ҲM�աA�O�H�y�ɷPı��ۤv�m����P�Ҥ����C
�A����ť��뤧�n�A��Өg�s���s�W���@�D�s��y�g�o�ءA
��������p�������D�W�����A���P��I�R�����ҥ[�W�@�U�S�@�U���M�ܤ��n�C
�A�C�C���V�e��A��ۤj�U�e�Q���j�s���J���¶�ۡA�観�i�g�s�j���P��C
�Ӫ�^�ۥ۪��e���ƦW������u�ۡC
LONG

	);
	set("exits",([
  "out" : __DIR__"dragon_door.c",
  "north" : __DIR__"dragon.c",
]));
        set("objects",([
                "/open/world1/npc/goldman.c" : 10,
        ]));
	set("item_desc",([

]));
	set("light",1);
set("no_goto",1);
	setup();
}
