#include <room.h>
inherit ROOM;
inherit DOOR;

void create()
{
        set("short", "�a�U���n���D");
        set("long", @LONG
�|�P���Ů�X�G�A�N�Ƥ��~���M�s�A�ݨӭ�診�X���Q�D���q�l�W��
�u���ǥ\�ΰǡA�q����q�l�������[���n������ť�X�A�o�Ӫ��ݫ����w�g
��O���v�[���F�A�s�����H���O2042�~�X�������j�������H�A�|�P�N�N�M
�M���A����o�o�̪��~��������̥h�F�C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
 "west":__DIR__"weapon.c",
   "north":__DIR__"sec3.c",
    "south":__DIR__"sec1.c",]));
        set("light",1);
        set("objects", ([ /* sizeof() == 1 */
]));
        set("no_clean_up", 0);

        setup();
 create_door("south","�q�Ϫ�","north",DOOR_OPENED,"nokey");
}


