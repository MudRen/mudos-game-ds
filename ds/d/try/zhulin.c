// Room: /d/shaolin/zhulin.c

//inherit VRM_SERVER;

inherit "/adm/daemons/virtual/vrm_server";
void create()
{
	// �g�c�ж����~�Ӫ������ɮצW�١C
	set_inherit_room( ROOM );

	//�g�c�ж������Ǫ��C
	//set_maze_npcs(__DIR__"npc/maque");

	//�g�c�������
	set_maze_long(20);

	//�J�f��V(�X�f�b�ﭱ)
	set_entry_dir("east");

	//�J�f�P�ϰ쪺�s����V
	set_link_entry_dir("east");

	//�J�f�P�ϰ쪺�s���ɮצW
	set_link_entry_room(__DIR__"shandao3");

	//�X�f�P�ϰ쪺�s����V
	set_link_exit_dir("west");

	//�X�f�P�ϰ쪺�s���ɮצW
	set_link_exit_room(__DIR__"muwu");

	//�J�f�ж��u�y�z
	set_entry_short("�s�D��");

	//�J�f�ж��y�z
	set_entry_desc(@LONG
�o���O�֫Ǥs���b�s�y�A�F���O�@���~�����s�D�A�V�譱��
�h�O�@���A�񪺦˪L�A���ɶǨ��n�n����C
LONG
);

	//�X�f�ж��u�y�z
	set_exit_short("�H�۸�");

	//�X�f�ж��y�z
	set_exit_desc(@LONG
�o���O�@���H�ۤp���A�F���O�@���A�񪺦˪L�A���ɶǨ��n
�n����C�V���h�����@���p��ΡA�̤s�ĪL�A�u�O�@�B�@�~��
�����P�Ҧb�C
LONG
);

	//�g�c�ж����u�y�z
	set_maze_room_short("�˪L");

	//�g�c�ж����y�z�A�p�G���h���y�z�A��y�C�ө�
	//�����ɭԷ|�q���H����ܤ@�ӡC
	set_maze_room_desc(@LONG
�o�O�@���@�K���A�˪L�A�p������s�n�M���j�L�˪L���F�F
�n��´�����R���j�۵M���۫ߡC�a�W�����O�ͻ����o���ܤ֦��H
�ӡC�ʧ����A�˵����V�W�A�o�N�O�ѤU�D�W���n�A�ˡC
LONG
);

	// �g�c�ж��O�_����~�ж��H
	set_outdoors(1);
}
