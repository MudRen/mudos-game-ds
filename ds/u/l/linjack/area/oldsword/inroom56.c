#include <room.h>
inherit ROOM;
void create()
{
 set("short","�m�\\��");
 set("long",@LONG
��ӳo��N�O�����@�éM�̤l�̤��R�Z�ު��a��, ���@�j
�d���L���[�b�o��, �򥻧L�����������ɦ�, �γ\�A�i�H�M�L
�̿i�i�M. �o�୷������, �_���٦����Ѿ��i�H���L�h.
LONG
    );
 set("exits",(["north":__DIR__"inroom57",
                "down":__DIR__"inroom51",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
