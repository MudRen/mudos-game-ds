inherit ROOM;
void create()
{
        set("short", "�D�ӫ�");
        set("long",@LONG
�o�̬O�ӫǤ�������m�A��_��L�a��e���h�F�C�ӳ̤�������m
��ۤ@��ᬰ���j���ä�A�Q���N�O�L�W�^�����v���B�a�C���Y��V��
��O�A�o�{�@�T���j�����e�C�Q�ۥL�ͫe���غءA�ߤ����K�R���F�O�a
�ðꪺ���M����C�u�O�_�Ǫ��O�A�����D�o�̭��̨Ӫ����u�A���M����
�ө����u��C
LONG
        );
        set("exits", ([
        "north" : __DIR__"grav1.c",
        "south" : __DIR__"grav4.c",
        ]));
	set("objects",([
	__DIR__"obj/coffin.c":1,
	]));
        set("item_desc",([
        "���e" : "�@�ӤH�M�b�԰��W�A�{�Y�ѯ������A���H�ѰJ���q�ȡC\n"
                 "���L���e�̪��H���W���ԥҦn���ޤ޵o�۪���...�C\n",
        ]));
        set("light", 1);
        setup();
}
