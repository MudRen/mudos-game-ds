#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"���G�t�Y"NOR);

 set("long",@LONG
�o�����Y�����, �p�G�b����, �A�i�H�����P�P�����L, �Ʀܤ��|
�`�N��o�����Y, ��, �o�����Y���Ҥ��P, ���S���|�Q��������, �S��
�|����A�Z�ު��ɤH, �S�����r����l, ��\, ��S���|�������a�O,
�u�O, �o�̯����F... �@���@�����G, �L�̹��s�Q���@�˥e����Ө��D
, �����Ʀܫإ߰_�ۤv���a��, �ݨӧA�n�q�L�o�̱o�O�@�f�\�ҤF, �b
�A���Y���W�観�@�Ӱ��B, �W����ۡy���G�t�Y�z�|�Ӥj�r, �ݨӳo�W
�r�u�O�����A����L�F.
LONG
    );
 set("exits",([ "south":__DIR__"guild2",
                "north":__DIR__"guild4",
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

