inherit DOOR;
inherit ROOM;
void create()
{
	set("short", "�x���e");
	set("long",@LONG
�o�̬O�B�F�����x���e���A���\�\�h�h�����شӦb���䪺���A
�b�����䪺�a�観�⮰�ܤj���j���A�j���W�観�\�h�H�x�N�����ϮסA
�Ӧb�⮰�j��������U���@���۷�l�A�M���O�u���Ϊ��A�b��������]
������@�æb�O�áC
LONG
	);
	set("exits", ([
//  "enter" : __DIR__"polity1.c",
  "east" : __DIR__"bnorth5.c",
]));
//	create_door("enter","�j��","out",DOOR_CLOSED);
	set("objects", ([
  __DIR__"npc/pguard.c" : 2,
]));
	set("no_clean_up", 0);
	set("light",1);
	setup();
}
