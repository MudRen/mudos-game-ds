inherit ROOM;

void create()
{
	set("short","�ۤ뤧��");
	set("long", @LONG
�@�Ө�o�̧A���T�P��@�}�Y�w�دt�A�]���q�|���K�観�ƥH�d
�U�p���P�I���~�V�A��g�L�ӡC�A�C�Y�@�ݧ�O�`�`���Y�F�@��A�A
�oı�ۤv���}�B�b��Ť����A���L���T�������ӬO���ߦb�@���z����
�������W�C�o�ӯ������Ŷ��ݨӤ@�w�N�O���Ӭy�Ǧb��ڻ�ɪ̶���
���K�F�A�u�O�p���_�����a��쩳�p��гy���O�A�o�S�O�t�@�Ӥ��
�����Ѥ����F�C�b�e�褣�����B���@�ӥ��j�������q�ߵۡA�R�R�a��
�o�۷ũM���H������~�C

LONG
	);
      set("exits",([
  "up" : __DIR__"room9.c",
]));
	set("objects",([
__DIR__"item/treasure_box" :1,
__DIR__"item/crystal" :1,
]));
/*	set("item_desc",([
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
*/
	set("light",1);
	set("no_kill",1);
set("no_goto",1);
	setup();
	set("stroom",1); //�o�˴N���|�M���o�̪��F��.�]���|�A�� (�S���p�~��)
        call_other( "/obj/board/moon_room8_b", "???" );
}

int valid_leave(object me, string dir)
{
        if( dir=="up" && CLUB_D->check_member("moon",getuid(me))  < 3 )
                return notify_fail("���D���O�G¾��b���Ѥ��U�̤��o�J���I�I\n");
        return ::valid_leave(me, dir);
}

