#include <room.h>
inherit ROOM;
void create()
{
 set("short","�ͽå𮧫�");
 set("long",@LONG
�o��O�V����j���~���ͽå��ɥ𮧪�²���𮧫�, 
�̭�����T�W�ͽå��b�Y�ۤp��ͤ�, �ݰ_�ӥL�̳��w
�g�h�Τ����F. �٦��Ӥp�ӱ詹�U��.
LONG
    );
 set("exits",([ "east":__DIR__"outroom1",
                "down":__DIR__"outroom5",]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}