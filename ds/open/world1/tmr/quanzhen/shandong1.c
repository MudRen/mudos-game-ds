// shandong.c
// Java Oct.10 1998

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "�s�}");
	set("long", @LONG
�b�o�p�s�}(dong)���`�B�A�@�ѱj�j�����y�ۦa�W�y�X�A�Φ��@��
�p�e�y�V�}�~�C�p�G�Q�A�i�@�B�`�J���ܡA�N�o�n���J�����F�C���~�i
��p�e��C���̴N�n����F�C
LONG
	);
	set("item_desc", ([
		"dong" : "�@�Ӳ`��B�շt�B���ƪ��p�s�}�C\n",
	]));
	set("exits", ([
		"out"       : __DIR__"xiaohebian",
		"southdown" : "/d/gumu/anhe2",
	]));

	set("coor/x", -3160);
	set("coor/y", -10);
	set("coor/z", -10);
	setup();
}
int valid_leave(object me, string dir)
{
	if (dir == "southdown" && me->query("family/family_name")!="�j�Ӭ�")
	{
		return notify_fail("�o��檺���A�A�Q���U�h�۱��r�H\n");
	}
	if (dir == "southdown" && me->query("family/family_name")=="�j�Ӭ�")
	{
		message_vision(HIG "$N�a���@�D�A���J���椧���C\n"NOR,me);
		write(HIC"�\�h�C���q�A��C�L�A�A����@���A�o��F�šC��M�A���e�@�G�A�@�ѷt�y�����ӨӡA�N�A�ĤJ�@�өҦb�C\n"NOR);
		return 1;
	}
	return ::valid_leave(me, dir);
}
