// Room: /u/c/chiaa/hourse/hourse0.c
#include <room.h>
inherit ROOM;
inherit DOOR;

void create ()
{
  set("short", "�j�Y������");
  set("long", @LONG
�o�̬O�j�Y���̳��w���a��!�]�O�ݩ�e���p�H�ж�!
�j�Y�����ܲz�W���O~~~�ڥu�Q�L�۱y������l~~~
LONG
        );
        set("valid_startroom", 1);  //�ϸөж������U�@���s�u�i�Ӫ��a��
        set("no_magic", 1);         //�ж����T��I�k�ϰ�
        set("no_die", 1);
  set("exits", ([ /* sizeof() == 3 */
"enter" : __DIR__"hourse1",
"west" : __DIR__"hourse2",
"south" :__DIR__"hourse3",
]));
setup();
create_door("south","��O��","north",DOOR_CLOSED);  //���n�䪺���O���۪�
                                                    //���������V�n�۹�
}
