#include <room.h>
inherit ROOM;
void create()
{
 set("short","�᰾�U");
 set("long",@LONG
�o�O�V���󪺫᰾�U, ���M���U�n�p���h, ���L�Pı
�_�����H���P�ŷx, �ӥB���C��[�I�R���, �A���e�観�i
�Q�۪�֪��j�Ȥl, ���ӬO���`�ɰ�D�b�𮧮ɧ����Ȥl,
�Ȥl�Ǧ��ӳq�D, �����D�q������.
LONG
    );
 set("exits",([
               "north":__DIR__"hall5",
                "east":__DIR__"inroom2",
                "west":__DIR__"inroom3",
               "south":__DIR__"inroom65",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}
