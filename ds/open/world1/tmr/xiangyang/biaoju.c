// Room: /d/xiangyang/biaoju.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�֫���");
	set("long", @LONG
�A�Ө�@�y���c�������ؿv�e�A���k�۾¤W�U���ۤ@�ڨ�
�V�h�����X���A���W�C�X�ƴ��C�k���X�l�Ϊ��u¸�ۤ@�Y�i��
�R������l�A��l�W�Y���@�u���������C�����X�l�W�g�ۡ���
���������������K�Ӷ¦r�A�ȹ_�K���A��l�D�Z�C�J�f�Ƶ�
��������A�X�W���Y���ۧ�u�C
LONG );
	set("exits", ([
		"west" : __DIR__"eastroad1",
	]));
	set("objects", ([
//		"/d/fuzhou/npc/liu" : 1,
	]));
	setup();
	replace_program(ROOM);
}