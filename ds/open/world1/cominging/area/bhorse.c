inherit ROOM;
void create()
{
    set("short","�s�԰��\\");
	set("long", @LONG
�o�̬O�B�F�����@�a���j�����Ӷ��a�A�o�䦳�۲��h���������A��
�i�ίʪ��A�N�O���Ѱ��T���C
    �o�a���\�W���s�ԡA��O�D�H���W�˵۹L�өҨ����A�@�ǤǪ�����
�B���j���}���A�]�b���\�]��ᤣ������s�ۡC
LONG
	);
//�o�O�B�F�����s�}�����氨���a��A�b�o�̦��\�h�����s�n�A�]��
//�\�h�U�Ȧb�����A�󦳱q�~�o���ܦ������@�|�઺�A�b�o�঳�@�I����
//�i�H�ܡA�]���@�ǭ����i�H�Y�A���L�ݰ_�ӤW���٦��@�ǨǪ��`�ߦb��
//�ˤl�A�b�i�Ӯɦ��@���۵P�j�j���g�ۡu�}���Ӧ��v�C
	set("exits", ([
  "west" : __DIR__"bsouth1.c",
]));
	set("objects", ([
  __DIR__"npc/horse_seller.c": 1,
]));
	set("no_clean_up", 0);
	set("light",1);
	setup();
	replace_program(ROOM);
}
