#include <room.h>
inherit ROOM;
void create()
{
 set("short","�F�_�A�L");
 set("long",@LONG
�A�Y�N�i�J�h�A��, �A�ݨ�a�U���@�Ǩ��H�H���d�g
, �P�ɤ]�ݨ�F�@�ӫD�`�ݯ}���i�ܵP, ���G�O�Y�Ӹ��L
���Ȧ�̯d�ߪ�. 

LONG
    );
 set("item_desc",([
        "�i�ܵP":"�A���̭����N�O�F�_�A�L���·t�a�a�F�C\n",
     ]));
 set("exits",(["east":__DIR__"en50",
               "south":__DIR__"en53",
               ]));
 
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
