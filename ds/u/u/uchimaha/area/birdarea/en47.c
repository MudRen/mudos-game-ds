#include <room.h>
inherit ROOM;
void create()
{
 set("short","�F�_�A�L");
 set("long",@LONG
�o�̪����V�ӶV�@�K, �w�g�ϧA�֬ݤ�����F, �o
�̥i�Hť��ǳ\�C�쪺��s�n, �٦��@�Ƿ|�������Φb�A
�����䭸�ӭ��h, �A�������@���p���q�V��n.

LONG
    );
 
 set("exits",(["southwest":__DIR__"en48",
               "northeast":__DIR__"en46",
               ]));
 
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        