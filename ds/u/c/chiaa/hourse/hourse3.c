// Room: /u/c/chiaa/hourse/hourse3.c
#include <room.h>
inherit ROOM;
inherit DOOR;
void create ()
{
  set("short", "�j�Y����Ū�ѫ�");
  set("long", @LONG
�o�̬O�j�Y���̤����w���a��!�Ө�o�өж��j�Y���N�n�}�l�Υ\!
���O�j�Y���u�Q�L�y������l!
LONG
        );
        set("valid_startroom", 1);
        set("no_magic", 1);
        set("no_die", 1);
  set("exits", ([ /* sizeof() == 1 */
"north" : __DIR__"hourse0",

]));
setup();
create_door("north","��O��","south",DOOR_CLOSED);  //�_�䪺��O���O���۪�
                                                    //�������V�n�۹�

}
