#include <room.h>
inherit ROOM;
void create()
{
 set("short","�a�V��");
 set("long",@LONG
�A���Ӽy���A�S�A���e���T�B, �_�h���w�L���a�V���U.
�o�䪺����������, ���L�A����ݨ��a�V����, �ݰ_�ӳo��
�|�ܰ����ˤl. �p�G�A��ۤv�����}���H��, �A�i�H�յ۩�
�U��(jumpdown).
LONG
    );
 set("exits",([ "north":__DIR__"outroom26",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
