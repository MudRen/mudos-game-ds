#include <room.h>
inherit ROOM;
void create()
{
 set("short","�K�}�Ϥ�");
 set("long",@LONG
�A�b�o�ӥѳq�D�ҧG�����K�}�Ϥ��樫, �����L�k����A�Ҧb
�����, �u��̵۪�ı�Ө���, ��_�Ǫ��O�b�o�ӯU�p���q�D����
�G������, �O�A�Q������, �Y���A���I�X�h, ���ȭn���b�̭��F.
LONG
    );
 set("exits",([ "west":__DIR__"secret6_10",
                "east":__DIR__"secret6_4",
                "north":__DIR__"secret6_4",
                "south":__DIR__"secret6_7",
                "northeast":__DIR__"secret6_4",
                "northwest":__DIR__"secret6_3",
                "southwest":__DIR__"secret6_4",
                "southeast":__DIR__"secret6_4",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
