// Room: /d/xiangyang/yaopu.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�ľQ");
	set("long", @LONG
�ľQ���j�A�o���`�����F�����O�d�x�A�d�x�᭱�O�Ӥj
�d�l�X�ʭӤp��P�W�@�@�ά��ȼе��ħ����W�١F�a��γ���
��W�a�ۤ@���©����r�����B�A�g�ۡ�����^�K���C�a�U�X��
��p���b���z��覬�ʨӪ����ġC�F��@�i�p�G���A�W����
�۵����ȵx�A��᧤�ۤ@��ѭ����C�@�Ѩ���Ĩ��R���F���
�ж��C
LONG );
	set("exits", ([
		"north" : __DIR__"eastjie1",
	]));
	set("objects", ([
//		"/d/city/npc/huoji" : 1,
	]));
	set("coor/x", -490);
	set("coor/y", -520);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}