// mishi8.c �K��
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "�K��");
	set("long", @LONG
�o���O�j�Ӥ����K�ǡA�|�P�K���z���A�A�u��ɵ��٤W���t���O��
�ӫj�j�����V�C�٬O�ξ�����C�۬�X�_�Ӫ��A���X���ƬO�����A�A
���H�q����X�@���_�ءC�K�Ǥ��\��ۤ@��²�檺�a�~�Ψ�A��ӳo�O
�j�Ӭ����v�L�­^���~�ǡC
LONG	);
	set("exits", ([
		"west" : __DIR__"mishi7",
//		"out"  : "/d/city/shilijie4",
	]));
  set("objects", ([
          __DIR__"npc/lee" : 1,
  ]));

	setup();
	replace_program(ROOM);
}
