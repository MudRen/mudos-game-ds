// guildhall.c

inherit CLASS_GUILD;

void create()
{
	set("short", "���ϻե��U");
	set("long", @LONG
�o�̬O���ϻժ����U�M²�檺���]���z�X�@�ѴL�Q���Z���𬣡M�@
�i�K�ª��Ӯv�Ⱥݧ��b�j�U�����M�o�̦P�ɤ]�O�u�Z�̡v��ĳ�ƪ��Ҧb
�M�C�~������Q�C���n�b���ϻե~���u�i�x�v����Z�L���D�M�M��b�o
���|��n��j��C�A�i�H�ݨ�_�䪺��W���ۤ@�̤��(sign)�M���G�g
�ۤ@�Ǧ��������@�W�Z�̪��ƶ��C
LONG
	);
	set("exits", ([
		"south" : "/d/waterfog/entrance",
	]));
	set("item_desc", ([
		"sign": @TEXT
�n�����@�W�Z�̨ä����M���ϻ��H���w����󨭮a�M�դ��H�����ڭ̪�
�@���l�M�u�n�A�[�J(join)�Z�̦P���M�N�i�H�V�P�������U�j�������v
�����C
TEXT
	]) );

	set("objects", ([
		__DIR__"champion":1,
		__DIR__"master":1
	]) );
	set("valid_startroom", 1);
	setup();
	call_other("/obj/board/fighter_b", "???");
}
