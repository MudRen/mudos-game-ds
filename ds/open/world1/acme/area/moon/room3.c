//add moon box by manto 2006.06.09
inherit ROOM;

void create()
{
	set("short","��");
	set("long", @LONG
���M�A�w�g���n�F�߲z�ǳơA���b�A�B�J�����ɡA�����T�]
�����Ҩ��ӱi�f���ޡC���L�ä��O�]���������G�m�I�R��ӡA�ϭˬO
�]����������P²��ӨϧA�P�ʲ��W�A�A�o�{�ۤv���������M���I��
��C�A�~��V�e���췵�������A���B���@���մ��������j�y�����
���o�X�ũM���ե��A�Q���o�N�O�뤧�۪�����a�I�b�o�ũM���ե���
�g���U�A�A�P��ۤv�N�n���b���˪��h�ꤧ���@�ˡC���D�O���
�ڤH���|���ҡA���k�U���@���q�D�q�������C

LONG
	);
	set("exits",([
  "up" : "/open/world1/wilfred/club/dragon/online",
  "south" : __DIR__"room2.c",
  "east" : __DIR__"room4.c",
  "west" : __DIR__"room6.c",
		"down" : __DIR__"bank",
]));
      set("objects",([
__DIR__"item/moon_box" :1,
]));
	set("item_desc",([
  "�B��":@DESC1

                              �H
                              ��
                              ��
                              ��
                              
                              ��
                              ��
                              ��
                       �P     �H
                       ��     
                       ��       
                              
DESC1
,
]));
	set("light",1);
	set("no_kill",1);
set("no_goto",1);
	setup();
	set("stroom",1); //�o�˴N���|�M���o�̪��F��.�]���|�A�� (�S���p�~��)
	call_other( "/obj/board/moon_room3_b", "???" );
}

void init()
{
	this_player()->set_temp("come_from_moon", 1);
	this_player()->set_temp("come_from_sky", 0);
	this_player()->set_temp("come_from_dragon", 0);
}
// add by -alickyuen@ds-
