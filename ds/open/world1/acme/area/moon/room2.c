inherit ROOM;

void create()
{
	set("short","������");
	set("long", @LONG
��L�F�j���A�A²���L�k�۫H�ۤv�����Ҭݨ쪺�@���C���M�u��
�j�F�@�D���A���~�o�O�@�ӺI�M���P���@�ɡC�@�i�j���A�A�M�ةҤ�
���O�\�h�ݳ��S�ݹL���_�Ყ���٦��\�h�ǻ������øV���~�C��Ӥ�
�ų����o�۲��˪����~�A�A�T�H�����藍�O����C�H�ۧA�w�w���~��
�e��A���Y�����߱������o�쥭�R�A�Aı�o���Ӥ��|�A���ƪ�����_
�٧A�����F�F�C�̫�A�Ө�F�@�ɴ��o�۲H�C����~���۷����e�A��
�e���۸O�B�{��-��-�T�r�C

LONG
	);
	set("exits",([
  "south" : __DIR__"room1.c",
  "north" : __DIR__"room3.c",
]));
//	set("objects",([
//__DIR__"box1" :1,
//]));
	set("item_desc",([
  "�۸O":"�W����� -��- �T�r�C\n",
]));
	set("light",1);
set("no_goto",1);
	set("no_kill",1);
	setup();
	set("stroom",1); //�o�˴N���|�M���o�̪��F��.�]���|�A�� (�S���p�~��)
//	call_other( "/obj/board/dragon_club_b", "???" );
}

