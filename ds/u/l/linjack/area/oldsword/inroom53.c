#include <room.h>
inherit ROOM;
void create()
{
 set("short","�s���ͽm�\\��");
 set("long",@LONG
�o���O�V����s�i�̤l����m�\�𮧤���, �ݰ_�ӳo�䦳
��T�H���ˤl, ���@�W������`���v�S���b�o��a�ۥL�̭׽m
���a�ߪk. �p�G�A�]�O�V���󪺧̤l, ���ӥi�H�M�L�̤@�_�m
�\�a.
LONG
    );
 set("exits",([ "south":__DIR__"inroom52",]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
