inherit ROOM;

void create()
{
	set("short", "���U");
	set("long", @LONG
�@���i�o�̡A�A�N�o�{��^���ǳ\�����ӹ�l�C�]���e�賺�M��
��㰮�͡C�@�㰮�ͨ����~�Z�ڪ��窫�A����b�j�z�ۥx�W�A����
�f�Q����F�@�Ӥj�}�A�ݨӬO�P�R�ˡA�ӥB���زu��A�n���O�a�۷�
�j����릺�h���A�ӥB�P���I���F�C�_���O�A���t���O���U����޲�
�C�t�@�㰮�ͨ��۬���P�ơA��Ž�Φa�A����M���A�⵲�k�L�A�L�L
�ӧ��A���b����y�W�A����ۤj�z�ۥx�W�����㰮�͡A�ݨӬO�ӱo�D
�����C���䪺����W���@�ǱK�K�³ª��r�A���L���G���O�g��A�ӬO
�@�ǰO�ԡA���ݵL���C
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  		"up" : __DIR__"cir12",
	]));
	
	setup();
	replace_program(ROOM);
}
