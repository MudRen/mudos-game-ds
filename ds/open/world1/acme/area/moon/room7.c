inherit ROOM;

void create()
{
	set("short","�F�뤧��");
	set("long", @LONG
�@�B�J���B�A�A���W�Q�o�̲��Y���𮧩ҷP�V�Ӥ���ı�����İ_
�ۤv�H�������e�C�A�V�|�P��F�@��A�o�{�|�P��a�����\��F�\�h
���J���C��Ӧ��B�N�O��ڬ��F�����}�Х��ڪ����H�H�ξ��N���ڪ�
�A�ӯS�O�M�ӥ��K�J�X�F�o�\�h�ݮݦp�ͪ��H���C�ڻ��o���F�뤧��
���æ��@���A���H�������K�A�u����ڪ���ɪ̭̤~�����|���D�C

LONG
	);
	set("exits",([
  "south" : __DIR__"room6.c",
]));
   set("no_recall",1);
	set("objects",([
//__DIR__"item/moon_statue" :1,
__DIR__"item/moon_statue2" :1,
//add by manto 2006.06.09
]));
//	set("item_desc",([
//  "�J��":@STATUE
//
//STATUE
//,
//]));
	set("light",1);
	set("no_kill",1);
set("no_goto",1);
	setup();
	set("stroom",1); //�o�˴N���|�M���o�̪��F��.�]���|�A�� (�S���p�~��)
//	call_other( "/obj/board/dragon_club_b", "???" );
}

