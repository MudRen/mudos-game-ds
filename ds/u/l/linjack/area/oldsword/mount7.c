#include <room.h>
inherit ROOM;
void create()
{
 set("short","���h����");
 set("long",@LONG
�A�J�Ӫ��n�۸}�U���۶�, ���n���A����Ū��ƥ�o��,
�]���q�o��^�U�h, �N�S�R�F. �Aı�o���դw�g������p,
�_�Ǫ��O�@�Ѳ��W�����X�{�b�A�Y�W, ��ӧA������ı��
�w�g��J�F���h����.
LONG
    );
 set("exits",([
               "northdown":__DIR__"mount8",
               "southup":__DIR__"mount6",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
