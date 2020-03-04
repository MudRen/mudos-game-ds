inherit ROOM;

void create()
{
	set("short","�g�s���j�U");
	set("long", @LONG
�@��L���e�A���Y�@�_�A��ӳo�N�O����W�¹D�D�����x���g�s
���A�Q�_�ۤv�H�e���Ұ��Ҭ��A��x�ߤ����T�_�X�@�}�N���C�S�Q��
�g�s�����j�U�M�@�릿��W���������P�C������W�������D���~����
�򪺱��ѩM�P�a��C�A�A�ݥk��D�D�o�ɤ~�o�{�A�g�s�����@�ӭө}
�����b�a�W�A���䯸�۪��ƤH���G���O�����n��A�@�ӭӤӶ��޶��_
�A�ⴤ�C��A�����M�`�����ۧA�C
LONG

	);
	set("exits",([
  "south" : __DIR__"dragon_garth.c",
  "north" : __DIR__"dragon_meeting_room.c",
  "northeast" : __DIR__"crazy_dragon.c",
  "southeast" : __DIR__"fire_dragon.c",
  "northwest" : __DIR__"god_dragon.c",
  "southwest" : __DIR__"valor_dragon.c",
  "up" : "/open/world1/wilfred/club/dragon/online",
]));
	set("objects",([
__DIR__"box1" :1,
]));
	set("item_desc",([
  "����":"�@��ť�����D�b�Y��q�Ѧӭ��ܮa���誺�@��C�A�C�W�B�{�{�o���A�ӻ��p���A���i�Y�Ѥ@��.\n",
  "�P�a":"����⪺�@���]�C�A�ǻ��o���]�C�O��~�L�@�d�h�U�H��ű�����A�����ٵo�X�@�I���.\n",
]));
	set("light",1);
	set("no_kill",1);
set("no_goto",1);
	setup();
	set("stroom",1); //�o�˴N���|�M���o�̪��F��.�]���|�A�� (�S���p�~��)
	call_other( "/obj/board/dragon_club_b", "???" );
}

void init()
{
	add_action("do_kill",({ "kk","kill" }));
  this_player()->set_temp("come_from_dragon",1);
  this_player()->set_temp("come_from_sky",0);
}

int valid_leave(object me, string dir)
{
	if( dir=="north" && !wizardp(me) )
	{
		if(CLUB_D->check_member("dragon",getuid(me)) < 4) return notify_fail("���̥u�����ѥH�W�~��i�h�C\n");
	}
	return ::valid_leave(me, dir);
}

int do_kill(string arg)
{
	if( arg == "guard" || arg == "dragon guard" )
	{
		tell_object(this_player(),"�A�Q�n���`�ۤv���⨬�H�I\n");
		return 1;
	}
	else return 0;
}
/*�o�̬O�g�s�����j�U�A�b�o�̦��\�h�öQ�_���b���A�`�`���~�a��^���S��
�^�m�_�éM�@�ǩ_�ò��_�A�|�P����W�����F�Ѫk�W�a�����l�Ө�����æ��Ǿ�
���A�b�o�̦��Ǫ״ȡA�W�����Q�F�۷�h����֡B�D�֤������������A�٦b���e
���Ӱ��B�A�W���g�ۡ����E�˹F���|�r�A�H�x�ۨg�s�����դO�@�餣�i�@�餧��
�A�ثe�H���\�h�����A�b�j�U�P�򦳨ǥX�f�A�ټЩ��۬O����γB�A�i���g�s��
�����B���]�B���աI*/
