inherit ROOM;

void create()
{
	set("short", "�e��������");
	set("long", @LONG
�o�̬O�e�������D���ж��A�b�o�̦��\�\�h�h���M�j�C��A�]���\
�h���ִ��A��o�઺�H�ݨ��ٻ����ֱ��e�N�A�e���������D�ثe�]����
�Ʀӥ~�X�A�ҥH�o�өж����`�N�ܤ֤H�X�J�A���L�b�\�C�[�Ǫ��Ѭ[�o
�p���s�~�A�n���S���b�B�I�ǹСA�Ѭ[�W�]���ǴM�`�H�a�Ҧ������g�B
�T�r�g�A�}�U���a��]�X�G�_�F��A�W���O¸�ۤ@�������ªZ�����s�A
�H�x�ۯe�����������ˤl�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"flurry48.c",
]));
	set("objects", ([
                "/open/world1/alickyuen/wind/ling" : 1,
"/open/world1/cominging/area/sorsin_man":1, // add by js
	]));
	set("light",1);
	setup();
}
void reset()
{
	:: reset();
//        call_out( (: find_living("wind_big_guy")->help():), 120);
}
