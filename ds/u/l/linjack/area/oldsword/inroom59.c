#include <room.h>
inherit ROOM;
void create()
{
 set("short","�k�����O");
 set("long",@LONG
�A�q�o�䩹�U��, �i�H�ݨ�V�����U�W�誺�γ����,
���ﭱ��h, �ﭱ�����٦��@�y�Ѿ�. �γ����W�����Ƕ�
�B���b�Ӥߪ����U�۳o�䪺�����.
LONG
    );
 set("exits",(["west":__DIR__"inroom58"]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
