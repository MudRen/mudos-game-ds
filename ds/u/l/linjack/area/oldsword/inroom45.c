#include <room.h>
inherit ROOM;
void create()
{
 set("short","�`�޹��");
 set("long",@LONG
�A�@���i�ӴNť��s�����_����]�V�����n��, �ӥB�D�`
���t, �@�ݴN���D�O�ѽm���`�ަb��b. �S��, �o���O�`�ު�
���, �A�ݨ즳�ӤH���b�Ѯ�e���V�O�����, �w�g���Y�վv.
���L�J�Ӥ@��, �L������L�O�Ӧܤ֭��F���窺���j�ɺ�L, 
���O�L�a�l�����O�o�i�H�@���O�O�����ʥ�, �i���A���e���O
�Ӥ��\�׬��`�p���Ѫ�.
LONG
    );
 set("exits",([ "north":__DIR__"inroom43",]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
