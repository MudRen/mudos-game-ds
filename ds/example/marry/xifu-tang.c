// Room: /ruzhou/xifu-tang.c //�|��B�b�Ҧb
// llm 99/07/09

inherit ROOM;
void create()
{
	set("short", "�ߺְ�");
	set("long", @LONG
�o���O�ﻫ�Ӫ��G�ӡA�e���a�i�H�\�U�T�Q�h�i�K�P��A�����E
�ۤj�j������ߦr�A�Ѥ_�`�`���H�b���|��B�b�A�o��������]�N��
���A�a�W�Q�۫p�p���j���a��A�@���߮�v�v�����H�C�A���b�ӤW��
��A�i�ݨ��Ѫi����A�R�s�m���C
LONG
);
	set("exits", ([
                "down" : __DIR__"yingbin-lou1",
	]));

	setup();
   replace_program(ROOM);
}
