// Room: /d/xiangyang/daxiaochang.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�j�ճ�");
	set("long", @LONG
�o�O�����u�x�ΨӮվ\�x�h���a��C�u���ճ��������޷f
�ۤ@�y���x�A�x�n�ƦC�ۤd�l�i�Ȥl�O���C�x�e�ݵۨ�ںX���A
�X�����W���ۺӤj���X���C�ճ��̻E���ۼƦʭӥ|�U�H�W����
���̤l�C�L�̳��O���v��s���������D���C
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"north" : __DIR__"westjie3",
	]));
	set("coor/x", -540);
	set("coor/y", -510);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
