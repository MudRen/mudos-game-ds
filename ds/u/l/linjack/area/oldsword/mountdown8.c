#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�s�U�D��");
 set("long",@LONG
�o���O�W������s�¤���, �ҭ׫ت��D�n�D�����q�F,
�A�i�H�M�����A�Ѧۤv�w�g�i�J�W�ꪺ��t. �ǻ��o�䦳�Ӥ���
�H�O���F�W�N���´¸t�¬ӫҽаU�өT�u�~�ڤJ�I��......
LONG
    );
 set("exits",([ "north":__DIR__"mountdown7",
                "south":__DIR__"mountdown9",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
